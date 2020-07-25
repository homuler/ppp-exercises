#include "external/ppp2code/file/std_lib_facilities.h"

double add(double x, double y)
{
  if ((x > 0 && y > numeric_limits<double>::max() - x) || (x < 0 && y < numeric_limits<double>::min() + x)) {
    throw overflow_error { "Overflow detected (x = " + to_string(x) + ", y = " + to_string(y)  + ")" };
  }

  return x + y;
}

vector<double> build_diffs(vector<double>& xs)
{
  if (xs.size() < 2)
  {
    throw invalid_argument { "The vector must have at least 2 elements to build difference vectors" };
  }

  vector<double> diffs;

  for (unsigned i = 0; i < xs.size() - 1; ++i)
  {
    auto diff = xs.at(i + 1) - xs.at(i);
    diffs.push_back(diff);
  }

  return diffs;
}

double sum(vector<double>& xs, int n)
{
  return accumulate(xs.begin(), xs.begin() + n, 0.0, add);
}

int main()
try {
  cout << "Please enter the number of values you want to sum: ";
  int n {};
  cin >> n;

  if (n <= 0)
  {
    cerr << "The value must be over zero." << endl;
    return 1;
  }

  cout << "Please enter some doubles (press '|' to stop)" << endl;

  vector<double> xs;
  for (double n; cin >> n;)
  {
    xs.push_back(n);
  }

  if (xs.size() < n)
  {
    cerr << "You must enter at least " << n << " values." << endl;
    return 1;
  }

  double ans { sum(xs, n) };

  cout << "The sum of the first " << n << " number" << (n > 1 ? "s" : "");
  cout << " (";
  for (unsigned i = 0; i < n; ++i)
  {
    cout << (i > 0 ? " " : "") << xs.at(i);
  }
  cout << ") ";
  cout << "is " << ans << "." << endl;

  vector<double> diffs = build_diffs(xs);

  cout << "Differences of adjacent numbers:";
  for (auto d : diffs)
  {
    cout << " " << d;
  }
  cout << endl;

  return 0;
} catch (overflow_error& e) {
  cerr << e.what() << endl;
  return 1;
} catch (invalid_argument& e) {
  cerr << e.what() << endl;
  return 2;
}
