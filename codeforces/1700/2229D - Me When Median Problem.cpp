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
bool check(int val,vi& a,vi& b){
    int cnt1=0,cnt0=0;
    int prev=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]>=val && b[i]>=val){
            cnt1+=2;
            if(prev==0){
                cnt0+=2;
            }
            prev=1;
        }
        else if(a[i]<val && b[i]<val){
            prev=0;
        }
    }
    if(prev==0) cnt0+=2;
    return cnt1>cnt0;
}
void solve(){
    // 1 1 ko add krunga, 0 0 ko khtm kr dunga apas m ladake, 0 1 ko consider nhi krna wo apas m mar jayenge
    int n;
    cin>>n;
    vi a(n),b(n);
    for(auto& x: a) cin>>x;
    for(auto& x: b) cin>>x;
    int l=0,h=2*n+1;
    int ans=l;
    while(h>=l){
        int mid=(l+h)/2;
        if(check(mid,a,b)){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    cout<<ans<<endl;
    // 0 0 1 0 1 1
    // 0 0 0 0 1 1

    // 1 0 0 1
    // 0 0 1 1
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