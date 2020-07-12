#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Enter a number in string" << endl;

  string number {""};
  cin >> number;

  if (number == "zero")
  {
    cout << 0;
  }
  else if (number == "one")
  {
    cout << 1;
  }
  else if (number == "two")
  {
    cout << 2;
  }
  else if (number == "three")
  {
    cout << 3;
  }
  else if (number == "four")
  {
    cout << 4;
  }
  else
  {
    cout << "not a number I know";
  }

  cout << endl;

  return 0;
}
