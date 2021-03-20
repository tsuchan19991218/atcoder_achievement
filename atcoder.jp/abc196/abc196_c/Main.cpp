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

ll get_num(ll x){
    string s_x = to_string(x);
    //if(s_x.size() % 2 == 1) return INFLL;
    reverse(s_x.begin(), s_x.end());
    ll d = 1;
    ll ans = 0;
    for(auto c: s_x){
        ans += d * (c - '0');
        d *= 10;
    }
    for(auto c: s_x){
        ans += d * (c - '0');
        d *= 10;
    }
    return ans;
}

int main(){
    ll n; cin >> n;
    int max_x = 1000000 + 5;
    ll ans = 0;
    for(ll x = 1; x < max_x; x ++){
        ll now = get_num(x);
        //cout << x << " " << now << endl;
        if(now <= n) ans ++;
    }
    cout << ans << endl;
}