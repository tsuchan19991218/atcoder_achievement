#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int d, g; cin >> d >> g;
    vector <pair<int, int>> p_c(d);
    vector <int> turn(d);
    rep(i, d){
        int p, c; cin >> p >> c;
        p_c.at(i) = make_pair(p, c);
        turn.at(i) = i;
    }

    ll ans = 1000000000;
    do{
        ll cnt = 0;
        int _g = g;
        rep(i, d){
            int now = turn.at(i);
            int now_one_point = (now + 1) * 100;
            ll now_all_point = p_c.at(now).first * now_one_point;
            if(now_all_point > _g){
                cnt += (_g + now_one_point - 1) / now_one_point;
                _g = 0;
            }
            else{
                cnt += p_c.at(now).first;
                _g -= now_all_point + p_c.at(now).second;
            }
            if(_g <= 0) break;
        }
        ans = min(ans, cnt);
    }while(next_permutation(turn.begin(), turn.end()));

    cout << ans << endl;

}