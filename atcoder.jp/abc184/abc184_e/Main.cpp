#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    int h, w; cin >> h >> w;
    vector <string> a(h + 1);
    rep(i, h + 1){
        if(i == 0) continue;
        string s; cin >> s;
        s = " " + s;
        a.at(i) = s;
    }

    pair <int, int> start;
    pair <int, int> goal;

    vector <vector<pair<int,int>>> warp(500);
    vector <int> warped(500, -1);

    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(a.at(i).at(j) == '.') continue;
            if(a.at(i).at(j) <= 'z' && 'a' <= a.at(i).at(j)){
                warp.at(a.at(i).at(j)).push_back(make_pair(i, j));
            }
            if(a.at(i).at(j) == 'S') start = make_pair(i, j);
            if(a.at(i).at(j) == 'G') goal = make_pair(i, j);
        }
    }

    deque <pair<int, int>> d;
    vector <vector <int>> dist(h + 2, vector<int>(w + 2, INF));

    d.push_back(start);
    dist.at(start.first).at(start.second) = 0;

    while(!d.empty()){
        auto v = d.front(); d.pop_front();
        int y = v.first;
        int x = v.second;
        //cout << y << " " << x << endl;
        for(int i = 0; i < 4; i ++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny <= 0 || ny > h || nx <= 0 || nx > w) continue;
            if(a.at(ny).at(nx) == '#') continue;
            //if(dist.at(y).at(x) + 1 >= dist.at(ny).at(nx)) continue;
            if(dist.at(ny).at(nx) != INF) continue;

            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            d.push_back(make_pair(ny, nx));
        }
        if(a.at(y).at(x) <= 'z' && a.at(y).at(x) >= 'a'){
            if(warped.at(a.at(y).at(x)) != -1) continue;
            for(auto next: warp.at(a.at(y).at(x))){
                int ny = next.first;
                int nx = next.second;

                //if(dist.at(y).at(x) + 1 >= dist.at(ny).at(nx)) continue;
                if(dist.at(ny).at(nx) != INF) continue;

                dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                d.push_back(make_pair(ny, nx));
                warped.at(a.at(y).at(x)) = 1;
            }
        }
    }
    // for(auto vec: dist){
    //     for(auto num: vec)cout << num << "     ";
    //     cout << endl;
    // }
    if(dist.at(goal.first).at(goal.second) == INF) cout << -1 << endl;
    else cout << dist.at(goal.first).at(goal.second) << endl;
}