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

typedef enum { 
  UNDEFINED_DataType,
  INT_DataType, 
  FLOAT_DataType, 
  CHAR_DataType, 
  BOOL_DataType 
} DataType;

struct node {

	DataType dataType;
	string val;
  bool isConst;
  bool isInitialized;
  bool isUsed;
  int line;

  node(string val = "", DataType dataType = UNDEFINED_DataType, bool isConst = 0, bool isInitialized = 0, bool isUsed = 0, int line = 0):
  val(val),dataType(dataType), isConst(isConst), isInitialized(isInitialized), isUsed(isUsed), line(line) {}

};


extern int yylineno;
int curRegID = 0;
map<string,node> symbolTable;

/* prototypes */
int yylex(void);
void yyerror(char *s);
void printQuadruples(string opreration,vector<string>operands);

%}

%union {
  char* val;
  char* name;
  struct info {		
		int type;
		char val[100];		
	};
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

%type <info> expr
%type <name> declaration


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
  |CONST CHAR VAR '=' CHARACTER                   {
                                                      // new variable to symbol table
                                                      node n($5, CHAR_DataType, 1, 1, 0, yylineno);
                                                      symbolTable[$3] = n;
                                                      for (auto i : symbolTable) {
                                                        printf(i.first.c_str());
                                                        printf("line %d",i.second.line);
                                                      }
                                                      // printing quadruples
                                                      vector<string>operands;
                                                      operands.push_back("R" + to_string(curRegID++));
                                                      operands.push_back($5);
                                                      printQuadruples("MOV",operands);
                                                  }
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

void printQuadruples(string opreration,vector<string>operands) {

    string out = opreration + " ";
    int n = operands.size();
    for (int i = 0; i < n; ++i) {
      out += operands[i];
      if(i != n-1) {
        out += ',';
      }
    }
    out += '\n';
    printf(out.c_str());
}

int main(void) {
  yyparse();
  return 0;
}