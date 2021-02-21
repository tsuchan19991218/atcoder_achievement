#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

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
    ll a, b, c; cin >> a >> b >> c;

    // if(a == 1){
    //     cout << 1 << endl;
    //     return 0;
    // }

    vector <int> x(10, -1);
    int d = 0;
    ll m = a % 10;
    int size;
    while(1){
        m = m % 10;
        if(x.at(m) != -1){
            size = d;
            break;
        }
        x.at(m) = d;
        d ++;
        m *= a;
    }

    // for(auto i: x){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << size << endl;
    auto index = pow(b, c, size) - 1;
    index += size;
    index %= size;

    int ans = 0;
    for(auto num: x){
        if(num != index){
            ans ++;
            continue;
        }
        cout << ans << endl;
        return 0;
    }

}