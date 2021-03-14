#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int MOD = 998244353;
long long my_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    int n; cin >> n;
    vector <int> f(n);
    ll heiro_cnt = 0;
    vector <int> seen(n, -1);
    rep(i, n){
        int _f;
        cin >> _f;
        _f --;
        f.at(i) = _f;
        // if(f.at(i) == i){
        //     heiro_cnt ++;
        //     seen.at(i) = 1;
        // }
    }
    for(int i = 0; i < n; i ++){
        if(seen.at(i) != -1) continue;
        deque <int> d;
        d.push_back(i);
        seen.at(i) = 1;
        vector <int> path;
        path.push_back(i);
        int flag = false;
        while(d.size()){
            auto now = d.front();
            d.pop_front();
            int next = f.at(now);
            //cout << i << " " << now << " " << next <<  endl;
            if(next == i){
                flag = true;
                break;
            }
            if(seen.at(next) != -1){
                for(int j = 0; j < path.size(); j ++){
                    if(next == path.at(j)) flag = true;
                    if(next == now) flag = true;
                }
                break;
            }
            seen.at(next) = 1;
            path.push_back(next);
            d.push_back(next);
        }
        if(flag){
            heiro_cnt ++;
        }
    }
    cout << my_pow(2, heiro_cnt) - 1 << endl;
}