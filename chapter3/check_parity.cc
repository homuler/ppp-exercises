#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter an integer" << endl;

  int x {0};
  cin >> x;
  cout << "The value " << x << " is " << (x % 2 == 0 ? "even" : "odd") << "." << endl;

  return 0;
}
