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
void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        int u;
        cin>>u;
        int x=0;
        for(int j=0;j<31;j++){
            if(u & (1<<j)) x=j;
        }
        int y=0,z=0;
        if(!(u & (u-1))){

        }
        else if(!((u-1)&(u-2))){
            y=1;
        }
        else z=1;
        if(i==0){
            a[0]=x;
            b[0]=y;
            c[0]=z;
        }
        else{
            a[i]=a[i-1]+x;
            b[i]=b[i-1]+y;
            c[i]=c[i-1]+z;
        }
    }
    vl ans(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        r--;
        l--;
        ll sum1=a[r]-(l==0?0:a[l-1]);
        ll sum2=b[r]-(l==0?0:b[l-1]);
        ll sum3=c[r]-(l==0?0:c[l-1]);
        ans[i]=sum1+sum3+sum2/2;
    }
    for(ll i: ans) cout<<i<<endl;
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