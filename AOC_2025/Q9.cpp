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

signed main(/*int argc, char **argv*/) {
  if (INPUT_FILE)
    freopen("Demo.txt", "r", stdin);
  else
    freopen("In.txt", "r", stdin);
#ifndef CLI
  freopen("Out.txt", "w", stdout);
#endif

  vector<pair<long long, long long>> arr;

  while (!cin.eof()) {
    long long a, b;
    char buff;
    cin >> a >> buff >> b;
    arr.push_back(make_pair(a, b));
  }
  /*
  long long m = 0;
  for(const auto& [i,v] : views::zip(views::iota(0),arr))
  {
      for(const auto& j : arr | views::drop(i+1))
      {
          long long tempx = 1+abs(v.first - j.first);
          long long tempy = 1+abs(v.second-j.second);
          m = max(m, tempx*tempy);
      }
  }
  cout<<m<<"\n";*/
  long long m = 0;
  auto n = arr.size();
  for (const auto &[i, v] : views::zip(views::iota(0), arr)) {
    auto prev = arr[(n + i - 1) % n];
    auto sec = arr[(i + 1) % n];
    auto lastc = make_pair(prev.first ^ v.first ^ sec.first,
                           prev.second ^ v.second ^ sec.second);
    for (size_t k = 2; k < n - 1; k++) {

      const auto &w = arr[(k + i) % n];
      if ((v.first < lastc.first) == (lastc.first <= w.first) &&
          (v.second < lastc.second) == (lastc.second <= w.second)) {
        long long tempx = 1 + abs(v.first - lastc.first);
        long long tempy = 1 + abs(v.second - lastc.second);
        m = max(m, tempx * tempy);
      }
    }
  }
  cout << m << "\n";
  return 0;
}