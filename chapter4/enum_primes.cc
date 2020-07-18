#include "external/ppp2code/file/std_lib_facilities.h"

bool is_prime(int x, vector<int>& primes)
{
  for (auto p : primes)
  {
    if (p * p > x) return true;
    if (x % p == 0) return false;
  }

  return true;
}

vector<int> enum_primes(unsigned int n)
{
  if (n <= 0)
  {
    return {};
  }

  vector<int> primes = { 2 };
  int p = 3;

  while (primes.size() < n)
  {
    if (is_prime(p, primes))
    {
      primes.push_back(p);
    }

    ++p;
  }

  return primes;
}

int main()
{
  cout << "Please enter an integer (>= 0): ";
  int n {};
  cin >> n;

  if (n < 0) return 0;

  auto primes = enum_primes(n);

  cout << "The first " << n << " prime numbers:";
  for (auto p : primes)
  {
    cout << " " << p;
  }
  cout << endl;

  return 0;
}
