#include "external/ppp2code/file/std_lib_facilities.h"

int get_hand_value(char hand)
{
  switch (hand)
  {
    case 's': return 1;
    case 'p': return 2;
    default: return 0;
  }
}

/**
 * @return the computer's hand and next seed value.
 */

pair<int, int> pick_random_hand(int seed, const vector<int>& hands)
{
  int idx = { ((seed % hands.size()) + hands.size()) % hands.size() };
  int com_value { hands[idx] };

  return make_pair(com_value, idx + 1);
}

/**
 * @return the game result (0 = draw, 1 = player win, 2 = com win).
 */
int judge(int player_hand, int com_hand)
{
  return ((com_hand - player_hand) + 3) % 3;
}

int main()
{
  const vector<int> hands = {
    0, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 2, 0, 2, 2,
    0, 0, 0, 0, 0, 1, 0, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 2, 1, 0,
    0, 0, 2, 0, 2, 1, 1, 0, 0, 2, 2, 2, 1, 1, 2, 1, 0, 2, 0, 1,
    2, 1, 0, 1, 0, 0, 2, 1, 1, 1, 0, 1, 1, 2, 0, 0, 2, 2, 0, 1,
    2, 0, 2, 2, 0, 2, 1, 0, 0, 2, 1, 0, 1, 2, 0, 1, 0, 2, 0, 0
  };

  cout << "Please enter an integer (default = 0): ";
  int seed {};
  cin >> seed;

  while (true)
  {
    cout << "Please enter your hand (default = r, p, s): ";
    char input {};
    cin >> input;

    int player_hand { get_hand_value(input) };
    auto p = pick_random_hand(seed, hands);
    int com_hand { p.first };

    string com_hand_text = com_hand == 0 ? "r" : com_hand == 1 ? "s" : "p";
    cout << "Computer's hand: " << com_hand_text << endl;

    auto result = judge(player_hand, com_hand);

    switch (result)
    {
      case 1:
        cout << "You win!" << endl;
        return 0;
      case 2:
        cout << "You lose." << endl;
        return 0;
      default:
        cout << "Draw" << endl;
        break;
    }

    seed = p.second;
  }

  return 0;
}
