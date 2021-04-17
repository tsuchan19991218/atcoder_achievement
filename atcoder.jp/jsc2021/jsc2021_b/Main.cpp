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
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    set <int> s;
    rep(i, n){
        cin >> a.at(i);
    }
    rep(i, m){
        cin >> b.at(i);
    }

    vector <int> ans;
    rep(i, n){
        bool flag = true;
        rep(j, m){
            if(a.at(i) == b.at(j)){
                flag = false;
            }
        }
        if(flag) ans.push_back(a.at(i));
    }

    rep(i, m){
        bool flag = true;
        rep(j, n){
            if(b.at(i) == a.at(j)){
                flag = false;
            }
        }
        if(flag) ans.push_back(b.at(i));
    }

    sort(ans.begin(), ans.end());
    for(auto num: ans){
        cout << num << " ";
    }
    cout << endl;
}