#include "external/ppp2code/file/std_lib_facilities.h"
#include <limits>

int main()
{
  vector<double> distances;

  for (double x; cin >> x;)
  {
    distances.push_back(x);
  }

  if (distances.empty()) return 0;

  double sum {};
  double shortest = numeric_limits<double>::max();
  double longest = numeric_limits<double>::min();

  for (auto x : distances)
  {
    sum += x;
    if (x < shortest) shortest = x;
    if (x > longest) longest = x;
  }

  cout << "Total distances: " << sum << endl;
  cout << "Shortest distance: " << shortest << endl;
  cout << "Longest distance: " << longest << endl;
  cout << "Average: " << sum / distances.size() << endl;

  return 0;
}
