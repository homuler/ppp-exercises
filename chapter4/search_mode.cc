#include "external/ppp2code/file/std_lib_facilities.h"

/**
 * @param xs - positive integers
 */
vector<int> find_modes(vector<int>& xs)
{
  sort(xs.begin(), xs.end());

  xs.push_back(-1); // sentinel

  int mode_count = 0;
  int current_count = 0;
  int current_value = xs.at(0);
  vector<int> modes;

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

  return modes;
}

int main()
{
  cout << "Please enter positive integers" << endl;
  vector<int> values;

  for (int input; cin >> input; )
  {
    if (input < 0) continue;
    values.push_back(input);
  }

  vector<int> modes = find_modes(values);

  if (modes.empty()) return 0;

  cout << "Mode:";
  for (auto x : modes)
  {
    cout << " " << x;
  }
  cout << endl;

  return 0;
}
