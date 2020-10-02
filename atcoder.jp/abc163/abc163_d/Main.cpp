#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for (ll i = k; i <= n + 1; i ++){ //i個選ぶ場合
        ll min_simo_num = (i - 1) * i / 2; //i個選んだ時の最小の下の数の和(それ以上は全部作れる？)
        ll max_simo_num = n * i - min_simo_num;
        ans += (max_simo_num - min_simo_num + 1) % 1000000007;
    }
    cout << ans % 1000000007 << endl;
}