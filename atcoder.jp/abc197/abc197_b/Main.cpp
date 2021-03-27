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
    int h, w, x, y; cin >> h >> w >> x >> y;
    x--;
    y--;
    vector <string> s(h);
    rep(i, h){
        cin >> s.at(i);
    }

    int now_x = x;
    int now_y = y - 1;
    int ans = 1;
    while(now_y >= 0){
        if(s.at(now_x).at(now_y) != '.') break;
        now_y --;
        ans ++;
    }
    now_y = y + 1;
    while(now_y < w){
        if(s.at(now_x).at(now_y) != '.') break;
        now_y ++;
        ans ++;
    }

    now_x = x - 1;
    now_y = y;
    while(now_x >= 0){
        if(s.at(now_x).at(now_y) != '.') break;
        now_x --;
        ans ++;
    }
    now_x = x + 1;
    while(now_x < h){
        if(s.at(now_x).at(now_y) != '.') break;
        now_x ++;
        ans ++;
    }
    cout << ans << endl;
}