#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define kunel ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define vl vector<ll>
#define vc vector<char>
#define vi vector<int>
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pair<int,int>>>
#define vvb vector<vector<bool>>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define vvvi vector<vector<vector<int>>>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define gl greater<ll>
#define vp vector<pair<ll,ll>> 
#define __int128_t i128
using ull=unsigned long long;
const int MOD=1e9+7;
const int MOD2=998244353;
const int MOD3=676767677;
const int MAXN=1e6+2;
const int N=2e5;
const int MAX=32;
ll fact[MAXN+1];
ll invfact[MAXN+1];
class disjointset{
    public:
    vi parent,rank,sz;
    disjointset(int n){
        parent.resize(n);
        rank.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]!=u){
            return parent[u]=find(parent[u]);
        }
        return u;
    }
    void unionbyrank(int u,int v){
        int uu=find(u);
        int vv=find(v);
        if(uu==vv) return;
        if(rank[uu]>rank[vv]){
            parent[vv]=uu;
        }
        else if(rank[vv]>rank[uu]){
            parent[uu]=vv;
        }
        else{
            parent[uu]=vv;
            rank[vv]++;
        }
    }
    void unionbysize(int u,int v){
        int uu=find(u);
        int vv=find(v);
        if(uu==vv) return;
        if(sz[uu]>sz[vv]){
            parent[vv]=uu;
            sz[uu]+=sz[vv];
        }
        else{
            parent[uu]=vv;
            sz[vv]+=sz[uu];
        }
    }
};
ll gcd(ll a, ll b) {
    while(b!=0){
        ll t=b;
        b=a%b;
        a=t;
    }
    return a;
}
ll binexp(ll a,ll b){
    ll res=1;
    a%=MOD2;
    while(b){
        if(b&1) res=res*a%MOD2;
        a=a*a%MOD2;
        b>>=1;
    }
    return res;
}
void precompute(){
    fact[0]=1;
    for(int i=1;i<=MAXN;i++){
        fact[i]=fact[i-1]*i%MOD2;
    }
    invfact[MAXN]=binexp(fact[MAXN],MOD2-2);
    for(int i=MAXN-1;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%MOD2;
    }
}
ll ncr(int n, int r){
    if(r<0 || r>n){
        return 0;
    }
    return fact[n]*invfact[r]%MOD2*invfact[n-r]%MOD2;
}
ll modinv(ll x){
    return binexp(x,MOD-2);
}
void divisors(ll n,vl& div){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div.emplace_back(i);
            if(n/i!=i){
                div.emplace_back(n/i);
            }
        }
    }
}
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
ll power(ll num,ll pow){
    if(pow==0) return 1;
    ll base=num%MOD;
    ll ans=1;
    while(pow>0){
        if(pow&1){
            ans=(base*ans)%MOD;
        }
        base=(base*base)%MOD;
        pow>>=1;
    }
    return ans;
}
tuple<int,int,int> dfs(int node,vvi& adj,vi& a,int& x){
    if(a[node]!=0){
        return {a[node],a[node],1};
    }
    int cnt=0;
    int mx=-1e9,mn=1e9;
    vector<tuple<int,int,int>> child;
    for(auto v: adj[node]){
        auto t=dfs(v,adj,a,x);
        child.push_back(t);
        cnt+=get<2>(t);
        mx=max(mx,get<1>(t));
        mn=min(mn,get<0>(t));
    }
    if((mx-mn+1)!=cnt){
        x=1;
    }
    int m=child.size();
    for(int i=0;i<m;i++){
        int j=(i+1)%m;
        int mx1=get<1>(child[i]);
        int mn2=get<0>(child[j]);
        bool normal=(mx1+1==mn2);
        bool wrap=(mx1==mx && mn2==mn);
        if(!normal && !wrap){
            x=1;
        }
    }
    return {mn,mx,cnt};
}
void solve(){
    int n;
    cin>>n;
    vi p(n-1);
    vvi adj(n+1);
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        adj[u].push_back(i);
    }
    vi a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=0;
    dfs(1,adj,a,x);
    if(x){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int32_t main(){
    kunel
    //precompute();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}