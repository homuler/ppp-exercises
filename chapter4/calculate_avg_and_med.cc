#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  vector<double> temps;
  for (double temp; cin >> temp;)
  {
    temps.push_back(temp);
  }

  if (temps.empty()) {
    return 0;
  }

  sort(temps.begin(), temps.end());

  double sum {};
  for (auto temp : temps) sum += temp;

  cout << "Average temperature: " << sum / temps.size() << endl;

  double med = (temps[(temps.size() - 1) / 2] + temps[temps.size() / 2]) / 2;
  cout << "Median temperature: " << med << endl;

  return 0;
}
