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

std::string executeCommand(const std::vector<std::string> &input)
{
    if (input.empty())
        return "";

#ifdef _WIN32
    std::vector<char *> args;
    args.reserve(input.size() + 1);
    for (const std::string &arg : input)
        args.push_back(const_cast<char *>(arg.c_str()));
    args.push_back(nullptr);
    // TODO: research about process.h
    return "";
#else
    pid_t pid = fork();
    if (pid == 0)
    {
        char *args[input.size() + 1];
        for (size_t i = 0; i < input.size(); i++)
        {
            args[i] = const_cast<char *>(input[i].c_str());
        }
        args[input.size()] = NULL;
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork failed");
    }

    return "";

#endif
}