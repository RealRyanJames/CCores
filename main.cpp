#include <iostream>
#include <thread>
#include <chrono>
#include "Declarations/Declarations.cpp"
#include "Classes/Init.cpp"

void Second::helloMessage()
{
    for (int i = 0; i < 1; i++)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "Hello Ryan From C++" << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

enum Seconds : int
{
    Hour = 2,
    Minutes = 2,
};

void Second::ReadSeconds(const Seconds &seconds)
{
    if (seconds == Seconds::Hour)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Second::Hour * 1000));
    }

    if (seconds == Seconds::Minutes)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Second::Hour * 1000));
    }
}

int main()
{

    std::string messageAdder;
    Option<bool> m(true);
    while (m.onEnabled())
    {
        std::cout << "Enter Message: " << std::endl;
        std::cin >> messageAdder;

        if (m.onEnabled())
        {

            if (messageAdder == "Add")
            {
                Second::ReadSeconds(Second::Seconds::Hour);
                std::thread th(Second::helloMessage);
                th.join();

                Second::ReadSeconds(Second::Seconds::Hour);
                std::cout << "Ending..." << std::endl;
            }
        }
    }

    return 0;
}