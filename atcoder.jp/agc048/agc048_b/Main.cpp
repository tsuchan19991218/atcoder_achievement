#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)



int main(){
    int n; cin >> n;
    vector <ll> a(n), b(n);
    ll ans = 0;
    priority_queue <ll> kisu, gusu;
    rep(i, n){
        cin >> a.at(i);
        ans += a.at(i);
    }
    rep(i, n){
        cin >> b.at(i);
    }
    
    rep(i, n){
        if(i % 2 == 0) gusu.push(b.at(i) - a.at(i));
        else kisu.push(b.at(i) - a.at(i)); 
    }

    while(!gusu.empty() && !kisu.empty()){
        ll tmp = gusu.top() + kisu.top();
        gusu.pop(); kisu.pop();
        if(tmp < 0) break;
        ans += tmp;
    }

    cout << ans << endl;

}