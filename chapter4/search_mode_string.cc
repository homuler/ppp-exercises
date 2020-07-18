#include "external/ppp2code/file/std_lib_facilities.h"

vector<string> find_modes(vector<string>& xs)
{
  sort(xs.begin(), xs.end());

  xs.push_back(""); // sentinel

  int mode_count = 0;
  int current_count = 0;
  string current_value = xs.at(0);
  vector<string> modes;

  for (auto x : xs)
  {
    if (x != current_value)
    {
      if (mode_count < current_count)
      {
        mode_count = current_count;
        modes = { current_value };
      }
      else if (mode_count == current_count)
      {
        modes.push_back(current_value);
      }

      current_value = x;
      current_count = 1;
      continue;
    }

    ++current_count;
  }

  xs.pop_back(); // remove sentinel

  return modes;
}

int main()
{
  cout << "Please enter strings" << endl;
  vector<string> values;

  for (string input; cin >> input; )
  {
    values.push_back(input);
  }

  if (values.empty()) return 0;

  sort(values.begin(), values.end());
  vector<string> modes = find_modes(values);

  cout << "Minimum: " << values.front() << endl;
  cout << "Maximum: " << values.back() << endl;
  cout << "Mode:";
  for (auto x : modes)
  {
    cout << " " << x;
  }
  cout << endl;

  return 0;
}
