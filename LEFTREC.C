#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void main()
{
	char prod[20],rep=' ';
	int i;

	clrscr();

	printf("\nEnter the production:\n");
	gets(prod);

	if(isupper(prod[0])&&prod[0]==prod[3])
	{
		for(i=3;i<strlen(prod);i++)
		{
			if(prod[i]=='|')
			{
				if(prod[i+1]!=prod[0]&&(prod[i+2]=='\0'||prod[i+2]=='|'))
				{
					rep=prod[i+1];
				}
			}
		}
		if(rep==' ')
		{
			printf("Cannot remove left recursion");
			getch();
			exit(0);
		}
		printf("Left recursive Production found !!!\n");
		printf("%c -> %c%c'\n",prod[0],rep,prod[0]);
		printf("%c' -> ",prod[0]);
		for(i=4;prod[i]!='|';i++)
		{
			printf("%c",prod[i]);
		}
		printf("%c'|^",prod[0]);
	}
	else
		printf("Not in left recursion. Valid");

	getch();
}
