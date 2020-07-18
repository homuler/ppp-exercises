#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  int min = 1;
  int max = 100;
  char ans {};

  cout << "Please think of an integer between " << min << " and " << max << "." << endl;

  while (max > min)
  {
    int med = (max + min) / 2;
    cout << "Is the number larger than " << med << "? (y or n): ";

    cin >> ans;

    switch (ans)
    {
      case 'y':
        min = med + 1;
        break;
      case 'n':
        max = med;
        break;
      default:
        cout << "Invalid answer: " << ans << endl;
        break;
    }
  }

  cout << "Your number must be " << min << endl;

  return 0;
}
