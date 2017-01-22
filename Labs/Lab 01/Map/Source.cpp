#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Create a map that uses two strings. Name it colors.
    map<string,string> colors;

    // Populate several colors and their hex codes
    // red = FF0000, green = 00FF00, blue = 0000FF
    // magenta = FF00FF, yellow = FFFF00, cyan = 00FFFF

    colors.insert(pair<string,string> ("red","FF0000"));
    colors.insert(pair<string,string> ("green","00FF00"));
    colors.insert(pair<string,string> ("blue","0000FF"));
    colors.insert(pair<string,string> ("magenta","FF00FF"));
    colors.insert(pair<string,string> ("yellow","FFFF00"));
    colors.insert(pair<string,string> ("cyan","00FFFF"));

    string color;
    cout << "Enter a color: ";
    cin >> color;

    // Display the hex value of the color, using the user's input as a key.


    for (auto mapiterator:colors){

        if(mapiterator.first == color){
            cout << "Key: " << mapiterator.first << " ";
            cout << "Value: " << mapiterator.second << endl;
        }
    }


    return 0;
}
