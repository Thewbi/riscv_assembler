/********************************************************
 * ex1.l 
 ********************************************************/
%{
#include "parser.hpp"
#include <iostream>
using namespace std;
%}

%option noyywrap
%option warn nodefault

%%

"add"	{ printf("ADD\n"); return ADD; }

"jalr"  { return JALR; }

"li"    { return LI; }

"zero"  { printf("zero\n"); return REG_ZERO; } 
"ra"    { printf("ra\n"); return REG_RA; } 
"sp"    { printf("sp\n"); return REG_SP; } 
"gp"    { printf("gp\n"); return REG_GP; } 
"tp"    { printf("tp\n"); return REG_TP; } 

"t0"    { printf("t0\n"); return REG_T0; } 
"t1"    { printf("t1\n"); return REG_T1; }  
"t2"    { printf("t2\n"); return REG_T2; } 
"t3"    { printf("t3\n"); return REG_T3; } 
"t4"    { printf("t4\n"); return REG_T4; } 
"t5"    { printf("t5\n"); return REG_T5; } 
"t6"    { printf("t6\n"); return REG_T6; } 

"fp"    { printf("fp\n"); return REG_FP; } 

"a0"    { printf("a0\n"); return REG_A0; }
"a1"    { printf("a1\n"); return REG_A1; }
"a2"    { printf("a2\n"); return REG_A2; }
"a3"    { printf("a3\n"); return REG_A3; }
"a4"    { printf("a4\n"); return REG_A4; }
"a5"    { printf("a5\n"); return REG_A5; }
"a6"    { printf("a6\n"); return REG_A6; }
"a7"    { printf("a7\n"); return REG_A7; }

"s0"    { printf("s0\n"); return REG_S0; }
"s1"    { printf("s1\n"); return REG_S1; }
"s2"    { printf("s2\n"); return REG_S2; }
"s3"    { printf("s3\n"); return REG_S3; }
"s4"    { printf("s4\n"); return REG_S4; }
"s5"    { printf("s5\n"); return REG_S5; }
"s6"    { printf("s6\n"); return REG_S6; }
"s7"    { printf("s7\n"); return REG_S7; }
"s8"    { printf("s8\n"); return REG_S8; }
"s9"    { printf("s9\n"); return REG_S9; }
"s10"   { printf("s10\n"); return REG_S10; }
"s11"   { printf("s11\n"); return REG_S11; }

"section"   { return SECTION; }
"global"    { return GLOBAL; }

"//".*  { /* DO NOTHING */ } /* https://stackoverflow.com/questions/25395251/detecting-and-skipping-line-comments-with-flex */
"#".*   { /* DO NOTHING */ }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
[/][*]                                    { printf("Unterminated comment"); }

[a-zA-Z_][a-zA-Z_0-9]*   { printf("identifier\n"); return IDENTIFIER; }

[0-9]+  { return NUMERIC; }

"."     { return DOT; }
":"     { return COLON; }
","     { return COMMA; }

(\r\n|\n) { printf("NEW_LINE\n"); return NEW_LINE; }

[ \t]+	{ }

<<EOF>>	{ return EOF; }

.       { return *yytext; }


%%