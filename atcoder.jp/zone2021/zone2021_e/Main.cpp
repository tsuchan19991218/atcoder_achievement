#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
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
    int r, c; cin >> r >> c;
    vector <vector<int>> a(r, vector <int>(c-1));
    rep(i, r)rep(j, c-1) cin >> a.at(i).at(j);
    vector <vector<int>> b(r-1, vector<int>(c));
    rep(i, r-1)rep(j, c) cin >> b.at(i).at(j);

    vector <vector<int>> dist(r, vector<int>(c, INF));
    dist.at(0).at(0) = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, make_pair(0, 0)));
    // r--;
    // c--;
    while(que.size()){
        auto p = que.top();
        que.pop();
        int y, x;
        int w = p.first;
        y = p.second.first;
        x = p.second.second;
        if(dist.at(y).at(x) < w) continue;
        // cout << y << " " << x << endl;
        // cout << dist.at(y).at(x) << endl;
        if(x + 1 < c){
            if(dist.at(y).at(x + 1) > dist.at(y).at(x) + a.at(y).at(x)){
                dist.at(y).at(x + 1) = dist.at(y).at(x) + a.at(y).at(x);
                que.push(make_pair(dist.at(y).at(x+1), make_pair(y, x + 1)));
            }
        }
        if(x - 1 >= 0){
            if(dist.at(y).at(x - 1) > dist.at(y).at(x) + a.at(y).at(x-1)){
                dist.at(y).at(x - 1) = dist.at(y).at(x) + a.at(y).at(x-1);
                que.push(make_pair(dist.at(y).at(x-1), make_pair(y, x - 1)));
            }
        }
        if(y + 1 < r){
            if(dist.at(y+1).at(x) > dist.at(y).at(x) + b.at(y).at(x)){
                dist.at(y+1).at(x) = dist.at(y).at(x) + b.at(y).at(x);
                que.push(make_pair(dist.at(y+1).at(x), make_pair(y+1, x)));
            }
        }

        for(int pre_y = y-1; pre_y >= 0; pre_y --){
            int cost = y - pre_y + 1;
            if(dist.at(pre_y).at(x) > dist.at(y).at(x) + cost){
                dist.at(pre_y).at(x) = dist.at(y).at(x) + cost;
                que.push(make_pair(dist.at(pre_y).at(x), make_pair(pre_y, x)));
            }
        }
    }

    // rep(i, r)rep(j, c){
    //     cout << dist.at(i).at(j) << endl;
    // }
    cout << dist.at(r-1).at(c-1) << endl;
    //cout << INF << endl;
}