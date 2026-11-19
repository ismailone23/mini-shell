#include "inputParser.h"
#include <sstream>

std::vector<std::string> parser(const std::string& input)
{
    std::istringstream inputStream(input);
    std::vector<std::string> inputParsed;
    std::string word;

    while (inputStream >> word)
    {
        inputParsed.push_back(word);
    }
    return inputParsed;
}