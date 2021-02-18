
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

static bool s_Finished = false;

void DoWork()
{
    std::cout << "Started thread = " << std::this_thread::get_id() << std::endl;
    while (!s_Finished)
    {
        std::cout << "Working ..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread t_work = std::thread(DoWork);
    std::cin.get();
    s_Finished = true;
 
    t_work.join();
    std::cout << "Finished" << std::endl;

    return 0;
}