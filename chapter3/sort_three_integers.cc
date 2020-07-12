#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter 3 integers" << endl;

  int a {0};
  int b {0};
  int c {0};

  cin >> a >> b >> c;

  int min { a > b ? (b > c ? c : b) : (a > c ? c : a) };
  int med { a > b ? (b > c ? b : (c > a ? a : c)) : (a > c ? a : (c > b ? b : c)) };
  int max { a > b ? (a > c ? a : c) : (b > c ? b : c) };

  cout << min << ", " << med << ", " << max << endl;

  return 0;
}
