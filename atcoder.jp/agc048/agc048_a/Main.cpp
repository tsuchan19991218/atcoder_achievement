#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int INF = 500000;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        //string _s = s;
        int ans = INF;
        string _s = s;
        for(int i = 0; i < s.size(); i ++){
            for(int j = 0; j < s.size(); j ++){
                _s.at(i) = s.at(j);
                _s.at(j) = s.at(i);
                if(_s > "atcoder") ans = min(ans, abs(i - j));
                _s.at(i) = s.at(i);
                _s.at(j) = s.at(j);
            }
        }
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }

}