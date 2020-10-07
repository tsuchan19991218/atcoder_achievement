#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector <ll> p(a), q(b);
    priority_queue <ll> r;
    rep(i, a){
        cin >> p.at(i);
    }
    rep(i, b){
        cin >> q.at(i);
    }
    rep(i, c){
        ll _r; cin >> _r;
        r.push(_r);
    }
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    priority_queue <ll, vector<ll>, greater<ll>> p_q;
    rep(i, x) p_q.push(p.at(i));
    rep(i, y) p_q.push(q.at(i));

    while(p_q.top() < r.top() && !r.empty()){
        p_q.pop();
        p_q.push(r.top());
        r.pop();
    }
    ll ans = 0;
    while(!p_q.empty()){
        ans += p_q.top();
        p_q.pop();
    }
    cout << ans << endl;
}