#include <iostream>
#include <string>

#define print //std::cout<<curr<<" " <<count<<"\n"
#define INPUT_FILE 1

using namespace std;

int main()
{
    if(INPUT_FILE)
        freopen("Demo.txt","r",stdin);
    else 
        freopen("In.txt","r",stdin);
    freopen("Out.txt","w",stdout);
    
    int curr = 50;
    int count = 0;
    string str;
    while(!std::cin.eof()){
        cin>>str;
        char direction = str.front();
        int magnitude;
        magnitude = stoi(str.substr(1,str.size()-1));
        count += magnitude/100;
        magnitude%=100;
        if(str.front()=='L')
            magnitude = -abs(magnitude);
        
        if(curr){
            if(curr+magnitude > 99){
                count ++;
                curr = (curr + magnitude + 100)%100;
            }else if(curr + magnitude <=0){
                count++;
                curr = (curr + magnitude + 100)%100;
            }else {
                curr = (curr + magnitude + 100)%100;
            }
        }
        else curr = (curr + magnitude + 100)%100;
        
        //if(!curr)count++;
        print;
    }
    
    cout<<count<<endl;

    return 0;
}
