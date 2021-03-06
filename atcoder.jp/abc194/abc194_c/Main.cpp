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
    ll n; cin >> n;
    vector <ll> a(n), a2(n);
    rep(i, n) cin >> a.at(i);
    rep(i, n) a2.at(i) = a.at(i) * a.at(i);

    ll x, y, z;
    x = y = z = 0;
    for(ll i = 1; i < n; i ++){
        x += i * a2.at(i);
    }

    vector <ll> s_a(n), s_a2(n);
    s_a.at(0) = a.at(0);
    s_a2.at(0) = a2.at(0);
    rep(i, n){
        if(i == 0) continue;
        s_a.at(i) = s_a.at(i-1) + a.at(i);
        s_a2.at(i) = s_a2.at(i-1) + a2.at(i);
    }

    for(ll i = 0; i < n - 1; i ++){
        y += s_a2.at(i);
        z += a.at(i+1) * s_a.at(i);
    }

    cout << x + y - 2*z << endl;
}