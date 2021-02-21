#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    string s; cin >> s;

    vector <pair<ll, ll>> v;
    vector <vector <ll>> acc(s.size(), vector<ll>(200));
    reverse(s.begin(), s.end());
    acc.at(0).at(s.at(0)) = 1;
    for(int i = 1; i < s.size(); i ++){
        acc.at(i).at(s.at(i)) = 1;
        for(int j = 'a'; j <= 'z'; j ++){
            acc.at(i).at(j) += acc.at(i-1).at(j);
        }
    }
    bool seq = false;
    char now = s.at(0);
    int fir, sec;
    for(int i = 1; i < s.size(); i ++){
        if(!seq){
            if(now == s.at(i)){
                fir = i - 1;
                seq = true;
                continue;
            }
            now = s.at(i);
        }
        if(seq){
            if(now != s.at(i)){
                //sec = i - 1;
                sec = now;
                seq = false;
                now = s.at(i);

                if(fir == 0) continue;
                v.push_back(make_pair(fir, sec));
                continue;
            }
        }
    }

    if(seq){
        if(fir != 0) v.push_back(make_pair(fir, now));
    }

    //cout << v.size() << endl;

    // for(auto p: v){
    //     cout << p.first << " " << p.second << endl;
    // }

    if(v.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    vector <int> used(500);
    ll ans = 0;
    ll cnt_bet = acc.at(v.at(0).first - 1).at(v.at(0).second);
    ans += v.at(0).first - cnt_bet;
    //cout << ans << endl;
    used.at(v.at(0).second) += v.at(0).first;
    for(ll i = 1; i < (ll)(v.size()); i ++){
        // if(i == 0) cnt += v.at(i).first;

        // if(v.at(i).second + 1 == v.at(i + 1).first){
        //     cnt += v.at(i).second - v.at(i).first + 1;
        // }
        // else{
        //     ans += cnt;
        //     cnt = 0;
        // }

        cnt_bet = acc.at(v.at(i).first - 1).at(v.at(i).second) - acc.at(v.at(i - 1).first - 1).at(v.at(i).second);
        //cout << cnt_bet << " " << used.at(v.at(i).second) << endl;
        ans += v.at(i).first - used.at(v.at(i).second) - cnt_bet;
        //cout << ans << endl;
        used.at(v.at(i-1).second) = 0;
        used.at(v.at(i).second) = v.at(i).first;
    }

    cout << ans << endl;
}