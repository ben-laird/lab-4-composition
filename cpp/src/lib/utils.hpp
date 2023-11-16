#include <exception>
#include <string>

class Todo : std::exception
{
    std::string what()
    {
        return "Not implemented yet!";
    }
};
