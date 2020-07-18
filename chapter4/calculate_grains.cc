#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  int count = 0;
  int grain = 1;
  int total = 0;
  
  vector<int> thresholds = { 1'000, 1'000'000, 1'000'000'000 };

  while (count < 64)
  {
    int next_total { total + grain };
    ++count;
 
    cout << "[DEBUG] count = " << count << ", grain = " << grain << ", total = " << next_total << endl;

    for (auto th : thresholds)
    {
      if (th > total && th <= next_total)
      {
        cout << "No. " << count << ": Total grains is now over " << th << " (" << next_total << ")" << endl;
      }
    }

    grain *= 2;
    total = next_total;
  }

  return 0;
}
