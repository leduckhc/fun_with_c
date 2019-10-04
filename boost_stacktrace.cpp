#include <boost/stacktrace.hpp>
#include <iostream>

void break_it(int i)
{
    std::cout << i << std::endl;
    std::cout << boost::stacktrace::stacktrace();
}

int main(int argc, char const* argv[])
{
    int i = 1;

    break_it(i);

    return 0;
}
