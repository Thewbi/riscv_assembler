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

"%hi"           { /*printf("%hi\n");*/ return MODIFIER_HI; }
"%lo"           { /*printf("%lo\n");*/ return MODIFIER_LO; }

(?i:.equ)	    { /*printf(".equ\n");*/ return DOT_EQU; }
(?i:.section)   { /*printf(".section\n");*/ return DOT_SECTION; }
(?i:.globl)     { /*printf(".globl\n");*/ return DOT_GLOBL; }
(?i:.global)    { /*printf(".global\n");*/ return DOT_GLOBAL; }
(?i:.text)      { /*printf(".text\n");*/ return DOT_TEXT; }
(?i:.data)      { /*printf(".data\n");*/ return DOT_DATA; }
(?i:.byte)      { /*printf(".byte\n");*/ return DOT_BYTE; }
(?i:.space)      { /*printf(".space\n");*/ return DOT_SPACE; }
(?i:.half)      { /*printf(".half\n");*/ return DOT_HALF; }
(?i:.word)      { /*printf(".word\n");*/ return DOT_WORD; }
(?i:.dword)     { /*printf(".dword\n");*/ return DOT_DWORD; }
(?i:.file)      { /*printf(".file\n");*/ return DOT_FILE; }
(?i:.rodata)    { /*printf(".rodata\n");*/ return DOT_RODATA; } /* read only data */
(?i:.asciz)     { /*printf(".asciz\n");*/ return DOT_ASCIZ; } /* ASCII string, zero terminated */
(?i:.skip)      { /*printf(".skip\n");*/ return DOT_SKIP; }
(?i:.string)    { /*printf(".string\n");*/ return DOT_STRING; }

(?i:add)        { /*printf("ADD\n");*/ return ADD; }
(?i:addi)       { /*printf("ADDI\n");*/ return ADDI; }
(?i:and)        { /*printf("AND\n");*/ return AND; }
(?i:andi)	    { /*printf("ANDI\n");*/ return ANDI; }
(?i:auipc)	    { /*printf("ADDI\n");*/ return AUIPC; }

(?i:beq)        { /*printf("BEQ\n");*/ return BEQ; }
(?i:beqz)       { /*printf("BEQZ\n");*/ return BEQZ; }
(?i:bge)        { /*printf("BGE\n");*/ return BGE; }
(?i:bgt)        { /*printf("BGT\n");*/ return BGT; }
(?i:blt)        { /*printf("BLT\n");*/ return BLT; }
(?i:bne)        { /*printf("BNEZ\n");*/ return BNE; }
(?i:bnez)       { /*printf("BNEZ\n");*/ return BNEZ; }

(?i:call)       { /*printf("CALL\n");*/ return CALL; }
(?i:ecall)       { /*printf("CALL\n");*/ return ECALL; }

(?i:j)          { /*printf("J\n");*/ return J; }
(?i:jr)         { /*printf("JR\n");*/ return JR; }
(?i:jalr)       { /*printf("JALR\n");*/ return JALR; }

(?i:la)         { /*printf("LA\n");*/ return LA; }
(?i:ld)         { /*printf("LD\n");*/ return LD; }
(?i:lw)         { /*printf("LW\n");*/ return LW; }
(?i:lh)	        { /*printf("LH\n");*/ return LH; }
(?i:lb)	        { /*printf("LB\n");*/ return LB; }
(?i:lbu)	    { /*printf("LBU\n");*/ return LBU; }
(?i:li)         { /*printf("LI\n");*/ return LI; }
(?i:lui)        { /*printf("LUI\n");*/ return LUI; }

(?i:mul)        { /*printf("MUL\n");*/ return MUL; }
(?i:mv)         { /*printf("MV\n");*/ return MV; }

(?i:nop)        { /*printf("NOP\n");*/ return NOP; }
(?i:not)        { /*printf("NOT\n");*/ return NOT; }

