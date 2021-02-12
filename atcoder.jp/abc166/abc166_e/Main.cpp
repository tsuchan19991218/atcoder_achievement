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
    vector <ll> a(n);
    vector <ll> r(n), l(n);
    rep(i, n){
        cin >> a.at(i);

        if(i + a.at(i) < n)r.at(i + a.at(i)) ++;
        if(i - a.at(i) >= 0)l.at(i - a.at(i)) ++;
    }

    ll ans = 0;
    rep(i, n){
        ans += r.at(i) * l.at(i);
    }
    cout << ans << endl;
}