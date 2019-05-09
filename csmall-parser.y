%{
#include <bits/stdc++.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<iostream>
#include <vector>
using namespace std;
ofstream codeProblemsFile,AssemblyFile,symbolTableFile;

set<string>unusedVariables;
set<string>uniqueProblems;
stack<int>lastRegisterHaslastSwitchExpr;
stack<int>unconditionalLabelsSwitch;
stack<int>unconditionalLabels,conditionalLabels;
extern int yylineno;
int curRegID = 0,scopeID = 0,labelID=0;
bool unsuccessfulCompilation=0;
enum dataType {
  UNDEFINED,
  BOOL_TYPE,
  INT_TYPE,
  FLOAT_TYPE,
  CHAR_TYPE
};
struct entry{
	bool isConst;
	dataType type;
	string stringValue;
	bool isInitialized;
	bool isUsed;
	int line;

	entry(bool isConst = 0, dataType type = UNDEFINED, string vall = "", bool isInitialized = 0, bool isUsed = 0, int line = 0) 
		: isConst(isConst), type(type), stringValue(vall), isInitialized(isInitialized), isUsed(isUsed), line(line) {}


  void display(char* variableName){
    string dt;
    switch(type){
      case BOOL_TYPE:
      dt="Boolean";
      break;
      case INT_TYPE:
      dt="Integer";
      break;
      case FLOAT_TYPE:
      dt="Float";
      break;
      case CHAR_TYPE:
      dt="Character";
      default:
      break;
    }
     symbolTableFile<<variableName<<"\t\t\t"<<isConst<<"\t\t"<< dt<<"\t\t\t"<<stringValue<<"\t\t\t"<<isInitialized<<"\t\t\t"<<isUsed<<"\t\t"<<line<<"\n";
  }


};

vector<map<string,entry>>symbolTable(1);
 const string _ADD = "ADD";
 const string _SUB = "SUB";
 const string _MUL = "MUL";
 const string _DIV = "DIV";
 const string _AND = "AND";
 const string _OR  = "OR";
 const string _GTE = "GTE";
 const string _LTE = "LTE";
 const string _GTN = "GTN";
 const string _LTN = "LTN";
 const string _EQU = "EQU";
 const string _NEQ = "NEQ";
 const string _NEG = "NEG";
 const string _NOT = "NOT";
 const string _MOV = "MOV";


 map<string,dataType>variableType;



/* prototypes */
int yylex(void);
void yyerror(char *s);
void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber);
void definedBefore(char* variableName);
int findVariable(char * variableName);
int getChosenType(int t1, int t2);
void variableAssignment(char* variableName,char* assignedValue);
void beforeExit();
void printConstError(char*variableName);
void printNotdefinedError(char*variableName);
void printUninitializedWarning(char* variableName);
void printIncompatibleTypeWarning();
void printfRedeclarationError(char* variableName);
void printTripleOperandOperation(string operationtype,string source,char* destination);
void printQuadOperandOperation(string operationtype,string source1,string source2,char* destination);
template <typename T>
string toString(T x);
void symboTableFileInit();
void printLabel(int labelNumber);
void printJumpTrue(int labelNumber);
void printJumpFalse(int labelNumber);
void printJump(int labelNumber);

%}

%union {
  char* val; 
      		
	char* name;

  struct info1{
    int type;
    char val[100];
  }info;
		

};


%token <val> INTEGER DECIMAL CHARACTER
%token <name> VAR
%token CONST INT FLOAT CHAR BOOL 
%token ENDOFFILE
%token GE LE GT LT EQ NE NOT AND OR 
%token WHILE FOR DO IF ELSE SWITCH CASE DEFAULT BREAK
%token BOOL_TRUE BOOL_FALSE
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE


%left AND OR
%left GE LE EQ NE GT LT

%left '+' '-'
%left '*' '/'

%right NOT

%type <name> declaration
%type <info> expr 


%start program

%%
program: 
	function                                          {beforeExit(); exit(0);}
	;
function:
		function stmt          											    {}
	| stmt
  |	ENDOFFILE																	      {}
	;

collection_stmt:
    collection_stmt stmt                              {}
  | stmt                                              {}
  ;

