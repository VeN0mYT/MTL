#ifndef TEST_H
#define TEST_H
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"unordered_map.h"
#include<ctype.h>

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

void testPOSTFIX_PROGRAM()
{
	Stack* num = createStack(CHAR);
	Stack* ope = createStack(CHAR);
	Stack* ans = createStack(CHAR);

	char input[] = "((1+2)*3+4)";

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
					char op = '0';
					PopStackRet(ope, &op);
					PushStack(num, &op);
					TopStack(ope, &temp);
				}
				PopStack(ope);
			}
			else
			{
				char temp = '0';
				TopStack(ope, &temp);
				while (!isEmptyStack(ope) && temp != '(' && isOperator(input[i]) <= isOperator(temp))
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
			int n1 = b - '0', n2 = a - '0';
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
			char r = result + '0';
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
}

void testSTACK()
{
	Stack* s = createStack(INT);
	for(int i = 0;i < 10;i++) PushStack(s, &i);
	ReverseStack(s);
	PrintStack(s);
	FreeStack(s);
}

void testSTRING()
{
	Stack* s = createStack(STRING);
	char str[] = "hello world";
	char str2[] = "hi";
	char str3[] = "bro";
	PushStack(s, str);
	PushStack(s, str2);
	PushStack(s, str3);
	PrintStack(s);
	FreeStack(s);
}

void testMAP()
{
	unordered_map* map = createUnordered_map(CHAR, INT);
	char m = 'a';
	int x = 5;
	x = 10;
	PutUnordered_map(map, &m, &x);
	PutUnordered_map(map, &m, &x);
	int y = 0;
	GetUnordered_map(map, &m, &y);
	printf("%d\n", y);
	FreeUnordered_map(map);

}

typedef struct PLAYER
{
	char name[20];
	int score;
}PLAYER;

void testPTR()
{
	PLAYER* p = malloc(sizeof(PLAYER));
	p->score = 10;

	Stack* st = createStack(POINTER);
	PushStack(st, &p);
	void* get = NULL;
	PLAYER* p2 = NULL;
	PopStackRet(st, &get);
	p2 = (PLAYER*)get;
	printf("%d", p2->score);
}

#endif // !TEST_H

