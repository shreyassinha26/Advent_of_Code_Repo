#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ranges>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
namespace rng = std::ranges;
#define INPUT_FILE 0
#define file_size 1000
#define TAKE_AMT 10
struct p3d{
    long long x,y,z;

    bool operator==(const p3d& other) const
    {
        return this->x == other.x 
            && this->y == other.y 
            && this->z == other.z; 
    }
    std::strong_ordering operator<=>(const p3d& other) const
    {
        if(auto cmp = this->x <=> other.x;cmp !=0){
            return cmp;
        }
        if(auto cmp = this->y <=> other.y;cmp !=0){
            return cmp;
        }
        return this->z <=> other.z;
    }
    
};

inline long long dist(const p3d &a, const p3d &b)
{
    return (long long)(a.x-b.x)*(a.x-b.x) 
        + (long long)(a.y-b.y)*(a.y-b.y) 
        + (long long)(a.z-b.z)*(a.z-b.z);    
}

ostream& operator <<(ostream& ostr, const p3d& p)
{
    ostr << p.x << " " << p.y << " " << p.z << " ";
    return ostr;
}

class DSU
{
public:
    map<p3d,p3d> vec;

    DSU() : vec(map<p3d,p3d>{}){};
    void make_set(const p3d& t)
    {
        vec[t] = t;
    }
    p3d find(const p3d& t,int DEPTH = 0)
    {
        if(DEPTH > 1000){cerr<<"Recursion error";return t;}
        if (vec[t] == t)return t;
        return vec[t] = find(vec[t],DEPTH+1);
    }
    void union_set( p3d t, p3d s)
    {
        t = find(t);
        s = find(s);
        if(t!=s)vec[s] = t;
    }
};

signed main(/*int argc, char **argv*/)
{
	if(INPUT_FILE)
        freopen("Demo.txt","r",stdin);
    else 
        freopen("In.txt","r",stdin);
    #ifndef CLI
	freopen("Out.txt", "w", stdout);
	#endif

    vector<p3d> point(file_size);
    for(auto &[x,y,z] : point){
        char buff;
        cin>>x>>buff>>y>>buff>>z;
    } 
    DSU m;
    vector<pair<p3d,p3d>> dists;
    for(int i = 0; i < file_size; i++){
        m.make_set(point[i]);
        if((i+1)%100==0)cerr<<"100 done\n";
        for(int j = i+1; j < file_size; j++){
            dists.push_back(make_pair(point[i],point[j]));
        }
       
    }
    sort(dists.begin(),dists.end(),[](const auto& a, const auto& b){
        return dist(a.first,a.second) < dist(b.first, b.second);
    });
    /*
    for(const auto &[i,j] : dists | views::take(TAKE_AMT)){
        //cout<<i<<j<<"\n";
        m.union_set(i,j);
    }
    
    cerr<<"working\n";
    map<p3d,int> c;
    for(auto &[k,v] : m.vec){
        //cout<<k<<v<<endl;
        c[m.find(k)]++;
    }
    long long cnt = 1;
    
    vector<long long> m3;
    for(auto &[i,j] : c)
    {
        
        m3.push_back(j);
        
    };
    rng::sort(m3);
    for(auto i :  m3 | views::reverse | views::take(3))cnt*=i;
    cout<<cnt<<"\n";
    */
    for(const auto& [i,j] : dists)
    {
        set<p3d> uc;
        m.union_set(i,j);
        for(const auto& [k,v] : m.vec)
        {
            uc.insert(m.find(k));
        }
        if(uc.size()==1){
            cout<<i.x <<" "<< j.x<<"\n";
            cout<<i.x * j.x<<"\n";
            return 0;
        }
    }
    return 0;
}
