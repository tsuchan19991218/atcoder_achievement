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


    set <ll> ok;

    for(ll a = 2; a <= 1e5 + 5; a ++){
        ll tmp = a;
        for(ll b = 2; b <= 1e5 + 5; b ++){
            tmp *= a;
            if(tmp > n) break;
            ok.insert(tmp);
            //cout << a << " " << b << " " << tmp << endl;
        }
    }

    cout << n - ok.size() << endl;

}