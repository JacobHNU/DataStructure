#include<iostream>
using namespace std;

#define MAXSIZE 50
typedef int Elemtype;

typedef struct
{
	int length;
	Elemtype data[MAXSIZE];
}Sqlist;

//直接统计不相等的元素，k统计不相等的个数即list长度，
//工作指针i遍历list，相等的则跳过，不等的赋值给data[k]
void del_x_1(Sqlist &L, Elemtype x)
{
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

//先统计相等的，再利用i-k与工作指针i，
//在不相等的时候将i前面发现的k个相等元素都替换为data[i]
void del_x_2(Sqlist &L, Elemtype x) 
{
	int k = 0,i = 0;
	while (i < L.length)
	{
		if (L.data[i] == x)    
		{
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
		i++;
	}
	L.length = L.length - k;
}

//统计在s和t范围内元素的个数k，用不在范围内的元素data[i]替换去掉k个元素后的位置的值
bool Del_s_t(Sqlist &L, Elemtype s, Elemtype t)
{
	int i, k;
	if (L.length == 0 || s > t)
	{
		return false;
	}
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)
		{
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
	}
	L.length = L.length - k;
	return true;
}

//有序顺序表
//先找出<s的元素，让指针i指向>=s的第一个元素，并判断是否是最后一个元素，如果是则没有元素在s到t范围内，返回false
//再j=i，在i的基础上向后找<t的元素，让指针j指向>=t的第一个元素，这就使得有序表中范围在s到t内的元素全被跳过，
//再接着将data[j]逐一添加到data[i]后面
bool Del_s_t2(Sqlist &L, Elemtype s, Elemtype t)
{
	int i, j;
	if (s >= t || L.length == 0)
	{
		return false;
	}
	for (i = 0; i < L.length && L.data[i] < s; i++);
	if (i >= L.length)
	{
		return false;
	}
	for (j = i; j < L.length && L.data[j] <t; j++);
	for (; j < L.length; i++, j++)
	{
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;
}




bool Delete_Same(Sqlist &L)
{
	if (L.length == 0)
	{
		return false;
	}
	int i, j;
	for (i = 0, j = 1; j < L.length; j++)
	{
		if (L.data[i] != L.data[j])
		{
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
	return true;
}




Elemtype inputList(Sqlist &list,Elemtype x) 
{
	int len;
	cout << " enter the len of list: " << endl;
	cin >> len;
	list.length = len;
	cout << "enter the number of list: " << endl;
	for (int i = 0; i < list.length; i++) {
		cin >> x;
		list.data[i] = x;
	}
	cout << " enter the num you want to delete:" << endl;
	cin >> x;
	return x;
}

void outputList(Sqlist list)
{
	cout << "list numbers are: " << endl;
	for (int i = 0; i < list.length; i++) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

int main()
{
	Sqlist list;
	Elemtype x=0;
	x = inputList(list,x);
	del_x_1(list, x);
	outputList(list);
	return 0;
}
