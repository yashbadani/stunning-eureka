//elimination of common subsequence
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void main()
{
	char code[20][6],tempcode[20][6],opticode[20][6];
	//'tempcode' is everything after equal. 'opticode' used to check if 'tempcode' exists
	int i,j,k,n,flag,check,indexer[20];
	//indexer holds optimized lines from 'code'
	clrscr();

	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter 3 address code sequence:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",&code[i]);
	}

	//initialize tempcode with code after = sign
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=2;code[i][j]!='\0';j++)
		{
			tempcode[i][k]=code[i][j];
			k++;
		}
		tempcode[i][k]='\0';
	}

	//main logic. first line in code is already optimized.
	k=0;//optimized code counter
	strcpy(opticode[k],tempcode[0]);
	indexer[k]=0;
	k++;
	for(i=1;i<n;i++)
	{
		flag=0;//if 1, optimized code contains the same expression
		for(j=0;j<k;j++)
		{
			check=strcmp(tempcode[i],opticode[j]);
			if(check==0)
			{
				flag=1;
				break;
			}
			else
				continue;
		}
		if(flag==0)
		{
			strcpy(opticode[k],tempcode[i]);
			indexer[k]=i;
			k++;
		}
	}

	printf("\nOptimized is: \n");
	for(i=0;i<k;i++)
	{
		printf("%s\n",code[indexer[i]]);
	}

	getch();
}