#ifndef STACK_H
#define STACK_H
#include"Node.h"



Stack* createStack(DataType type);
int isEmptyStack(Stack* stack);
void PushStack(Stack* stack, void*data);
void PopStackRet(Stack* stack,void*data);
void PopStack(Stack* stack);
void TopStack(Stack* stack,void*data);
int CopyStack(Stack* dest, Stack* src);
int PrintStack(Stack* stack);
int ReverseStack(Stack* stack);
int StackSize(Stack* stack);
void FreeStack(Stack* stack);
#endif
