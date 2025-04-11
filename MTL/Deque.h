#ifndef DEQUE_H
#define DEQUE_H
#include"Node.h"

Deque* createDeque(DataType type);
int isEmptyDeque(Deque* deque);
void HPushDeque(Deque* deque, void*data);
void TPushDeque(Deque* deque, void*data);
void HPopDequeRet(Deque* deque, void*data);
void TPopDequeRet(Deque* deque, void*data);
void HPopDeque(Deque* deque);
void TPopDeque(Deque* deque);
void HTopDeque(Deque* deque, void*data);
void TTopDeque(Deque* deque, void*data);
int CopyDeque(Deque* dest, Deque* src);
int PrintDeque(Deque* deque);
int DequeSize(Deque* deque);
void FreeDeque(Deque* deque);


#endif