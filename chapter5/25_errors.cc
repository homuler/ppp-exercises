#include "external/ppp2code/file/std_lib_facilities.h"

int main()
try {
  /* No.1 - 4 */
  // Cout << "Success!\n";
  // cout << "Success!\n;
  // cout << "Success" << !\n"
  // cout << success << '\n';

  // cout << "Success!\n";


  /* No.5 */
  // string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";

  // int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";


  /* No.6 */
  // vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n";

  // vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";


  /* No.7 - 8 */
  // if (cond) cout << "Success!\n"; else cout << "Fail!\n";
  // bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";

  // bool cond = true; if (cond) cout << "Success!\n"; else cout << "Fail!\n";


  /* No.9 */
  // string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n";
  // string s = "ape"; bool c = "fool" < s; if (!c) cout << "Success!\n";


  /* No.10 - 12 */
  // string s = "ape"; if (s == "fool") cout << "Success!\n";
  // string s = "ape"; if (s == "fool") cout < "Success!\n";
  // string s = "ape"; if (s + "fool") cout < "Success!\n";

  // string s = "ape"; if (s != "fool") cout << "Success!\n";


  /* No.13 - 14 */
  // vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
  // vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";

  // Maybe...
  // vector<char> v(5); for (unsigned i = 0; i < v.size(); ++i); cout << "Success!\n";


  /* No.15 */
  // string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];

  // string s = "Success!\n"; for (unsigned i = 0; i < s.size(); ++i) cout << s[i];


  /* No.16 */
  // if (true) then cout << "Success!\n"; else cout << "Fail!\n";

  // if (true) cout << "Success!\n"; else cout << "Fail!\n";


  /* No.17 */
  // int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";

  // int x = 2000; int c { x }; if (c == 2000) cout << "Success!\n";


  /* No.18 */
  // string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];


  /* No.19 */
  // vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";

  // Maybe...
  // vector<char> v(5); for (unsigned i = 0; i < v.size(); ++i); cout << "Success!\n";


  /* No.20 */
  // int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";

  // int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";


  /* No.21 */
  // int x = 2; double d = 5/(x - 2); if (d == 2*x + 0.5) cout << "Success!\n";

  // Maybe...
  // int x = 3; double d = 5/(x - 2); if (d == 2*(x - 0.5)) cout << "Success!\n";


  /* No.22 */
  // string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];

  // string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];


  /* No.23 */
  // int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";

  // Maybe...
  // int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";


  /* No.24 */
  // int x = 4; double d = 5/(x - 2); if (d = 2*x + 0.5) cout << "Success!\n";

  // Maybe...
  // int x = 3; double d = 5/(x - 2); if (d == 2*(x - 0.5)) cout << "Success!\n";


  /* No.25 */
  // cin << "Success!\n";

  // cout << "Success!\n";

  keep_window_open();
  return 0;
} catch (exception& e) {
  cerr << "error: " << e.what() << endl;
  keep_window_open();
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!" << endl;
  keep_window_open();
  return 2;
}
