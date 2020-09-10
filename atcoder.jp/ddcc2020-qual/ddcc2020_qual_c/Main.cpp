#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector <string> s(h);
    rep(i, h) cin >> s.at(i);

    vector <vector<int>> ans(h, vector<int>(w, -1));

    int cnt = 0;
    rep(i, h){
        bool find = false;
        rep(j, w){
            //初めて見つけたとき
            if (!find && s.at(i).at(j) == '#'){
                find = true;
                cnt += 1;
                rep(k, j + 1) ans.at(i).at(k) = cnt;
                continue;
            }
            //２回目以降
            if (s.at(i).at(j) == '#'){
                cnt += 1;
                ans.at(i).at(j) = cnt;
                continue;
            }
            if (j != 0) ans.at(i).at(j) = ans.at(i).at(j - 1);
        }
        if (!find && cnt > 0){
            rep(j, w){
                ans.at(i).at(j) = ans.at(i - 1).at(j);
            }
        }
    }

    for (int i = h - 1; i >=0; i --){
        if (ans.at(i).at(0) != -1) continue;
        rep(j, w){
                ans.at(i).at(j) = ans.at(i + 1).at(j);
            }
    }


    //出力
    rep(i, h){
        rep(j, w){
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
