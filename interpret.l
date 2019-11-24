%{
  //definition section
#include <stdio.h>
#include "tree.h"
#include "type.h" //symtab_type type
#include "interpret.tab.h"  //interpret.y에서 정의된 토큰 가져옴.
%}

letter			[a-zA-Z]
digit			[0-9]
id			{letter}({letter}|{digit})*

digits			{digit}{digit}*
fraction		("."{digits})
rnum			{digits}{fraction}
inum			{digits}
whitespace		[ \t]

relop			(">"|">="|"<"|"<="|"=="|"<>"|"in")
addop			("+"|"-")
mulop			("*"|"/")

%%
"mainprog"|"MAINPROG"		{printf("MAINPROG\n"); return MAINPROG; }
"var"|"VAR"			{printf("VAR\n"); return VAR; }
"of"|"OF"			{printf("OF\n"); return OF;}
"nop"|"NOP"			{printf("NOP\n"); return NOP;}
"function"|"FUNCTION"		{printf("FUNCTION\n"); return FUNCTION; }
"procedure"|"PROCEDURE"		{printf("PROCEDURE\n"); return PROCEDURE; }
"begin"|"BEGIN"			{printf("BEGIN\n"); return BBEGIN; }
"end"|"END"			{printf("END\n"); return END; }
"if"|"IF"			{printf("IF\n"); return IF; }
"then"|"THEN"			{printf("THEN\n"); return THEN; }
"elif"|"ELIF"			{printf("ELIF\n"); return ELIF; }
"else"|"ELSE"			{printf("ELSE\n"); return ELSE; }
"while"|"WHILE"			{printf("WHILE\n"); return WHILE; }
"for"|"FOR"			{printf("FOR\n"); return FOR; }
"in"|"IN"			{printf("IN\n"); return IN;}
"array"|"ARRAY"			{printf("ARRAY\n"); return ARRAY; }
"float"|"FLOAT"			{printf("FLOAT\n"); return FLOAT; }
"int"|"INT"			{printf("INT\n"); return INT; }
"return"|"RETURN"		{printf("RETURN\n"); return RETURN; }
"="				{printf("ASSIGNOP\n"); return ASSIGNOP; }
"print"|"PRINT"			{printf("PRINT\n"); return PRINT;	}
";"				{printf("SEMI\n"); return SEMI; }
","				{printf("COMA\n"); return COMA; }
":"				{printf("COLON\n"); return COLON; }
"("				{printf("LPARENT\n"); return LPARENT;}
")"				{printf("RPARENT\n"); return RPARENT;}
"["				{printf("LSBRACK\n"); return LSBRACK;}
"]"				{printf("RSBRACK\n"); return RSBRACK;}
"!"				{printf("NOT\n"); return NOT; }
"."				{printf("DOT\n"); return DOT; }

{addop}			{ yylval.opval = strdup(yytext);printf("ADDOP\n"); return ADDOP; }	
{mulop}			{ yylval.opval = strdup(yytext);printf("MULOP\n"); return MULOP; } 
{relop}			{ yylval.opval = strdup(yytext);printf("RELOP\n"); return RELOP; }
{id}			{ yylval.sval = strdup(yytext);printf("ID\n"); return ID; }
{rnum}			{ yylval.rval = atof(yytext);printf("RNUM\n"); return RNUM; }	
{inum}			{ yylval.ival = atoi(yytext);printf("INUM\n"); return INUM; }	
	
{whitespace}	        { }                    				

"//".*			{ }						
"/*"               	{ int c;
                   	   while (c = input()) {
                  	      if (c == '*')
                        	  if ((c = input()) == '/')
                        	    break;
                       		  else
	                            unput(c);
        	           } }

\n			{ } 					
.			{ }
%%

void yyerror(char *msg) {
  fprintf(stderr, "error [line: %d]: %s at %s\n", yylineno, msg, yytext);
  exit(1);
}



