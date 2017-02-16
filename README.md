# lex_sql
lexical analysis for sql by lex and c

for lex.l 

commands: 

flex lex.l

gcc lex.yy.c-lfl -o assign

./assign


for lexinc.c

gcc lexinc.c -o lexinc

./lexinc
