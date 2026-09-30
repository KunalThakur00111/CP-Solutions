#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> small,large;
    for(int i=0;i<n;i++){
        if(i<(n/2)){
            if(a[i]<=n/2){
                small.emplace_back(a[i]);
            }
            else large.emplace_back(a[i]);
        }
        else{
            if(a[i]<=n/2){
                large.emplace_back(a[i]);
            }
            else small.emplace_back(a[i]);
        }
    }
    if(small.size()==0 || large.size()==0){
        cout<<1<<endl;
        cout<<n<<" ";
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl; return;
    }
    cout<<2<<endl;
    cout<<small.size()<<" ";
    for(int i=0;i<small.size();i++){
        cout<<small[i]<<" ";
    }
    cout<<endl;
    cout<<large.size()<<" ";
    for(int i=0;i<large.size();i++){
        cout<<large[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}