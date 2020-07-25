#include "external/ppp2code/file/std_lib_facilities.h"

class Bad_temp {};

constexpr double zero_temp_k = 273.15;

double ctok(double c)
{
  const double k = c + zero_temp_k;

  return k < 0 ? throw Bad_temp {} : k;
}

double ktoc(double k)
{
  if (k < 0) throw Bad_temp {};

  return k - zero_temp_k;
}

int main()
try {
  cout << "Enter a temperature value (in Kelvin or Celsius): ";

  double t {};
  char unit {};
  cin >> t >> unit;

  if (cin.fail())
  {
    cerr << "Please enter the value and the unit (e.g. 273.15K, 0C)" << endl;
    return 1;
  }

  if (unit == 'C')
  {
    double k = ctok(t);
    cout << t << unit << " = " << k << "K" << endl;
  }
  else if (unit == 'K')
  {
    double c = ktoc(t);
    cout << t << unit << " = " << c << "C" << endl;
  }
  else
  {
    cerr << "The unit must be C or K" << endl;
    return 1;
  }

  return 0;
} catch (Bad_temp) {
  cerr << "The input value is below absolue zero." << endl;

  return 1;
}
