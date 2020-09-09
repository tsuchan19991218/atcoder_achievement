#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    ll n; cin >> n;
    ll ans = 1;
    vector <ll> prime_cnt(n + 1);
    rep(i, n + 1){
        if (i == 0) continue;
        auto res = prime_factorize(i);
        for (auto p: res){
            prime_cnt.at(p.first) += p.second; 
        }
    }

    rep(i, n + 1){
        ans = ans * (prime_cnt.at(i) + 1) % 1000000007;
    }

    cout << ans << endl;

}