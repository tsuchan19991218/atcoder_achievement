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
    vector <int> a(n), b(n);
    rep(i, n) cin >> a.at(i) >> b.at(i);
    int ans = INF;
    rep(i, n)rep(j, n){
        if(i == j)ans = min(ans, a.at(i) + b.at(j));
        else ans = min(ans, max(a.at(i), b.at(j)));
    }
    cout << ans << endl;
}