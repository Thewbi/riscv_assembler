/********************************************************
 * ex1.l
 ********************************************************/
%{

#include <stdio.h>

#include <node.h>
#include "parser.h"

%}

%option yylineno
%option noyywrap
%option warn nodefault

%%

".equ"	    { /*printf(".equ\n");*/ return EQU; }
".section"  { /*printf(".section\n");*/ return SECTION; }
".globl"    { /*printf(".globl\n");*/ return GLOBL; }
".global"    { /*printf(".global\n");*/ return GLOBAL; }
".text"    { /*printf(".text\n");*/ return TEXT; }
".data"    { /*printf(".data\n");*/ return DATA; }
".byte"    { /*printf(".byte\n");*/ return BYTE; }
".half"    { /*printf(".half\n");*/ return HALF; }
".word"    { /*printf(".word\n");*/ return WORD; }
".dword"    { /*printf(".dword\n");*/ return DWORD; }

"add"	{ /*printf("ADD\n");*/ return ADD; }
"addi"	{ /*printf("ADDI\n");*/ return ADDI; }
"auipc"	{ /*printf("ADDI\n");*/ return AUIPC; }

"beq"   { /*printf("BEQ\n");*/ return BEQ; }
"beqz"   { /*printf("BEQZ\n");*/ return BEQZ; }
"bge"  { /*printf("BGE\n");*/ return BGE; }
"bgt"  { /*printf("BGT\n");*/ return BGT; }
"blt"  { /*printf("BLT\n");*/ return BLT; }
"bne"   { /*printf("BNEZ\n");*/ return BNE; }
"bnez"  { /*printf("BNEZ\n");*/ return BNEZ; }

"call"  { /*printf("CALL\n");*/ return CALL; }

"j"     { /*printf("J\n");*/ return J; }
"jalr"  { /*printf("JALR\n");*/ return JALR; }

"ld"    { /*printf("LD\n");*/ return LD; }
"lw"    { /*printf("LW\n");*/ return LW; }
"lh"	{ /*printf("LH\n");*/ return LH; }
"lb"	{ /*printf("LB\n");*/ return LB; }
"li"    { /*printf("LI\n");*/ return LI; }
"lui"   { /*printf("LUI\n");*/ return LUI; }

"mul"   { /*printf("MUL\n");*/ return MUL; }
"mv"    { /*printf("MV\n");*/ return MV; }

"ret"   { /*printf("RET\n");*/ return RET; }

"srli"  { /*printf("SRLI\n");*/ return SRLI; }
"slli"  { /*printf("SLLI\n");*/ return SLLI; }
"sd"    { /*printf("SD\n");*/ return SD; }
"sw"    { /*printf("SW\n");*/ return SW; }
"sh"    { /*printf("SH\n");*/ return SH; }
"sb"    { /*printf("SB\n");*/ return SB; }

"zero"  { /*printf("zero\n");*/ return REG_ZERO; }
"ra"    { /*printf("ra\n");*/ return REG_RA; }
"sp"    { /*printf("sp\n");*/ return REG_SP; }
"gp"    { /*printf("gp\n");*/ return REG_GP; }
"tp"    { /*printf("tp\n");*/ return REG_TP; }

"t0"    { /*printf("lexer t0\n");*/ return REG_T0; }
"t1"    { /*printf("lexer t1\n");*/ return REG_T1; }
"t2"    { /*printf("t2\n");*/ return REG_T2; }
"t3"    { /*printf("t3\n");*/ return REG_T3; }
"t4"    { /*printf("t4\n");*/ return REG_T4; }
"t5"    { /*printf("t5\n");*/ return REG_T5; }
"t6"    { /*printf("t6\n");*/ return REG_T6; }

"fp"    { /*printf("fp\n");*/ return REG_FP; }

"a0"    { /*printf("lexer a0\n");*/ return REG_A0; }
"a1"    { /*printf("a1\n");*/ return REG_A1; }
"a2"    { /*printf("a2\n");*/ return REG_A2; }
"a3"    { /*printf("a3\n");*/ return REG_A3; }
"a4"    { /*printf("a4\n");*/ return REG_A4; }
"a5"    { /*printf("a5\n");*/ return REG_A5; }
"a6"    { /*printf("a6\n");*/ return REG_A6; }
"a7"    { /*printf("a7\n");*/ return REG_A7; }

