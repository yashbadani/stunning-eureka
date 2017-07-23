//macro name table generation
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	char macrocode[50][50],mnt[20][20],mdt[100];
	int mntp=0,mdtp=0,i,j,k,n=10,checkstart,checkend,flag;
	clrscr();

	printf("Enter the macro code:\n");

	for(i=0;i<n;i++)
	{
		gets(macrocode[i]);
	}

	printf("ID\tMacro Name\tMDT Index\n-----------------------------------------\n");
	for(i=0;i<n;i++)
	{
		checkstart=strcmpi("MACRO",macrocode[i]);
		checkend=strcmpi("MEND",macrocode[i]);
		if(checkstart==0)
		{
			i++;
			for(j=0;macrocode[i][j]!=' ';j++)
			{
				mnt[mntp][j]=macrocode[i][j];
			}
			mnt[mntp][j]='\0';
			printf("%d\t%s\t\t%d\n",mntp,mnt[mntp],mdtp);
			flag=1;
			mntp++;
		}
		else if(flag==1)
		{
			mdtp++;
		}

		if(checkend==0)
		{
			flag=0;
			mdtp++;
		}
	}

	getch();
}

