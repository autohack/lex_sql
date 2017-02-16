#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char *keyword[61] = {"add","all","as","alter","and","any","asc","avg","by","char","character"	,"column",
"create","cascade","constraints","date","distinct","double","default","delete","desc","drop","exists","foreign",
"float","from","group","having","in","index","insert","into","is","int","integer","join","key","left","like",
"max","min","not","null","or","order","outer","references","right","schema","select","set","smallint","sum",
"table","union","unique","update","value","values","varchar","where"};

const char *operator[11] = {"*","+","-","/",".","=","<",">","<>",">=","<="};

int iskeyword(char *str)
{

	int i;
	for(i = 0; str[i]; i++)
	{
  		str[i] = tolower(str[i]);
	}
	for(i=0;i<=60;i++)
	{
		if(!strcmp(keyword[i],str))
			return 1;
	}
	return 0;
}

int isoperator(char *str)
{
	int i;
	for(i=0;i<=10;i++)
	{
		if(!strcmp(operator[i],str))
			return 1;
	}
	return 0;
}

int isval(char *str)
{
	int i;
	for (i=0;i<strlen(str);i++){
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int isind(char *str)
{
	int i;
	if(!isdigit(str[0]))
	{
		for(i=1;i<strlen(str);i++)
		{
			if(!isalnum(str[i]))
				return 0;
		}
	}
	else
		return 0;

	return 1;	
}


int main()
{
	/* code */
	char s[100], *p[100],c[100];
	
	int i = 0,j=0,k=0,z=0,y=0;
	while(1){
		scanf("%[^'\n']s",s);
		getchar();

		if(!strcmp(s,"exit"))
			break;
		while(s[z] != '\0')
		{
			if(s[z]=='>' && s[z+1] =='=')
			{
				c[y] = ' ';
				c[++y] = s[z];
				c[++y] = s[++z];
				c[++y] = ' ';

			}
			else if(s[z]=='<' && s[z+1] =='=')
			{
				c[y] = ' ';
				c[++y] = s[z];
				c[++y] = s[++z];
				c[++y] = ' ';

			}
			else if(s[z]=='<' && s[z+1] =='>')
			{
				c[y] = ' ';
				c[++y] = s[z];
				c[++y] = s[++z];
				c[++y] = ' ';

			}
			else if(s[z]=='*' || s[z] ==';' || s[z] == '(' || s[z] == ')' || s[z] ==',' || s[z] == '>' || s[z] == '<' ||
				s[z] == '='|| s[z] == '-' || s[z] == '+' || s[z] == '/' || s[z] == ';')
			{
				c[y] = ' ';
				c[++y] = s[z];
				c[++y] = ' ';
			}
			else
			{
				c[y] = s[z];
			}
			y++;
			z++;
		}
		c[y] = '\0';
		printf("%s\n", c);
		p[0] = strtok(c, " ");
		i = 0;

		while(p[i] != NULL)
		{
			i++;
			p[i] = strtok(NULL," ");
		}


		while(p[j]!= NULL)
		{
			if(iskeyword(p[j]))
			{
				printf("%s\t\t : Keyword\n",p[j] );
			}
			else if (isoperator(p[j]))
			{
				printf("%s\t\t : Operator\n",p[j] );
			}
			else if(!strcmp(p[j],")"))
			{
				printf("%s\t\t : Right Bracket\n",p[j] );
			}
			else if(!strcmp(p[j],"("))
			{
				printf("%s\t\t : Left Bracket\n",p[j] );
			}
			else if(!strcmp(p[j],","))
			{
				printf("%s\t\t : Comma\n",p[j] );
			}
			else if(!strcmp(p[j],";"))
			{
				printf("%s\t\t : Semi Colon\n",p[j] );
			}
			else if(isval(p[j]))
			{
				printf("%s\t\t : Value\n", p[j]);
			}
			else if (isdigit(p[j][0]) && !isdigit(p[j][1]))
			{
				printf("%s\t\t : Invalid Identifier\n",p[j] );
				printf("ERROR: Invalid Identifier. You have an error in your SQL lexeme near '%s.\n",p[j]);
				exit(1);
			}

			
			else if(isind(p[j]))
			{
				printf("%s\t\t : Identifier\n",p[j]);
			}
			else
			{
				printf("%s\t\t : Invalid Token\n",p[j]);
			}
			j++;

		}
		j=0;

		while(p[k] != NULL)
		{
			p[k] = NULL;
			k++;
		}

		k=0;
		y=0;z=0;
		
	}
	return 0;
}
