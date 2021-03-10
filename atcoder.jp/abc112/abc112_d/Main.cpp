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
    ll n, m; cin >> n >> m;
    ll ans = 1;
    for(ll i = 1; i * i <= m; i ++){
        ll p = i;
        if(m % p != 0) continue;
        ll q = m / p;
        if(q >= n){
            ans = max(ans, p);
        }
        if(p >= n){
            ans = max(ans, q);
        }
    }
    cout << ans << endl;
}