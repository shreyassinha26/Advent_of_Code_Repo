#include <iostream>
#include <sstream>
#include <string>
#define INPUT_FILE 0

using namespace std;

int main() {
  if (INPUT_FILE)
    freopen("Demo.txt", "r", stdin);
  else
    freopen("In.txt", "r", stdin);
  freopen("Out.txt", "w", stdout);

  unsigned long long count = 0;
  string str;
  while (!cin.eof()) {
    cin >> str;
    int n = str.size();
    int prev = -1;
    array<int, 12> arr;
    for (int i = 0; i < 12; i++)
      arr[i] = n - (12 - i);
    for (int i = 0; i < 12; i++) {
      for (int j = arr[i]; j > prev; j--) {
        if (str[j] >= str[arr[i]])
          arr[i] = j;
      }
      prev = arr[i];
    }
    stringstream con;
    for (int i : arr)
      con << str[i];
    count += stoull(con.str());
  }
  cout << count << "\n";

  return 0;
}