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

  for (unsigned i = 0; i < names.size(); ++i)
  {
    cout << names[i] << " " << scores[i] << endl;
  }

  return 0;
}
