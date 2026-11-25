#include <iostream>
#include <string>
#include <inputParser.h>
#include <execute.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string getCurrentFolder()
{
    fs::path cwd = fs::current_path();
    return cwd.filename().string();
}

int main()
{
    while (true)
    {

        string input;
        cout << "~/" + getCurrentFolder() + "$ ";
        if (!getline(cin, input))
            break;
        if (input == "exit")
            break;
        vector<string> cmd = parser(input);
        cout << executeCommand(cmd);
    }
}