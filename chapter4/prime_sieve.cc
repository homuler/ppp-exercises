#include "external/ppp2code/file/std_lib_facilities.h"

vector<int> enum_primes(int max)
{
  if (max < 2)
  {
    return {};
  }

  vector<bool> sieve(max+1);
  vector<int> primes;

  sieve.at(0) = true;
  sieve.at(1) = true;

  for (unsigned i = 2; i * i < sieve.size(); ++i)
  {
    if (sieve.at(i)) continue;

    for (unsigned j = i * i; j < sieve.size(); j += i)
    {
      sieve.at(j) = true;
    }
  }

  for (unsigned i = 0; i < sieve.size(); ++i)
  {
    if (!sieve.at(i))
    {
      primes.push_back(i);
    }
  }

  return primes;
}

int main()
{
  cout << "Please enter a max value: ";
  int max {};
  cin >> max;

  auto primes = enum_primes(max);

  cout << "Total count: " << primes.size() << endl;

  if (primes.empty()) return 0;

  cout << "Primes:";
  for (auto p : primes) cout << " " << p;
  cout << endl;

  return 0;
}