(?i:ret)        { /*printf("RET\n");*/ return RET; }

(?i:srli)       { /*printf("SRLI\n");*/ return SRLI; }
(?i:slli)       { /*printf("SLLI\n");*/ return SLLI; }
(?i:sd)         { /*printf("SD\n");*/ return SD; }
(?i:sw)         { /*printf("SW\n");*/ return SW; }
(?i:sh)         { /*printf("SH\n");*/ return SH; }
(?i:sb)         { /*printf("SB\n");*/ return SB; }

(?i:wfi)        { /*printf("WFI\n");*/ return WFI; }

(?i:zero)       { /*printf("zero\n");*/ return REG_ZERO; }
(?i:ra)         { /*printf("ra\n");*/ return REG_RA; }
(?i:sp)         { /*printf("sp\n");*/ return REG_SP; }
(?i:gp)         { /*printf("gp\n");*/ return REG_GP; }
(?i:tp)         { /*printf("tp\n");*/ return REG_TP; }

(?i:t0)         { /*printf("lexer t0\n");*/ return REG_T0; }
(?i:t1)         { /*printf("lexer t1\n");*/ return REG_T1; }
(?i:t2)         { /*printf("t2\n");*/ return REG_T2; }
(?i:t3)         { /*printf("t3\n");*/ return REG_T3; }
(?i:t4)         { /*printf("t4\n");*/ return REG_T4; }
(?i:t5)         { /*printf("t5\n");*/ return REG_T5; }
(?i:t6)         { /*printf("t6\n");*/ return REG_T6; }

(?i:fp)         { /*printf("fp\n");*/ return REG_FP; }

(?i:a0)         { /*printf("lexer a0\n");*/ return REG_A0; }
(?i:a1)         { /*printf("a1\n");*/ return REG_A1; }
(?i:a2)         { /*printf("a2\n");*/ return REG_A2; }
(?i:a3)         { /*printf("a3\n");*/ return REG_A3; }
(?i:a4)         { /*printf("a4\n");*/ return REG_A4; }
(?i:a5)         { /*printf("a5\n");*/ return REG_A5; }
(?i:a6)         { /*printf("a6\n");*/ return REG_A6; }
(?i:a7)         { /*printf("a7\n");*/ return REG_A7; }

(?i:s0)         { /*printf("s0\n");*/ return REG_S0; }
(?i:s1)         { /*printf("s1\n");*/ return REG_S1; }
(?i:s2)         { /*printf("s2\n");*/ return REG_S2; }
(?i:s3)         { /*printf("s3\n");*/ return REG_S3; }
(?i:s4)         { /*printf("s4\n");*/ return REG_S4; }
(?i:s5)         { /*printf("s5\n");*/ return REG_S5; }
(?i:s6)         { /*printf("s6\n");*/ return REG_S6; }
(?i:s7)         { /*printf("s7\n");*/ return REG_S7; }
(?i:s8)         { /*printf("s8\n");*/ return REG_S8; }
(?i:s9)         { /*printf("s9\n");*/ return REG_S9; }
(?i:s10)        { /*printf("s10\n");*/ return REG_S10; }
(?i:s11)        { /*printf("s11\n");*/ return REG_S11; }

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

[\.]?[a-zA-Z_][a-zA-Z0-9_]*([\.][a-zA-Z0-9_]*)* {

    /* FLEX regex tester - https://regex101.com/r/wG3hF4/1 */

    // DEBUG
    //printf("lexer::identifier: %s\n", yytext);

    // copy the value into the token
    memset(yylval.string_val, 0, 100);
    memcpy(yylval.string_val, yytext, strlen(yytext));

    // return token type
    return IDENTIFIER;
}

[0-9]+[fb] {

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

\"(\\.|[^"\\])*\" {
    // copy the value into the token
    memset(yylval.string_val, 0, 100);
    memcpy(yylval.string_val, yytext, strlen(yytext));

    // return token type
    return STRING_LITERAL;
}

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