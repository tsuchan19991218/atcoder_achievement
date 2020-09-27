#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 100000000;

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int h, w; cin >> h >> w;
    vector <string> c(h);
    vector <vector <int>> b_cnt(h, vector<int>(w, INF));
    deque <pair<int, int>> d;
    pair <int, int> g_pos;
    rep(i, h){
        cin >> c.at(i);
        rep(j, w){
            if(c.at(i).at(j) == 's'){
                b_cnt.at(i).at(j) = 0;
                d.push_back(make_pair(i, j));
            }
            if(c.at(i).at(j) == 'g'){
                g_pos = make_pair(i, j);
            }
        }
    }

    while(!d.empty()){
        auto v = d.back();
        d.pop_back();
        int x, y;
        y = v.first; x = v.second;
        rep(i, 4){
            int nx, ny;
            ny = y + dy.at(i); nx = x + dx.at(i);

            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            else if(c.at(ny).at(nx) == '#'){
                if(b_cnt.at(ny).at(nx) <= b_cnt.at(y).at(x) + 1) continue;
                b_cnt.at(ny).at(nx) = b_cnt.at(y).at(x) + 1;
                d.push_front(make_pair(ny, nx));
            }
            else if(b_cnt.at(ny).at(nx) <= b_cnt.at(y).at(x))continue;
            else{
                b_cnt.at(ny).at(nx) = b_cnt.at(y).at(x);
                d.push_back(make_pair(ny, nx));
            }

            // rep(j, 4){
            //     int nnx, nny;
            //     nny = ny + dy.at(j); nnx = nx + dx.at(j);

            //     if(nny < 0 || nny >= h || nnx < 0 || nnx >= w);
            //     else if(c.at(nny).at(nnx) == '#');
            //     else if(b_cnt.at(nny).at(nnx) <= b_cnt.at(y).at(x) + 1);
            //     else{
            //         b_cnt.at(nny).at(nnx) = b_cnt.at(y).at(x) + 1;
            //         d.push_front(make_pair(nny, nnx));
            //     }
            // }
        }
    }
    if(b_cnt.at(g_pos.first).at(g_pos.second) <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    //cout << b_cnt.at(g_pos.first).at(g_pos.second) << endl;

}