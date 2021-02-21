#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const ll MOD = 998244353;
long long pow(long long x, long long n, ll MOD) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll n, m, k; cin >> n >> m >> k;

    if(n != 1 && m != 1){
        ll ans = 0;
        for(ll i = 1; i <= k; i ++){
            ans += pow(i, n, MOD) * pow(k - i + 1, m, MOD);
            ans -= pow(i-1, n, MOD) * pow(k - i + 1, m, MOD);
            ans = (ans + MOD) % MOD;
            //cout << i << " " << ans << endl;
        }
        //ans -= _ans;
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
        return 0;
    }

    if(n == 1 && m != 1){
        ll ans = 0;
        for(ll i = 1; i <= k; i ++){
            ans += pow(k - i + 1, m, MOD) - pow(k - i, m, MOD);
            ans %= MOD;
        }
        //ans -= _ans;
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
    }
    else if(m == 1 && n != 1){
        ll ans = 0;
        for(int i = 1; i <= k; i ++){
            ans += pow(i, n, MOD) - pow(i - 1, n, MOD);
            ans %= MOD;
        }
        //ans -= _ans;
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
    }
    else{
        cout << k << endl;
    }

}