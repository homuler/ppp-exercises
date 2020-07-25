#include "external/ppp2code/file/std_lib_facilities.h"

int add(int x, int y)
{
  if ((x > 0 && y > numeric_limits<int>::max() - x) || (x < 0 && y < numeric_limits<int>::min() + x)) {
    throw overflow_error { "Overflow detected (x = " + to_string(x) + ", y = " + to_string(y)  + ")" };
  }

  return x + y;
}

int sum(vector<int>& xs, int n)
{
  return accumulate(xs.begin(), xs.begin() + n, 0, add);
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

  cout << "Please enter some integers (press '|' to stop)" << endl;

  vector<int> xs;
  for (int n; cin >> n;)
  {
    xs.push_back(n);
  }

  if (xs.size() < n)
  {
    cerr << "You must enter at least " << n << " values." << endl;
    return 1;
  }

  int ans { sum(xs, n) };

  cout << "The sum of the first " << n << " number" << (n > 1 ? "s" : "");
  cout << " (";
  for (unsigned i = 0; i < n; ++i)
  {
    cout << (i > 0 ? " " : "") << xs.at(i);
  }
  cout << ") ";
  cout << "is " << ans << "." << endl;

  return 0;
} catch (overflow_error& e) {
  cerr << e.what() << endl;
  return 1;
}
