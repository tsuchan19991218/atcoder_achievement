#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    int n; cin >> n;
    vector <ll> a(n);
    rep(i, n) cin >> a.at(i);
    // if(n == 1){
    //     if(a.at(0) != 0) cout << 0 << endl;
    //     else cout << 1 << endl;
    //     return 0;
    // }
    vector <ll> sum_a(n + 1);
    rep(i, n){
        sum_a.at(i + 1) += sum_a.at(i) + a.at(i);
    }
    sort(ALL(sum_a));

    // rep(i, n + 1) cout << sum_a.at(i) << " ";
    // cout << endl;
    
    ll ans = 0;
    ll cnt = 1;
    ll hold_num = sum_a.at(0);
    for(int i = 1; i < n + 1; i ++){
        ll now_num = sum_a.at(i);
        if(hold_num != now_num){
            ans += (cnt * (cnt - 1)) / 2;
            hold_num = now_num;
            cnt = 1;
            continue;
        }
        cnt ++;
        continue;
    }

    ans += (cnt * (cnt - 1)) / 2;
    cout << ans << endl;

}