#include <iostream>
#include <range/v3/all.hpp> // get everything
#include <string>
using std::cout;

int main()
{
  std::string s{"hello"};

  // output: h e l l o
  ranges::for_each(s, [](char c) { cout << c << ' '; });
  cout << '\n';
}
