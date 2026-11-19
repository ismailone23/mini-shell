#include <iostream>
#include <vector>
#include <string>
#include "inputParser.h"
#include "execute.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << "$ ";
        string input;
        if (!getline(cin, input))
            break;

        vector<string> parsedInput = parser(input);
        cout << executeCommand(parsedInput) << endl;
    }

    return 0;
}