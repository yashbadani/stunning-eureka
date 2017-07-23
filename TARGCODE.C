//target code generation
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	char code[6];
	int n;
	clrscr();

	printf("Enter a three address code\n");
	gets(code);

	n=strlen(code);
	if(n>5)
	{
		printf("Invalid 3 address code\n");
		getch();
		return;
	}
	else if(n==5)
	{
		if(isalnum(code[0])&&isalnum(code[2])&&isalnum(code[4]))
		{
			printf("\nMOV AX,'%c'",code[2]);
			printf("\nMOV BX,'%c'",code[4]);
			switch(code[3])
			{
				case '+':
					printf("\nADD AX,BX");
					break;
				case '-':
					printf("\nSUB AX,BX");
					break;
				case '*':
					printf("\nMUL BX");
					break;
				case '/':
					printf("\nDIV BX");
					break;
				case '%':
					printf("\nDIV BX");
					printf("\nMOV AX,DX");
					break;
			}
			printf("\nMOV '%c',AX",code[0]);
		}
		else
			printf("Invalid 3 address code\n");
	}
	else if(n==3)
	{
		if(isalnum(code[0])&&isalnum(code[2]))
		{
			printf("\nMOV '%c','%c'",code[0],code[2]);
		}
		else
			printf("Invalid 3 address code\n");
	}

	getch();
}