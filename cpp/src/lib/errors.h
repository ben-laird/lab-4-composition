#pragma once

#include <exception>
#include <string>

class Error : std::exception
{
protected:
    std::string reason;

public:
    Error();
    Error(std::string assumption_broken);

    std::string what();
};

class Todo : public Error
{
public:
    Todo();
};