"s0"    { /*printf("s0\n");*/ return REG_S0; }
"s1"    { /*printf("s1\n");*/ return REG_S1; }
"s2"    { /*printf("s2\n");*/ return REG_S2; }
"s3"    { /*printf("s3\n");*/ return REG_S3; }
"s4"    { /*printf("s4\n");*/ return REG_S4; }
"s5"    { /*printf("s5\n");*/ return REG_S5; }
"s6"    { /*printf("s6\n");*/ return REG_S6; }
"s7"    { /*printf("s7\n");*/ return REG_S7; }
"s8"    { /*printf("s8\n");*/ return REG_S8; }
"s9"    { /*printf("s9\n");*/ return REG_S9; }
"s10"   { /*printf("s10\n");*/ return REG_S10; }
"s11"   { /*printf("s11\n");*/ return REG_S11; }

"x0" { /*printf("\n");*/ return REG_ZERO; }  // 0, Hard-wired zero
"x1" { /*printf("\n");*/ return REG_RA; } // 1, Return address
"x2" { /*printf("\n");*/ return REG_SP; } // 2, Stack pointer
"x3" { /*printf("\n");*/ return REG_GP; } // 3, Global pointer
"x4" { /*printf("\n");*/ return REG_TP; } // 4, Thread pointer

"x5" { /*printf("\n");*/ return REG_T0; } // 5, Temporary/alternate link register
"x6" { /*printf("\n");*/ return REG_T1; } // 6, Temporary
"x7" { /*printf("\n");*/ return REG_T2; } // 7, Temporary

"x8" { /*printf("\n");*/ return REG_S0; } // 8, Saved register/frame pointer
"x9" { /*printf("\n");*/ return REG_S1; } // 9, Saved register

"x10" { /*printf("\n");*/ return REG_A0; } // 10, Function arguments/return values
"x11" { /*printf("\n");*/ return REG_A1; } // 11, Function arguments/return values

"x12" { /*printf("\n");*/ return REG_A2; } // 12, Function arguments
"x13" { /*printf("\n");*/ return REG_A3; } // 13, Function arguments
"x14" { /*printf("\n");*/ return REG_A4; } // 14, Function arguments
"x15" { /*printf("\n");*/ return REG_A5; } // 15, Function arguments
"x16" { /*printf("\n");*/ return REG_A6; } // 16, Function arguments
"x17" { /*printf("\n");*/ return REG_A7; } // 17, Function arguments

"x18" { /*printf("\n");*/ return REG_S2; } // 18, Saved registers
"x19" { /*printf("\n");*/ return REG_S3; } // 19, Saved registers
"x20" { /*printf("\n");*/ return REG_S4; } // 20, Saved registers
"x21" { /*printf("\n");*/ return REG_S5; } // 21, Saved registers
"x22" { /*printf("\n");*/ return REG_S6; } // 22, Saved registers
"x23" { /*printf("\n");*/ return REG_S7; } // 23, Saved registers
"x24" { /*printf("\n");*/ return REG_S8; } // 24, Saved registers
"x25" { /*printf("\n");*/ return REG_S9; } // 25, Saved registers
"x26" { /*printf("\n");*/ return REG_S10; } // 26, Saved registers
"x27" { /*printf("\n");*/ return REG_S11; } // 27, Saved registers

"x28" { /*printf("\n");*/ return REG_T2; } // 28, Temporary
"x29" { /*printf("\n");*/ return REG_T3; } // 29, Temporary
"x30" { /*printf("\n");*/ return REG_T4; } // 30, Temporary
"x31" { /*printf("\n");*/ return REG_T5; } // 31, Temporary

"//".*  { /* DO NOTHING */ } /* https://stackoverflow.com/questions/25395251/detecting-and-skipping-line-comments-with-flex */
"#".*   { /* DO NOTHING */ }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
[/][*]                                    { /*printf("Unterminated comment");*/ }

[0-9]+[fb] {

    // DEBUG
    //printf("lexer::identifier: %s\n", yytext);

    // copy the value into the token
    memset(yylval.string_val, 0, 100);
    memcpy(yylval.string_val, yytext, strlen(yytext));

    // return token type
    return IDENTIFIER;
}

"."?[a-zA-Z_][a-zA-Z_0-9]* {

    // DEBUG
    //printf("lexer::identifier: %s\n", yytext);

    // copy the value into the token
    memset(yylval.string_val, 0, 100);
    memcpy(yylval.string_val, yytext, strlen(yytext));

    // return token type
    return IDENTIFIER;
}

"-"?[0-9]+ { yylval.int_val = atoi(yytext); return NUMERIC; }
"-"?"0"[xX][0-9a-fA-F]+ { yylval.int_val = strtol(yytext, NULL, 0); return NUMERIC; }

"."     { return DOT; }
":"     { return COLON; }
","     { return COMMA; }
"("     { return OPENING_BRACKET; }
")"     { return CLOSING_BRACKET; }

(\r\n|\n) { /*printf("NEW_LINE\n");*/ return NEW_LINE; }

[ \t]+	{ }

<<EOF>>	{ return EOF; }

.       { return *yytext; }


%%