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

  cout << "Please enter scores" << endl;

  while (cin >> score)
  {
    int count = 0;

    for (unsigned i = 0; i < scores.size(); ++i)
    {
      if (score != scores[i]) continue;

      if (count == 0)
      {
        cout << "Scorer:";
      }

      ++count;
      cout << " " << names[i];
    }

    if (count == 0)
    {
      cout << "score not found";
    }
    cout << endl;
  }

  return 0;
}
