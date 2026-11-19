#include "execute.h"
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <vector>

#ifdef _WIN32
    #include <process.h>
#else
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif

std::string executeCommand(const std::vector<std::string>& input)
{
    if (input.empty())
        return "";

#ifdef _WIN32
    std::vector<char*> args;
    args.reserve(input.size() + 1);
    for (const std::string& argument : input)
        args.push_back(const_cast<char*>(argument.c_str()));
    args.push_back(nullptr);

    if (_spawnvp(_P_WAIT, args[0], args.data()) == -1)
        perror("_spawnvp failed");
#else
    pid_t pid = fork();

    if (pid == 0)
    {
        std::vector<char*> args;
        args.reserve(input.size() + 1);
        for (const std::string& argument : input)
            args.push_back(const_cast<char*>(argument.c_str()));
        args.push_back(nullptr);

        execvp(args[0], args.data());
        perror("execvp failed");
        std::_Exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        int status;
        if (waitpid(pid, &status, 0) == -1)
            perror("waitpid failed");
    }
    else
    {
        perror("fork failed");
    }
#endif

    return "";
}