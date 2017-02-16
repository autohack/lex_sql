%{
#include <stdio.h>
#include <stdlib.h>
int linenum = 1;
void print(char *x,char *y);
void yyerror(char *s);
%}

%%
exit								{exit(EXIT_SUCCESS);}

add	|
all	|
alter	|
and	|
any	|
as	|
asc	|
avg	|
by	|
char(acter)?	|
column	|
create	|
cascade	|
constraint	|
date	|
distinct	|
double	|
default	|
delete	|
desc	|
drop	|
exists	|
foreign	|
float	|
from 	|
group	|
having	|
in	|
index	|
insert	|
into	|
is	|
int(eger)?	|
join	|
key	|
left	|
like	|
max	|
min |
not	|
null 	|
or	|
order	|
outer	|
primary	|
real	|
references		|
right	|
schema	|
select	|
set |
smallint	|
sum	|
table	|
union	|
unique	|
update	|
value(s)?	|
varchar	|
where								{print(yytext,"Keyword");}

[A-Za-z_][A-Z0a-z0-9_]*         	{print(yytext,"Identifier");}
[0-9]+[A-Za-z_][A-Za-z0-9_]*     	{yyerror("Invalid Identifier");}
[(]									{print(yytext,"Left bracket");}
[)]									{print(yytext,"Right Bracket");}
'[^']*'                    			{print(yytext,"Text String");}
'[^']*$	                    		{yyerror("Invalid string");}
[,]                         		{print(yytext,"Comma");}
"<="	|
">="	|
"<>"	|
[*+-/.=<>]							{print(yytext,"Operator");}
[;]                             	{print(yytext,"Semi Colon");linenum++;}
[0-9]+  |
[0-9]+"."[0-9]+ |
"."[0-9]+                    		{print(yytext,"Value");}
[ \n\r\t]                       	;
.									{yyerror("Invalid token");}

%%

void print(char *x,char	*y){
	printf("%25s : %s\n",x,y);
}
void yyerror(char *s){
	printf("ERROR: (%s) You have an error in your SQL lexeme near '%s at line %d\n",s,yytext,linenum);
	exit(EXIT_SUCCESS);
}
int yywrap(void){
  return 1;
}
int main(){
	yylex();
	return 0;
}