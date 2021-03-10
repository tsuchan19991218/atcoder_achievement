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
    ll ans = 0;
    for(ll x = 1; x * x <= n; x ++){
        if(n % x != 0) continue;
        ll p = x;
        ll q = n / p;
        ll m = p - 1;
        if(m > 1 && n % m != 0 && (n / m) == (n % m)) ans += m;
        if(p == q) continue;
        m = q - 1;
        if(m > 1 && n % m != 0 && (n / m) == (n % m)) ans += m;
    }
    cout << ans << endl;
}