#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  vector<string> digits { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

  int digit {};
  cout << "Enter an integer between 0 and 9" << endl;
  cin >> digit;

  if (cin.fail())
  {
    cout << "Not a number" << endl;
    cin.clear();
  }
  else if (digit < 0)
  {
    cout << "The number is too small." << endl;
  }
  else if (digit > 9)
  {
    cout << "The number is too large." << endl;
  }
  else
  {
    cout << digits.at(digit) << endl;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string number {};
  cout << "Enter a number in string" << endl;
  cin >> number;

  auto it = find(digits, number);

  if (it == digits.end())
  {
    cout << "Unknown number" << endl;
  }
  else
  {
    cout << distance(digits.begin(), it) << endl;
  }

  return 0;
}
