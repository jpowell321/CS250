#include <iostream>
#include <string>
#include "SortedList.h"

using namespace std;

int main()
{
	// Create list
	SortedList<int> listObj;
	cout << "Test 1:  Size should be zero for emtpy list." << endl << "Size = " << listObj.Size() << endl;
	cout << endl;

	cout << "Test 2:  No data should display for empty list." << endl <<"Current List : " << endl;
	listObj.Display();
	cout << endl;

	//Load List out of order
	cout << "Push values 1, 2, 4, 3, 6, 5" << endl;
	listObj.Sortedpush(1);
	listObj.Sortedpush(2);
	listObj.Sortedpush(4);
	listObj.Sortedpush(3);
	listObj.Sortedpush(6);
	listObj.Sortedpush(5);
	cout << endl;

	cout << "Test 3:  Size should be 6" << endl << "Size = " << listObj.Size() << endl;
	cout << endl;

	cout << "Test 4:  List should be sorted 1 through 6." << endl << "Current List : " << endl;
	listObj.Display();
	cout << endl;

	cout << endl << "Test 5: Get Index 2 - should be value of 3:" << endl;
	int N1;
	N1 = listObj.GetAt(2);
	cout << N1 << endl;

	
	cout << endl << "Test 6:  Get Index 3 - should be value of 4:" << endl;
	int N2;
	N2 = listObj.GetAt(3);
	cout << N2 << endl<<endl;
		
	system("pause");

	return 0;
}