#include<iostream>
using namespace std;

#define MAX 50
typedef int ElemType;

typedef struct
{
	int length;
	ElemType data[MAX];
}SeqList;

bool orderListMerge(SeqList listA, SeqList listB, SeqList &listC)
{
	if (listA.length + listB.length > MAX )
		return false;
	int i = 0, j = 0, k = 0;
	//循环两两比较，较小的加入listC中
	while (i < listA.length && j < listB.length) { 
		if (listA.data[i] <= listB.data[j])
			listC.data[k++] = listA.data[i++];
		else
			listC.data[k++] = listB.data[j++];
	}
	//还剩余一个循序表没有添加完的继续添加
	while (i < listA.length)
		listC.data[k++] = listA.data[i++];
	while (j < listB.length)
		listC.data[k++] = listB.data[j++];
	listC.length = k;
	return true;
}

void inputList(SeqList &list)
{
	int len = 0, value = 0;
	cout << " enter the len of list: " << endl;
	cin >> len;
	list.length = len;
	cout << "enter the number of list: " << endl;
	for (int i = 0; i < list.length; i++) {
		cin >> value;
		list.data[i] = value;
	}
}

void outputList(SeqList list)
{
	cout << "list numbers are: " << endl;
	for (int i = 0; i < list.length; i++) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}


int main()
{
	SeqList listA,listB,listC;
	inputList(listA);
	outputList(listA);
	inputList(listB);
	outputList(listB);
	orderListMerge(listA, listB, listC);
	outputList(listC);
	system("pause");
	return 0;
}