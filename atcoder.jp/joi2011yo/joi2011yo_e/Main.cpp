#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {1, 0, -1, 0};
vector <int> dx = {0, 1, 0, -1};

const int INF = 1000000000;

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector <string> s(h);
    vector <pair<int, int>> s_pos(n + 1);
    rep(i, h){
        cin >> s.at(i);
        rep(j, w){
            if(s.at(i).at(j) == '.' || s.at(i).at(j) == 'X') continue;
            if(s.at(i).at(j) == 'S'){
                s_pos.at(0) = make_pair(i, j);
                continue;
            }
            int index = s.at(i).at(j) - '0';
            s_pos.at(index) = make_pair(i, j);
            //cout << i << " " << j << " " << index << endl;
        }
    }
    ll ans = 0;
    for(int now = 0; now < n; now ++){
        // now ~~~ now + 1　までの最短距離を足すだけ
        int sy = s_pos.at(now).first;
        int sx = s_pos.at(now).second;

        int gy = s_pos.at(now + 1).first;
        int gx = s_pos.at(now + 1).second;

        deque <pair<int, int>> d;
        vector <vector<int>> dist(h, vector<int>(w, INF));
        d.push_back(make_pair(sy, sx)); 
        dist.at(sy).at(sx) = 0;

        while(!d.empty()){
            auto v = d.front(); d.pop_front();
            int y = v.first;
            int x = v.second;
            rep(i, 4){
                int ny = y + dy.at(i);
                int nx = x + dx.at(i);

                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(s.at(ny).at(nx) == 'X') continue;
                if(dist.at(ny).at(nx) <= dist.at(y).at(x) + 1) continue;

                dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                d.push_back(make_pair(ny, nx));
            }
        }


        ans += dist.at(gy).at(gx);
    }

    cout << ans << endl;
}