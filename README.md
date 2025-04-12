this a library in c made to semulate the stls of c++ and work on diffrant datatypes to semulate the template of c++ but it still a prototype and not fully finished yet

supported datatype for now INT CHAR FLOAT DOUBLE STRING

!!! you have to assgine value in functions by (&) like  PushStack(s,&m);  if (int m = 5;) same when get a value (int x = 0;) TopStack(s,&x);
```
you can do that for example

+ Stack*s = createStack(INT);
+ Stack*s = createStack(CHAR);
+ Stack*s = createStack(STRING);
```

```###Stack functions###```

+ Stack* createStack(DataType type);   
+ int isEmptyStack(Stack* stack);
+ void PushStack(Stack* stack, void*data);
+ void PopStackRet(Stack* stack,void*data);  ### pop calue with return ###
+ void PopStack(Stack* stack);  ### pop with no return ###
+ void TopStack(Stack* stack,void*data);
+ int CopyStack(Stack* dest, Stack* src);
+ int PrintStack(Stack* stack);
+ int ReverseStack(Stack* stack);
+ int StackSize(Stack* stack);
+ void FreeStack(Stack* stack);


```###Queue functions###```

+ Queue* createQueue(DataType type);
+ int isEmptyQueue(Queue* queue);
+ void PushQueue(Queue* queue, void*data);
+ void PopQueueRet(Queue* queue,void*data);  ### pop calue with return ###
+ void PopQueue(Queue* queue);  ### pop with no return ###
+ void TopQueue(Queue* queue,void*data);
+ int CopyQueue(Queue* dest, Queue* src);
+ int PrintQueue(Queue* queue);
+ int QueueSize(Queue* queue);
+ void FreeQueue(Queue* queue);

```###Deque functions###```

+ Deque* createDeque(DataType type);
+ int isEmptyDeque(Deque* deque);
+ void HPushDeque(Deque* deque, void*data);  ### push in head ###
+ void TPushDeque(Deque* deque, void*data);  ### push in tail ###
+ void HPopDequeRet(Deque* deque, void*data);  ### pop from head with return value ###
+ void TPopDequeRet(Deque* deque, void*data);  ### pop from tail with return value ###
+ void HPopDeque(Deque* deque);  ### pop from head no return value ###
+ void TPopDeque(Deque* deque);   ### pop from tail no return value ###
+ void HTopDeque(Deque* deque, void*data);
+ void TTopDeque(Deque* deque, void*data);
+ int CopyDeque(Deque* dest, Deque* src);
+ int PrintDeque(Deque* deque);
+ int DequeSize(Deque* deque);
+ void FreeDeque(Deque* deque);

```### unordered_map functions ###    not fully finished or staible yet```

+ unordered_map* createUnordered_map(DataType typeKey,DataType typeValue);
+ int compare(DataType type,void*key1,void*key2);
+ int hash(void*key, DataType type);
+ int isEmptyUnordered_map(unordered_map*unordered_map);
+ void PutUnordered_map(unordered_map*unordered_map,void*key,void*value);
+ void GetUnordered_map(unordered_map*unordered_map,void*key,void*value);
+ void RemoveUnordered_map(unordered_map*unordered_map,void*key);    
+ int CopyUnordered_map(unordered_map*dest,unordered_map*src);
+ int FindUnordered_map(unordered_map*unordered_map,void*key);
+ void FreeUnordered_map(unordered_map*unordered_map);
