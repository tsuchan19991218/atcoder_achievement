#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    int n, d, h; cin >> n >> d >> h;
    vector <pair<int, int>> d_h(n);
    rep(i, n){
        int _d, _h; cin >> _d >> _h;
        d_h.at(i) = make_pair(_d, _h);
    }
    sort(d_h.begin(), d_h.end());
    double ans = 0;
    for(int i = 0; i < n; i ++){
        if(d_h.at(i).first > d) break;
        double now_d = d_h.at(i).first;
        double now_h = d_h.at(i).second;
        ans = max(ans, h - ((h - now_h) / (d - now_d)) * d);
    }
    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
    //cout << INF << endl;
}