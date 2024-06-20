#include <prompt_command.hpp>
#include <vector>
#include <iostream>
class prompt
{
private:
    bool exit;
    std::vector<prompt_command> commands;
    std::string prompt_text;
    std::string wellcome_text;
    int check_input();

public:
    prompt(const char *well, const char *after);
    int addcommand(
        int (*func)(std::string), const char *, const char *, const char *, const char *, const char *);
    int begin();
    int execute(std::string);
};
prompt::prompt(const char *well, const char *after)
{
    wellcome_text = well;
    prompt_text = after;
}
//Adds parameter  to struct, pushes struct to vector
int prompt::addcommand(
    int (*func)(std::string), const char *exec_name, const char *success, const char *error, const char *name, const char *description)
{
    prompt_command command;
    command.function = func;
    command.success_prompt = success;
    command.error_prompt = error;
    command.exec_name = exec_name;
    command.name = name;
    command.description = description;
    commands.push_back(command);
    return 0;
}

//Starts while loop and gets user input
//Calls execute() with imput as parameter
int prompt::begin()
{
    std::cout << wellcome_text << "\n";
    std::string order = "";
    while (!exit)
    {
        std::cout << prompt_text << " ";
        getline(std::cin, order);
        execute(order);
    }
    return 0;
}

//Separates command and arguments
//If command exists or is one of the defaults, execute the function assosiated with that struct
//It also checks if that ptr is null
int prompt::execute(std::string cmmnd)
{
    std::string command_noargs = cmmnd.substr(0, cmmnd.find(" "));
    std::string command_args = cmmnd.substr((cmmnd.find(" ") == -1) ? cmmnd.size() : cmmnd.find(" "));

    bool found = false;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (command_noargs == commands.at(i).exec_name)
        {
            found = true;
            if (commands.at(i).function != nullptr)
            {
                commands.at(i).function(command_args);
            }
            else
            {
                std::cout << "ERROR: INVALID FUNCTION (NULL POINTER)\n";
                return 1;
            }
            std::cout << "\n\n"
                      << commands.at(i).success_prompt << "\n";
            // << "\nArgs: " << command_args << "\n";
        }
        else if (command_noargs == "clear")
        {
            found = true;
            std::cout << "\033[2J\033[1;1H";
        }
        else if (command_noargs == "list")
        {
            found = true;
            std::cout << "\033[2J\033[1;1H\n TODO";
        }
        else if (command_noargs == "exit")
        {
            found = true;
            exit = true;
            // exit(0);
        }
        else if (command_noargs == "prompt")
        {
            std::cout << "\033[2J\033[1;1H\n TODO";
        }
    }
    if (!found)
    {
        std::cout << "Command not found: " << command_noargs << "\n";
    }

    return 0;
}