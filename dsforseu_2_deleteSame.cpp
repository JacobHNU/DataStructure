#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define MAXSIZE 50
typedef int Elemtype;

typedef struct
{
	int len;
	Elemtype data[MAXSIZE];
}SqList;

//有序顺序表采用类似直接插入法思想
//初始时将第一个元素看作非重复的有序表，之后以此判断后面的元素是否与前面非重复的最后一个元素是否相同（所以此处必须为有序顺序表），
//如果相同则继续往后找，如果不同则加入非重复有序表的最后一个，直至判断到表尾为止
bool deleteSame_ex(SqList &list)
{
	if (list.len == 0)
		return false;
	int i, j;     //i存储每次查找到的第一个非重复的元素,也即非重复有序表的最后一个元素，j为工作指针
	for (i = 0, j = 1; j < list.len; j++) {
		if (list.data[i] != list.data[j])
			list.data[++i] = list.data[j];
	}
	list.len = i + 1;
	return true;
}

//无序顺序表,删除重复元素，利用hash表
void deleteSame(SqList &list)
{

}


//利用set集合来实现
/*
	set的单元素版返回一个二元组（Pair）。
	成员 pair::first 被设置为指向新插入元素的迭代器或指向等值的已经存在的元素的迭代器。
	成员 pair::second 是一个 bool 值，如果新的元素被插入，返回 true，
	如果等值元素已经存在（即无新元素插入），则返回 false
*/
//因为在 set 中元素的主键是唯一的，当前插入操作将会检测被插入元素是否等于容器中某个已存在元素，
//如果是，新的元素将不会被插入，且返回指向这个等值的已经存在的元素（如果当前函数有返回值）。
//所以set.insert().second是用来确认set元素是否成功插入的标识，也可以用来确认该元素之前没有被插入也没有被处理过。
void useSETtoDeleteSame(SqList &list)
{
	set<int> setInt;
	size_t length = list.len;
	for (int i = 0; i < length; i++) {
		if (setInt.insert(list.data[i]).second)
			cout << list.data[i]<<" ";
	}
	cout << endl;
}


void inputList(SqList &list)
{
	int length = 0, value = 0;
	cout << " enter the len of list: " << endl;
	cin >> length;
	list.len = length;
	cout << "enter the number of list: " << endl;
	for (int i = 0; i < list.len; i++) {
		cin >> value;
		list.data[i] = value;
	}
}

void outputList(SqList list)
{
	cout << "list numbers are: " << endl;
	for (int i = 0; i < list.len; i++) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

int main()
{
	SqList list;
	inputList(list);
	useSETtoDeleteSame(list);
	cout << "plz enter order parameter: " << endl;
	inputList(list);
	deleteSame_ex(list);
	outputList(list);
	system("pause");
}
