#include "Queue.h"

Queue* createQueue(DataType type)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->type = type;
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

int isEmptyQueue(Queue* queue)
{
	return queue->front == NULL;
}

void PushQueue(Queue* queue, void* data)
{
	Node* newNode = CreateNode(queue->type, data);
	if (isEmptyQueue(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->left = newNode;
		newNode->right = queue->rear;
		queue->rear = newNode;
	}
	queue->size++;
}

void PopQueueRet(Queue* queue, void* data)
{
	if (isEmptyQueue(queue)) return;
	Node* temp = queue->front;
	queue->front = queue->front->left;
	GetNodeData(temp, data);
	FreeNode(temp);
	queue->size--;
	if (queue->front == NULL) queue->rear = NULL;
}

void PopQueue(Queue* queue)
{
	if (isEmptyQueue(queue)) return;
	Node* temp = queue->front;
	queue->front = queue->front->left;
	FreeNode(temp);
	queue->size--;
	if(queue->front == NULL) queue->rear = NULL;
}

void TopQueue(Queue* queue, void* data)
{
	if (isEmptyQueue(queue)) return;
	GetNodeData(queue->front, data);
}

int CopyQueue(Queue* dest, Queue* src)
{
	if (isEmptyQueue(src)) return 0;
	if(src->type!=dest->type) return 0;
	Node* temp = src->front;
	while (temp != NULL)
	{
		PushQueue(dest, temp->data);
		temp = temp->left;
	}
	dest->size = src->size;
	return 1;
}

int PrintQueue(Queue* queue)
{
  if(isEmptyQueue(queue)) return 0;
	Node* temp = queue->front;
	while (temp != NULL)
	{
		PrintNode(temp);
		temp = temp->left;
	}
	return 1;
}

int QueueSize(Queue* queue)
{
	return queue->size;
}

void FreeQueue(Queue* queue)
{
	Node* temp = queue->front;
	while (temp != NULL)
	{
		Node* next = temp->left;
		FreeNode(temp);
		temp = next;
	}
	free(queue);
}
