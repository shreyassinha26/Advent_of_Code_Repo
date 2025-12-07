#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <array>
#define INPUT_FILE 0

using namespace std;



int main()
{
    if(INPUT_FILE)
        freopen("Demo.txt","r",stdin);
    else 
        freopen("In.txt","r",stdin);
    freopen("Out.txt","w",stdout);
	
    const int lc = 4;

    vector<vector<long long>> arr;

    array<istringstream, lc> no;
    
    for(int i = 0; i < lc; i++){
        string buff;
        getline(cin,buff);
        no[i] = istringstream(buff);
    }

    arr.push_back(vector<long long>{});
    while(!no[0].eof()){
        string num;
        num.resize(lc);
        for(int i = 0; i < lc; i++){
            no[i].get(num[i]);
        }
        int f = 0;
        for(auto i : num)if(i!=' ' && i != '\0')f=1;
        //cout<<num<<"\n";
        if(f)arr.back().push_back(stoi(num));
        else if(!arr.back().empty())arr.push_back(vector<long long>{});
    }
    //for(auto i : arr){for(auto j : i)cout<<j<<" ";cout<<"\n";}
    /*
    //cout<<buff<<endl;
    while(!isstr.eof()){
        long long x; isstr>>x;
        //cout<<x<<endl;
        arr.push_back(vector<long long>{});
        arr.back().push_back(x);
        isstr>>std::ws;
        //cout<<x<<"\n";
    }
    //cout<<arr.size()<<endl;
    for(int i = 1; i < lc; i++)for(auto &j : arr){
        long long x;
        cin>>x;
        j.push_back(x);
    };
    */
    //for(auto i : arr)for (auto j : i)cout<<j<<" ";
    unsigned long long count = 0;
    cout<<arr.size()<<"\n";
    //int c = 0;
    //string buff;
    //getline(cin,buff);
    //for(auto i : buff)if(i!=' ')c++;
    


    for(auto i : arr){
        if(i.size()==0)continue;
        char op;
        cin>>op>>std::ws;
        //cout<<op;
        if(op=='+')for(auto j : i)count += j;
        else {
            long long temp = 1;
            for(auto j : i)temp*=j;
            count += temp;
        }
    }
    //cout<<c<<endl;
    cout<< count;
    
    return 0;
}
