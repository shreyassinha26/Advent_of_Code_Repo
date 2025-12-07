#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ranges>
#include <algorithm>
using namespace std;
namespace rng = std::ranges;
#define INPUT_FILE 0

long long dp(vector<vector<long long>> &arr, vector<string>& block,
	 int curr, std::size_t line, int DEPTH = 0)
{
	if(line>=block.size()){
		//cout<<DEPTH<<"\n";
		return 1;
	}
	if(DEPTH>100)return 0;
	if(arr[line][curr]!=0)return arr[line][curr];
	long long &c = arr[line][curr];
	if(block[line][curr]=='^'){
		c+=dp(arr, block, curr-1,line + 2, DEPTH + 1);
		c+=dp(arr, block, curr+1,line + 2, DEPTH + 1);
	}else{
		c+=dp(arr, block, curr,line + 2, DEPTH + 1);
	}
	return c;
}

signed main(/*int argc, char **argv*/)
{
	if(INPUT_FILE)
        freopen("Demo.txt","r",stdin);
    else 
        freopen("In.txt","r",stdin);
    /*
	if(argc == 2){
		if(string(argv[1]) == "Demo")freopen("Demo.txt", "r", stdin);
		else freopen("Input.txt", "r", stdin);
	}*/
	#ifndef CLI
	freopen("Out.txt", "w", stdout);
	#endif

	string prev_line;
	getline(cin,prev_line);
	
	string curr_line;
	cin>>curr_line;
	for(const auto &[i,s] : views::zip(views::iota(0),prev_line))
	{
		if(s=='S')curr_line[i] = '|';
	}

	prev_line = curr_line;
	int splits = 0;
	while(!cin.eof()){
		cin>>curr_line;
		for(const auto&[i,s] : views::zip(views::iota(0),prev_line))
		{
			if(s == '|')
			{
				if(curr_line[i]=='^')
				{
					curr_line[i-1] = '|';
					curr_line[i+1] = '|';
					splits++;
				}else
					curr_line[i] = '|';
			}
		}
		prev_line = curr_line;
	}
	cout<<splits<<"\n";
	
	cin.clear();
	rewind(stdin);
	getline(cin,prev_line);
	int curr = 0;
	for(const auto&[i,s] : views::zip(views::iota(0),prev_line))
	{
		if(s=='S')curr = i;
	}
	//cout<<curr<<"\n";
	vector<string> block;
	while(!cin.eof()){
		block.push_back(string{});
		getline(cin,block.back());
	}
	vector<vector<long long>> arr(block.size(),vector<long long>(block.front().size(),0));
	cout<<dp(arr, block,curr,1)<<"\n";
	//for(auto i : block)cout<<i<<"\n";
	/*for(auto i : arr)
	{
		for(auto j : i)cout<<j<<" ";
		cout<<"\n";
	}*/
	return 0;
}










