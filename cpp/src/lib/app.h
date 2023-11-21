#pragma once

#include <unordered_map>
#include <functional>
#include <string>

struct AppArm
{
    std::string title;
    std::string description;
    std::function<void()> lam;
};

class App
{
protected:
    std::unordered_map<std::string, AppArm> app_arms;

public:
    App(std::unordered_map<std::string, AppArm> execution_options);

    void run();

    bool search_and_execute(std::string arm);
};
