#include "Node.h"

void DataTemplet(DataType type, Node*node, void* data)
{
	switch (type)
	{
	case INT:
		node->data = (int*)malloc(sizeof(int));
		node->type = INT;
		node->size = sizeof(int);
		memcpy(node->data, data, sizeof(int));
		break;
	case FLOAT:
		node->data = (float*)malloc(sizeof(float));
		node->type = FLOAT;
		node->size = sizeof(float);
		memcpy(node->data, data, sizeof(float));
		break;
	case DOUBLE:
		node->data = (double*)malloc(sizeof(double));         // if it crash here you may forget to send the variable by (&) refrance
		node->type = DOUBLE;
		node->size = sizeof(double);
		memcpy(node->data, data, sizeof(double));
		break;
	case CHAR:
		node->data = (char*)malloc(sizeof(char));
		node->type = CHAR;
		node->size = sizeof(char);
		memcpy(node->data, data, sizeof(char));
		break;
	case STRING:
		node->data = strdup(data);
		node->type = STRING;
		node->size = strlen(data);
		break;
	case STACK:
		node->data = malloc(sizeof(Stack*));  
		if (node->data) {
			*(Stack**)node->data = (Stack*)data;  //need fix show garpage value
		}
		node->type = STACK;
		node->size = sizeof(Stack*);
		break;
	default:
		break;
	}
}

void KeyTemplet(DataType type, NodeMap* node, void* data)
{
	switch (type)
	{
	case INT:
		node->key = (int*)malloc(sizeof(int));
		node->typeKey = INT;
		node->size = sizeof(int);
		memcpy(node->key, data, sizeof(int));
		break;
	case FLOAT:
		node->key = (float*)malloc(sizeof(float));
		node->typeKey = FLOAT;
		node->size = sizeof(float);
		memcpy(node->key, data, sizeof(float));
		break;
	case DOUBLE:
		node->key = (double*)malloc(sizeof(double));		// if it crash here you may forget to send the variable by (&) refrance
		node->typeKey = DOUBLE;
		node->size = sizeof(double);
		memcpy(node->key, data, sizeof(double));
		break;
	case CHAR:
		node->key = (char*)malloc(sizeof(char));
		node->typeKey = CHAR;
		node->size = sizeof(char);
		memcpy(node->key, data, sizeof(char));
		break;
	case STRING:
		node->key = strdup(data);
		node->typeKey = STRING;
		node->size = strlen(data);
		break;
	default:
		break;
	}
}

void ValueTemplet(DataType type, NodeMap* node, void* data)
{
	switch (type)
	{
	case INT:
		node->data = (int*)malloc(sizeof(int));
		node->typeValue = INT;
		node->size = sizeof(int);
		memcpy(node->data, data, sizeof(int));
		break;
	case FLOAT:
		node->data = (float*)malloc(sizeof(float));
		node->typeValue = FLOAT;
		node->size = sizeof(float);
		memcpy(node->data, data, sizeof(float));
		break;
	case DOUBLE:
		node->data = (double*)malloc(sizeof(double));			// if it crash here you may forget to send the variable by (&) refrance
		node->typeValue = DOUBLE;
		node->size = sizeof(double);
		memcpy(node->data, data, sizeof(double));
		break;
	case CHAR:
		node->data = (char*)malloc(sizeof(char));
		node->typeValue = CHAR;
		node->size = sizeof(char);
		memcpy(node->data, data, sizeof(char));
		break;
	case STRING:
		node->data = strdup(data);
		node->typeValue = STRING;
		node->size = strlen(data);
		break;
	default:
		break;
	}
}

