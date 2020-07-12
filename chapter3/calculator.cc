#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  string operation {""};
  double x {0};
  double y {0};

  while (cin >> operation >> x >> y) {
    double ans {0};

    if (operation == "+" || operation == "plus")
    {
      ans = x + y;
    }
    else if (operation == "-" || operation == "minus")
    {
      ans = x - y;
    }
    else if (operation == "*" || operation == "mul")
    {
      ans = x * y;
    }
    else if (operation == "/" || operation == "div")
    {
      ans = x / y;
    }
    else
    {
      cout << "Unknown operation: " << operation << endl;
      continue;
    }

    cout << ans << endl;
  }

  return 0;
}
