#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < r; i ++)

int main(){
    int k;
    ll n; cin >> n >> k;
    vector <ll> p_x(1), m_x;
    rep(i, n){
        ll x; cin >> x;
        if (x < 0){
            m_x.push_back(x * -1);
        }
        else{
            p_x.push_back(x);
        }
    }
    m_x.push_back(0);
    reverse(m_x.begin(), m_x.end());
    
    ll ans = 100000000000000000;
    int left_max, right_max;
    left_max = min(k, int(m_x.size()) - 1);
    right_max = min(k, int(p_x.size()) - 1);
    rep(i, k){
        int l, r;
        l = left_max - i;
        if (l < 0) break;
        r = k - l;
        if (r >right_max) break;
        ans = min(ans, 2 * m_x.at(l) + p_x.at(r));
        ans = min(ans, m_x.at(l) + 2 * p_x.at(r));
    }

    cout << ans << endl;

}