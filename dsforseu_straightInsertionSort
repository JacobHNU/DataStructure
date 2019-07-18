#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int Elemtype;

typedef struct
{
	int length;
	Elemtype data[MAXSIZE];
}SeqList;

/*
* straight insertion sort
* Tn = O(n^2)
*/
void insertSort(SeqList &list)
{
	int i = 0, j = 0;
	for (i = 2; i <= list.length; i++) {  //0号下标不存放数据，作为哨兵
		if (list.data[i] < list.data[i - 1]) {  
			list.data[0] = list.data[i];   //data[0]作为哨兵，存放无序区的元素
			for (j = i - 1; list.data[0] < list.data[j];j--)  //在有序区查找无序区中待排序的元素的插入位置
				list.data[j + 1] = list.data[j];     //找到插入位子，将插入位置之后的有序区元素后移
		}
		list.data[j + 1] = list.data[0];  //插入有序区
	}
}// 输入元素验证需要从下标为1开始输入，下面则不需要，直接从0开始比较,但算法复杂度为n!

void insertSort2(SeqList &list)
{
	int i = 0, j = 0;
	for (i = 1; i < list.length; i++) {
		int temp = list.data[i];
		for (j = i - 1; j >= 0 && list.data[j] > temp; j--) {
			list.data[j + 1] = list.data[j];
		}
		list.data[j + 1] = temp;
	}
}

void inputList(SeqList &list)
{
	int len = 0, value = 0;
	cout << " enter the len of list: " << endl;
	cin >> len;
	list.length = len;
	cout << "enter the number of list: " << endl;
	for (int i = 1; i <= list.length; i++) {
		cin >> value;
		list.data[i] = value;
	}
}

void outputList(SeqList list)
{
	cout << "list numbers are: " << endl;
	for (int i = 1; i <= list.length; i++) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

int main()
{
	SeqList list;
	inputList(list);
	insertSort(list);
	outputList(list);
	return 0;
}