Node* CreateNode(DataType type, void* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	DataTemplet(type, node, data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* CreateNodeNext(DataType type, void* data, Node* next)
{
	Node* node = (Node*)malloc(sizeof(Node));
	DataTemplet(type, node, data);
	node->left = next;
	node->right = NULL;
	return node;
}

Node* CreateNodeDouble(DataType type, void* data, Node* prev, Node* next)
{
	Node* node = (Node*)malloc(sizeof(Node));
	DataTemplet(type, node, data);
	node->left = next;
	node->right = prev;
	return node;
}

void GetNodeData(Node* node, void* data)
{
	if (node == NULL)
	{
		printf("Accessing Node is NULL\n");
		exit(1);
		return;
	}
	switch (node->type)
	{
	case INT:
		memcpy(data, node->data, sizeof(int));
		break;
	case FLOAT:
		memcpy(data, node->data, sizeof(float));
		break;
	case DOUBLE:
		memcpy(data, node->data, sizeof(double));		// if it crash here you may forget to get the variable by (&) refrance
		break;
	case CHAR:
		memcpy(data, node->data, sizeof(char));
		break;
	case STRING:
		*(char**)data = strdup((char*)node->data);
		break;
	case STACK:
		if (node->data != NULL) {
			*(Stack**)data = *(Stack**)node->data;
		}
		else {
			*(Stack**)data = NULL;
		}
		break;
	default:
		break;
	}
}

void PrintNode(Node* node)
{
	switch (node->type)
	{
	case INT:
		printf("%d ", *(int*)node->data);
		break;
	case FLOAT:
		printf("%f ", *(float*)node->data);
		break;
	case DOUBLE:
		printf("%lf ", *(double*)node->data);
		break;
	case CHAR:
		printf("%c ", *(char*)node->data);
		break;
	case STRING:
		printf("%s ", node->data);
		break;
	default:
		break;
	}
}

void FreeNode(Node* node)
{
	if(node == NULL) return;
	if(node->data!=NULL)
	free(node->data);
	free(node);
}
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===================================================
//===========^========^==============================
//==========/=\======/=\=============================
//=========/===\====/===\============================
//========/=====\==/=====\===========================
//=======/=======\/=======\==========================
//======/==================\=========================
//=====/====================\========================
//====/======================\=======================
//===================================================
//===================================================
//===================================================
//===================================================
NodeMap* CreateNodeMap(DataType typeKey,DataType typeValue, void* key, void* data)
{
	NodeMap*node = (NodeMap*)malloc(sizeof(NodeMap));
	KeyTemplet(typeKey, node, key);
	ValueTemplet(typeValue, node, data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

NodeMap* CreateNodeMapNext(DataType typekey, DataType typeValue, void* key, void* data, NodeMap* next)
{
	NodeMap* node = (NodeMap*)malloc(sizeof(NodeMap));
	KeyTemplet(typekey, node, key);
	ValueTemplet(typeValue, node, data);
	node->left = next;
	node->right = NULL;
	return node;
}

NodeMap* CreateNodeMapDouble(DataType typeKey, DataType typeValue , void* key, void* data, NodeMap* prev, NodeMap* next)
{
	NodeMap* node = (NodeMap*)malloc(sizeof(NodeMap));
	KeyTemplet(typeKey, node, key);
	ValueTemplet(typeValue, node, data);
	node->left = next;
	node->right = prev;
	return node;
}


void GetNodeMapData(NodeMap* node, void* data)
{
	if (node == NULL)
	{
		printf("Accessing Node is NULL\n");
		exit(1);
		return;
	}
	switch (node->typeValue)
	{
	case INT:
		memcpy(data, node->data, sizeof(int));
		break;
	case FLOAT:
		memcpy(data, node->data, sizeof(float));
		break;
	case DOUBLE:
		memcpy(data, node->data, sizeof(double));		// if it crash here you may forget to get the variable by (&) refrance
		break;
	case CHAR:
		memcpy(data, node->data, sizeof(char));
		break;
	case STRING:
		*(char**)data = strdup(node->data);
		break;
	default:
		break;
	}
}

void PrintNodeMap(NodeMap* node)
{
	switch (node->typeValue)
	{
	case INT:
		printf("%d ", *(int*)node->data);
		break;
	case FLOAT:
		printf("%f ", *(float*)node->data);
		break;
	case DOUBLE:
		printf("%lf ", *(double*)node->data);		// if it crash here you may forget to get the variable by (&) refrance
		break;
	case CHAR:
		printf("%c ", *(char*)node->data);
		break;
	case STRING:
		printf("%s ", node->data);
		break;
	default:
		break;
	}
}

void FreeNodeMap(NodeMap* node)
{
	if(node == NULL) return;
	if(node->key!=NULL)
	free(node->key);
	if(node->data!=NULL)
	free(node->data);
	free(node);
}

