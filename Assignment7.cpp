#include<iostream>
using namespace std;
struct Node
{
	int age;
	int noOfItems;
};
class Heap
{
	Node* arr;
	int currentsize;
	int totalsize;
	int totalelem;
public:
	Heap()
	{
		arr = nullptr;
		totalelem = 0;
		totalsize = 0;
		currentsize = 0;
	}
	Heap(int cap)
	{
		totalelem = 0;
		currentsize = 0;
		totalsize=cap;
		arr = new Node[totalsize + 1];
	}
	void resizeheap()
	{
		Node* temp = new Node[totalsize * 2];
		for (int i = 1; i < totalsize; i++)
		{
			temp[i] = arr[i];
		}
		totalsize *= 2;
		delete[]arr;
		arr = temp;
	}
	void insert(int age, int noOfitems)
	{
		currentsize++;
		if (currentsize == totalsize)
		{
			resizeheap();
		}
		else
		{
			arr[currentsize].age = age;
			arr[currentsize].noOfItems = noOfitems;
			totalelem += noOfitems;
			Heapify_Max();
		}
	}
	void Heapify_Max()
	{
		int i = currentsize;
		while( i >1 && arr[i].age > arr[i/2].age)
		{
			swap(arr[i].age, arr[i/2].age);
			swap(arr[i].noOfItems, arr[i/2].noOfItems);
			i = i/ 2;
		}
	}
	int gettotalsize()
	{
		return totalsize;
	}
	int gettotalitems()
	{
		return totalelem;
	}
	void print()
	{
		if (!isEmpty())
		{
			int index = 1;
			while (index <= currentsize)
			{
				cout << "CUSTOMER " << index << endl;
				cout << "AGE " << arr[index].age << " NO OF ITEMS " << arr[index].noOfItems << endl;
				index++;
			}
		}
		else
			cout << "Empty Heap\n";
	}
	bool isEmpty()
	{
		return (currentsize == 0);
	}
	~Heap()
	{
		if (arr != NULL)
		{
			delete arr;
			arr = NULL;
		}
	}
};
//Shortest heap return the shortest heap among the four
Heap& ShortestHeap(Heap& a1, Heap& a2, Heap& a3, Heap& a4)
{
	int var = a1.gettotalitems();
	if (a2.gettotalitems() < var)
	{
		var = a2.gettotalitems();
	}
	else if (a3.gettotalitems() < var)
	{
		var = a3.gettotalitems();
	}
	else if (a4.gettotalitems() < var)
	{
		var = a4.gettotalitems();
	}
	if (a1.gettotalitems() == var)
	{
		return a1;
	}
	else if (a2.gettotalitems() == var)
	{
		return a2;
	}
	else if (a3.gettotalitems() == var)
	{
		return a3;
	}
	else if (a4.gettotalitems() == var)
	{
		return a4;
	}
}
void customerinput()
{
	int val = 0;
	char choice = 'Y';
	int age = 0, items = 0;
	Heap a1(10), a2(10), a3(10), a4(10);
	bool value = false;
	while (choice == 'Y' || choice == 'y')
	{
		cout << "************Heap 1***********\n";
		a1.print();
		cout << "************Heap 2***********\n";
		a2.print();
		cout << "************Heap 3***********\n";
		a3.print();
		cout << "************Heap 4***********\n";
		a4.print();
		cout << "Do you want to pay your bill(Y/N)?\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			value = false;
			cout << "Please enter your age?\n";
			cin >> age;
			cout << "Please enter your number of items?\n";
			cin >> items;
			if (a1.isEmpty() || a2.isEmpty() || a3.isEmpty() || a4.isEmpty())
			{
				if (a1.isEmpty())
				{
					a1.insert(age, items);
				}
				else if (a2.isEmpty())
				{
					a2.insert(age, items);
				}
				else if (a3.isEmpty())
				{
					a3.insert(age, items);
				}
				else if (a4.isEmpty())
				{
					a4.insert(age, items);
				}
			}
			else if (!a1.isEmpty() || !a2.isEmpty() || !a3.isEmpty() || !a4.isEmpty())
			{
				ShortestHeap(a1, a2, a3, a4).insert(age, items);
			}
		}
		else
		{
			cout << "Exit\n";
			cout << "************Heap 1***********\n";
			a1.print();
			cout << "************Heap 2***********\n";
			a2.print();
			cout << "************Heap 3***********\n";
			a3.print();
			cout << "************Heap 4***********\n";
			a4.print();
		}
	}
}
int main()
{
	customerinput();
	return 0;
}