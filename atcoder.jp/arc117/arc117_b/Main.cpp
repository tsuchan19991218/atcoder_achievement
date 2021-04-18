#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int MOD = 1000000007;
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
    rep(i, n) cin >> a.at(i);
    sort(a.rbegin(), a.rend());
    ll m = a.at(n-1);
    //cout << m << endl;
    ll ans = 1;
    for(int i = 1; i < n; i ++){
        if(a.at(i) - a.at(i - 1) == 0) continue;
        ans *= (abs(a.at(i) - a.at(i-1)) + 1);
        ans %= MOD;
        //cout << ans << endl;
    }
    ans *= m + 1;
    ans %= MOD;
    cout << ans << endl;
}