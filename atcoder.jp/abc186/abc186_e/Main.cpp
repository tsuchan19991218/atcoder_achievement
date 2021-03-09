#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;


// ax + by = gcd(a, b)　解く
pair <ll, ll> ext_gcd(ll a, ll b){
    //cout << a << " " << b << endl;
    if(b == 0) return make_pair(1, 0);
    auto _xy = ext_gcd(b, a % b);
    return make_pair(_xy.second, _xy.first - (a / b) * _xy.second);
}

int main(){
    ll t; cin >> t;
    while(t --){
        ll n, s, k; cin >> n >> s >> k;
        if((n - s) % k == 0){
            cout << (n - s) / k << endl;
            continue;
        }
        // s + kx = 0 mod n
        // kx - ny = -s

        ll g = gcd(gcd(k, n), s);
        k /= g;
        n /= g;
        s /= g;
        if(gcd(k, n) != 1){
            cout << -1 << endl;
            continue;
        }
        //auto p = ext_gcd(max(k, n), min(k, n));
        auto p = ext_gcd(k, n);
        //cout << p.first << " " << p.second << endl;

        cout << ((((p.first * -s) % n) + n) % n) << endl;
    }
}