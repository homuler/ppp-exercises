#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  int penny {0};
  int nickel {0};
  int dime {0};
  int quarter {0};
  int half_dollar {0};
  int dollar {0};

  cout << "How many pennies do you have? ";
  cin >> penny;
  cout << "How many nickels do you have? ";
  cin >> nickel;
  cout << "How many dimes do you have? ";
  cin >> dime;
  cout << "How many quarters do you have? ";
  cin >> quarter;
  cout << "How many half dollars do you have? ";
  cin >> half_dollar;
  cout << "How many dollars do you have? ";
  cin >> dollar;

  if (penny > 0)
  {
    cout << "You have " << penny << " " << (penny == 1 ? "penny" : "pennies") << "." << endl;
  }
  if (nickel > 0)
  {
    cout << "You have " << nickel << " " << (nickel == 1 ? "nickel" : "nickels") << "." << endl;
  }
  if (dime > 0)
  {
    cout << "You have " << dime << " " << (dime == 1 ? "dime" : "dimes") << "." << endl;
  }
  if (quarter > 0)
  {
    cout << "You have " << quarter << " " << (quarter == 1 ? "quarter" : "quarters") << "." << endl;
  }
  if (half_dollar > 0)
  {
    cout << "You have " << half_dollar << " " << (half_dollar == 1 ? "half dollar" : "half dollars") << "." << endl;
  }
  if (dollar > 0)
  {
    cout << "You have " << dollar << " " << (dollar == 1 ? "dollar" : "dollars") << "." << endl;
  }

  int sum = penny + 5 * nickel + 10 * dime + 25 * quarter + 50 * half_dollar + 100 * dollar;
  int sum_dollar = sum / 100;
  int sum_cent = sum % 100;

  cout << "The value of all of your coins is";
  
  if (sum == 0 || sum_dollar > 0)
  {
    cout << " " << sum_dollar << (sum_dollar == 1 ? " dollar" : " dollars");
  }
  if (sum_cent > 0)
  {
    cout << " " << sum_cent << (sum_cent == 1 ? " cent" : " cents");
  }
  
  cout << "." << endl;

  return 0;
}
