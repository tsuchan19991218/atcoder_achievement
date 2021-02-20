#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

ll g1(ll x){
    string tmp = to_string(x);
    sort(tmp.begin(), tmp.end());
    ll ans = 0;
    ll d = 1;
    for(auto c: tmp){
        ans += d * (c - '0');
        d *= 10;
    }
    return ans;
}

ll g2(ll x){
    string tmp = to_string(x);
    sort(tmp.rbegin(), tmp.rend());
    ll ans = 0;
    ll d = 1;
    for(auto c: tmp){
        ans += d * (c - '0');
        d *= 10;
    }
    return ans;
}

ll f(ll x){
    return g1(x) - g2(x);
}

int main(){
    ll n, k; cin >> n >> k;
    vector <ll> ans(k + 1);
    ans.at(0) = n;
    for(ll i = 1; i <= k; i ++){
        ans.at(i) = f(ans.at(i-1));
    }
    cout << ans.at(k) << endl;
}