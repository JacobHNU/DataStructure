#pragma once
#define M 7   //f(key) = key % M ，M must less than the length of hashtable
typedef int ElemType;

//struct of linkList
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *pNode;

//struct of hashtable
typedef struct HashNode
{
	pNode first;   //the first pNode pointer pointers the first elem of linkList 
}HashNode,*HashTable;

//create hashtable
HashTable createHashTable(int);

//search elem in hashtable
pNode searchHashTable(HashTable, ElemType);

//insert elem to hashtable
bool insertHashTable(HashTable, ElemType);

//delete elem from hashtable
bool deleteHashTable(HashTable, ElemType);

//destroy hashtable
void destroyHashTable(HashTable, int);
