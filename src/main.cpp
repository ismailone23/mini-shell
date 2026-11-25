#include <iostream>
#include <string>
#include <inputParser.h>
using namespace std;

int main()
{
    while (true)
    {

        string input;
        cout << "$ ";
        if (!getline(cin, input))
            break;
        if (input == "exit")
            break;
        vector<string> cmd = parser(input);
        for (string c : cmd)
            cout << c << endl;
    }
}