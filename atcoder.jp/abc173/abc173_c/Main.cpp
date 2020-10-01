#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector <string> c(h);
    rep(i, h) cin >> c.at(i);

    int h_bit = pow(2, h);
    int w_bit = pow(2, w);

    int ans = 0;
    rep(h_pat, h_bit)rep(w_pat, w_bit){
        int cnt = 0;
        rep(y, h)rep(x, w){
            if((h_pat >> y) & 1){
                if((w_pat >> x) & 1){
                    if(c.at(y).at(x) == '#') cnt ++;
                }
            }
        }
        if(cnt == k) ans ++;
    }
    cout << ans << endl;
}