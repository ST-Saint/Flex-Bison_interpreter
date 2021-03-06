%{
//#define YYDEBUG 1
//#define YYERROR_VERBOSE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"	
#include "decl_list.h"
#include "arg_list.h"			//argument list
#include "scope.h"			//scope
#include "type.h"  			
#include "symtab.h"			//symbol table
#include "semantics.h"			//semantic

int num_add_to_sytb = 1;
void add_decl_to_symtab(symtab_type class, type_struct *type, location_e location);

/* Declaration list head node (linked list) */
decl_elem *head = NULL, *data;

/* A single symbol table */
symtable *st;

/* Symbol table entry */
st_node_t *st_node;

/* Function/Procedure argument list head node (linked list) */
arg_elem *arg_head = NULL;

char *calling_func_name;

/* Symbol table stack */
scope_elem *symtable_stack;

int num_of_args;
int stack_offset;

int yylex();				//error handling
void yyerror(const char *msg);		//error handling
%}


%union {
  char *sval;
  int ival;
  float rval;
  char *opval;
  tree_t *tval;
  type_struct *type_s;
}

%token <sval> ID
%token <rval> RNUM
%token <ival> INUM

%token ARRAY BBEGIN ELSE END FOR FUNCTION IF INT SEMI COMA COLON LPARENT RPARENT LSBRACK RSBRACK NOT DOT POSITIVE NEGATIVE ELIF
%token OF PROCEDURE MAINPROG FLOAT THEN VAR WHILE PRINT RETURN SIGN IN NOP
%token <opval> ADDOP MULOP RELOP ASSIGNOP

%type <type_s> type
%type <ival> standard_type

%type <tval> compound_statement statement_list statement print_statement
%type <tval> variable procedure_statement if_statement while_statement for_statement
%type <tval> expression_list expression simple_expression
%type <tval> term factor

%start program

%%

program :
            MAINPROG ID SEMI
		{	
		}
            declarations
		{
                scope_push(symtable_stack, st);
		print_symtab(st);	
		}
            subprogram_declarations
		{
		}
            compound_statement
		{	
                stack_offset = calculate_stack_offset(st); 
		}

          ;

declarations:
            declarations type identifier_list SEMI 
			{
				add_decl_to_symtab(VAR_CLASS, $2, ST_LOCAL); 
			}
          | 
          ;


identifier_list:
            ID 
			{
				head = decl_append(head, $1);
			}
           | identifier_list COMA ID
			{				
				head = decl_append(head, $3);
			}
	  ;

type:
            standard_type
			{
				$$ = (type_struct *) calloc(1, sizeof(type_struct)); 
				$$->name = $1;					
			}

	| standard_type LSBRACK INUM RSBRACK
		{
		if ($3 == FLOAT_TYPE)
		 sem_error(ARRAY_NON_INTEGER_BOUNDS);
               $$ = (type_struct *) calloc(1, sizeof(type_struct));
               if ($1 == INTEGER_TYPE)
               	$$->name = ARRAY_TYPE_INT;
               else if ($1 == FLOAT_TYPE)
               	$$->name = ARRAY_TYPE_REAL;
               $$->lb = 1;	//low bound = 1
               $$->ub = $3;	//upper bound = inum
		}
          ;

standard_type:
            INT
		{
			$$ = INTEGER_TYPE;	
		}
          | FLOAT
		{
			$$ = FLOAT_TYPE;
		}
          ;

subprogram_declarations:
            subprogram_declaration subprogram_declarations
          | 
          ;

subprogram_declaration:
            subprogram_head declarations compound_statement
		{
               /* Calculate a function's stack offset */
               stack_offset = calculate_stack_offset(st);
               /* Make sure the function var was assigned if class is function_type
                  The procedure case might not fire because there should be a
                  type mismatch when trying to assign a value to the proc's id */
               if (calling_func_name != NULL) {
                 st_node = search_scope_stack(symtable_stack, calling_func_name);
                 if (st_node->class == FUNCTION_CLASS && st->has_return != 1 && st->name != NULL)
                   sem_error(NO_RETURN_STMT);
                 else if (st_node->class == PROCEDURE_CLASS && st->has_return == 1)
                   sem_error(NON_LOCAL_MODIFICATION);
		/* Pop current scope */
               st = scope_pop(symtable_stack);
		/* Pop parent scope so it's available again */
               st = scope_pop(symtable_stack);
               }
		}
          ;

subprogram_head:
            FUNCTION ID
		{
               type_struct *t = calloc(1, sizeof(type_struct));

               /* st->entries increases to keep track of the variable's
                  index in the symbol table (st).  Used for gencode identifier lookups */
               (st->entries)++;
               symtab_insert(st, $2, FUNCTION_CLASS, t, ST_LOCAL, st->entries);

               // push parent with function name added to it
               scope_push(symtable_stack, st);
               st = calloc(1, sizeof(symtable));
               /* reset to 0 because a new symbol table has its own set of offsets
                  for local declarations */
               st->entries = 0;

               // set encountered func as calling func name
               calling_func_name = $2;

               // reset arg counter and argument list
               num_of_args = 0;
               arg_head = NULL;
		}
 	     arguments COLON standard_type SEMI
		{
 		// set symtab name as the function name
               st->name = calling_func_name;

               // create arg_type_list for the parent symbol table
               st_node = search_scope_stack(symtable_stack, $2);
               st_node->arg_type_list = arg_head;
               st_node->type->name = $6;
               st_node->num_of_args = num_of_args;

               // push symtab so it can be searched in the function
               scope_push(symtable_stack, st);
		}
          | PROCEDURE ID
		{
               type_struct *t = calloc(1, sizeof(type_struct));

               (st->entries)++;
               symtab_insert(st, $2, PROCEDURE_CLASS, t, ST_LOCAL, st->entries);

               // push parent with procedure name added to it
               scope_push(symtable_stack, st);
               st = calloc(1, sizeof(symtable));
               st->entries = 0;

               // set func as calling func name
               calling_func_name = $2;

               // reset arg counter and argument list
               num_of_args = 0;
               //arg_destroy(arg_head);
               arg_head = NULL;
		}
	    arguments SEMI
		{
  		// set symtab name as the procedure name
               st->name = calling_func_name;

               // create arg_type_list for the parent symbol table
               st_node = search_scope_stack(symtable_stack, $2);
               st_node->arg_type_list = arg_head;
               st_node->num_of_args = num_of_args;

               // push symtab so it can be searched in the function
               scope_push(symtable_stack, st);
		}
          ;

