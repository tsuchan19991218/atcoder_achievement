#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector <int> cnt_a(n + 1), cnt_t(n + 1), cnt_c(n + 1), cnt_g(n + 1);

    rep(i, n){
        char c = s.at(i);
        if(c == 'A') cnt_a.at(i + 1) += 1;
        if(c == 'T') cnt_t.at(i + 1) += 1;
        if(c == 'C') cnt_c.at(i + 1) += 1;
        if(c == 'G') cnt_g.at(i + 1) += 1;

        cnt_a.at(i + 1) += cnt_a.at(i);
        cnt_t.at(i + 1) += cnt_t.at(i);
        cnt_c.at(i + 1) += cnt_c.at(i);
        cnt_g.at(i + 1) += cnt_g.at(i);
    }

    int ans = 0;

    for(int l = 0; l < n + 1; l ++){
        for(int r = l + 1; r < n + 1; r ++){
            int ca, ct, cc, cg;
            ca = cnt_a.at(r) - cnt_a.at(l);
            ct = cnt_t.at(r) - cnt_t.at(l);
            cc = cnt_c.at(r) - cnt_c.at(l);
            cg = cnt_g.at(r) - cnt_g.at(l);

            if(ca == ct && cc == cg) ans ++;
        }
    }
    cout << ans << endl;
}