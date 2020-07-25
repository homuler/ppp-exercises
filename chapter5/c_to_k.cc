#include "external/ppp2code/file/std_lib_facilities.h"

class Bad_temp {};

constexpr double zero_temp = 273.15;

double ctok(double c)
{
  const double k = c + 273.15;

  return k < 0 ? throw Bad_temp {} : k;
}

int main()
try {
  double d {};
  cin >> d;
  double k { ctok(d) };
  cout << k << endl;

  return 0;
} catch (Bad_temp) {
  cerr << "Temperature must be over " << zero_temp  << "." << endl;

  return 1;
}
