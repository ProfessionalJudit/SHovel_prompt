#ifndef PROMPT_S
#define PROMPT_S
#include <prompt_command.hpp>
#include <vector>
class prompt
{
private:
    bool exit = false;
    std::vector<prompt_command> commands;
    std::string prompt_text;
    std::string wellcome_text;
    int check_input();

public:
    // ARGS, wellcome message and default prompt
    prompt(const char *, const char * = " >>> ");
    // Add a new command, (function ptr, exec name, prompt if success, if fail, name and description)
    int addcommand(int (*func)(std::string), const char *, const char *, const char *, const char * = " - ", const char * = " - ");
    // start console
    int begin();
    //Execute command
    int execute(std::string);
};
#endif