#include "errors.h"

Error::Error()
{
    reason = "An error occurred!";
}
Error::Error(std::string assumption_broken)
{
    reason = assumption_broken;
}

std::string Error::what()
{
    return reason;
}

Todo::Todo() : Error()
{
    reason = "Not implemented yet!";
}
