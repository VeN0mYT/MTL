#ifndef QUEUE_H
#define QUEUE_H
#include"Node.h"

Queue* createQueue(DataType type);
int isEmptyQueue(Queue* queue);
void PushQueue(Queue* queue, void*data);
void PopQueueRet(Queue* queue,void*data);
void PopQueue(Queue* queue);
void TopQueue(Queue* queue,void*data);
int CopyQueue(Queue* dest, Queue* src);
int PrintQueue(Queue* queue);
int QueueSize(Queue* queue);
void FreeQueue(Queue* queue);

#endif
