#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 2000000005;
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
    int n; cin >> n;
    vector <pair<ll, ll>> c_x(n);
    rep(i, n){
        ll x, c; cin >> x >> c;
        c --;
        c_x.at(i) = make_pair(c, x);
    }
    sort(c_x.begin(), c_x.end());

    vector <ll> min_of_c(n, INFLL);
    vector <ll> max_of_c(n, -INFLL);

    int now = c_x.at(0).first;
    ll m = INFLL;
    ll M = -INFLL;
    rep(i, n+1){
        if(i == n){
            min_of_c.at(now) = m;
            max_of_c.at(now) = M;
            break;
        }
        if(c_x.at(i).first != now){
            min_of_c.at(now) = m;
            max_of_c.at(now) = M;

            m = INFLL;
            M = -INFLL;
            now = c_x.at(i).first;
        }
        m = min(m, c_x.at(i).second);
        M = max(M, c_x.at(i).second);
        // cout << i << endl;
        // cout << m << " " << M << endl;
    }
    vector <vector<ll>> dp(2, vector <ll>(2, INFLL));
    const int R = 0;
    const int L = 1;
    dp[R][R] = dp[R][L] = dp[L][L] = dp[L][R] = 0;

    now = 0;
    ll pre_M = 0;
    ll pre_m = 0;
    for(int i = 0; i < n; i ++){
        if(min_of_c.at(i) == INFLL) continue;
        now = pre_M;
        ll tmp1, tmp2;
        tmp1 = min(dp[R][R], dp[L][R]);
        tmp2 = min(dp[R][L], dp[L][L]);
        dp[R][R] = tmp1 + abs(min_of_c.at(i) - now) + abs(max_of_c.at(i) - min_of_c.at(i));
        dp[R][L] = tmp1 + abs(max_of_c.at(i) - now) + abs(max_of_c.at(i) - min_of_c.at(i));
        now = pre_m;
        dp[L][R] = tmp2 + abs(min_of_c.at(i) - now) + abs(max_of_c.at(i) - min_of_c.at(i));
        dp[L][L] = tmp2 + abs(max_of_c.at(i) - now) + abs(max_of_c.at(i) - min_of_c.at(i));
        // cout << i << endl;
        // cout << min_of_c.at(i) << " " << max_of_c.at(i) << endl;
        // cout << dp[R][R] << " " << dp[R][L] << " " << dp[L][R] << " " << dp[L][L] << endl;

        pre_M = max_of_c.at(i);
        pre_m = min_of_c.at(i);
    }
    cout << min(min(dp[R][R] + abs(pre_M), dp[R][L] + abs(pre_m)), min(dp[L][L] + abs(pre_m), dp[L][R] + abs(pre_M))) << endl;
}