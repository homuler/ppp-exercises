#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  string name {};
  int score {};

  vector<string> names;
  vector<int> scores;

  while (cin >> name >> score)
  {
    if (name == "NoName" && score == 0)
    {
      break;
    }

    if (find(names, name) != names.end())
    {
      simple_error("Duplicated name: " + name);
    }

    names.push_back(name);
    scores.push_back(score);
  }

  cout << "Please enter a name to print their score" << endl;

  while (cin >> name)
  {
    auto it = find(names, name);

    if (it == names.end())
    {
      cout << "name not found" << endl;
      continue;
    }

    int i = distance(names.begin(), it);
    cout << scores[i] << endl;
  }

  return 0;
}
