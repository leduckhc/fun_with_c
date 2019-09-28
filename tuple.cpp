#include <iostream>
#include <tuple>

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "Hello World from Tuple.cpp" << endl;

  string name;
  int age;
  tie(name, age) = make_tuple("Tom", 4);
  cout << name << ", " << age << endl;

  tie(name, age, ignore) = make_tuple("Tom", 4, "It's a cat");
  cout << name << ", " << age << endl;

  return 0;
}
