#include "execute.h"
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <vector>

#ifdef _WIN32
#include <process.h>
#include <io.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#endif

std::string executeCommand(std::vector<std::string> cmd)
{
    if (cmd.empty())
        return "";

#ifdef _WIN32
    std::vector<char *> args;
    args.reserve(cmd.size() + 1);
    for (std::string arg : cmd)
        args.push_back(const_cast<char *>(arg.c_str()));
    args.push_back(nullptr);
#else

#endif
}