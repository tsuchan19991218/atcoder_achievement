#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {1, 0, -1, 0};
vector <int> dx = {0, 1, 0, -1};

const int INF = 1000000000;

int main(){
    int r, c; cin >> r >> c;
    pair <int, int> s_pos;
    pair <int, int> g_pos;

    int x, y; cin >> x >> y;
    s_pos = make_pair(x - 1, y - 1);
    cin >> x >> y;
    g_pos = make_pair(x - 1, y - 1);

    vector <string> C(r);
    rep(i, r) cin >> C.at(i);
    
    deque <pair<int, int>> d;
    vector <vector<int>> dist(r, vector<int>(c, INF));

    d.push_back(s_pos);
    dist.at(s_pos.first).at(s_pos.second) = 0;

    while(!d.empty()){
        auto v = d.front();
        d.pop_front();

        rep(i, 4){
            int y = v.first;
            int x = v.second;
            int ny = v.first + dy.at(i);
            int nx = v.second + dx.at(i);

            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(C.at(ny).at(nx) == '#') continue;
            if(dist.at(ny).at(nx) <= dist.at(y).at(x) + 1) continue;

            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            d.push_back(make_pair(ny, nx));
        }
    }
    cout << dist.at(g_pos.first).at(g_pos.second) << endl;
}