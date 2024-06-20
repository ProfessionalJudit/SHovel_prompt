#ifndef COMMND_S
#define COMMND_S
#include <iostream>
struct prompt_command
{
    int (*function)(std::string args);
    std::string name;
    std::string description;
    std::string exec_name;
    std::string success_prompt;
    std::string error_prompt;
};
#endif