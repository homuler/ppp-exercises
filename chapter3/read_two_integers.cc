#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter 2 integers" << endl;

  int a {0};
  int b {0};

  cin >> a >> b;

  int min = a > b ? b : a;
  int max = a > b ? a : b;
  int sum = a + b;
  int product = a * b;
  double ratio = (double)a / b;

  cout << "min: " << min << endl;
  cout << "max: " << max << endl;
  cout << "sum: " << sum << endl;
  cout << "product: " << product << endl;
  cout << "ratio: " << ratio << endl;

  return 0;
}
