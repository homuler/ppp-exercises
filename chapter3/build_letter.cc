#include "external/ppp2code/file/std_lib_facilities.h"

int main()
{
  string writer_name = "";
  string recipient_name = "???";
  string friend_name = "???";
  char friend_gender = 0;
  int recipient_age = -1;

  cout << "Enter your name" << endl;
  cin >> writer_name;
  cout << "Enter the name of the person you want to write to" << endl;
  cin >> recipient_name;
  cout << "Enter a name of your friend" << endl;
  cin >> friend_name;

  while (friend_gender != 'f' && friend_gender != 'm')
  {
    cout << "Enter the gender of the freind (f or m)" << endl;
    cin >> friend_gender;
  }

  cout << "Enter the age of the recipient" << endl;
  cin >> recipient_age;

  if (recipient_age <= 0 || recipient_age >= 110)
  {
    simple_error("you're kidding!");
  }

  cout << "Dear " << recipient_name << ",";
  cout << "How are you? I am fine. I miss you." << endl;

  cout << "Have you seen " << friend_name << " lately?";
  cout << " If you see " << friend_name << " please ask " << (friend_gender == 'f' ? "her" : "him") << " to call me." << endl;

  cout << "I hear you just had a birthday and you are " << recipient_age << " years old.";

  if (recipient_age < 12)
  {
    cout << " Next year you will be " << recipient_age + 1 << ".";
  }
  else if (recipient_age == 17)
  {
    cout << " Next year you will be able to vote.";
  }
  else if (recipient_age >= 70)
  {
    cout << " I hope you are enjoying retirement.";
  }

  cout << endl;
  cout << "Yours sincerely" << endl;
  cout << endl << endl;

  cout << writer_name << endl;
  return 0;
}
