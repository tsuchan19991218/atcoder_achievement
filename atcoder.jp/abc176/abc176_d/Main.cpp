#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

vector <pair<int, int>> dy_5_dx;


ll mod = 998244353;
int INF = 1000000000;

int main(){
    rep(i, 5)rep(j, 5){
        int y = i - 2; int x = j - 2;
        bool ok = true;
        rep(k, 4){
            if(y == dy.at(k) && x == dx.at(k)) ok = false;
        }
        if(!ok) continue;
        if(x == 0 && y == 0) continue;
        dy_5_dx.push_back(make_pair(y, x));
    }
    int w, h; cin >> h >> w;
    pair <int, int> s_pos, g_pos;
    cin >> s_pos.first >> s_pos.second;
    cin >> g_pos.first >> g_pos.second;
    s_pos.first --; s_pos.second --;
    g_pos.first --; g_pos.second --;
    vector <string> s(h); rep(i, h) cin >> s.at(i);

    deque <pair<int, int>> d; d.push_back(make_pair(s_pos.first, s_pos.second));
    vector <vector<int>> cnt(h, vector<int>(w, INF)); cnt.at(s_pos.first).at(s_pos.second) = 0;

    while(!d.empty()){
        auto v = d.back();
        d.pop_back();
        int y = v.first; int x = v.second;
        rep(i, 4){
            int ny = y + dy.at(i);
            int nx = x + dx.at(i);
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(s.at(ny).at(nx) == '#') continue;
            if(cnt.at(ny).at(nx) <= cnt.at(y).at(x)) continue;

            cnt.at(ny).at(nx) = cnt.at(y).at(x);
            d.push_back(make_pair(ny, nx));
        }
        for(auto dy_dx: dy_5_dx){
            int ny = y + dy_dx.first;
            int nx = x + dy_dx.second;

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(s.at(ny).at(nx) == '#') continue;
            if(cnt.at(ny).at(nx) <= cnt.at(y).at(x) + 1) continue;

            cnt.at(ny).at(nx) = cnt.at(y).at(x) + 1;
            d.push_front(make_pair(ny, nx));
        }
    }

    if(cnt.at(g_pos.first).at(g_pos.second) == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << cnt.at(g_pos.first).at(g_pos.second) << endl;

}