stmt:
   	';'																	         	{}
	|	declaration	';'															  {}
	|	assignment ';'															  {}
  | expr ';'                                      {}
  | loop                                          {}
  | condition                                     {}
  | open_brace collection_stmt closed_brace       {}
  | open_brace closed_brace
  ;

open_brace:
            '{'                                   {++scopeID; map<string,entry>initMap; symbolTable.push_back(initMap);}
             ;

closed_brace:
             '}'                                  {symbolTable.pop_back(); --scopeID;}
             ;

declaration:
   CONST INT VAR '=' expr                         {getChosenType(INT_TYPE,$5.type); variableType[$3] = INT_TYPE; declarationHandler($3,1,INT_TYPE,$5.val,1,0,_MOV,yylineno);}
  |CONST FLOAT VAR '=' expr                       {getChosenType(FLOAT_TYPE,$5.type); variableType[$3] = FLOAT_TYPE; declarationHandler($3,1,FLOAT_TYPE,$5.val,1,0,_MOV,yylineno);}
  |CONST CHAR VAR '=' expr                        {getChosenType(CHAR_TYPE,$5.type); variableType[$3] = CHAR_TYPE; declarationHandler($3,1,CHAR_TYPE,$5.val,1,0,_MOV,yylineno);}
  |CONST BOOL VAR '=' expr                        {getChosenType(BOOL_TYPE,$5.type); variableType[$3] = BOOL_TYPE; declarationHandler($3,1,BOOL_TYPE,$5.val,1,0,_MOV,yylineno);}
  
  
  |INT VAR '=' expr                               {getChosenType(INT_TYPE,$4.type); variableType[$2] = INT_TYPE; declarationHandler($2,0,INT_TYPE,$4.val,1,0,_MOV,yylineno);}
  |FLOAT VAR '=' expr                             {getChosenType(FLOAT_TYPE,$4.type); variableType[$2] = FLOAT_TYPE; declarationHandler($2,0,FLOAT_TYPE,$4.val,1,0,_MOV,yylineno);}
  |CHAR VAR '=' expr                              {getChosenType(CHAR_TYPE,$4.type); variableType[$2] = CHAR_TYPE; declarationHandler($2,0,CHAR_TYPE,$4.val,1,0,_MOV,yylineno);}
  |BOOL VAR '=' expr                              {getChosenType(BOOL_TYPE,$4.type); variableType[$2] = BOOL_TYPE; declarationHandler($2,0,BOOL_TYPE,$4.val,1,0,_MOV,yylineno);}
  
  
  |INT VAR                                        {variableType[$2] = INT_TYPE; declarationHandler($2,0,INT_TYPE,"0",0,0,_MOV,yylineno);}
  |FLOAT VAR                                      {variableType[$2] = FLOAT_TYPE; declarationHandler($2,0,FLOAT_TYPE,"0",0,0,_MOV,yylineno);}
  |CHAR VAR                                       {variableType[$2] = CHAR_TYPE; declarationHandler($2,0,CHAR_TYPE,"0",0,0,_MOV,yylineno);}
  |BOOL VAR                                       {variableType[$2] = BOOL_TYPE; declarationHandler($2,0,BOOL_TYPE,"0",0,0,_MOV,yylineno);}
  ;

assignment:
		VAR '=' expr 													       	{getChosenType(variableType[$1],$3.type); variableAssignment($1,$3.val);}
	;


