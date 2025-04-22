#include "unordered_map.h"

unordered_map* createUnordered_map(DataType typeKey, DataType typeValue)
{
	unordered_map* map = (unordered_map*)malloc(sizeof(unordered_map));
	map->typeKey = typeKey;
	map->typeValue = typeValue;
	map->size = 0;
	for(int  i = 0;i<MAX;i++) map->Bucket[i] = NULL;
	return map;
}

int compare_MAP(DataType type, void* key1, void* key2)
{
	switch (type)
	{
		case INT:
			if (*(int*)key1 == *(int*)key2) return 1;
			break;
		case CHAR:
			if(*(char*)key1 == *(char*)key2) return 1;
			break;
		case FLOAT:
			if(*(float*)key1 == *(float*)key2) return 1;
			break;
		case DOUBLE:
			if(*(double*)key1 == *(double*)key2) return 1;
			break;
		case STRING:
			if (strcmp((char*)key1, (char*)key2) == 0) return 1;
			break;
		case STACK:
			if (*(Stack**)key1 == *(Stack**)key2) return 1;
			break;
		case POINTER:													// stack and pointer still need to be tested!!!
			if (*(void**)key1 == *(void**)key2) return 1;
			break;
	default:
		printf("this data type is not supported to be compared\n");
		exit(EXIT_FAILURE);
		break;
	}
	return 0;
}

int hash(void* key, DataType type)
{
	
		size_t h = 0;
		switch (type)
		{
		case INT:
			h = (*(int*)key) * 2654435761 % MAX; 
			break;
		case FLOAT:
			h = (size_t)(*(float*)key * 1000) % MAX;  
			break;
		case STRING:
			for (char* p = (char*)key; *p; p++)
				h = (h * 31) + (*p);  
			break;
		default:
			h = (size_t)key % MAX;  
			break;
		}
		return h % MAX;
}


int isEmptyUnordered_map(unordered_map* unordered_map)
{
	return unordered_map->size == 0;
}

void PutUnordered_map(unordered_map* unordered_map, void* key, void* value)
{
	int index = hash(key, unordered_map->typeKey);
	NodeMap* nodeTemp = unordered_map->Bucket[index];
	while (nodeTemp != NULL)
	{
		if (compare_MAP(unordered_map->typeKey, key, nodeTemp->key))
		{
			ValueTemplet(unordered_map->typeValue, nodeTemp, value);
			return;
		}
		nodeTemp = nodeTemp->left;
	}
	NodeMap* node = CreateNodeMap(unordered_map->typeKey, unordered_map->typeValue, key, value);
	node->left = unordered_map->Bucket[index];
	unordered_map->Bucket[index] = node;
	unordered_map->size++;

}

void GetUnordered_map(unordered_map* unordered_map, void* key, void* value)
{
	if(isEmptyUnordered_map(unordered_map)) return;
	int index = hash(key, unordered_map->typeKey);
	NodeMap* node = unordered_map->Bucket[index];
	while (node != NULL)
	{
		if (compare_MAP(unordered_map->typeKey, key, node->key))
		{
			GetNodeMapData(node, value);
			return;
		}
		node = node->left;
	}
	value = NULL;
}

void RemoveUnordered_map(unordered_map* unordered_map, void* key)
{
	if (isEmptyUnordered_map(unordered_map)) return;

	int index = hash(key, unordered_map->typeKey);
	NodeMap* node = unordered_map->Bucket[index];
	NodeMap* prevNode = NULL;

	while (node != NULL)
	{
		if (compare_MAP(unordered_map->typeKey, key, node->key))
		{
			if (prevNode == NULL) // First node in the bucket
			{
				unordered_map->Bucket[index] = node->left;
			}
			else
			{
				prevNode->left = node->left;
			}

			FreeNodeMap(node);
			unordered_map->size--;
			return;
		}
		prevNode = node;
		node = node->left;
	}
}

int CopyUnordered_map(unordered_map* dest, unordered_map* src)
{
	return 0;
}

int FindUnordered_map(unordered_map* unordered_map, void* key)
{
	if(isEmptyUnordered_map(unordered_map)) return 0;
	int index = hash(key, unordered_map->typeKey);
	NodeMap* node = unordered_map->Bucket[index];
	while (node != NULL)
	{
		if (compare_MAP(unordered_map->typeKey, key, node->key)) return 1;
		node = node->left;
	}
	if(node == NULL) return 0;
	return 0;
}

int Unordered_MapSize(unordered_map* unordered_map) { return unordered_map->size; }
void FreeUnordered_map(unordered_map* unordered_map)
{
	for (int i = 0;i < MAX;i++)
	{
		NodeMap* node = unordered_map->Bucket[i];
		while (node != NULL)
		{
			NodeMap* next = node->left;
			FreeNodeMap(node);
			node = next;
		}
	}
	free(unordered_map);
}
