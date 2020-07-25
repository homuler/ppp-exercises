#include "external/ppp2code/file/std_lib_facilities.h"

string to_lower(string str)
{
  transform(str.begin(), str.end(), str.begin(), ::tolower);

  return str;
}

int get_index_for(const string& day_of_the_week)
{
  string d = to_lower(day_of_the_week);

  if (d == "sunday" || d == "sun") return 0;
  if (d == "monday" || d == "mon") return 1;
  if (d == "tuesday" || d == "tue") return 2;
  if (d == "wednesday" || d == "wed") return 3;
  if (d == "thursday" || d == "thu") return 4;
  if (d == "friday" || d == "fri") return 5;
  if (d == "saturday" || d == "sat") return 6;

  return -1;
}

string get_name_for(const unsigned i)
{
  switch (i)
  {
    case 0: return "Sun";
    case 1: return "Mon";
    case 2: return "Tue";
    case 3: return "Wed";
    case 4: return "Thu";
    case 5: return "Fri";
    case 6: return "Sat";
  }

  throw invalid_argument { "The argument must be between 0 and 6" };
}

int main()
{
  string day_of_the_week;
  int value;
  vector<int> vs(7);
  int rejected {};

  while (cin >> day_of_the_week >> value)
  {
    int i = get_index_for(day_of_the_week);

    if (i < 0)
    {
      ++rejected;
      continue;
    }

    vs[i] += value;
  }

  for (unsigned i = 0; i < vs.size(); ++i)
  {
    string day = get_name_for(i);
    cout << day << ": " << vs[i] << endl;
  }

  cout <<  "Rejected count: " << rejected << endl;
  return 0;
}
