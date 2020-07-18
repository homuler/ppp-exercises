#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  double x;
  double y;
  char op;

  cout << "Enter 2 numbers and an operator(+, -, *, /)" << endl;
  cin >> x >> y >> op;

  if (cin.fail())
  {
    cout << "Invalid format" << endl;
    return 1;
  }

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
      ans = x / y;
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
