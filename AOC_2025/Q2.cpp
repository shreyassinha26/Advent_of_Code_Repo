#include <iostream>
#include <string>

#define print //std::cout<<curr<<" " <<count<<"\n"

using namespace std;


int main()
{
    freopen("In.txt","r",stdin);
    freopen("Out.txt","w",stdout);

    unsigned long long c = 0;
    while(!cin.eof()){
        string segment;
        if(getline(cin,segment,',')){
        }else {
           getline(cin,segment);
        }
        
        int hyphen = -1;
        while(segment[++hyphen]!='-');
        long long lower = stoll(segment.substr(0,hyphen));
        long long higher = stoll(segment.substr(hyphen+1,segment.size()-hyphen-1));
        //clog<<lower<<" "<<higher<<endl;
        for(long long val = lower; val <=higher; val++){
            //cerr<<i<<" "<<static_cast<int>(log10(i))%2<<"\n";
            string str = to_string(val);
            int digits = static_cast<int>(log10(val));
            digits++;
            //clog<<val<<endl;
            for(int i = 1; i <digits;i++){
                if(digits%i)continue;
                int parse_size = digits/i;
                int flag = 1;
                for(int j = 1; j < digits/i; j++){
                    //cout<<str.substr((j-1)*i,i)<<" "<<str.substr((j)*i,i)<<" ";
                    if(str.substr((j-1)*i,i)!=str.substr((j)*i,i)){
                        flag = 0;
                        break;
                    }
                }
                //cout<<"\n";
                if(flag){
                    cout<<val<<"\n";
                    c+=val;
                    break;
                }
            }
        }
    }
    cout<<c<<"\n";
    return 0;
}