
# SHovel prompt

Tini prompy that can be instanciated, functions can be added with pointers. Made this for my projects since it can be usefull. 

I did not take this seriously.

## Usage/Examples

```cpp

prompt NAME("WELLCOME MESSAGE","DEFAULT PROMPT");

NAME.begin(); //Starts the prompt loop

NAME.execute() //Executes a command, it's called from begin(), or can be called manually in case you don't want an infinite loop bitting your toes
//It supports arguments, that get passed to the function as a string

NAME.addcommand(
    int(*func)(string args),
    "EXEC NAME (ex: ls)",
    "SUCCESS PROMPT (displays if command could execute",
    "ERROR PROMPT (same, but if not)",
    "NAME (for the list function, has default value)",
    "DESRIPTION (for the list function, has default value)"
    )
//Ex: NAME.addcommand(multiply,mult,COULD,COULD NOT, Multply, Multiplies 2 numbers passed as argyments)

/*
    Default commands:
        clear: Clears screen
        list: Lists all avaliable commands and it's info TODO
        exit: Exits prompt loop
        prrompt: Changes prompt text
*/

```

