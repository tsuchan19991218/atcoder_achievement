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
    ll r, x, y; cin >> r >> x >> y;
    ll g_r = (x * x) + (y * y);
    r *= r;
    if(g_r < r){
        cout << 2 << endl;
        return 0;
    }
    ll ans = 1;
    while(1){
        if(r * ans * ans >= g_r){
            cout << ans << endl;
            return 0;
        }
        ans ++;
    }
}