// Bison File Structure: https://web.mit.edu/gnu/doc/html/bison_6.html

//-- SECTION 1: C declarations -----------------------------

%{

#include <stdio.h>
//#include <cstring>

#include <asm_line.h>
#include <encoder.h>
#include <common.h>
#include <node.h>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

extern int yylineno;

node_t* current_node = NULL;

// defining this symbol makes the generated riscv emulator or assembler a self sustained
// application that works without an external driver. It defines all
// symbols to become self-sustained.
//
// If you would rather not have the symbols
// defined because you are building an external driver, then do not
// define the USE_INTERNAL_DRIVER symbol
//#define USE_INTERNAL_DRIVER 1

//-- Lexer prototype required by bison, aka getNextToken()
int yylex();
int yyerror(const char *p) { printf("yyerror() - Error! '%s' | Line: %d \n", p, yylineno); return 1; }

#ifdef USE_INTERNAL_DRIVER
    asm_line_t parser_asm_line;
#else
    extern asm_line_t parser_asm_line;
#endif

// https://www.geeksforgeeks.org/function-pointer-in-c/
void (*fp_emit)(asm_line_t*);

%}

//-- SECTION 2: SYMBOL SEMANTIC VALUES -----------------------------

%locations

%union {
    uint64_t int_val;
    char string_val[100];
    char sym;
    node_t* expr_ptr;
};

%token <sym> DOT_EQU DOT_SECTION DOT_GLOBL DOT_GLOBAL DOT_TEXT DOT_DATA DOT_BYTE DOT_HALF DOT_WORD DOT_DWORD DOT_FILE DOT_RODATA DOT_ASCIZ DOT_SKIP DOT_STRING
%token <sym> ADD ADDI AND ANDI AUIPC BEQ BEQZ BGE BLT BGT BNE BNEZ CALL J JR JALR LD LW LH LB LBU LI LUI MUL MV NOP NOT RET SRLI SLLI SD SW SH SB WFI
%token <sym> NEW_LINE
%token <sym> MODIFIER_HI MODIFIER_LO
%token <int_val> NUMERIC
%token <string_val> IDENTIFIER
%token <string_val> STRING_LITERAL
%token <sym> DOT COLON COMMA OPENING_BRACKET CLOSING_BRACKET
%token <sym> REG_ZERO REG_RA REG_SP REG_GP REG_TP REG_T0 REG_T1 REG_T2 REG_T3 REG_T4 REG_T5 REG_T6 REG_FP REG_A0 REG_A1 REG_A2 REG_A3 REG_A4 REG_A5 REG_A6 REG_A7 REG_S0 REG_S1 REG_S2 REG_S3 REG_S4 REG_S5 REG_S6 REG_S7 REG_S8 REG_S9 REG_S10 REG_S11

//%token <val> NUM
//%token <sym> OPA OPM LP RP STOP
//%type  <val> exp term sfactor factor res

%type <expr_ptr> expr; // the expr rule will return a node_t pointer
%type <string_val> label;
%type <string_val> csv_identifier_list;
%type <int_val> csv_numeric_list;
%type <string_val> modifier;

//-- SECTION 3: GRAMMAR RULES ---------------------------------------

%%

/* https://stackoverflow.com/questions/47687247/does-bison-allow-in-its-syntax */

asm_file :
    line_end asm_file
    |
    line_end
    |
    asm_line line_end asm_file
    |
    asm_line line_end
    |
    asm_line

line_end : NEW_LINE

