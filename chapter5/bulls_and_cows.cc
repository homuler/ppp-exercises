#include "external/ppp2code/file/std_lib_facilities.h"

vector<int> generate_seq()
{
  vector<int> seq;

  for (int i = 0; i < 4; ++i)
  {
    seq.push_back(randint(10));
  }

  return seq;
}

pair<int, int> check(vector<int>& seq, vector<int>& guess)
{
  int bull = 0;
  int cow = 0;

  for (unsigned i = 0; i < seq.size(); ++i)
  {
    if (guess[i] == seq[i])
    {
      ++bull;
    }
    else if (find(seq, guess[i]) != seq.end())
    {
      ++cow;
    }
  }

  return make_pair(bull, cow);
}

void print_result(pair<int, int> result)
{
  cout << result.first << " bull" << (result.first == 1 ? "" : "s");
  cout << " and ";
  cout << result.second << " cow" << (result.second == 1 ? "" : "s");
  cout << endl;
}

void validate_guess(vector<int>& xs)
{
  for (unsigned i = 0; i < xs.size(); ++i)
  {
    if (xs[i] < 0 || xs[i] > 9)
    {
      throw invalid_argument { "The value must be between 0 and 9" };
    }

    for (unsigned j = i + 1; j < xs.size(); ++j)
    {
      if (xs[i] == xs[j])
      {
        throw invalid_argument { "The values in the sequence must be unique, but " + to_string(xs[i]) + " is duplicated." };
      }
    }
  }
}

void reset_cin(istream& cin)
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void run_game(vector<int>& seq)
{
  while (true)
  {
    cout << "Guess the sequence: ";

    vector<int> guess;

    try {
      char n {};
      for (int i = 0; i < 4; ++i)
      {
        cin >> n;
        guess.push_back(n - '0');

        if (cin.fail()) reset_cin(cin);
      }

      validate_guess(guess);
    } catch (invalid_argument& e) {
      cerr << e.what() << endl;
      continue;
    }

    auto result = check(seq, guess);
    print_result(result);

    if (result.first == 4) return;
  }
}

int main()
{
  int seed {};

  cout << "Please enter a seed integer (default = 0): ";
  cin >> seed;
  srand(seed); // TODO: not working

  if (cin.fail()) reset_cin(cin);

  while (true)
  {
    vector<int> seq = generate_seq();

    run_game(seq);

    char c {};
    cout << "Do you continue? (y or n): ";
    cin >> c;

    if (c == 'y') continue;

    return 0;
  }
}
