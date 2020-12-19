#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    int n; cin >> n;
    vector <ll> a(n); rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    vector <ll> dp(n + 5);
    dp.at(0) = 0;

    ll accum = 0;
    for(int i = 1; i < n; i ++){
        ll dist = a.at(i) - a.at(i - 1);
        dp.at(i) = dp.at(i - 1) + dist * (i);
        //cout << dp.at(i) << endl;
    }

    ll ans = 0;
    for(auto num: dp){
        ans += num;
    }
    cout << ans << endl;
}