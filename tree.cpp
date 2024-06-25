#define _GLIBCXX_FILESYSTEM
#include<bits/stdc++.h>
#define mod 1000000007
#define read(n) ll n;cin>>n
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define initialize(n,A) int n;cin>>n;vector<int> A(n);for(int i=0;i<n;i++) cin>>A[i]
#define inf 1e9
#define INF 1e18
#define fi first
#define se second
#define full(A) A.begin(),A.end()
#define rfull(A) A.rbegin(),A.rend()
#define  pb push_back
#define vi vector<int>
using namespace std;
using ll = long long;
using pii= pair<int,int>;
int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int n;
vector<vi> g;
vi dis;
vi par;
//Find the diameter length in a tree

void dfs(int nn,int pp,int dd){
    dis[nn]=dd;
    par[nn]=pp;
    //Add
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1);
            //Add
        }

    }
    //Add
}    
//This function saves the shortest path from node nn to all other nodes in a tree in dis[] array

void solve(){
cin>>n;
g.clear();
dis.clear();
par.clear();
g.resize(n+1);
dis.resize(n+1);
par.resize(n+1);
ff(i,1,n-1){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
}

dfs(1,0,0);
int max1=1;
ff(i,2,n){
    if(dis[max1]<dis[i]) max1=i;
}


dfs(max1,0,0);
int max2=1;
ff(i,2,n){
    if(dis[max2]<dis[i]) max2=i;
}

vi path;
int temp=max2;
while(temp!=0){
    path.pb(temp);
    temp=par[temp];
}

cout<<path.size()-1<<endl;//will give the length of the diameter
//Diameter has odd nodes
if(path.size()%2){
   int centre=path[path.size()/2];
   cout<<centre<<endl;
}
//Diameter has even nodes
else{
    int centre1=path[path.size()/2];
    int centre2=path[(path.size()-1)/2];
    cout<<centre1<<" "<<centre2<<endl;

}


}
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1; cin>>t; while(t--)
    solve();
    return 0;
}
// input
// 1
// 7
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7