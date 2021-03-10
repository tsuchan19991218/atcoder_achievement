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
    ll n, a, b; cin >> n >> a >> b;
    vector <ll> x(n);
    ll first = 0;
    ll ans = 0;
    rep(i, n){
        if(i == 0){
            cin >> first;
            x.at(i) = first;
            continue;
        }
        ll _x; cin >> _x;
        x.at(i) = _x;
        if((x.at(i) - x.at(i-1)) * a > b) ans += b;
        else ans += (x.at(i) - x.at(i-1)) * a;
    }
    cout << ans << endl;
}