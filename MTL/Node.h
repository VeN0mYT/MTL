#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"DataType.h"

void DataTemplet(DataType type,Node*node,void*data);
void KeyTemplet(DataType type,NodeMap*node,void*data);
void ValueTemplet(DataType type,NodeMap*node,void*data);

//==================================
//==================================
//==================================


Node*CreateNode(DataType type,void*data);

Node*CreateNodeNext(DataType type,void*data,Node*next);

Node*CreateNodeDouble(DataType type,void*data,Node*prev,Node*next);

void GetNodeData(Node*node,void*data);

void PrintNode(Node*node);

void FreeNode(Node*node);
//=================================
//=================================
//=================================


NodeMap*CreateNodeMap(DataType typeKey,DataType typeValue,void*key,void*data);

NodeMap* CreateNodeMapNext(DataType typekey, DataType typeValue, void* key, void* data, NodeMap* next);

NodeMap* CreateNodeMapDouble(DataType typeKey, DataType typeValue, void* key, void* data, NodeMap* prev, NodeMap* next);

void GetNodeMapData(NodeMap*node,void*data);

void PrintNodeMap(NodeMap*node);

void FreeNodeMap(NodeMap*node);
#endif // !

