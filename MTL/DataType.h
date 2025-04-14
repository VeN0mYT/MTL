#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum DataType
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	STRING,
	STACK,  // work but a prototype
	POINTER // under testing
}DataType;
//normal node
typedef struct Node {
	void* data;
	DataType type;
	int size;
	struct Node* right;
	struct Node* left;
}Node;
//node for map
typedef struct NodeMap
{
	void* key;
	void* data;
	DataType typeKey;
	DataType typeValue;
	int size;
	struct NodeMap* right;
	struct NodeMap* left;
}NodeMap;
//==================================
//==================================
//==================================
//==================================
//Data Structures Types
//====================
//stack
typedef struct Stack
{
	Node* top;
	DataType type;
	int size;
}Stack;

//queue

typedef struct Queue
{
	Node* front;
	Node* rear;
	DataType type;
	int size;
}Queue;

//deque
typedef struct Deque
{
	Node* head;
	Node* tail;
	DataType type;
	int size;
}Deque;
//undordered map
typedef struct unordered_map
{
	NodeMap* Bucket[1007];
	DataType typeKey;
	DataType typeValue;
	int size;
}unordered_map;


#endif