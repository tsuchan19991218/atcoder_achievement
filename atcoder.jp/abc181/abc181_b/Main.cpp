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
    ll ans = 0;
    int n; cin >> n;
    vector<pair <ll, ll>> a_b(n);
    rep(i, n){
        ll a, b; cin >> a >> b;
        a_b.at(i) = make_pair(a, b);
    }

    vector <ll> sum(1000005);
    for(ll i = 0; i < 1000005; i ++){
        sum.at(i) = i * (i + 1) / 2;
    }

    for(auto p: a_b){
        ans += sum.at(p.second) - sum.at(p.first - 1);
    }
    cout << ans << endl;
}