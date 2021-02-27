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
    ll ans = INFLL;
    
    rep(i, n){
        ll a, p, x; cin >> a >> p >> x;

        x -= a;
        if(x <= 0) continue;
        ans = min(ans, p);
    }

    if(ans == INFLL){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}