%option yylineno

%{
#include<bits/stdc++.h>
#include <stdlib.h>
#include "y.tab.h"
void yyerror(char *);

%}

printable [\x20-\x7E]

%%


[ \t]+                          ;/* ignore tabs */
"/*"{printable}*"*/"            ;/* Ignore Comments */

"const"							{return CONST;}
"int"							{return INT;}
"float"							{return FLOAT;}
"char"							{return CHAR;}
"bool"							{return BOOL;}


"true"                          {return BOOL_TRUE;}
"false"                         {return BOOL_FALSE;}

"if"                            {return IF;}
"else"                          {return ELSE;}
"for"                           {return FOR;}
"while"                         {return WHILE;}
"do"                            {return DO;}

"{"								{return '{';}
"}"								{return '}';}
"("								{return '(';}
")"								{return ')';}
";"								{return ';';}

"="								{return '=';}
"+"								{return '+';}
"-"								{return '-';}
"*"								{return '*';}
"/"								{return '/';}
">="							{return GE;}
"<="							{return LE;}
">"								{return GT;}
"<"								{return LT;}
"=="							{return EQ;}
"!="							{return NE;}
"!"								{return NOT;}
"&&"							{return AND;}
"||"							{return OR;}

[a-zA-Z_][a-zA-Z_0-9]*			{yylval.val = strdup(yytext); return VAR;}
[+-]?[0-9]+						{yylval.val = strdup(yytext);  return INTEGER;}
[+-]?[0-9]+['.'][0-9]*			{yylval.val = strdup(yytext);  return DECIMAL;}
[\'].[\']						{yylval.val = strdup(yytext);  return CHARACTER;}

<<EOF>>							{return ENDOFFILE;}

. yyerror("Unknown character");
%%

void yyerror (const char * err) {
	printf("Syntax error. Line %d\n", yylineno);
}
int yywrap(void){
	return 1;
}
