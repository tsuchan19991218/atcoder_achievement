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
    ll n, x; cin >> n >> x;
    x *= 100;
    //vector <ll> v(n), p(n);
    rep(i, n){
        ll v, p; cin >> v >> p;
        //cin >> v.at(i) >> p.at(i);
        x -= v * p;
        if(x < 0){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}