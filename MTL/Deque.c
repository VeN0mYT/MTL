#include "Deque.h"

Deque* createDeque(DataType type)
{
	Deque* d = malloc(sizeof(Deque));
	d->type = type;
	d->head = NULL;
	d->tail = NULL;
	d->size = 0;
	return d;
}

int isEmptyDeque(Deque* deque)
{
	return deque->head == NULL;
}

void HPushDeque(Deque* deque, void* data)
{
	Node* node = CreateNode(deque->type, data);
	if (isEmptyDeque(deque))
	{
		deque->head = node;
		deque->tail = node;
	}
	else
	{
		node->left = deque->head;
		deque->head->right = node;
		deque->head = node;
	}
	deque->size++;
}

void TPushDeque(Deque* deque, void* data)
{
	Node* node = CreateNode(deque->type, data);
	if (isEmptyDeque(deque))
	{
		deque->head = node;
		deque->tail = node;
	}
	else
	{
		node->right = deque->tail;
		deque->tail->left = node;
		deque->tail = node;
	}
	deque->size++;
}

void HPopDequeRet(Deque* deque, void* data)
{
	if (isEmptyDeque(deque)) return;

	Node* node = deque->head;
	GetNodeData(node, data);
	deque->head = node->left;

	if (deque->head) deque->head->right = NULL;  
	else deque->tail = NULL;  

	FreeNode(node);
	deque->size--;
}

void TPopDequeRet(Deque* deque, void* data)
{
	if (isEmptyDeque(deque)) return;

	Node* node = deque->tail;
	GetNodeData(node, data);
	deque->tail = node->right;

	if (deque->tail) deque->tail->left = NULL;  
	else deque->head = NULL; 

	FreeNode(node);
	deque->size--;
}


void HPopDeque(Deque* deque)
{
	if (isEmptyDeque(deque)) return;

	Node* node = deque->head;
	deque->head = node->left;

	if (deque->head) deque->head->right = NULL; 
	else deque->tail = NULL; 

	FreeNode(node);
	deque->size--;
}

void TPopDeque(Deque* deque)
{
	if (isEmptyDeque(deque)) return;

	Node* node = deque->tail;
	deque->tail = node->right;

	if (deque->tail) deque->tail->left = NULL;  
	else deque->head = NULL;  

	FreeNode(node);
	deque->size--;
}


void HTopDeque(Deque* deque, void* data)
{
	if(isEmptyDeque(deque)) return;
	GetNodeData(deque->head, data);
}

void TTopDeque(Deque* deque, void* data)
{
	if (isEmptyDeque(deque)) return;
	GetNodeData(deque->tail, data);
}

int CopyDeque(Deque* dest, Deque* src)
{
	if(isEmptyDeque(src)) return 0;
	if(src->type!=dest->type) return 0;
	Node* temp = src->head;
	while (temp != NULL)
	{
		TPushDeque(dest, temp->data);
		temp = temp->left;
	}
	return 1;
}

int PrintDeque(Deque* deque)
{
	if(isEmptyDeque(deque)) return 0;
	Node* temp = deque->head;
	while (temp != NULL)
	{
		PrintNode(temp);
		temp = temp->left;
	}
	return 1;
}

int DequeSize(Deque* deque)
{
	return deque->size;
}

void FreeDeque(Deque* deque)
{
	Node* temp = deque->head;
	while (temp != NULL)
	{
		Node* next = temp;
		temp = temp->left;
		FreeNode(next);
		
	}
	free(deque);
}
