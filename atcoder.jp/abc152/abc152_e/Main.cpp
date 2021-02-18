#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int mod = 1e9 + 7;

// ll my_pow(ll x, ll p){
//     if(p == 0) return 1;
//     if(p == 1) return x % mod;

//     if(p % 2 == 0) return my_pow(x, p/2) * my_pow(x, p/2) % mod;
//     else return x * my_pow(x, p/2) * my_pow(x, p/2) % mod;
// }

long long my_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % mod;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

// ll my_lcm(ll a, ll b){
//     ll ue = a * b;
//     ue %= mod;
//     ll sita = gcd(a, b);
//     sita = my_pow(sita, mod - 2);

//     return ue * sita % mod;
// }


int main(){

    int n; cin >> n;
    vector <ll> a(n);
    vector <int> div(2000005);
    ll l = 1;
    rep(i, n){
        cin >> a.at(i);
        //l = my_lcm(l, a.at(i));
        int _a = a.at(i);
        for(int j = 2; j < 1500; j ++){
            if(_a % j != 0) continue;
            int cnt = 0;
            while(_a % j == 0){
                _a /= j;
                cnt ++;
            }
            div.at(j) = max(div.at(j), cnt);
        }
        div.at(_a) = max(div.at(_a), 1);
    }

    rep(i, 2000005){
        if(i == 0) continue;
        l *= my_pow(i, div.at(i));
        l %= mod;
    }

    //cout << l << endl;
    ll ans = 0;
    rep(i, n){
        ans += l * my_pow(a.at(i), mod - 2);
        ans %= mod;
    }

    cout << ans << endl;
}