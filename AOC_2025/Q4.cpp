#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define INPUT_FILE 0

using namespace std;

int main() {
  if (INPUT_FILE)
    freopen("Demo.txt", "r", stdin);
  else
    freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);

  vector<string> block;
  while (!cin.eof()) {
    string str;
    cin >> str;
    block.emplace_back(str);
  }

  int n = block.at(0).size();
  int m = block.size();
  int totalcount = 0;
  auto iter = [&]() {
    int count = 0;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (block[i][j] == '@') {
          int c = 0;
          if (block[i - 1][j - 1] != '.')
            c++;
          if (block[i + 1][j - 1] != '.')
            c++;
          if (block[i - 1][j + 1] != '.')
            c++;
          if (block[i + 1][j + 1] != '.')
            c++;
          if (block[i][j + 1] != '.')
            c++;
          if (block[i][j - 1] != '.')
            c++;
          if (block[i - 1][j] != '.')
            c++;
          if (block[i + 1][j] != '.')
            c++;
          if (c < 4) {
            block[i][j] = 'x';
            count++;
          }
        }
      }
    }
    for (int j = 1, i = 0; j < n - 1; j++) {
      if (block[i][j] == '@') {
        int c = 0;
        if (block[i + 1][j - 1] != '.')
          c++;
        if (block[i + 1][j + 1] != '.')
          c++;
        if (block[i][j + 1] != '.')
          c++;
        if (block[i][j - 1] != '.')
          c++;
        if (block[i + 1][j] != '.')
          c++;
        if (c < 4) {
          block[i][j] = 'x';
          count++;
        }
      }
    }
    for (int j = 1, i = m - 1; j < n - 1; j++) {
      if (block[i][j] == '@') {
        int c = 0;
        if (block[i - 1][j - 1] != '.')
          c++;
        if (block[i - 1][j + 1] != '.')
          c++;
        if (block[i][j + 1] != '.')
          c++;
        if (block[i][j - 1] != '.')
          c++;
        if (block[i - 1][j] != '.')
          c++;
        if (c < 4) {
          block[i][j] = 'x';
          count++;
        }
      }
    }
    for (int i = 1, j = 0; i < m - 1; i++) {

      if (block[i][j] == '@') {
        int c = 0;
        if (block[i - 1][j + 1] != '.')
          c++;
        if (block[i + 1][j + 1] != '.')
          c++;
        if (block[i][j + 1] != '.')
          c++;
        if (block[i - 1][j] != '.')
          c++;
        if (block[i + 1][j] != '.')
          c++;
        if (c < 4) {
          block[i][j] = 'x';
          count++;
        }
      }
    }
    for (int i = 1, j = n - 1; i < m - 1; i++) {

      if (block[i][j] == '@') {
        int c = 0;
        if (block[i - 1][j - 1] != '.')
          c++;
        if (block[i + 1][j - 1] != '.')
          c++;
        if (block[i][j - 1] != '.')
          c++;
        if (block[i - 1][j] != '.')
          c++;
        if (block[i + 1][j] != '.')
          c++;
        if (c < 4) {
          block[i][j] = 'x';
          count++;
        }
      }
    }
    if (block[0][0] == '@')
      count++;
    if (block[m - 1][0] == '@')
      count++;
    if (block[0][n - 1] == '@')
      count++;
    if (block[m - 1][n - 1] == '@')
      count++;
    block[0][0] = '.';
    block[m - 1][0] = '.';
    block[0][n - 1] = '.';
    block[m - 1][n - 1] = '.';
    for (auto &i : block) {
      for (auto &j : i)
        if (j == 'x')
          j = '.';
    }
    return count;
  };
  int curr = iter();
  totalcount = curr;
  while (curr) {
    curr = iter();
    totalcount += curr;
  }
  cout << totalcount << "\n";
  // for(auto &i : block){for(auto j : i)cout<<j;cout<<"\n";}

  return 0;
}