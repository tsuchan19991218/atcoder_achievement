#include <bits/stdc++.h>
#include <atcoder/all>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 9000000000000000000;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

//cでもc++でも
ll lcm(ll a, ll b){
  return a*b / gcd(a, b);
}



int main(){
    
    int t; cin >> t;

    while(t--){
        ll x, y, p, q; cin >> x >> y >> p >> q;

        ll ans = INFLL;
        for(ll m = x; m < x + y; m ++){
            vector <ll> v1, v2;
            v1 = {m, p};
            v2 = {(2 * x + 2 * y), (p + q)};
            auto P = crt(v1, v2);
            if(P.first != 0){
                while(P.first < x || P.first < p){
                    P.first += P.second;
                }
                ans = min(P.first, ans);
            }
        }

        for(ll m = x + 1; m <= x + y; m ++){
            vector <ll> v1, v2;
            v1 = {m, 0};
            v2 = {(2 * x + 2 * y), (p + q)};
            auto P = crt(v1, v2);
            if(P.first != 0){
                while(P.first < x || P.first < p){
                    P.first += P.second;
                }
                ans = min(P.first, ans);
            }
        }

        for(ll m = p; m < p + q; m ++){
            vector <ll> v1, v2;
            v1 = {x, m};
            v2 = {(2 * x + 2 * y), (p + q)};
            auto P = crt(v1, v2);
            if(P.first != 0){
                while(P.first < x || P.first < p){
                    P.first += P.second;
                }
                ans = min(P.first, ans);
            }
        }

        if(ans == INFLL){
            cout << "infinity" << endl;
            continue;
        }
        cout << ans << endl;

    }
}