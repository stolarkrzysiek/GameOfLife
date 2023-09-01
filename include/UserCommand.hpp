#pragma once
#include "CommandSource.hpp"
#include <iostream>

class UserCommand : public CommandSource
{
    private:
        char choice;//n - next, s - stop
    public:
        std::string next_command() override;

};