asm_line :
    label mnemonic params {
        //printf("label mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, $1, strlen($1));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
	|
	mnemonic params {
        //printf("mnemonic params\n");
        /*print_asm_line(&parser_asm_line);*/
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno -1);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
	|
	label mnemonic {
        //printf("label mnemonic\n");
        //printf("Line: %d\n", (yylineno -1));

        parser_asm_line.line_nr = (yylineno - 1);

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, $1, strlen($1));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
	|
	mnemonic {
        //printf("mnemonic\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
    |
    assembler_instruction {
        printf("assembler_instruction without label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
    |
    label assembler_instruction {
        printf("assembler_instruction with label\n");
        //printf("Line: %d\n", yylineno);

        parser_asm_line.line_nr = yylineno;

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, $1, strlen($1));

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }
    |
    label {
        //printf("label\n");
        //printf("label Line: %d\n", (yylineno-1));

        memset(parser_asm_line.label, 0, 100);
        memcpy(parser_asm_line.label, $1, strlen($1));

        parser_asm_line.line_nr = (yylineno - 1);

        //printf("Line: %d label: %s \n", parser_asm_line.label, yylineno);
        //printf("Line: %d\n", yylineno);

        if (fp_emit != NULL) { (*fp_emit)(&parser_asm_line); }
    }

modifier :
    MODIFIER_HI OPENING_BRACKET expr CLOSING_BRACKET {
        /*printf("MODIFIER_HI\n");*/
        strncpy($$, "HI", 2);
    }
    |
    MODIFIER_LO OPENING_BRACKET expr CLOSING_BRACKET {
        /*printf("MODIFIER_LO\n");*/
        strncpy($$, "LO", 2);
    }
    ;

params : param_1 COMMA param_2 COMMA param_3 {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
    | param_1 COMMA param_2 COMMA param_3 COMMA {
        //printf("param_1 COMMA param_2 COMMA param_3\n");
    }
    | param_1 COMMA param_2 COMMA {
        //printf("param_1 COMMA param_2\n");
    }
    | param_1 COMMA param_2 {
        //printf("param_1 COMMA param_2\n");
    }
    | param_1 COMMA {
        //printf("param_1\n");
    }
    | param_1 {
        //printf("param_1\n");
    }

param_1 :
    IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET {
        insert_identifier_offset(&parser_asm_line, (char *)$1, 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
    |
    NUMERIC OPENING_BRACKET expr CLOSING_BRACKET {
        insert_offset(&parser_asm_line, $2, 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
    |
    modifier OPENING_BRACKET expr CLOSING_BRACKET {
        printf("modifier 1: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)$1, 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
    |
    modifier {
        printf("modifier 1: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)$1, 0);

        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }
    |
    expr {
        insert_expr(&parser_asm_line, current_node, 0);
        current_node = NULL;
    }

param_2 :
    IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET {
        insert_identifier_offset(&parser_asm_line, (char *)$1, 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
    |
    NUMERIC OPENING_BRACKET expr CLOSING_BRACKET {
        insert_offset(&parser_asm_line, $2, 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
    |
    modifier OPENING_BRACKET expr CLOSING_BRACKET {
        //printf("modifier 2: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)$1, 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
    |
    modifier {
        //printf("modifier 2: '%s' \n", (char *) $1);
        insert_modifier(&parser_asm_line, (char *)$1, 1);

        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }
    |
    expr {
        insert_expr(&parser_asm_line, current_node, 1);
        current_node = NULL;
    }

param_3 :
    IDENTIFIER OPENING_BRACKET expr CLOSING_BRACKET {
        insert_identifier_offset(&parser_asm_line, (char *)$1, 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
    |
    NUMERIC OPENING_BRACKET expr CLOSING_BRACKET {
        insert_offset(&parser_asm_line, $2, 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
    |
    modifier OPENING_BRACKET expr CLOSING_BRACKET {
        //printf("modifier 3: '%s' \n", (char *) $1);


        insert_modifier(&parser_asm_line, (char *)$1, 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
    |
    modifier {
        //printf("modifier 3: '%s' \n", (char *) $1);


        insert_modifier(&parser_asm_line, (char *)$1, 2);

        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }
    |
    expr {
        //printf("expr 3\n");
        insert_expr(&parser_asm_line, current_node, 2);
        current_node = NULL;
    }

label :
    IDENTIFIER COLON {
        //printf("label A detected!\n");
        strncpy($$, $1, 100);
    }
    |
    NUMERIC COLON {
        //printf("label B detected!\n");
        char buffer[100];
        memset(buffer, 0, 100);
        snprintf(buffer, 100, "%d", $1);
        strncpy($$, buffer, 100);
    }

// https://www.gnu.org/software/bison/manual/bison.html
expr:
    NUMERIC {
        printf("PARSER-NUMERIC: %16" PRIx64 "\n", $1);
        //insert_integer_immediate(&parser_asm_line, $1);

        if (current_node == NULL) {
            //current_node = new node_t;
            current_node = (node_t *)malloc(sizeof(node_t));

            //printf("Line: %d\n", yylineno);

            reset_node(current_node);

            //printf("PARSER-NUMERIC: creating node: %d\n", $1);
            printf("PARSER-NUMERIC: creating node: %16" PRIx64 "\n", $1);
            //current_node->int_val = sign_extend_20_bit_to_uint32_t($1);
            current_node->int_val = $1;
            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            //printf("PARSER-NUMERIC: creating node: %d\n", current_node->int_val);

            $$ = current_node;
        } else {
            printf("PARSER-NUMERIC: not null!\n");
        }
    }
    |
    register {
        //printf("expr - register\n");
        $$ = current_node;
    }
    |
    IDENTIFIER {
        printf("expr - IDENTIFIER: %s \n", $1);

        if (current_node == NULL) {

            current_node = (node_t *)malloc(sizeof(node_t));

            reset_node(current_node);

            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, $1, strlen($1));

            $$ = current_node;
        }

        //  else {
        //     printf("expr - IDENTIFIER: not null!\n");
        // }
    }
    |
    STRING_LITERAL {
        if (current_node == NULL) {

            current_node = (node_t *)malloc(sizeof(node_t));

            reset_node(current_node);

            memset(current_node->string_val, 0, 100);
            memcpy(current_node->string_val, $1, strlen($1));

            $$ = current_node;
        }
    }

csv_identifier_list :
    IDENTIFIER
    |
    IDENTIFIER COMMA csv_identifier_list

csv_numeric_list :
    NUMERIC
    {
        insert_numeric_list_raw_data(&parser_asm_line, $1);
    }
    |
    csv_numeric_list COMMA NUMERIC
    {
        insert_numeric_list_raw_data(&parser_asm_line, $3);
    }

assembler_instruction :
    DOT_EQU IDENTIFIER COMMA expr {

        parser_asm_line.asm_instruction = AI_EQU;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, $2, strlen($2));

        parser_asm_line.asm_instruction_expr = $4;
        current_node = NULL;

    }
    |
    DOT_SECTION DOT_TEXT {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, ".text", strlen(".text"));

        current_node = NULL;

    }
    |
    DOT_SECTION DOT_RODATA {

        parser_asm_line.asm_instruction = AI_SECTION;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, ".rodata", strlen(".rodata"));

        current_node = NULL;

    }
    |
    DOT_GLOBL csv_identifier_list {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, $2, strlen($2));

        current_node = NULL;

    }
    |
    DOT_GLOBAL csv_identifier_list {

        parser_asm_line.asm_instruction = AI_GLOBL;

        memset(parser_asm_line.asm_instruction_symbol, 0, 100);
        memcpy(parser_asm_line.asm_instruction_symbol, $2, strlen($2));

        current_node = NULL;

    }
    |
    DOT_TEXT {

        parser_asm_line.asm_instruction = AI_TEXT;

        current_node = NULL;

    }
    |
    DOT_DATA {

        parser_asm_line.asm_instruction = AI_DATA;

        current_node = NULL;

    }
    |
    DOT_BYTE csv_numeric_list {

        parser_asm_line.asm_instruction = AI_BYTE;

        insert_numeric_list_end_raw_data(&parser_asm_line, $2);
        //parser_asm_line.asm_instruction_expr = $2;

        //current_node = NULL;

    }
    |
    DOT_HALF expr {

        parser_asm_line.asm_instruction = AI_HALF;
        parser_asm_line.asm_instruction_expr = $2;

        current_node = NULL;

    }
    |
    DOT_WORD expr {

        parser_asm_line.asm_instruction = AI_WORD;
        parser_asm_line.asm_instruction_expr = $2;

        current_node = NULL;

    }
    |
    DOT_DWORD expr {

        parser_asm_line.asm_instruction = AI_DWORD;
        parser_asm_line.asm_instruction_expr = $2;

        current_node = NULL;

    }
    |
    DOT_FILE expr {

        parser_asm_line.asm_instruction = AI_FILE;
        parser_asm_line.asm_instruction_expr = $2;

        current_node = NULL;

    }
    |
    DOT_SKIP expr {

        parser_asm_line.asm_instruction = AI_SKIP;
        parser_asm_line.asm_instruction_expr = $2;

        current_node = NULL;

    }
    |
    DOT_ASCIZ STRING_LITERAL {

        parser_asm_line.asm_instruction = AI_ASCIZ;
        //parser_asm_line.asm_instruction_expr = $2;
        insert_identifier_offset(&parser_asm_line, (char *)$2, 0);

        current_node = NULL;

    }
    |
    DOT_STRING STRING_LITERAL {

        printf("DOT_STRING STRING_LITERAL %s, %d \n\n", __FILE__, __LINE__);

        parser_asm_line.asm_instruction = AI_STRING;
        //parser_asm_line.asm_instruction_expr = $2;

        insert_identifier_offset(&parser_asm_line, (char *)$2, 0);

        // if (current_node == NULL) {

        //     current_node = (node_t *)malloc(sizeof(node_t));

        //     reset_node(current_node);

        //     parser_asm_line.asm_instruction_expr = current_node;

        //     memset(parser_asm_line.asm_instruction_expr->string_val, 0, 100);
        //     memcpy(parser_asm_line.asm_instruction_expr->string_val, $2, strlen($2));
        // }

        current_node = NULL;

    }

mnemonic : ADD { /*printf("Parser-ADD: %d\n", I_ADD);*/ /*parser_asm_line.instruction = I_ADD; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADD, IT_R); }
    | ADDI { /*printf("Parser-ADDI: %d\n", I_ADDI);*/ /*parser_asm_line.instruction = I_ADDI; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_ADDI, IT_R); }
    | AND { set_instruction(&parser_asm_line, I_AND, IT_R); }
    | ANDI { set_instruction(&parser_asm_line, I_ANDI, IT_I); }
    | AUIPC { /*printf("Parser-AUIPC: %d\n", I_AUIPC);*/ /*parser_asm_line.instruction = I_AUIPC; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_AUIPC, IT_U); }
    | BEQ { /*printf("Parser-BEQ: %d\n", I_BEQ);*/ /*parser_asm_line.instruction = I_BEQ; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BEQ, IT_B); }
    | BEQZ { /*printf("Parser-BEQZ: %d\n", I_BEQZ);*/ /*parser_asm_line.instruction = I_BEQZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BEQZ, IT_P); }
    | BNE { /*printf("Parser-BNE: %d\n", I_BNE);*/ /*parser_asm_line.instruction = I_BNE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BNE, IT_B); }
    | BGE { /*printf("Parser-BGE: %d\n", I_BGE);*/ /*parser_asm_line.instruction = I_BGE; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGE, IT_B); }
    | BGT { /*printf("Parser-BGT: %d\n", I_BGT);*/ /*parser_asm_line.instruction = I_BGT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BGT, IT_B); }
    | BLT { /*printf("Parser-BLT: %d\n", I_BLT);*/ /*parser_asm_line.instruction = I_BLT; parser_asm_line.instruction_type = IT_B;*/ set_instruction(&parser_asm_line, I_BLT, IT_B); }
    | BNEZ { /*printf("Parser-BNEZ: %d\n", I_BNEZ);*/ /*parser_asm_line.instruction = I_BNEZ; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_BNEZ, IT_P); }
    | CALL { /*printf("Parser-CALL: %d\n", I_CALL);*/ /*parser_asm_line.instruction = I_CALL; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_CALL, IT_P); }
    | J { /*printf("Parser-J: %d\n", I_J);*/ /*parser_asm_line.instruction = I_J; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_J, IT_P); }
    | JR { /*printf("Parser-JR: %d\n", I_JR);*/ /*parser_asm_line.instruction = I_JR; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_JR, IT_P); }
    | JALR { /*printf("Parser-JALR: %d\n", I_JALR);*/ /*parser_asm_line.instruction = I_JALR; parser_asm_line.instruction_type = IT_J;*/ set_instruction(&parser_asm_line, I_JALR, IT_J); }
    | LB { /*printf("Parser-LB: %d\n", I_LB);*/ /*parser_asm_line.instruction = I_LB; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LB, IT_I); }
    | LBU { set_instruction(&parser_asm_line, I_LBU, IT_I); }
    | LH { /*printf("Parser-LH: %d\n", I_LH);*/ /*parser_asm_line.instruction = I_LH; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LH, IT_I); }
    | LI { /*printf("Parser-LI: %d\n", I_LI);*/ /*parser_asm_line.instruction = I_LI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LI, IT_P); }
    | LW { /*printf("Parser-LW: %d\n", I_LW);*/ /*parser_asm_line.instruction = I_LW; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LW, IT_I); }
    | LD { /*printf("Parser-LD: %d\n", I_LD);*/ /*parser_asm_line.instruction = I_LD; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_LD, IT_I); }
    | LUI { /*printf("Parser-LUI: %d\n", I_LUI);*/ /*parser_asm_line.instruction = I_LUI; parser_asm_line.instruction_type = IT_U;*/ set_instruction(&parser_asm_line, I_LUI, IT_U); }
    | MUL { /*printf("Parser-LW: %d\n", I_MUL);*/ /*parser_asm_line.instruction = I_MUL; parser_asm_line.instruction_type = IT_R;*/ set_instruction(&parser_asm_line, I_MUL, IT_R); }
    | MV { /*printf("Parser-LW: %d\n", I_MV);*/ /*parser_asm_line.instruction = I_MV; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_MV, IT_P); }
    | NOP { set_instruction(&parser_asm_line, I_NOP, IT_P); }
    | NOT { /*printf("Parser-NOT: %d\n", I_NOT);*/ /*parser_asm_line.instruction = I_NOT; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_NOT, IT_P); }
    | RET { /*printf("Parser-RET: %d\n", I_RET);*/ /*parser_asm_line.instruction = I_RET; parser_asm_line.instruction_type = IT_P;*/ set_instruction(&parser_asm_line, I_RET, IT_P); }
    | SRLI { /*printf("Parser-SRLI: %d\n", I_SRLI);*/ /*parser_asm_line.instruction = I_SRLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SRLI, IT_I); }
    | SLLI { /*printf("Parser-SLLI: %d\n", I_SLLI);*/ /*parser_asm_line.instruction = I_SLLI; parser_asm_line.instruction_type = IT_I;*/ set_instruction(&parser_asm_line, I_SLLI, IT_I); }
    | SD { /*printf("Parser-SD: %d\n", I_SD);*/ /*parser_asm_line.instruction = I_SD; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SD, IT_S); }
    | SW { /*printf("Parser-SW: %d\n", I_SW);*/ /*parser_asm_line.instruction = I_SW; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SW, IT_S); }
    | SH { /*printf("Parser-SH: %d\n", I_SH);*/ /*parser_asm_line.instruction = I_SH; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SH, IT_S); }
    | SB { /*printf("Parser-SB: %d\n", I_SB);*/ /*parser_asm_line.instruction = I_SB; parser_asm_line.instruction_type = IT_S;*/ set_instruction(&parser_asm_line, I_SB, IT_S); }
    | WFI { set_instruction(&parser_asm_line, I_WFI, IT_SYSTEM); }

register : REG_ZERO { /*printf("REG_ZERO\n");*/ insert_register(&parser_asm_line, R_ZERO); }
    | REG_RA { /*printf("REG_RA\n");*/ insert_register(&parser_asm_line, R_RA); }
    | REG_SP { /*printf("REG_SP\n");*/ insert_register(&parser_asm_line, R_SP); }
    | REG_GP { /*printf("REG_GP\n");*/ insert_register(&parser_asm_line, R_GP); }
    | REG_TP { /*printf("REG_TP\n");*/ insert_register(&parser_asm_line, R_TP); }
    | REG_T0 { /*printf("REG_T0\n");*/ insert_register(&parser_asm_line, R_T0); }
    | REG_T1 { /*printf("REG_T1\n");*/ insert_register(&parser_asm_line, R_T1); }
    | REG_T2 { /*printf("REG_T2\n");*/ insert_register(&parser_asm_line, R_T2); }
    | REG_T3 { /*printf("REG_T3\n");*/ insert_register(&parser_asm_line, R_T3); }
    | REG_T4 { /*printf("REG_T4\n");*/ insert_register(&parser_asm_line, R_T4); }
    | REG_T5 { /*printf("REG_T5\n");*/ insert_register(&parser_asm_line, R_T5); }
    | REG_T6 { /*printf("REG_T6\n");*/ insert_register(&parser_asm_line, R_T6); }
    | REG_FP { /*printf("REG_FP\n");*/ insert_register(&parser_asm_line, R_S0); }
    | REG_A0 { /*printf("REG_A0\n");*/ insert_register(&parser_asm_line, R_A0); }
    | REG_A1 { /*printf("REG_A1\n");*/ insert_register(&parser_asm_line, R_A1); }
    | REG_A2 { /*printf("REG_A2\n");*/ insert_register(&parser_asm_line, R_A2); }
    | REG_A3 { /*printf("REG_A3\n");*/ insert_register(&parser_asm_line, R_A3); }
    | REG_A4 { /*printf("REG_A4\n");*/ insert_register(&parser_asm_line, R_A4); }
    | REG_A5 { /*printf("REG_A5\n");*/ insert_register(&parser_asm_line, R_A5); }
    | REG_A6 { /*printf("REG_A6\n");*/ insert_register(&parser_asm_line, R_A6); }
    | REG_A7 { /*printf("REG_A7\n");*/ insert_register(&parser_asm_line, R_A7); }
    | REG_S0 { /*printf("REG_S0\n");*/ insert_register(&parser_asm_line, R_S0); }
    | REG_S1 { /*printf("REG_S1\n");*/ insert_register(&parser_asm_line, R_S1); }
    | REG_S2 { /*printf("REG_S2\n");*/ insert_register(&parser_asm_line, R_S2); }
    | REG_S3 { /*printf("REG_S3\n");*/ insert_register(&parser_asm_line, R_S3); }
    | REG_S4 { /*printf("REG_S4\n");*/ insert_register(&parser_asm_line, R_S4); }
    | REG_S5 { /*printf("REG_S5\n");*/ insert_register(&parser_asm_line, R_S5); }
    | REG_S6 { /*printf("REG_S6\n");*/ insert_register(&parser_asm_line, R_S6); }
    | REG_S7 { /*printf("REG_S7\n");*/ insert_register(&parser_asm_line, R_S7); }
    | REG_S8 { /*printf("REG_S8\n");*/ insert_register(&parser_asm_line, R_S8); }
    | REG_S9 { /*printf("REG_S9\n");*/ insert_register(&parser_asm_line, R_S9); }
    | REG_S10 { /*printf("REG_S10\n");*/ insert_register(&parser_asm_line, R_S10); }
    | REG_S11 { /*printf("REG_S11\n");*/ insert_register(&parser_asm_line, R_S11); }

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

/*
void emit(asm_line_t* asm_line) {
    printf("emit\n");
}
*/

int main(int argc, char **argv)
{
    reset_asm_line(&parser_asm_line);

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