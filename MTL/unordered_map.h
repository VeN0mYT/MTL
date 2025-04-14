#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H
#include"Node.h"
#define MAX  1007

//not fully finished

unordered_map* createUnordered_map(DataType typeKey,DataType typeValue);

int compare(DataType type,void*key1,void*key2);

int hash(void*key, DataType type);
int isEmptyUnordered_map(unordered_map*unordered_map);
void PutUnordered_map(unordered_map*unordered_map,void*key,void*value);
void GetUnordered_map(unordered_map*unordered_map,void*key,void*value);
void RemoveUnordered_map(unordered_map*unordered_map,void*key);
int CopyUnordered_map(unordered_map*dest,unordered_map*src);
int FindUnordered_map(unordered_map*unordered_map,void*key);

int Unordered_MapSize(unordered_map* unordered_map);
void FreeUnordered_map(unordered_map*unordered_map);


#endif
