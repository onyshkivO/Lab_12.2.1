#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next;
	int info;
};

void Create(Elem*& end, Elem*& begin, int a)
{

	Elem* tmp = new Elem;
	tmp->info = a;
	tmp->next = NULL;
	if (end != NULL)
	{
		end->next = tmp;
	}
	end = tmp;
	if (begin == NULL)
	{
		begin = tmp;
	}

}

void Print(Elem* begin)
{
	while (begin != NULL)
	{
		cout << begin->info << "\t";
		begin = begin->next;
	}
	cout << endl;
}

bool AreInElem(Elem* begin1, Elem* begin2)
{
	bool result = false;
	Elem* L = begin2;
	while (begin1 != NULL)
	{
		if (L != NULL)
		{
			if (begin1->info == L->info)
			{
				L = L->next;
				result = true;
				begin1 = begin1->next;
			}
			else
			{
				if (begin1->info == begin2->info)
				{
					L = begin2;
					result = false;
				}
				else
				{
					L = begin2;
					result = false;
					begin1 = begin1->next;
				}
			}
		}
		else
		{
			break;
		}
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* begin1 = NULL,
		* end1 = NULL,
		* begin2 = NULL,
		* end2 = NULL;
	int a1[5] = { 1,1,2,3,5 };
	int a2[3] = { 1,2,3 };
	for (int i = 0; i < 5; i++)
	{
		Create(end1, begin1, a1[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		Create(end2, begin2, a2[i]);
	}
	Print(begin2);
	Print(begin1);
	if (AreInElem(begin1, begin2))
	{
		cout << "���, ������ l1 ������� � ������ l2" << endl;
	}
	else
	{
		cout << "ͳ, ������ l1 �� ������� � ������ l2" << endl;
	}

	return 0;
}
