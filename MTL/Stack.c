#include "Stack.h"

Stack* createStack(DataType type)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->type = type;
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

int isEmptyStack(Stack* stack)
{
	return stack->top == NULL;
}

void PushStack(Stack* stack, void* data)
{
	if (isEmptyStack(stack))
	{
		stack->top = CreateNode(stack->type, data);
	}
	else
	{
		stack->top = CreateNodeNext(stack->type, data, stack->top);
	}
	stack->size++;
}

void PopStackRet(Stack* stack,void* data)
{
	if (isEmptyStack(stack)) return;
	GetNodeData(stack->top, data);
	PopStack(stack);
	stack->size--;
}

void PopStack(Stack* stack)
{
	if (isEmptyStack(stack)) return;
	Node* temp = stack->top;
	stack->top = stack->top->left;
	FreeNode(temp);
	stack->size--;
}

void TopStack(Stack* stack, void* data)
{
	if (isEmptyStack(stack)) return;
	GetNodeData(stack->top, data);
}

int CopyStack(Stack* dest, Stack* src)
{
	if(isEmptyStack(src)) return 0;
	if(src->type!=dest->type) return 0;
	Node* temp = src->top;
	Stack* tempStack = createStack(src->type);
	while (temp != NULL)
	{
		PushStack(tempStack, temp->data);
		temp = temp->left;
	}
	temp = tempStack->top;
	while (temp != NULL)
	{
		PushStack(dest, temp->data);
		temp = temp->left;
	}
	FreeStack(tempStack);
	dest->size = src->size;

	return 1;
}

int PrintStack(Stack* stack)
{
	if(isEmptyStack(stack)) return 0;
	Node* temp = stack->top;
	while (temp != NULL)
	{
		PrintNode(temp);
		temp = temp->left;
	}
	return 1;
}

int ReverseStack(Stack* stack)
{
	if(isEmptyStack(stack)) return 0;
	Stack* tempStack = createStack(stack->type);
	while (!isEmptyStack(stack))
	{
		PushStack(tempStack, stack->top->data);
		PopStack(stack);
	}
	Node* temp = stack->top;
	stack->top = tempStack->top;
	tempStack->top = temp;
	FreeStack(tempStack);
	return 1;
}

int StackSize(Stack* stack)
{
	return stack->size;
}

void FreeStack(Stack* stack)
{
	while (!isEmptyStack(stack))
	{
		PopStack(stack);
	}
	free(stack);
}
