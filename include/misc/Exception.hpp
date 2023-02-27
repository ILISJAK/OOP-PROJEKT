#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>

class Exception : public std::exception
{
public:
    Exception(std::string message);
    const char *what() const throw();

protected:
    std::string message;
};

class InputValidation : public Exception
{
public:
    InputValidation(std::string message);
};
class InvalidReference : public Exception
{
public:
    InvalidReference(std::string message);
};

#endif