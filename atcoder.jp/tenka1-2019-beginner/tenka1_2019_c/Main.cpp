#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    string S; cin >> S;
    vector <int> white_cnt(n);

    int max_white = 0;

    for (auto c: S){
        if (c == '.') max_white += 1;
    }

    rep(i, n){
        white_cnt.at(i) = max_white;
        if(S.at(i) == '.') max_white -= 1;
    }
    white_cnt.push_back(0);

    int black_cnt = 0;
    int ans = 10000000;

    rep(i, n + 1){
        int _ans;
        _ans = black_cnt + white_cnt.at(i);
        ans = min(ans, _ans);

        if(i == n) break;
        if (S.at(i) == '#') black_cnt += 1;
    }

    cout << ans << endl;

}