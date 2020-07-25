#include "external/ppp2code/file/std_lib_facilities.h"

int add(int x, int y)
{
  if ((x > 0 && y > numeric_limits<int>::max() - x) || (x < 0 && y < numeric_limits<int>::min() + x)) {
    throw overflow_error { "Overflow detected (x = " + to_string(x) + ", y = " + to_string(y)  + ")" };
  }

  return x + y;
}

vector<int> fibs(int n)
{
  switch (n)
  {
    case 0: return {};
    case 1: return { 1 };
    case 2: return { 1, 1 };
  }

  vector<int> xs { 1, 1 };

  while (xs.size() < n)
  {
    int x = xs[xs.size() - 2];
    int y = xs[xs.size() - 1];

    xs.push_back(add(x, y));
  }

  return xs;
}

int maximu_fib_count()
{
  int n = 2;

  try {
    int x = 1;
    int y = 1;

    while (true)
    {
      int next = add(x, y);
      x = y;
      y = next;
      ++n;
    }
  } catch (overflow_error&) {
    return n;
  }
}

int main()
{
  int max_n { maximu_fib_count() };

  cout << "Enter a positive integer (<= " << max_n << "): ";
  int n {};
  cin >> n;

  if (n <= 0)
  {
    cerr << "The value must be positive." << endl;
    return 1;
  }
  else if (n > max_n)
  {
    cerr << "Values in the sequence will overflow." << endl;
    return 1;
  }

  cout << "Fibonacci sequences:";
  for (auto x : fibs(n))
  {
    cout << " " << x;
  }
  cout << endl;

  return 0;
}
