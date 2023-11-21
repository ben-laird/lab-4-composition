#include <iostream>

#include "room.h"

#include "app.h"

App::App(std::unordered_map<std::string, AppArm> execution_options)
{
    app_arms = execution_options;

    std::cout << "Hello! App initialized!" << std::endl;
}

void App::run()
{
    const std::string QUIT_SENTINEL = "_";

    std::string input_buf = "";

    std::cout << "Welcome!" << std::endl
              << std::endl;

    while (input_buf != QUIT_SENTINEL)
    {
        std::cout << "Here are your options:" << std::endl
                  << std::endl;

        for (auto choice : app_arms)
        {
            auto title = choice.second.title;
            auto desc = choice.second.description;

            std::cout << choice.first << ": " << title << " - " << desc << std::endl;
        }
        std::cout << QUIT_SENTINEL << ": Quit - Quit the app" << std::endl
                  << std::endl;

        std::cout << "Choice: ";
        getline(std::cin, input_buf);

        bool executed_successfully = input_buf == QUIT_SENTINEL || search_and_execute(input_buf);
        if (!executed_successfully)
        {
            std::cout << "Option not found! Replaying welcome menu..." << std::endl
                      << std::endl;

            input_buf = "";
        }
    }
}

bool App::search_and_execute(std::string arm_title)
{
    auto arm_iter = app_arms.find(arm_title);
    auto outside = app_arms.end();

    if (arm_iter == outside)
    {
        return false;
    }
    auto f = arm_iter->second.lam;

    f();

    return true;
}
