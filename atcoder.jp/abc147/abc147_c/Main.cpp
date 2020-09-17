#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    int max_pat = pow(2, n);

    vector <vector<pair<int, int>>> shogen(n);
    
    rep(i, n){
        int a; cin >> a;
        rep(j, a){
            int x, y; cin >> x >> y;
            shogen.at(i).push_back(make_pair(x, y));
        }
    }

    int ans = 0;
    for(int one_pat = 0; one_pat < max_pat; one_pat ++){
        vector <int> chara(n);
        int _ans = 0;
        rep(i, n){
            chara.at(i) = ((one_pat >> i) & 1);
            _ans += chara.at(i);
        }

        bool ok = true;
        rep(i, n){
            if(chara.at(i) == 0) continue;
            for(auto ps: shogen.at(i)){
                int x = ps.first - 1;
                int y = ps.second;

                if(chara.at(x) != y){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) ans = max(ans, _ans);
    }

    cout << ans << endl;
}