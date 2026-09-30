#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    if(n%2==0){
        for(int i=0;i<n;i+=2){
            if(a[i+1]-a[i]>d) {cout<<"NO\n"; return;}
        }
        cout<<"YES\n";
    }
    else{
        for(int i=0;i<n;i++){
            int f=0;
            vector<int> na;
            for(int j=0;j<n;j++){
                if(i!=j) na.emplace_back(a[j]);
            }
            for(int i=0;i<n-1;i+=2){
                if(na[i+1]-na[i]>d) {f=1;break;}
            }
            if(!f){
                cout<<"YES\n"; return;
            }
        }
        cout<<"NO\n";
    }
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}