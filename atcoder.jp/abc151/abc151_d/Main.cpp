#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int h, w; cin >> h >> w;
    vector <string> S(h);
    rep(i, h) cin >> S.at(i);

    vector <int> dx = {0, -1, 0, 1};
    vector <int> dy = {1, 0, -1, 0};
    deque <pair<int, int>> next_masu;

    int ans = 1;
    rep(i, h){
        rep(j, w){
            if (S.at(i).at(j) == '#') continue;
            vector <vector <int>> cnt(h, vector <int> (w, 1000000000));
            cnt.at(i).at(j) = 0;
            rep(k, 4){
                int n_i, n_j;
                n_i = i + dy[k];
                n_j = j + dx[k];
                if (n_i < 0 || n_i > h - 1 || n_j < 0 || n_j > w - 1) continue;
                if (S.at(n_i).at(n_j) == '#') continue;
                next_masu.push_back(make_pair(n_i, n_j));
                cnt.at(n_i).at(n_j) = 1;
            }

            while(!next_masu.empty()){
                auto now_masu = next_masu.front();
                next_masu.pop_front();
                rep(k, 4){
                int n_i, n_j;
                n_i = now_masu.first + dy[k];
                n_j = now_masu.second + dx[k];
                if (n_i < 0 || n_i > h - 1 || n_j < 0 || n_j > w - 1) continue;
                if (S.at(n_i).at(n_j) == '#') continue;
                if (cnt.at(n_i).at(n_j) <= cnt.at(now_masu.first).at(now_masu.second) + 1) continue;
                next_masu.push_back(make_pair(n_i, n_j));
                cnt.at(n_i).at(n_j) = cnt.at(now_masu.first).at(now_masu.second) + 1;

                ans = max(ans, cnt.at(n_i).at(n_j));
                }
            }
        }
    }
    cout << ans << endl;
    
}