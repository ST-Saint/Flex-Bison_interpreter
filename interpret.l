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
"mainprog"|"MAINPROG"		{ return MAINPROG; }
"var"|"VAR"			{ return VAR; }
"of"|"OF"			{ return OF;}
"nop"|"NOP"			{ return NOP;}
"function"|"FUNCTION"		{ return FUNCTION; }
"procedure"|"PROCEDURE"		{ return PROCEDURE; }
"begin"|"BEGIN"			{ return BBEGIN; }
"end"|"END"			{ return END; }
"if"|"IF"			{ return IF; }
"then"|"THEN"			{ return THEN; }
"elif"|"ELIF"			{ return ELIF; }
"else"|"ELSE"			{ return ELSE; }
"while"|"WHILE"			{ return WHILE; }
"for"|"FOR"			{ return FOR; }
"in"|"IN"			{ return IN;}
"array"|"ARRAY"			{ return ARRAY; }
"float"|"FLOAT"			{ return FLOAT; }
"int"|"INT"			{ return INT; }
"return"|"RETURN"		{ return RETURN; }
"="				{ return ASSIGNOP; }
"print"|"PRINT"			{ return PRINT;	}
";"				{ return SEMI; }
","				{ return COMA; }
":"				{ return COLON; }
"("				{ return LPARENT;}
")"				{ return RPARENT;}
"["				{ return LSBRACK;}
"]"				{ return RSBRACK;}
"!"				{ return NOT; }
"."				{ return DOT; }

{addop}			{ yylval.opval = strdup(yytext); return ADDOP; }	
{mulop}			{ yylval.opval = strdup(yytext); return MULOP; } 
{relop}			{ yylval.opval = strdup(yytext); return RELOP; }
{id}			{ yylval.sval = strdup(yytext); return ID; }
{rnum}			{ yylval.rval = atof(yytext); return RNUM; }	
{inum}			{ yylval.ival = atoi(yytext); return INUM; }	
	
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



