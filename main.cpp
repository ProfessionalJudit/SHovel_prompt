#include "prompt.hpp"
int test(std::string args = "fed"){
    std::cout << args;
    return 5;
}
int main(int argc, char const *argv[])
{
    prompt a("TEST PROMPT");
    a.addcommand(test,"test","test ok","test fail");
    a.begin();
    return 0;
}
