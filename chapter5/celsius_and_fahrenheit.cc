#include "external/ppp2code/file/std_lib_facilities.h"

class Bad_temp {};

constexpr double absolute_zero = -273.15;
constexpr double esp = 1e-9;

void throw_bad_temp()
{
  throw range_error { "The temperature is below absolute zero." };
}

double ctof(double c, bool require_validation);
double ftoc(double f, bool require_validation);

double ctof(double c, bool require_validation = false)
{
  if (c < absolute_zero) throw_bad_temp();

  const double f =  9 * c / 5 + 32;

  if (require_validation)
  {
    const double c_dash = ftoc(f, false);

    if (abs(c_dash - c) >= esp)
    {
      cerr << "The result might be wrong: " << c << "C = " << f << "F = " << c_dash << "C?" << endl;
    }
  }

  return f;
}

double ftoc(double f, bool require_validation = false)
{
  const double c = 5 * (f - 32) / 9;

  if (c < absolute_zero) throw_bad_temp();

  if (require_validation)
  {
    const double f_dash = ctof(c, false);

    if (abs(f_dash - f) >= esp)
    { 
      cerr << "The result might be wrong: " << f << "F = " << c << "C = " << f_dash << "F?" << endl;
    }
  }

  return c;
}

int main()
try {
  cout << "Enter a temperature value (in Celsius or Fahrenheit): ";

  double t {};
  char unit {};
  cin >> t >> unit;

  if (cin.fail())
  {
    cerr << "Please enter the value and the unit (e.g. -273.15C, 0F)" << endl;
    return 1;
  }

  if (unit == 'C')
  {
    double f = ctof(t, true);
    cout << t << unit << " = " << f << "F" << endl;
  }
  else if (unit == 'F')
  {
    double c = ftoc(t, true);
    cout << t << unit << " = " << c << "C" << endl;
  }
  else
  {
    cerr << "The unit must be C or F" << endl;
    return 1;
  }

  return 0;
} catch (range_error& e) {
  cerr << e.what() << endl;

  return 1;
}
