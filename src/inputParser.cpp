#include "inputParser.h"
#include <sstream>
using namespace std;

vector<string> parser(string input)
{
    vector<string> cmd;
    stringstream ss(input);

    while (getline(ss, input, ' '))
    {
        cmd.push_back(input);
    }

    return cmd;
}