expr:
  INTEGER      { $$.type = INT_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());  printTripleOperandOperation(_MOV,$1,$$.val);/* mov int register*/} 
  | DECIMAL    { $$.type = FLOAT_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_MOV,$1,$$.val);/* mov dec register*/}
  | CHARACTER  { $$.type = CHAR_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_MOV,$1,$$.val);/*mov char register*/}
  | VAR           {$$.type = variableType[$1]; string registerNumber = "R" + toString<int>(curRegID++);
                    strcpy($$.val,registerNumber.c_str()); 
                    /*check if defined before*/
                     definedBefore($1);
                     printTripleOperandOperation(_MOV,$1,$$.val);/*mov var register*/
                  } 
  | BOOL_TRUE           {$$.type = BOOL_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_MOV,"1",$$.val);/* mov 1 register*/}
  | BOOL_FALSE          {$$.type = BOOL_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_MOV,"0",$$.val);/* mov 0 register*/}
  | '-' expr %prec UMINUS {$$.type = $2.type; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_NEG,$2.val,$$.val);}
  | expr '+' expr { $$.type = getChosenType($1.type,$3.type);  string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_ADD,$1.val,$3.val,$$.val);/*add source1 source2 destination*/}
  | expr '-' expr { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_SUB,$1.val,$3.val,$$.val);/*sub source1 source2 destination*/}
  | expr '*' expr { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_MUL,$1.val,$3.val,$$.val);/*mul source1 source2 destination*/}
  | expr '/' expr { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_DIV,$1.val,$3.val,$$.val);/*div source1 source2 destination*/}
  | expr LT expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_LTN,$1.val,$3.val,$$.val);/*lt source1 source2 destination*/}
  | expr GT expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_GTN,$1.val,$3.val,$$.val);/*gt source1 source2 destination*/}
  | expr GE expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_GTE,$1.val,$3.val,$$.val);/*ge source1 source2 destination*/}
  | expr LE expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_LTE,$1.val,$3.val,$$.val);/*le source1 source2 destination*/}
  | expr NE expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_NEQ,$1.val,$3.val,$$.val);/*ne source1 source2 destination*/}
  | expr EQ expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_EQU,$1.val,$3.val,$$.val);/*eq source1 source2 destination*/}
  | NOT expr      { $$.type = $2.type; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_NOT,$2.val,$$.val); /*not source destination*/}
  | expr AND expr { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_AND,$1.val,$3.val,$$.val);/*and source1 source2 destination*/}
  | expr OR expr  { $$.type = getChosenType($1.type,$3.type); string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printQuadOperandOperation(_OR,$1.val,$3.val,$$.val);/*or source1 source2 destination*/}
  | '(' expr ')'  { $$.type = $2.type; string registerNumber = "R" + toString<int>(curRegID++);strcpy($$.val,registerNumber.c_str());printTripleOperandOperation(_MOV,$2.val,$$.val);/* mov register register*/}
  ;

loop:
  forKeyword for_leftPart for_condition for_rightPart stmt  {
                                                            printJump(unconditionalLabels.top()); 
                                                            unconditionalLabels.pop();                                                                                           
                                                            printLabel(conditionalLabels.top());
                                                            conditionalLabels.pop();
                                                            symbolTable[scopeID--].clear();                                      
                                                            }
  |while stmt                                               {printJump(unconditionalLabels.top()); unconditionalLabels.pop(); printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();}
  | doKeyword stmt WHILE expr ';'                    {printJumpTrue(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();}
  ;
 

forKeyword:
FOR                                                 {  map<string,entry>temp; symbolTable.push_back(temp); ++scopeID;}
;
for_leftPart:
  '(' assignment                                    {printLabel(++labelID); unconditionalLabels.push(labelID);}
  |'(' declaration                                  {printLabel(++labelID); unconditionalLabels.push(labelID);}
  ;

for_condition:
  ';' expr                                          {printJumpFalse(++labelID); conditionalLabels.push(labelID);}
  ;

for_rightPart:
  ';' assignment ')'                                {}
  ;

whileKeyword:
WHILE                                               {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); unconditionalLabels.push(labelID);}
;
while:
  whileKeyword '(' expr ')'                         {printJumpFalse(++labelID); conditionalLabels.push(labelID);}
  ;

doKeyword:
DO                                                  {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); conditionalLabels.push(labelID);}
;

condition:
   if_statement stmt %prec IFX                      {printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();}
  |ifelse_statement                                 {printLabel(unconditionalLabels.top()); unconditionalLabels.pop(); symbolTable[scopeID--].clear();}
  | switch_statement                                 {}
  ;
if_statement:
  ifKeyword '(' expr ')'                            {printJumpFalse(++labelID); conditionalLabels.push(labelID);}
  ;
ifKeyword: 
IF                                                  {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; }
;                                        
ifelse_statement:
  if_statement stmt  else_block                     {}
  ;
