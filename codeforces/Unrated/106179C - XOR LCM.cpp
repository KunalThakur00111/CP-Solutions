#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long c;
    cin>>c;
    long long a=c;
    int bits=0;
    long long copy=c;
    while(copy){
        bits++;
        copy=copy>>1LL;
    }
    long long b=c;
    for(int i=0;i<bits;i++){
        b=b<<1LL;
    }
    cout<<a<<" "<<b<<endl;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}