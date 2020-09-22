#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    int h, w;
    cin >> h >> w;
    vector <string> c(h);
    pair <int, int> s_pos, g_pos;
    rep(i, h) {
        cin >> c.at(i);
        for(int j = 0; j < w; j ++){
            if(c.at(i).at(j) == 's') s_pos = make_pair(i, j);
            else if(c.at(i).at(j) == 'g') g_pos = make_pair(i, j);
        }
    }

    vector <vector<int>> dist(h, vector<int>(w, -1));

    vector <int> dy = {0, 1, 0, -1};
    vector <int> dx = {1, 0, -1, 0};

    deque <pair<int, int>> d; d.push_back(s_pos);
    dist.at(s_pos.first).at(s_pos.second) = 0;

    while(!d.empty()){
        auto v = d.front();
        d.pop_front();

        rep(i, 4){
            int next_y, next_x;
            next_y = v.first + dy.at(i);
            next_x = v.second + dx.at(i);

            if(next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) continue;
            if(c.at(next_y).at(next_x) == '#') continue;
            if(dist.at(next_y).at(next_x) != -1) continue;

            dist.at(next_y).at(next_x) = dist.at(v.first).at(v.second) + 1;
            d.push_back(make_pair(next_y, next_x));
        }
    }

    //cout << dist.at(g_pos.first).at(g_pos.second) << endl;
    if(dist.at(g_pos.first).at(g_pos.second) == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
}