#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	int i,j,n;
	char b[50][50];
	char d[20][20];
	clrscr();

	printf("enter the number of insrtuctions");
	scanf("%d",&n);

	printf("enter the instructions:");
	for(i=0;i<n;i++)
	{
		scanf("%s",b[i]);
	}

	printf("operater result arg1 arg2\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(b[i]);j++)
		{
			if((b[i][j]=='+')||(b[i][j]=='*')||(b[i][j]=='/')||(b[i][j]=='-'))
			{
				printf("%c\t",b[i][j]);
				break;
			}
		}
		if(j==strlen(b[i]))
			printf("=\t");

		j=0;
		while(isalnum(b[i][j]))
		{
			printf("%c",b[i][j]);
			j++;
		}
		printf("\t");
		j++;
		while(isalnum(b[i][j]))
		{
			printf("%c",b[i][j]);
			j++;
		}
		printf("\t");
		j++;
		while(isalnum(b[i][j]))
		{
			printf("%c",b[i][j]);
			j++;
		}
		printf("\n");
	}
	getch();
}
