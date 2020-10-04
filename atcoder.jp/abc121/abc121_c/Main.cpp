#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n, m; cin >> n >> m;
    vector <pair<int, int>> a_b(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        a_b.at(i) = make_pair(a, b);
    }
    sort(a_b.begin(), a_b.end());

    ll ans = 0;
    rep(i, n){
        ll cost = a_b.at(i).first;
        ll limit = a_b.at(i).second;
        ll max_cost = cost * limit;
        if(limit > m){
            ans += cost * m;
            break;
        }
        else{
            ans += max_cost;
            m -= limit;
        }
    }
    cout << ans << endl;
}