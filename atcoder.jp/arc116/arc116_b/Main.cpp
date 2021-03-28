#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int MOD = 998244353;
long long my_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll n; cin >> n;
    vector <ll> a(n);
    ll X = 0;
    rep(i, n){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    rep(i, n){
        if(i < 2) X += a.at(i) % MOD;
        else X += (a.at(i) * my_pow(2, i-1)) % MOD;

        X %= MOD;
    }
    //cout << X << endl;

    ll ans = 0;
    rep(i, n){
        // cout << i << endl;
        // cout << X << endl;
        ans += a.at(i) * X;
        if(i == n-1) break;
        X = (X - a.at(i) - a.at(i+1)) % MOD;
        X += MOD;
        X %= MOD;
        //cout << X << endl;
        X *= my_pow(2, MOD-2);
        X += a.at(i+1) + MOD;
        X %= MOD;
        //cout << X << endl;
        X += MOD;
        X %= MOD;
        ans += MOD;
        ans %= MOD;
    }
    cout << ans % MOD << endl;

}