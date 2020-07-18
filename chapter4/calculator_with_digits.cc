#include "external/ppp2code/file/std_lib_facilities.h"

int get_digit(vector<string>& digits)
{
  int x;

  if (cin >> x)
  {
    return x;
  }

  cin.clear();

  string input;
  cin >> input;

  auto it = find(digits, input);

  if (it != digits.end())
  {
    return distance(digits.begin(), it);
  }

  return -1;
}

int main()
{
  vector<string> digit_words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

  cout << "Enter 2 digits (in number or string) and an operator(+, -, *, /)" << endl;

  int x { get_digit(digit_words) };

  if (x < 0)
  {
    cout << "The first value is invalid" << endl;
    return 1;
  }

  int y { get_digit(digit_words) };

  if (y < 0)
  {
    cout << "The second value is invalid" << endl;
    return 1;
  }

  char op {};
  cin >> op;

  double ans {};
  string result_type {};

  switch (op)
  {
    case '+':
      ans = x + y;
      result_type = "sum";
      break;
    case '-':
      ans = x - y;
      result_type = "difference";
      break;
    case '*':
      ans = x * y;
      result_type = "product";
      break;
    case '/':
      ans = (double)x / y;
      result_type = "ratio";
      break;
    default:
      cout << "Unknown operator: " << op << endl;
      cout << "Operator must be one of +, -, *, or /" << endl;
      return 1;
  }

  cout << "The " << result_type << " of " << x << " and " << y << " is " << ans << endl;

  return 0;
}
