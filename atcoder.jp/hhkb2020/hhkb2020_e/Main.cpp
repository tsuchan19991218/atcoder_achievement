#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int M = 1000000007;

int main(){
    int h, w; cin >> h >> w;
    vector <string> s(h);
    rep(i, h) cin >> s.at(i);
    vector <vector<pair<ll, ll>>> cnt(h, vector<pair<ll, ll>>(w));
    int k = 0;

    rep(y, h){
        rep(x, w){
            if(s.at(y).at(x) == '#') continue;
            k ++;
            int cnt_y = 0;
            int cnt_x = 0;
            if(cnt.at(y).at(x).first == 0){ //y座標に対しみていく
                cnt_y = 1;
                for(int next_y = y + 1; next_y < h; next_y ++){
                    if(s.at(next_y).at(x) == '#') break;
                    cnt_y ++;
                }
                for(int next_y = y; next_y < h; next_y ++){
                    if(s.at(next_y).at(x) == '#') break;
                    cnt.at(next_y).at(x).first = cnt_y;
                }
                //cnt.at(y).at(x).first = cnt_y;
            }

            if(cnt.at(y).at(x).second == 0){
                cnt_x = 1;
                for(int next_x = x + 1; next_x < w; next_x ++){
                    if(s.at(y).at(next_x) == '#') break;
                    cnt_x ++;
                }
                for(int next_x = x; next_x < w; next_x ++){
                    if(s.at(y).at(next_x) == '#') break;
                    cnt.at(y).at(next_x).second = cnt_x;
                }
                //cnt.at(y).at(x).second = cnt_x;
            }
            //cout << y << " " << x << " " << cnt_y << " " << cnt_x << endl;
        }
    }

    ll ans = 0;
    rep(y, h)rep(x, w){
        //cout << cnt.at(y).at(x).first << " " << cnt.at(y).at(x).second << endl;
        int sum = cnt.at(y).at(x).first + cnt.at(y).at(x).second - 1;
        if(sum < 0) continue;
        ans += ((pow_mod(2, sum, M) - 1) * pow_mod(2, k - sum, M)) % M;
    }
    cout << ans % M << endl;
}