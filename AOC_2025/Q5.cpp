#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
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

  map<unsigned long long, unsigned long long> good;

  string input_line;

  getline(cin, input_line);
  auto loc = find(input_line.begin(), input_line.end(), '-');
  int c = 500;
  while (loc != input_line.end() && --c) {
    // cout<<input_line<<" ";
    unsigned long long low, high;
    istringstream isstr(input_line);
    char buff;
    isstr >> low >> buff >> high;
    // cout<<low<<" "<<high<<"\n";
    getline(cin, input_line);
    loc = find(input_line.begin(), input_line.end(), '-');

    good[low] = max(good[low], high);
  }
  long long count = 0;
  // cout<<input_line<<endl;
  // long long buff = stoll(input_line);
  /*
  unsigned long long buff;

  while(!cin.eof()){
      cin>>buff;
      //auto it = good.upper_bound(buff);

      for(auto &[a,x]:good){
          if(a<=buff && buff <=x){count++;break;}
      }
  }
  cout<<count<<"\n";
  */
  cerr << "map made\n";
  vector<pair<unsigned long long, bool>> order;
  for (auto &[f, s] : good) {
    order.push_back(make_pair(f, 0));
    order.push_back(make_pair(s, 1));
    // if(s<=f)cout<<"prob in input";
  }
  cerr << "vector made\n";
  good.clear();
  sort(
      order.begin(), order.end(),
      [](pair<unsigned long long, bool> &a, pair<unsigned long long, bool> &b) {
        if (a.first == b.first)
          return a.second < b.second;
        return a.first < b.first;
      });
  cerr << "sorted\n";
  stack<unsigned long long> st;
  unsigned long long last = 0;
  int c1 = 0, c2 = 0;
  int ips = 0;
  for (auto [i, b] : order) {

    // cout<<i<<" ";
    if (b)
      c2++;
    else
      c1++;
    if (c2 > c1)
      cout << i << " " << ips << "\n";
    if (st.size() == 0 && b)
      cerr << "prob\n";
    if (b) {
      if (st.size())
        last = st.top();
      if (st.size())
        st.pop();
      // cout<<st.size()<<"\n";
      if (st.empty())
        count += i - last + 1;
    } else {
      st.push(i);
    }
    ips++;
  }
  cout << count << "\n";
  cout << c1 << " " << c2 << "\n";

  return 0;
}