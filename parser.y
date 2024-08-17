// Bison File Structure: https://web.mit.edu/gnu/doc/html/bison_6.html

//-- SECTION 1: C declarations -----------------------------

%{

#include <stdio.h>

#include <asm_line.h>
#include <encoder.h>

#define YYDEBUG 1

// defining this symbol makes the generated riscv.exe a self sustained
// application that works without an external driver. It defines all
// symbols to become self-sustained. 
//
// If you would rather not have the symbols
// defined because you are building an external driver, then do not
// define the USE_INTERNAL_DRIVER symbol
//#define USE_INTERNAL_DRIVER 1

//-- Lexer prototype required by bison, aka getNextToken()
int yylex(); 
int yyerror(const char *p) { printf("Error!\n"); return 1; }

#ifdef USE_INTERNAL_DRIVER
    asm_line_t asm_line;
#else
    extern asm_line_t asm_line;
#endif

// https://www.geeksforgeeks.org/function-pointer-in-c/
void (*fp_emit)(asm_line_t*);

%}

//-- SECTION 2: SYMBOL SEMANTIC VALUES -----------------------------

%union {
  int val; 
  char sym;
};

%token <sym> ADD JALR LI
%token <sym> NEW_LINE
%token <sym> IDENTIFIER NUMERIC
%token <sym> SECTION GLOBAL
%token <sym> DOT COLON COMMA
%token <sym> REG_ZERO REG_RA REG_SP REG_GP REG_TP REG_T0 REG_T1 REG_T2 REG_T3 REG_T4 REG_T5 REG_T6 REG_FP REG_A0 REG_A1 REG_A2 REG_A3 REG_A4 REG_A5 REG_A6 REG_A7 REG_S0 REG_S1 REG_S2 REG_S3 REG_S4 REG_S5 REG_S6 REG_S7 REG_S8 REG_S9 REG_S10 REG_S11

//%token <val> NUM
//%token <sym> OPA OPM LP RP STOP
//%type  <val> exp term sfactor factor res

//-- SECTION 3: GRAMMAR RULES ---------------------------------------

%%

/* https://stackoverflow.com/questions/47687247/does-bison-allow-in-its-syntax */

//asm_file: asm_line line_end asm_file | asm_line line_end
asm_file: line_end asm_file | asm_line line_end asm_file | asm_line line_end

line_end: NEW_LINE

asm_line: label mnemonic params { print_asm_line(&asm_line); if (fp_emit != NULL) { (*fp_emit)(&asm_line); } }
	|
	mnemonic params { print_asm_line(&asm_line); if (fp_emit != NULL) { (*fp_emit)(&asm_line); } }
	|
	label mnemonic
	|
	mnemonic
    |
    label
    |
    assembler_instruction

params: param COMMA param COMMA param
    | param COMMA param 
    | param

param: expr

label: IDENTIFIER COLON

mnemonic: ADD { asm_line.instruction = I_ADD; } | JALR | LI

register: REG_ZERO { printf("REG_ZERO\n"); insert_register(&asm_line, R_ZERO); }
    | REG_RA { printf("REG_RA\n"); insert_register(&asm_line, R_RA); }
    | REG_SP { printf("REG_SP\n"); insert_register(&asm_line, R_SP); }
    | REG_GP { printf("REG_GP\n"); insert_register(&asm_line, R_GP); }
    | REG_TP { printf("REG_TP\n"); insert_register(&asm_line, R_TP); }
    | REG_T0 { printf("REG_T0\n"); insert_register(&asm_line, R_T0); }
    | REG_T1 { printf("REG_T1\n"); insert_register(&asm_line, R_T1); }
    | REG_T2 { printf("REG_T2\n"); insert_register(&asm_line, R_T2); }
    | REG_T3 { printf("REG_T3\n"); insert_register(&asm_line, R_T3); }
    | REG_T4 { printf("REG_T4\n"); insert_register(&asm_line, R_T4); }
    | REG_T5 { printf("REG_T5\n"); insert_register(&asm_line, R_T5); }
    | REG_T6 { printf("REG_T6\n"); insert_register(&asm_line, R_T6); }
    | REG_FP { printf("REG_FP\n"); insert_register(&asm_line, R_S0); }
    | REG_A0 { printf("REG_A0\n"); insert_register(&asm_line, R_A0); }
    | REG_A1 { printf("REG_A1\n"); insert_register(&asm_line, R_A1); }
    | REG_A2 { printf("REG_A2\n"); insert_register(&asm_line, R_A2); }
    | REG_A3 { printf("REG_A3\n"); insert_register(&asm_line, R_A3); }
    | REG_A4 { printf("REG_A4\n"); insert_register(&asm_line, R_A4); }
    | REG_A5 { printf("REG_A5\n"); insert_register(&asm_line, R_A5); }
    | REG_A6 { printf("REG_A6\n"); insert_register(&asm_line, R_A6); }
    | REG_A7 { printf("REG_A7\n"); insert_register(&asm_line, R_A7); }
    | REG_S0 { printf("REG_S0\n"); insert_register(&asm_line, R_S0); }
    | REG_S1 { printf("REG_S1\n"); insert_register(&asm_line, R_S1); }
    | REG_S2 { printf("REG_S2\n"); insert_register(&asm_line, R_S2); }
    | REG_S3 { printf("REG_S3\n"); insert_register(&asm_line, R_S3); }
    | REG_S4 { printf("REG_S4\n"); insert_register(&asm_line, R_S4); }
    | REG_S5 { printf("REG_S5\n"); insert_register(&asm_line, R_S5); }
    | REG_S6 { printf("REG_S6\n"); insert_register(&asm_line, R_S6); }
    | REG_S7 { printf("REG_S7\n"); insert_register(&asm_line, R_S7); }
    | REG_S8 { printf("REG_S8\n"); insert_register(&asm_line, R_S8); }
    | REG_S9 { printf("REG_S9\n"); insert_register(&asm_line, R_S9); }
    | REG_S10 { printf("REG_S10\n"); insert_register(&asm_line, R_S10); }
    | REG_S11 { printf("REG_S11\n"); insert_register(&asm_line, R_S11); }

expr : NUMERIC | register

assembler_instruction:  
    DOT SECTION section_name
    |
    DOT GLOBAL IDENTIFIER

section_name: DOT IDENTIFIER
    

/*
asm_line: IDENTIFIER COLON ADD NEW_LINE
*/



/*
run: res run | res    // forces bison to process many stmts 

res: exp STOP         { cout << $1 << endl; }

exp: exp OPA term     { $$ = ($2 == '+' ? $1 + $3 : $1 - $3); }
| term                { $$ = $1; }

term: term OPM factor { $$ = ($2 == '*' ? $1 * $3 : $1 / $3); }
| sfactor             { $$ = $1; }

sfactor: OPA factor   { $$ = ($1 == '+' ? $2 : -$2); }
| factor              { $$ = $1; }

factor: NUM           { $$ = $1; }
| LP exp RP           { $$ = $2; }
*/

%%

//-- SECTION 4: FUNCTION DEFINITIONS ---------------------------------


// only define this symbol if there is not external application that uses the parser
#ifdef USE_INTERNAL_DRIVER

extern FILE* yyin;
extern int yy_flex_debug;

/* void emit(asm_line_t* asm_line) {
    printf("emit LUL\n");
} */


int main(int argc, char **argv)
{
    reset_asm_line(&asm_line);

    //fp_emit = &emit;
    fp_emit = &encoder_callback;

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", argv[1]);
    }

    yy_flex_debug = 0;
    yydebug = 0;
    yyparse();

    return 0;
}

#endif