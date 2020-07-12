#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  cout << "Please enter 3 strings" << endl;

  string a {""};
  string b {""};
  string c {""};

  cin >> a >> b >> c;

  string min { a > b ? (b > c ? c : b) : (a > c ? c : a) };
  string med { a > b ? (b > c ? b : (c > a ? a : c)) : (a > c ? a : (c > b ? b : c)) };
  string max { a > b ? (a > c ? a : c) : (b > c ? b : c) };

  cout << min << ", " << med << ", " << max << endl;

  return 0;
}