else_block:
  elseKeyword stmt                                  {}
  ;

elseKeyword:
  ELSE                                              {
                                                    printJump(++labelID);
                                                    unconditionalLabels.push(labelID);
                                                    printLabel(conditionalLabels.top()); conditionalLabels.pop();
                                                    map<string,entry>temp; symbolTable.push_back(temp); ++scopeID;

                                                    }
  ;

switch_statement:
   switch_expr open_brace  case_list  default_stmt closed_brace  {lastRegisterHaslastSwitchExpr.pop(); printLabel(unconditionalLabelsSwitch.top()); unconditionalLabelsSwitch.pop(); symbolTable[scopeID--].clear(); }
  | switch_expr open_brace  case_list closed_brace               {lastRegisterHaslastSwitchExpr.pop(); printLabel(unconditionalLabelsSwitch.top()); unconditionalLabelsSwitch.pop(); symbolTable[scopeID--].clear(); }
  ;

switch_expr:
  switchKeyword '(' expr ')'                                     {lastRegisterHaslastSwitchExpr.push(curRegID - 1);}
 ;

switchKeyword:
  SWITCH                                                         {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; unconditionalLabelsSwitch.push(++labelID);}
  ;

case_list:
    case_list case_stmt                                          {}
  | case_stmt                                                    {}
  ;

case_stmt:
    case_condition collection_stmt BREAK ';'            {printJump(unconditionalLabelsSwitch.top()); printLabel(conditionalLabels.top()); conditionalLabels.pop(); }
    | case_condition  BREAK ';'                         {printJump(unconditionalLabelsSwitch.top()); printLabel(conditionalLabels.top()); conditionalLabels.pop(); }
    ;

case_condition:
    CASE INTEGER ':'                                    {
                                                            AssemblyFile << _MOV << " 	" << $2 << " 	R" << curRegID << endl;                                                          
                                                            AssemblyFile << _EQU << "     R" << lastRegisterHaslastSwitchExpr.top() << " 	R" << curRegID << " 	R" << ++curRegID << endl;   
                                                            printJumpFalse(++labelID);
                                                            conditionalLabels.push(labelID);

                                                        }
    ;

default_stmt: 
  DEFAULT ':' collection_stmt BREAK ';'                                {printJump(unconditionalLabelsSwitch.top()); }
  |DEFAULT ':' BREAK ';'                                               {printJump(unconditionalLabelsSwitch.top()); }
  ;




%%

void yyerror(char *s) {
  printf("%s at line: %d\n", s,yylineno);
  codeProblemsFile << s << " at line " << yylineno << endl;
}

void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber){
      
        //check if re-declaration
        if(findVariable(variableName) != -1) {
             printfRedeclarationError(variableName);
            unsuccessfulCompilation=1;          
        }
        else{
          printTripleOperandOperation(operationtype,value,variableName);
           symbolTable[scopeID][variableName]= entry(isconst,datatype,value,isinitialized,isused,linenumber);
           unusedVariables.insert(variableName); 
           entry& e =symbolTable[scopeID][variableName];
           e.display(variableName);  
        }
        return;
}

void definedBefore(char* variableName){

      //check if defined before or not
     int idx=findVariable(variableName);
     
     if(idx==-1){
           printNotdefinedError(variableName);
           unsuccessfulCompilation=1;
     }
     else {
           entry& e = symbolTable[idx][variableName];
            if(e.isInitialized==0){
              printUninitializedWarning(variableName);
            }
            if(e.isUsed != 1){
              e.isUsed=1;
              e.display(variableName);
            }
            unusedVariables.erase(variableName);

     }

    return;


}
int findVariable(char * variableName){

 
    int currentScopeID = scopeID;
    
     for(int i=currentScopeID;i>=0;--i){
       
       if(symbolTable[i].find(variableName)!=symbolTable[i].end()){
         //l2eto
         
        return i;
       }
     }
     return -1;
}

