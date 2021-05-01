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
int n;
vector <int> a, b, c, d, e;

void input(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    e.resize(n);
    rep(i, n) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i) >> e.at(i);
}

bool is_ok(ll num){
    vector <int> vec(1<<5);  //  0  ~  31  がはいる
    rep(i, n){
        int tmp = 0;
        tmp += (1 << 4) * (a.at(i) >= num);
        tmp += (1 << 3) * (b.at(i) >= num);
        tmp += (1 << 2) * (c.at(i) >= num);
        tmp += (1 << 1) * (d.at(i) >= num);
        tmp += (1 << 0) * (e.at(i) >= num);

        vec.at(tmp) = 1;
    }

    bool flag = false;
    rep(i, 32)rep(j, 32)rep(k, 32){
        if(!vec.at(i) || !vec.at(j) || !vec.at(k)) continue;
        if((i | j | k) == (1 << 5) - 1) flag = true;
    }
    // for(auto num1: vec){
    //     for(auto num2: vec){
    //         for(auto num3: vec){
    //             if((num1 | num2 | num3) == (1 << 5) - 1) flag = true;
    //         }
    //     }
    // }
    return flag;
}

int main(){
    // cin >> n;
    // rep(i, n) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i) >> e.at(i);
    input();
    ll l = 0;
    ll r = 1000000000 + 5;

    while(r - l > 1){
        ll middle = (l + r) / 2;
        if(is_ok(middle)) l = middle;
        else r = middle;

        //cout << middle << " " << is_ok(middle) << endl;
    }
    cout << l << endl;
}