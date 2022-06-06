#include<bits/stdc++.h>
using namespace std;
char arr[3];

void isCorrect(char *str)
{

	int semicolon = 0, bracket1 = 0, bracket2 = 0, flag = 0;

	int i;
	for (i = 0; i < 3; i++)
		arr[i] = str[i];


	if(strcmp(arr, "for") != 0)
	{
		printf("Error in for keyword usage");
		return;
	}


	while(i != strlen(str))
	{
		char ch = str[i++];
		if(ch == '(')
		{

			bracket1 ++;
		}
		else if(ch == ')')
		{

			bracket2 ++;

		}
		else if(ch == ';')
		{

			semicolon ++;
		}
		else continue;

	}


	if(semicolon != 2)
	{
		printf("\nSemicolon Error");
		flag++;
	}

	else if(str[strlen(str) - 1] != ')')
	{
		printf("\nClosing parenthesis absent at end");
		flag++;
	}


	else if(str[3] == ' ' && str[4] != '(' )
	{
		printf("\nOpening parenthesis absent after for keyword");
		flag++;
	}


	else if(bracket1 != 1 || bracket2 != 1 || bracket1 != bracket2)
	{
		printf("\nParentheses Count Error");
		flag++;
	}


	if(flag == 0)
		printf("\nNo error");

}
int main()
{
    char str1[100] = "for (i = 10; i < 20; i++)";
	isCorrect(str1);

	char str2[100] = "for i = 10; i < 20; i++)";
	isCorrect(str2);

    return 0;

}
