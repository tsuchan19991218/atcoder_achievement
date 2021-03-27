#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll n; cin >> n;
    vector <ll> a(n);
    rep(i, n){
        cin >> a.at(i);
    }

    ll ans = INFLL;

    for(ll s = 0; s < (1 << (n - 1)); s ++){
        ll tmp = 0;
        vector <ll> or_values;
        ll _or = a.at(0);
        for(int i = 0; i < n - 1; i ++){
            if((s >> i) & 1){
                or_values.push_back(_or);
                _or = 0;
            }
            _or |= a.at(i + 1);
        }
        or_values.push_back(_or);
        for(auto num: or_values){
            tmp ^= num;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}