#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "Page.hpp"


// Page pages[100]
void LoadPages(vector<Page> & pages, const string& filename)
{
	ifstream input(filename);
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;
	Page pages2;

	while (getline(input, line))
	{

		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{
			// Add page to book now
			// pages[pageCount].text = pageText;
			pages2.text = pageText;

			pages.push_back(pages2);

			pageCount++;

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}

		// if (pageCount == 100)
		// {
			// The book is full! Can't load any more.
			// return;
		// }
	}

	input.close();
}

void ReadBook(vector<Page>& pages)
{
	int currentPage = 0;
	//int totalPages = 100;
	int totalPages = pages.size();

	bool done = false;
	Page pages2;

	while (!done)
	{
		pages2 = pages[currentPage];
		//pages[currentPage].Display();
		pages2.Display();
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q")
		{
			done = true;
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{
	vector<Page> pages;
	// Page pages[100];

	LoadPages(pages, "Aesop.txt");
	ReadBook(pages);

	return 0;
}
