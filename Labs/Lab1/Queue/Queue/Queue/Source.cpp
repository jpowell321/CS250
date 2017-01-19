#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions
	queue<float> transactions;
	
	// Push some + and - floats into the transactions queue.
	transactions.push(78.8);
	transactions.push(-.6);
	transactions.push(325.63);
	

	// Loop through all the transactions - while the queue is empty.
	while (!transactions.empty()) {
		cout << transactions.front() << endl;
		balance += transactions.front();
		transactions.pop();
	}
		
	// Within the loop, whatever amount is at the front of the queue,
	// add it to the balance and then pop it off the queue.

	cout << "Final balance: $" << balance << endl;
	system("pause");
	return 0;
}