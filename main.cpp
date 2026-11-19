#include <iostream>
#include <vector>
#include <string>
#include "inputParser.h"
#include "execute.h"
#include <filesystem>
using namespace std;

string getPathFromHome()
{
    /**
     *
     *
     string cwd = filesystem::current_path().string();
     const char *home = getenv("HOME");

     if (home && cwd.rfind(home, 0) == 0)
     return "~" + cwd.substr(string(home).length());

     return cwd;
     */

    return filesystem::current_path().filename().string();
}

int main()
{
    while (true)
    {
        cout << "[~/" << getPathFromHome() << "]$ ";
        string input;
        if (!getline(cin, input))
            break;

        vector<string> parsedInput = parser(input);
        cout << executeCommand(parsedInput) << endl;
    }

    return 0;
}