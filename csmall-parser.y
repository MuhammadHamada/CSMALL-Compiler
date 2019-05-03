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

enum dataType {
  UNDEFINED,
  INT_TYPE,
  FLOAT_TYPE,
  CHAR_TYPE
};

struct entry{
	bool isConst;
	dataType type;
	string val;
	bool isInitialized;
	bool isUsed;
	int line;
	
	entry(bool isConst = 0, dataType type = UNDEFINED, string val = "", bool isInitialized = 0, bool isUsed = 0, int line = 0) 
		: isConst(isConst), type(type), val(val), isInitialized(isInitialized), isUsed(isUsed), line(line) {}
};

extern int yylineno;
int curRegID = 0,scopeID = 0;

/* prototypes */
int yylex(void);
void yyerror(char *s);


%}

%union {
  char* val; 
  char* name;      
  struct info{		
		int type;
		char val[100];		
	};
};


%token <val> INTEGER DECIMAL CHARACTER
%token <name> VAR
%token CONST INT FLOAT CHAR BOOL 
%token ENDOFFILE
%token GE LE GT LT EQ NE NOT AND OR 
%token WHILE FOR DO IF ELSE
%token BOOL_TRUE BOOL_FALSE


%left AND OR
%left GE LE EQ NE GT LT

%left '+' '-'
%left '*' '/'

%right NOT
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%type <name> declaration
%type <info> expr 


%start program

%%
program: 
	function                                                                        {exit(0);}
	;
function:
		function stmt          											    {}
	|	ENDOFFILE																	      {}
	|
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
  | open_brace collection_stmt closed_brace       {/* check */}
  | open_brace closed_brace
  ;

open_brace:
            '{'                                   {}
             ;

closed_brace:
             '}'                                  {}
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
  | '-' expr %prec UMINUS {}
  | expr '+' expr          {}
  | expr '-' expr         {}
  | expr '*' expr      {}
  | expr '/' expr        {}
  | expr LT expr  {}
  | expr GT expr  {}
  | expr GE expr  {}
  | expr LE expr  {}
  | expr NE expr  {}
  | expr EQ expr  {}
  | NOT expr
  | expr AND expr
  | expr OR expr
  | '(' expr ')'  {}
  ;

loop:
  FOR for_leftPart for_condition for_rightPart stmt {}
  while stmt                                        {}
  | DO stmt while ';'                               {}
  ;

for_leftPart:
  '(' assignment                                    {}
  |'(' declaration                                  {}
  ;

for_condition:
  ';' expr                                          {}
  ;

for_rightPart:
  ';' assignment ')'                                {}
  ;

while:
  WHILE '(' expr ')'                                {}
  ;

condition:
   if_statement stmt %prec IFX                      {}
  |ifelse_statement                                 {}
  ;

if_statement:
  IF '(' expr ')'                                   {}
  ;

ifelse_statement:
  if_statement stmt ELSE stmt                       {}
  ;


%%

void yyerror(char *s) {
  printf("%s at line: %d\n", s,yylineno);
}


int main(void) {
  yyparse();
  return 0;
}
