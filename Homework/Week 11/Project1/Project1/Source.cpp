#include <iostream>
#include <string>
#include "SortedList.h"

using namespace std;

int main()
{
	
	SortedList<int> listObj;


		
	cout << "Add 1, 2, 4, 3, 6, 5" << endl;
	listObj.Sortedpush(1);
	listObj.Sortedpush(2);
	listObj.Sortedpush(4);
	listObj.Sortedpush(3);
	listObj.Sortedpush(6);
	listObj.Sortedpush(5);

	cout << "Size: " << listObj.Size() << endl;
		
		
	
	cout << endl << "Current list:" << endl;
	listObj.Display();

	cout << endl << "Get Index 2 - should be value of 4:" << endl;
	int N1;
	N1 = listObj.GetAt(2);
	cout << N1 << endl;

	listObj.Sort();

	cout << endl << "Sorted list:" << endl;
	listObj.Display();
	
	cout << endl << "Get Index 2 - should be value of 3:" << endl;
	int N2;
	N2 = listObj.GetAt(2);
	cout << N2 << endl<<endl;
		
	system("pause");

	return 0;
}