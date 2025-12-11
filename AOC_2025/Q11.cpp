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

int code_to_key(istringstream &parser) {
  int key = 0;
  char c;
  parser >> c;
  key |= static_cast<int>(c) << 16;
  parser >> c;
  key |= static_cast<int>(c) << 8;
  parser >> c;
  key |= static_cast<int>(c);
  return key;
}
int code_to_key(const string &parser) {
  int key = 0;
  char c;
  c = parser[0];
  key |= static_cast<int>(c) << 16;
  c = parser[1];
  key |= static_cast<int>(c) << 8;
  c = parser[2];
  key |= static_cast<int>(c);
  return key;
}

long long dfs(int key, const int &endkey,
              const map<int, vector<int>> &connections,
              map<int, long long> &dp) {
  if (key == endkey)
    return 1;
  if (key == 7304564)
    return 0;
  if (dp.contains(key))
    return dp[key];
  long long &path_count = dp[key];
  for (const auto &k : connections.at(key)) {
    path_count += dfs(k, endkey, connections, dp);
  }
  return path_count;
}

signed main(/*int argc, char **argv*/) {
  // freopen("Demo.txt", "r", stdin);

  map<int, vector<int>> connections;
  while (!cin.eof()) {
    string buff;
    getline(cin, buff);
    istringstream parser(buff);
    int key = code_to_key(parser);
    connections[key] = vector<int>{};
    parser.ignore(1);
    parser >> ws;
    while (!parser.eof()) {
      connections[key].push_back(code_to_key(parser));
      parser >> ws;
    }
  }
  // for (const auto &[k, v] : connections) {
  //   cout << k << ":";
  //   for (const auto i : v)
  //     cout << " " << i;
  //   cout << "\n";
  // }

  map<int, long long> dp1, dp2, dp3;
  unsigned long long fft_dac =
      dfs(code_to_key("fft"), code_to_key("dac"), connections, dp1);
  unsigned long long dac_out =
      dfs(code_to_key("dac"), code_to_key("out"), connections, dp2);
  unsigned long long svr_fft =
      dfs(code_to_key("svr"), code_to_key("fft"), connections, dp3);
  cout << svr_fft << "\n";
  cout << fft_dac << "\n";
  cout << dac_out << "\n";
  cout << fft_dac * dac_out * svr_fft << "\n";

  return 0;
}