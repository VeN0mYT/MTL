#include<stdio.h>
#include"Stack.h"
#include<ctype.h>

// check test header 
// unordered_map not fully finished yet
// the library still a prototype

int isOperator(char c)
{
	switch (c)
	{
	case'+':
	case'-':
		return 1;
	case'/':
	case'*':
		return 2;
	}
	return 0;
}

int main()
{
	Stack*num = createStack(CHAR);
	Stack*ope = createStack(CHAR);
	Stack*ans = createStack(CHAR);

	char* input = "((1+2)*3+4)";

	for (int i = 0;i < strlen(input);i++)
	{
		if (isdigit(input[i]))
		{
			PushStack(num, &input[i]);
		}
		else
		{
			if (input[i] == '(')
			{
				PushStack(ope, &input[i]);
			}
			else if (input[i] == ')')
			{
				char temp = '0';
				TopStack(ope, &temp);
				while (!isEmptyStack(ope) && temp != '(')
				{
					char op='0';
					PopStackRet(ope, &op);
					PushStack(num,&op);
					TopStack(ope, &temp);
				}
				PopStack(ope);
			}
			else
			{
				char temp = '0';
				TopStack(ope, &temp);
				while (!isEmptyStack(ope) &&temp != '(' && isOperator(input[i]) <= isOperator(temp))
				{
					char op = '0';
					PopStackRet(ope, &op);
					PushStack(num, &op);
					TopStack(ope, &temp);
				}
				PushStack(ope, &input[i]);
			}
		}
	}
	while (!isEmptyStack(ope))
	{
		char op = '0';
		PopStackRet(ope, &op);
		PushStack(num, &op);
	}
	ReverseStack(num);
	PrintStack(num);
	printf("\n");


	while (!isEmptyStack(num))
	{
		char temp = '0';
		TopStack(num, &temp);
		if (isdigit(temp))
		{
			PopStackRet(num, &temp);
			PushStack(ans, &temp);
		}
		else
		{
			char b = '0';
			PopStackRet(ans, &b);
			char a = '0';
			PopStackRet(ans, &a);
			int n1 = b-'0', n2 = a - '0';
			int result = 0;
			switch (temp)
			{
			case'+':
				result = n1 + n2;
				break;
			case'-':
				result = n1 - n2;
				break;
			case'*':
				result = n1 * n2;
				break;
			case'/':
				result = n1 / n2;
				break;
			}
			char r = result+'0';
			PushStack(ans, &r);
			PopStack(num);
		}
	}
	int result = 0;
	char temp = '0';
	TopStack(ans, &temp);
	result = temp - '0';
	printf("%d\n", result);
	FreeStack(num);
	FreeStack(ope);
	FreeStack(ans);
	return 0;
}