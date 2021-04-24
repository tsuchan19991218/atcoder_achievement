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
    int n; cin >> n;
    vector <int> a(n), b(n);
    rep(i, n){
        cin >> a.at(i);
    }
    rep(i, n){
        cin >> b.at(i);
    }
    int min_x = a.at(0);
    int max_x = b.at(0);
    for(int i = 1; i < n; i ++){
        min_x = max(min_x, a.at(i));
        max_x = min(max_x, b.at(i));
    }
    cout << max(0, (max_x - min_x + 1)) << endl;
}