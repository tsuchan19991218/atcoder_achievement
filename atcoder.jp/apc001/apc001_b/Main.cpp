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
    ll x, y;
    x = y = 0;
    vector <ll> a(n), b(n);
    rep(i, n){
        ll _a; cin >> _a;
        a.at(i) = _a;
    }
    rep(i, n){
        ll _b; cin >> _b;
        b.at(i) = _b;
    }
    rep(i, n){
        x += max(0LL, (b[i] - a[i]) / 2);
        y += max(0LL, (a[i] - b[i]));
    }
    // cout << x << " " << y << endl;
    if(x >= y)cout << "Yes" << endl;
    else cout << "No" << endl;
}