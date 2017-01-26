#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> LoadData( const string& filename )
{
        // Don't modify this function
        vector<string> list;
        ifstream input( filename );
        
        string buffer;
        while ( getline( input, buffer ) )
        {
                list.push_back( buffer );
        }
        
        input.close();
        
        cout << list.size() << " items loaded" << endl;
        
        return list;
}

int LinearSearch( const vector<string>& list, string findMe, int& cycleCounter )
{
        // Go from 0, 1, 2, ... to the last item, searching for findMe in the list vector. 
        // Return the position that the item is found at,
        // or -1 if the item is not found.
		cycleCounter = 0;

		for (cycleCounter; cycleCounter < list.size(); cycleCounter++) {
			if (list[cycleCounter] == findMe) {
				return cycleCounter;
			}
		}
    
		return -1;
}

int CustomSearch( const vector<string>& list, string findMe, int& cycleCounter )
{
        // Implement your own search algorithm.
        // Return the position that the item is found at,
        // or -1 if the item is not found.
        
		int point = list.size() - 1;
		for (point; point > 1; point--) {
			//cout << "here";
			if (list[point] == findMe) {
				return point;
			}
			cycleCounter++;
		}

		return -1;
}

int BinarySearch( const vector<string>& list, string findMe, int& cycleCounter )
{
	
        // Implement the Binary Search algorithm.
        // https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm
        // Return the position that the item is found at,
        // or -1 if the item is not found.
	
		cycleCounter = 0;
		int point = 0;
		int middle = 0;
		int end = list.size();
		for (point; point < end; point++) {
			middle = (point + end) / 2;
			if (list[middle] < findMe) {
				point = middle + 1;
			}
			if(list[middle] > findMe) {
				
				end = middle - 1;
			}
			if (list[point] == findMe){
				cout << "here3";
				return point;
			}
			cycleCounter++;
		}
        return -1;
}

int main()
{
        // Don't modify main()
        vector<string> countries = LoadData( "countrylist.txt" );
        
        string searchItems[4] = { "Austria", "Yemen", "Curacao", "CS250Land" };
        
        int cycleCounter;
        
        // Linear search
        cout << endl << "LINEAR SEARCH" << endl;
        for ( int i = 0; i < 4; i++ )
        {
                cout << "Linear search - looking for \"" << searchItems[i] << "\"... ";
                int foundPosition = LinearSearch( countries, searchItems[i], cycleCounter );                
                cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
        }
        
        // Custom search
        cout << endl << "CUSTOM SEARCH" << endl;
        for ( int i = 0; i < 4; i++ )
        {
                cout << "Custom search - looking for \"" << searchItems[i] << "\"... ";
                int foundPosition = CustomSearch( countries, searchItems[i], cycleCounter );                
                cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
        }
        
        // Binary search
        cout << endl << "BINARY SEARCH" << endl;
        for ( int i = 0; i < 4; i++ )
        {
                cout << "Binary search - looking for \"" << searchItems[i] << "\"... ";
                int foundPosition = BinarySearch( countries, searchItems[i], cycleCounter );                
                cout << "Found at position " << foundPosition << " in " << cycleCounter << " cycles" << endl;
        }
		system("pause");
        return 0;
}
