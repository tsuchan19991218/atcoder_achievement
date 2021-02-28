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

    ll x, y, a, b; cin >> x >> y >> a >> b;

    ll ans = 0;
    while(x < b / (a - 1) && x * a < y){
        ans ++;
        x *= a;
    }
    ans += ((y - 1) - x) / b;
    cout << ans << endl;
}