int getChosenType(int t1, int t2) {

    if(t1 != t2){
        printIncompatibleTypeWarning();
    }
    if(t1 == FLOAT_TYPE || t2 == FLOAT_TYPE) {
      return FLOAT_TYPE;
    }else if(t1 == INT_TYPE || t2 == INT_TYPE) {
      return INT_TYPE;
    }else if(t1 == CHAR_TYPE || t2 == CHAR_TYPE){
      return CHAR_TYPE;
    }else {
      return t1;
    }

}



void variableAssignment(char* variableName,char* assignedValue){
     

 int idx=findVariable(variableName);
   if(idx==-1){
    printNotdefinedError(variableName);
    unsuccessfulCompilation=1;
   }
   else {
     entry& e= symbolTable[idx][variableName];
     if(e.isConst){

        printConstError(variableName);
        unsuccessfulCompilation=1;
     }
     else {
       if(e.isInitialized != 1) {
          
          e.isInitialized=1; 
          e.display(variableName);
       }
       printTripleOperandOperation(_MOV,assignedValue,variableName);

     }
   }
  return;
}




















void printJump(int labelNumber){
  AssemblyFile<<"JMP \tLabel"<<labelNumber<<"\n";
}

void printJumpFalse(int labelNumber){
  AssemblyFile<<"JMF \tLabel"<<labelNumber<<"\n";
}
void printJumpTrue(int labelNumber){
  AssemblyFile<<"JMT \tLabel"<<labelNumber<<"\n";
}

void printLabel(int labelNumber){
  AssemblyFile<<"Label"<<labelNumber<<":\n";
}

void beforeExit() {

    for (auto i : unusedVariables) {

        codeProblemsFile << "Warning: Variable " << i << " is not used.\n";
  

    }

    for (auto i : uniqueProblems) {
        codeProblemsFile << i;
    }

    if(!unsuccessfulCompilation){
      codeProblemsFile << "Compiled Successfully." << endl;
    }else {
      codeProblemsFile << "Compilation Error." << endl;
    }

}

void printConstError(char*variableName){
   string s="";
   s+=variableName;
   s+=" is constant and cannot be changed at line ";
   s+=toString<int>(yylineno);
   codeProblemsFile << s << endl;
  return;
}
void printNotdefinedError(char*variableName){
         string s="";
          s+= variableName; 
          s+= "  is not defined ";
          s+="at line ";
          s+=toString<int>(yylineno)+"\n";
          codeProblemsFile<<s;
           return;
          
}
void printUninitializedWarning(char* variableName){
        string s = "WARNING: variable ";
        s += variableName;
        s += " is not initialized ";
        s += "at line ";
        s += toString<int>(yylineno);
        s += "\n";
        codeProblemsFile << s;
        return;
}

void printIncompatibleTypeWarning() {

  string s = "Warning: Incompatible types at line: ";
  s += toString<int>(yylineno);
  s += "\n";
  uniqueProblems.insert(s);
  return;

}

void printfRedeclarationError(char* variableName){
    string redeclarationError="";
    redeclarationError+="multible definintions of variable: ";
    redeclarationError+=variableName;
    redeclarationError+=" at line: ";
    redeclarationError+=toString<int>(yylineno);
    redeclarationError+="\n";
    codeProblemsFile<<redeclarationError;
    return;
}


 void printTripleOperandOperation(string operationtype,string source,char* destination){


AssemblyFile<<operationtype<<" \t"<<source<<" \t"<<destination<<"\n";
return;
}
void printQuadOperandOperation(string operationtype,string source1,string source2,char* destination){

 AssemblyFile<<operationtype<<" \t"<<source1<<" \t"<<source2<<" \t"<<destination<<"\n";
 return;
}
template <typename T>
string toString(T x){
  stringstream ss;
  ss<<x;
  string ret;
  ss>>ret;
  return ret;
}
void symboTableFileInit(){
  symbolTableFile<<"Variable Name\t\tIsConst\t\tDatatype\t\tVariable Value\t\tIsInitialized\t\tIsUsed\t\tLine Number\n";
}

int main(void) {
  AssemblyFile.open("ASM.txt");
  codeProblemsFile.open("CodeProblems.txt");
  symbolTableFile.open("SymbolTable.txt");
  symboTableFileInit();
  yyparse();
  return 0;
}