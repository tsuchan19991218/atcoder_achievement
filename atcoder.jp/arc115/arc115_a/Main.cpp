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

ll nC2(ll n){
    return (n * (n - 1)) / 2;
}

int main(){
    ll n, m; cin >> n >> m;
    vector <string> s(n);
    rep(i, n){
        cin >> s.at(i);
    }

    ll damedane = 0;
    ll ok = 0;
    for(int i = 1; i < n; i ++){
        ll tmp = 0;
        for(int j = 0; j < m; j ++){
            tmp += (s.at(0).at(j) - '0') ^ (s.at(i).at(j) - '0');
        }
        //cout << tmp << endl;
        if(tmp % 2 == 0) damedane ++;
        else ok ++;
    }
    cout << ok + (damedane * ok) << endl;
}