#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

int trans[10][10], start, finish[10]={NULL}, finish_no;

void main()
{
	int i,j,k,n,e,s,flag; //s states over e symbols, k current state
	char input[50];

	clrscr();

	printf("How many states do you want? ");
	scanf("%d",&s);
	printf("Over how many input symbols? ");
	scanf("%d",&e);

	printf("\nInitial state: ");
	scanf("%d",&start);

	printf("How many Final states: ");
	scanf("%d",&finish_no);

	printf("Enter the final states: ");
	for(i=0;i<finish_no;i++)
	{
		scanf("%d",&finish[i]);
	}

	printf("\nEnter the transition table:\n");
	for(i=0;i<s;i++)
	{
		for(j=0;j<e;j++)
		{
			scanf("%d",&trans[i][j]);
		}
	}

	fflush(stdin);
	printf("Enter the input string:");
	gets(input);

	n=strlen(input);

	if(n>32)
	{
		n=32;
		printf("Only first 32 characters will be considered\n");
	}

	//main logic
	k=0; //initially
	for(i=0;i<n;i++)
	{
		if(isalpha(input[i]))
			k=trans[k][0];
		else if(isdigit(input[i]))
			k=trans[k][1];
		else if(input[i]=='_')
			k=k;
	}
	//end of main logic

	//transition table validation
	if(finish_no==1)
	{
		if(k==finish[0])
			printf("Valid");
		else
			printf("Invalid");
	}
	else
	{
		flag=0;
		for(i=0;i<finish_no;i++)
		{
			if(k==finish[i])
			{
				printf("Valid");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Invalid");
	}

	getch();
}