#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

ll INF = 1000000000;

int main(){
    int h, w; cin >> h >> w;
    deque <pair<int, int>> d;
    vector <vector<int>> dist(h, vector<int>(w, INF));

    vector <string> A(h);
    rep(i, h){
        cin >> A.at(i);
        for(int j = 0; j < w; j ++){
            if(A.at(i).at(j) == '#'){
                d.push_back(make_pair(i, j));
                dist.at(i).at(j) = 0;
            }
        }
    }

    int ans = 0;
    while(!d.empty()){
        auto v = d.front();
        d.pop_front();
        int y = v.first; int x = v.second;
        
        rep(i, 4){
            int ny = y + dy.at(i);
            int nx = x + dx.at(i);
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(A.at(ny).at(nx) == '#') continue;

            A.at(ny).at(nx) = '#';
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            ans = max(ans, dist.at(ny).at(nx));
            d.push_back(make_pair(ny, nx));
        }
    }

    cout << ans << endl;

}