arguments:
            LPARENT parameter_list RPARENT
          | //epsilon
          ;

parameter_list:
            identifier_list COLON type
		{
               add_decl_to_symtab(VAR_CLASS, $3, ST_PARAMETER);
		
		}
          | identifier_list COLON type SEMI parameter_list
		{
               //add_decl_to_symtab(VAR_CLASS, $3, ST_PARAMETER);
		}
          ;

compound_statement:
            BBEGIN statement_list END
		{
		$$ = mktree(BEGIN_END, 1, $2);
		}

          ;

statement_list:
			statement
		{
			$$=$1;
		}
		  | statement SEMI statement_list
		{
			$$ = mktree(STMT_LIST, 2, $3, $1);
		}
		  ;

statement:
		variable ASSIGNOP expression
		{
			//type checking
			fprintf(stderr, "type comparison : %d (compare) %d\n",type_check($1),type_check($3));
	               	if (type_check($1) != type_check($3)) {
			sem_error(TYPE_MISMATCH_ASSN);
			}            
			$$ = mktree(ASSIGN_STMT, 2, $1, $3);
			printf("assign success\n");
		}
		  | print_statement
			{}
		  | procedure_statement
			{}
		  | compound_statement
			{}
		  | RETURN expression
			{ st->has_return = 1;}	

		  | if_statement
			{}
		  | while_statement
			{}
		  | for_statement
			{}
  		  | {}

		 
		  ;


print_statement:
			PRINT
			{}
		  | PRINT LPARENT expression RPARENT
			{}
		  ;

variable:
			ID
{
               st_node = search_scope_stack(symtable_stack, $1);	//Search Stack
               if (st_node == NULL) { sem_error(VAR_UNDECLARED); }	//None - Error
             

               $$ = mktree(IDENT, 0);
               $$->attr.sval = st_node;
}
		  | ID LSBRACK expression RSBRACK
			{
				st_node = search_scope_stack(symtable_stack, $1);
				if (st_node == NULL) { sem_error(VAR_UNDECLARED); }
				array_semantics(st_node, $3);

				$$ = mktree(ID_ARRAY, 1, $3);
				$$->attr.sval = st_node;
			}
		  ;

procedure_statement:
			ID LPARENT actual_parameter_expression RPARENT
				{}
		  ;
if_statement:
			IF expression COLON statement 
				{}
			ELIF expression COLON statement
				{}
			ELSE COLON statement
				{}
		  ;

while_statement: 
			WHILE expression COLON statement
				{}
			ELSE COLON statement
				{}
		  ;
for_statement:
			FOR expression IN expression COLON statement
			{}
			ELSE COLON statement
		  ;

actual_parameter_expression:
			//epsilon
		  | expression_list

		  ;

expression_list:
			expression
		  | expression COMA expression_list
		  ;

expression:
		simple_expression
		{
			$$= $1;
		}
		  | simple_expression RELOP simple_expression
		  ;

simple_expression:
            term
		{
			$$=$1;
		}
          | term ADDOP simple_expression
	  ;
term:
            factor
		{
			$$=$1;
		}
          | factor MULOP term
		{
			$$ = mktree(MULOP_EXPR, 2, $3, $1);
			$$->attr.opval = $2;
		}

          ;

factor:
            INT
		{}
          | FLOAT
		{}
          | variable
		{$$ = $1;}
          | procedure_statement
		{function_semantics(st_node,yyval.tval);}
          | NOT factor
                { $$ = mktree(NOT_FACTOR, 1, $2); }
          | SIGN factor
		{ $$ = mktree(SIGN_TERM, 1,$2); }
	  | INUM
		{
		printf("int number : %d\n",$1);	
		$$ = mktree(INUMBER,0);
		$$->attr.ival = $1;
		printf("int number accept success - %d\n",$1);			
		}
	  | RNUM
		{
		printf("real number : %f\n",$1);
		$$ = mktree(RNUMBER,0);
		$$->attr.rval = $1;
		printf("real number accept success - %f\n",$1);			
		}
          ;

%%

void add_decl_to_symtab(symtab_type class, type_struct *type, location_e location) {
  data = head;
  if (data != NULL) {
    do {
      if (location == ST_PARAMETER) {
        num_of_args++;
        arg_head = arg_append(arg_head, type->name);
      }

	fprintf(stderr,"calling func name: %s\n",calling_func_name);
      (st->entries)++;
      symtab_insert(st, data->name, class, type, location, st->entries);
	fprintf(stderr,"PARAM_LIST,NAME: %s, type: %d\n\n",data->name, type->name);

      data = data->next;
    }
    while (data != head);

    decl_destroy(head);
    decl_destroy(data);
    head = NULL;
  }
  else
    fprintf(stderr, "data is null\n");

}

int main() {
  symtable_stack = scope_init(10);
  st = calloc(1, sizeof(symtable));
  st->entries = 0;
 

  yyparse();
  printf("\n");
}

