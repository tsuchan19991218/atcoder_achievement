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
    ll n, m, t; cin >> n >> m >> t;
    ll n_max = n;
    vector <pair <ll, ll>> a_b(m);
    rep(i, m){
        ll a, b; cin >> a >> b;
        a_b.at(i).first = a;
        a_b.at(i).second = b;
    }

    ll pre = 0;
    for(auto a_b: a_b){
        n -= a_b.first - pre;
        if(n <= 0){
            cout << "No" << endl;
            return 0;
        }
        n += (a_b.second - a_b.first);
        n = min(n, n_max);
        pre = a_b.second;
    }
    n -= t - pre;
    if(n <= 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    }