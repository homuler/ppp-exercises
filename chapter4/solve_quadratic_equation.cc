#include "external/ppp2code/file/std_lib_facilities.h"
#include <complex>

vector<complex<double>> solve_quadratic_equation(double a, double b, double c)
{
  double base = -b / (2 * a);
  double d = b * b - 4 * a * c;
  const double eps = 1e-9;

  if (abs(d) < eps)
  {
    return { base };
  }

  complex<double> root = sqrt((complex<double>)d);

  return { base - root / (2 * a), base + root / (2 * a) };
}

int main()
{
  double a {};
  double b {};
  double c {};

  cout << "Solving a quadratic equation (ax^2 + bx + c = 0) ..." << endl;
  cout << "Please enter the coefficients (a, b, and c): ";
  cin >> a >> b >> c;

  if (a == 0)
  {
    cout << "The first value must not be zero" << endl;
    return 1;
  }

  auto ans = solve_quadratic_equation(a, b, c);

  cout << "Answers:";
  for (auto x : ans)
  {
    cout << " " << x.real();

    if (x.imag() == 0) continue;
    cout << (x.imag() > 0 ? "+" : "-") << abs(x.imag()) << "i";
  }
  cout << endl;

  return 0;
}
