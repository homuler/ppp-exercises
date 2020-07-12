#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter a distance in mile" << endl;

  double mile {0};
  cin >> mile;
  cout << mile * 1.609 << endl;

  return 0;
}
