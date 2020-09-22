#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n, m; cin >> n >> m;
    vector <vector<int>> G(n + 1);
    rep(i, m){
        int x, y; cin >> x >> y;
        G.at(x).push_back(y);
        G.at(y).push_back(x);
    }

    int ans = 0;
    rep(pat, pow(2, n)){
        vector <int> check;
        rep(i, n){
            if((pat >> i) & 1){
                check.push_back(i + 1);
            }
        }
        int cnt = 0;
        cnt = check.size();
        bool ok = true;
        for(int check_i = 0; check_i < cnt - 1; check_i ++){
            for(int checked_i = check_i + 1; checked_i < cnt; checked_i ++){
                int per1 = check.at(check_i);
                int per2 = check.at(checked_i);
                if(find(G.at(per1).begin(), G.at(per1).end(), per2) != G.at(per1).end()) continue;
                ok = false;
                break;
            }
            if(!ok){
                cnt = 0;
                break;
            }
        }

        ans = max(ans, cnt);
    }
    cout << ans << endl;
}