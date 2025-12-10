#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
namespace rng = std::ranges;
#define INPUT_FILE 0

int dp(size_t idx, unsigned prev, vector<vector<int>> buttons, unsigned &cmps) {
  if (cmps == prev)
    return 0;
  if (idx >= buttons.size())
    return idx;
  int leave = dp(idx + 1, prev, buttons, cmps);

  for (auto i : buttons[idx]) {
    prev ^= 1 << i;
  }
  int take = 1 + dp(idx + 1, prev, buttons, cmps);

  return min(take, leave);
}

signed main(/*int argc, char **argv*/) {
  if (INPUT_FILE)
    freopen("Demo.txt", "r", stdin);
  else
    freopen("In.txt", "r", stdin);
#ifndef CLI
  freopen("Out.txt", "w", stdout);
#endif

  int cnt = 0;
  int joltcnt = 0;
  while (!cin.eof()) {
    // cout<<"line\n";
    unsigned req{};
    vector<vector<int>> buttons;
    vector<int> joltage;
    char buff;
    cin.get(buff);
    unsigned idx = 1;
    while (buff != ']') {
      if (buff == '#')
        req |= idx;
      if (buff != '[')
        idx <<= 1;
      cin.get(buff);
    }
    cin >> ws;
    cin.get(buff);
    while (buff != '{') {

      if (buff == '(') {
        buttons.push_back(vector<int>{});
        int b;
        cin >> b;
        buttons.back().push_back(b);
      } else if (buff == ',') {
        int b;
        cin >> b;
        buttons.back().push_back(b);
      } else if (buff == ')') {
        cin >> ws;
      }
      cin.get(buff);
    }
    while (buff != '}') {
      int b;
      cin >> b;
      joltage.push_back(b);
      cin.get(buff);
    }
    cin >> ws;
    // for(int i : req)cout<<i<<" ";
    // for(auto i : buttons)for(auto j : i)cout<<j<<" ";
    // for(auto i : joltage)cout<<i<<" ";
    // cout<<"\n";
    // cout<<req<<" "<<buttons.size()<<endl;
    sort(buttons.begin(), buttons.end(),
         [](const auto &a, const auto &b) { return a.size() > b.size(); });
    int t = dp(0, 0, buttons, req);
    // cout<<t<<"\n";
    cnt += t;
    int jolts = 0;
    for (const auto &v : buttons) {
      int m = 1e4;
      for (const auto &i : v) {
        m = min(m, joltage[i]);
      }
      for (const auto &i : v) {
        joltage[i] -= m;
        ;
      }
      jolts += m;
    }
    for (auto i : joltage)
      jolts += i;
    // cout<<jolts<<"\n";
    joltcnt += jolts;
  }
  cout << cnt << "\n";
  cout << joltcnt << "\n";
  return 0;
}