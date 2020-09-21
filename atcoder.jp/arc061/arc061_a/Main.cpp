#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    string s; cin >> s;

    int sz = s.size();

    ll all_pat = pow(2, sz - 1);

    ll ans = 0;
    reverse(s.begin(), s.end());
    rep(pat, all_pat){
        ll d = 1;
        
        for(int i = 0; i < sz - 1; i ++){
            ans += (s.at(i) - '0') * d;
            if((pat >> i) & 1) d = 1;
            else d *= 10;
        }

        ans += (s.at(sz - 1) - '0') * d;
    }

    cout << ans << endl;
}