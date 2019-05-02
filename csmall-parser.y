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

typedef enum { typeVariable, typeCodeValue, typeOperation } NodeType;
typedef enum { intData, floatData, charData, boolData } DataType;

struct node{
	NodeType nodeType;
	int opType;
	DataType dataType;
	bool openScope;
	
	int intValue;      // used for codeValues only, not variables
	float floatValue;  // used for codeValues only, not variables
	char charValue;    // used for codeValues only, not variables
	bool boolValue;    // used for codeValues only, not variables

	char* variableName;

	vector<node*> operands;

};


extern int yylineno;
int curRegID = 0;
map<string,node> symbolTable;

/* prototypes */
int yylex(void);
node* opr(int operationId, vector<node*> operands);
node* id(char* val);
node* con(char* val, DataType dtype);
int ex(node *p);
void yyerror(char *s);


%}

%union {
  char* val; 
  char* name;      
  struct node *nPtr; /* node pointer */
};


%token <val> INTEGER DECIMAL CHARACTER
%token <name> VAR
%token CONST INT FLOAT CHAR BOOL 
%token OPENBRACE CLOSEDBRACE OPENPAR CLOSEDPAR OPENSQB CLOSESQB SEMICOL
%token ENDOFFILE
%token PLUS MINUS MULTIPLY DIVIDE GE LE GT LT EQ NE NOT AND OR 
%token BOOL_TRUE BOOL_FALSE

%left AND OR
%left GE LE EQ NE GT LT
%left PLUS MINUS
%left MULTIPLY DIVIDE

%right NOT
%nonassoc UMINUS

%type <nPtr> program collection_stmt stmt declaration assignment expr 


%start program

%%
program:
		collection_stmt        														{}
	|	ENDOFFILE																        	{exit(0);}
	;

collection_stmt:
    collection_stmt stmt                              {}
  | stmt                                              {}
  ;

stmt:
   	SEMICOL																	         	{}
	|	declaration	SEMICOL															  {}
	|	assignment SEMICOL															  {}
  ;

declaration:
   CONST INT VAR '=' expr                         {}
  |CONST FLOAT VAR '=' expr                       {}
  |CONST CHAR VAR '=' CHARACTER                   {}
  |CONST BOOL VAR '=' expr                        {}
  |INT VAR '=' expr                               {}
  |FLOAT VAR '=' expr                             {}
  |CHAR VAR '=' expr                              {}
  |BOOL VAR '=' expr                              {}
  |INT VAR                                        {}
  |FLOAT VAR                                      {}
  |CHAR VAR                                       {}
  |BOOL VAR                                       {}
  ;

assignment:
		VAR '=' expr 														{}
	;


expr:
  INTEGER      {}
  | DECIMAL    {}
  | CHARACTER  {}
  | VAR        {}
  | BOOL_TRUE  {}
  | BOOL_FALSE {}
  | MINUS expr %prec UMINUS {}
  | expr PLUS expr          {}
  | expr MINUS expr         {}
  | expr MULTIPLY expr      {}
  | expr DIVIDE expr        {}
  | expr LT expr  {}
  | expr GT expr  {}
  | expr GE expr  {}
  | expr LE expr  {}
  | expr NE expr  {}
  | expr EQ expr  {}
  | OPENPAR expr CLOSEDPAR  {}
  ;


%%

void yyerror(char *s) {
  printf("%s\n", s);
}

node* opr(int operationId, vector<node*> operands){
	node* p = new node();
	p->nodeType = typeOperation;
	p->opType = operationId;
	p->operands = operands;
	p->openScope = 0;
	return p;
}

node* id(char* val){
	node* p = new node();
	p->nodeType = typeVariable;
	p->variableName = val;
	p->openScope = 0;
	return p;
}

node* con(char* val, DataType dtype) {

  node* p = new node();
  p->nodeType = typeCodeValue;
  p->variableName = val;
  p->openScope = 0;
  p->dataType = dtype;
  return p;
}


//static int lbl;
//int ex(node *p) {
//    int lbl1, lbl2;
//    if (!p) return 0;
//    switch(p->type) {
//    case typeCon:
//          printf("\tpush\t%d\n", p->con.value);
//          break;
//    case typeId:
//          printf("\tpush\t%c\n", p->id.i + 'a');
//          break;
//    case typeOpr:
//          switch(p->opr.oper) {
//                case WHILE:
//                    printf("L%03d:\n", lbl1 = lbl++);
//                    ex(p->opr.op[0]);
//                    printf("\tjz\tL%03d\n", lbl2 = lbl++);
//                    ex(p->opr.op[1]);
//                    printf("\tjmp\tL%03d\n", lbl1);
//                    printf("L%03d:\n", lbl2);
//                    break;
//                case IF:
//                    ex(p->opr.op[0]);
//                    if (p->opr.nops > 2) {
//                    /* if else */
//                    printf("\tjz\tL%03d\n", lbl1 = lbl++);
//                    ex(p->opr.op[1]);
//                    printf("\tjmp\tL%03d\n", lbl2 = lbl++);
//                    printf("L%03d:\n", lbl1);
//                    ex(p->opr.op[2]);
//                    printf("L%03d:\n", lbl2);
//                    } else {
//                    /* if */
//                    printf("\tjz\tL%03d\n", lbl1 = lbl++);
//                    ex(p->opr.op[1]);
//                    printf("L%03d:\n", lbl1);
//                    }
//                    break;
//                case PRINT:
//                    ex(p->opr.op[0]);
//                    printf("\tprint\n");
//                    break;
//                case '=':
//                    ex(p->opr.op[1]);
//                    printf("\tpop\t%c\n", p->opr.op[0]->id.i + 'a');
//                    break;
//                case UMINUS:
//                    ex(p->opr.op[0]);
//                    printf("\tneg\n");
//                    break;
//                default:
//                    ex(p->opr.op[0]);
//                    ex(p->opr.op[1]);
//                switch(p->opr.oper) {
//                    case '+': printf("\tadd\n"); break;
//                    case '-': printf("\tsub\n"); break;
//                    case '*': printf("\tmul\n"); break;
//                    case '/': printf("\tdiv\n"); break;
//                    case '<': printf("\tcompLT\n"); break;
//                    case '>': printf("\tcompGT\n"); break;
//                    case GE: printf("\tcompGE\n"); break;
//                    case LE: printf("\tcompLE\n"); break;
//                    case NE: printf("\tcompNE\n"); break;
//                    case EQ: printf("\tcompEQ\n"); break;
//                  }
//          }
//    }
//  return 0;
//}


int main(void) {
  yyparse();
  return 0;
}
