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

ll h, w, a, b;
ll ans = 0;
ll dfs(ll y, ll x, ll a, ll b, vector <vector<int>> used){
    if(a < 0 || b < 0) return 0; // 敷ける畳がなくなってしまった場合
    if(x == w){
        x = 0;
        y ++;
    }
    if(y == h) return 1; // y = h -> 全て見終えた 1通りとしてカウントして良い

    ll tmp = 0;
    if(used.at(y).at(x)){ // 今のマスにもう敷いている場合
        return dfs(y, x+1, a, b, used);
    }
    used.at(y).at(x) = 1; // 今のマスに敷く
    rep(i, 3){
        if(i == 0){ // 畳を伸ばさずに次に進める
            tmp += dfs(y, x+1, a, b-1, used);
        }
        if(i == 1){ // 畳を横に伸ばす
            if(x + 1 == w) continue; // 伸ばせない
            if(!used.at(y).at(x+1)){ // 伸ばす方向に畳があるといけない
                used.at(y).at(x+1) = 1;
                tmp += dfs(y, x+1, a-1, b, used);
                used.at(y).at(x+1) = 0;
            }
        }
        if(i == 2){ // 畳を縦に伸ばす
            if(y + 1 == h) continue; // 伸ばせない
            if(!used.at(y+1).at(x)){ // 伸ばす方向に畳があるといけない
                used.at(y+1).at(x) = 1;
                tmp += dfs(y, x+1, a-1, b, used);
                used.at(y+1).at(x) = 0;
            }
        }
    }
    // cout << y << " " << x << " " << a << " " << b << endl;
    // cout << tmp << endl;
    return tmp;
}


int main(){
    cin >> h >> w;
    cin >> a >> b;
    vector <vector<int>> used(h, vector<int>(w, 0));
    cout << dfs(0, 0, a, b, used) << endl;
}