#include "external/ppp2code/file/std_lib_facilities.h"
#include <limits>
#include <numeric>

double normalize_value(const double x, const string& unit)
{
  constexpr double m_per_centimeter = 0.01;
  constexpr double cm_per_inch = 2.54;
  constexpr double in_per_feet = 12;


  if (unit == "cm")
  {
    return x * m_per_centimeter;
  }

  if (unit == "in")
  {
    return x * cm_per_inch * m_per_centimeter;
  }

  if (unit == "ft")
  {
    return x * in_per_feet * cm_per_inch * m_per_centimeter;
  }

  return x;
}

bool is_valid_unit(const string& unit)
{
  return unit == "cm" || unit == "m" || unit == "in" || unit == "ft";
}

int main() {
  vector<double> values;
  double minimum = numeric_limits<double>::max();
  double maximum = numeric_limits<double>::min();
  string minimum_expr {};
  string maximum_expr {};

  double x {};
  string unit {};

  while (cin >> x >> unit)
  {
    if (!is_valid_unit(unit))
    {
      cout << "invalid unit: " << unit << endl;
      continue;
    }

    const double value = normalize_value(x, unit);

    if (value <= minimum)
    {
      minimum = value;
      minimum_expr = to_string(x) + unit; // TODO: keep the original format
      cout << "the smallest so far" << endl;
    }

    if (value >= maximum)
    {
      maximum = value;
      maximum_expr = to_string(x) + unit; // TODO: keep the original format
      cout << "the largest so far" << endl;
    }

    values.push_back(value);
  }

  if (values.empty())
  {
    return 0;
  }

  sort(values.begin(), values.end());

  double sum {};

  cout << "input values (in ascending order):";

  for (auto v : values)
  {
    cout << " " << v << "m";
    sum += v;
  }

  cout << endl;

  cout << "the smallest value is: " << minimum_expr << endl;
  cout << "the largest value is: " << maximum_expr << endl;
  cout << "the number of input values is: " << values.size() << endl;
  cout << "the total is: " << sum << "m" << endl;

  return 0;
}
