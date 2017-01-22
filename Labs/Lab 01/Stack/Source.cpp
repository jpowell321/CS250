#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Book
{
public:
	Book(const string& title)
	{
		m_title = title;
		m_checkedIn = false;
	}

	void CheckIn()
	{
		cout << "Checked in \"" << m_title << "\"" << endl;
		m_checkedIn = true;
	}

private:
	string m_title;
	bool m_checkedIn;
};

int main()
{
	// Create a stack of Book objects called bookDrop.
	stack<Book> bookDrop;
	Book book1("Of Mice and Men");
	Book book2("To Kill a Mocking Bird");
	Book book3("Lord of the Rings");
    Book top ("Null");

	// Push a series of books into the bookDrop.
	bookDrop.push(book1);
	bookDrop.push(book2);
	bookDrop.push(book3);

	vector<Book> bookPool;

	// Go through the stack of books using a while loop,
	// while the stack is not empty...
	// Take the top-most book, and push it into the bookPool.
	// Then pop the top book off the bookDrop.

	while (!bookDrop.empty()) {
        top = bookDrop.top();
        top.CheckIn();
        bookPool.push_back(top);
        bookDrop.pop();
	}


	return 0;
}
