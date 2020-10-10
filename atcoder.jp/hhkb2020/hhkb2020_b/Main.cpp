#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int h, w; cin >> h >> w;
    vector <string> s(h);
    rep(i, h) cin >> s.at(i);

    int ans = 0;
    int seq_yoko = 0;
    rep(i, h){
        for(auto c: s.at(i)){
            if(c == '.'){
                seq_yoko ++;
                continue;
            }
            ans += max(seq_yoko - 1, 0);
            seq_yoko = 0;
        }
        ans += max(seq_yoko - 1, 0);
        seq_yoko = 0;
    }

    int seq_tate = 0;
    rep(i, w){
        for(int y = 0; y < h; y ++){
            if(s.at(y).at(i) == '.'){
                seq_tate ++;
                continue;
            }
            ans += max(seq_tate - 1, 0);
            seq_tate = 0;
        }
        ans += max(seq_tate - 1, 0);
        seq_tate = 0;
    }
    cout << ans << endl;
}