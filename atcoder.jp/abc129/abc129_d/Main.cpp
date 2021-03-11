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
    vector <string> s(h);
    rep(i,h) cin >> s.at(i);
    vector <vector<int>> yoko(h, vector <int>(w)), tate(h, vector <int>(w));
    for(int y = 0; y < h; y ++){
        int cnt = 0;
        int start = INF;
        for(int x = 0; x < w; x ++){
            if(s.at(y).at(x) == '#'){
                for(int _x = start; _x < x; _x ++){
                    yoko.at(y).at(_x) = cnt;
                    //cout << y << " " << _x << " " << cnt << endl;
                }
                cnt = 0;
                start = INF;
                continue;
            }
            if(s.at(y).at(x) == '.' && cnt == 0){
                cnt = 1;
                start = x;
                continue;
            }
            if(s.at(y).at(x) == '.') cnt ++;
            //cout << start << endl;
        }
        if(cnt > 0){
            for(int _x = start; _x < w; _x ++){
                yoko.at(y).at(_x) = cnt;
            }
        }
    }
    for(int y = 0; y < w; y ++){
        int cnt = 0;
        int start = INF;
        for(int x = 0; x < h; x ++){
            if(s.at(x).at(y) == '#'){
                for(int _x = start; _x < x; _x ++){
                    tate.at(_x).at(y) = cnt;
                }
                cnt = 0;
                start = INF;
                continue;
            }
            if(s.at(x).at(y) == '.' && cnt == 0){
                cnt = 1;
                start = x;
                continue;
            }
            if(s.at(x).at(y) == '.') cnt ++;
        }
        if(cnt > 0){
            for(int _x = start; _x < h; _x ++){
                tate.at(_x).at(y) = cnt;
            }
        }
    }
    int ans = 0;
    // cout << "たて" << endl;
    // rep(i, h){
    //     rep(j, w){
    //         cout << tate.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "横" << endl;
    // rep(i, h){
    //     rep(j, w){
    //         cout << yoko.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    rep(i, h)rep(j, w) ans = max(ans, tate.at(i).at(j) + yoko.at(i).at(j) - 1);
    cout << ans << endl;
}