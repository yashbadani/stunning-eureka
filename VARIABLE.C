//Program to check validity of a variable
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void main()
{
	char variable[32];
	int n,i,flag=0;
	clrscr();

	start:
	printf("Enter the variable: ");
	gets(variable);

	if(variable[0]=='\0')
		goto start;

	n=strlen(variable);
	if(n>8)
	{
		printf("Only 8 characters are significant\n");
		getch();
		exit(0);
	}
	if(isdigit(variable[0]))
	{
		printf("Variable cannot start with a number\n");
		flag=1;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(isalnum(variable[i]))
				continue;
			else if(variable[i]=='_')
				continue;
			else if(variable[i]==' ')
			{
				printf("Variable cannot contain whitespace in between\n");
				flag=1;
				break;
			}
			else
			{
				printf("Variable can contain only Alphanumeric characters and underscore\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Valid Variable\n");
	}

	getch();
}