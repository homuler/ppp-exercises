#include "external/ppp2code/file/std_lib_facilities.h"

class No_root {};

void validate_answer(double a, double b, double c, double x)
{
  constexpr double eps = 1e-9;
  const double v = a * x * x + b * x + c;

  if (abs(v) > eps)
  {
    cerr << "The answer " << x << " might not be a valid solution." << endl;
  }
}

pair<double, double> solve_quadratic_equation(double a, double b, double c)
{
  const double d = b * b - 4 * a * c;

  if (d < 0)
  {
    throw No_root {};
  }

  const double sq = sqrt(d);

  // validation
  const double x1 = (-b - sq) / (2 * a);
  const double x2 = (-b + sq) / (2 * a);

  validate_answer(a, b, c, x1);
  validate_answer(a, b, c, x2);

  return make_pair(x1, x2);
}

int main()
try {
  double a {};
  double b {};
  double c {};

  cout << "Solving a quadratic equation (ax^2 + bx + c = 0) ..." << endl;
  cout << "Please enter the coefficients (a, b, and c): ";
  cin >> a >> b >> c;

  if (a == 0)
  {
    cerr << "The first value must not be zero" << endl;
    return 1;
  }

  auto ans = solve_quadratic_equation(a, b, c);

  cout << "Answers: " << ans.first << ", " << ans.second << endl;

  return 0;
} catch (No_root) {
  cerr << "No real solution." << endl;
  return 1;
}
