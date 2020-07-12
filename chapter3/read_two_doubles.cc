#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter 2 doubles" << endl;

  double a {0};
  double b {0};

  cin >> a >> b;

  double min = a > b ? b : a;
  double max = a > b ? a : b;
  double sum = a + b;
  double product = a * b;
  double ratio = (double)a / b;

  cout << "min: " << min << endl;
  cout << "max: " << max << endl;
  cout << "sum: " << sum << endl;
  cout << "product: " << product << endl;
  cout << "ratio: " << ratio << endl;

  return 0;
}
