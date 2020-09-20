#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
vector <ll> divisor(ll n);

int main(){
    ll n; cin >> n;

    auto div_list = divisor(2 * n);
    vector <ll> n_div_list;

    for(auto &div: div_list){
        n_div_list.push_back(2 * n / div);
    }

    ll ans = n; vector <ll> r = {-1, 0};
    for(int i = 0; i < div_list.size(); i ++){
        vector <ll> m(0);
        m.push_back(n_div_list.at(i));
        m.push_back(div_list.at(i));
        pair <ll, ll> ans1 = crt(r, m);
        if(ans1.first == 0) ans1.first = ans1.second;
        if(ans1.first == 0) continue;
        if(ans1.first % div_list.at(i) != 0) continue;
        if(ans1.first + 1 < int(2 * n / ans1.first)) continue;
        ans = min(ans, ans1.first);
    }
    cout << ans << endl;
}

vector <ll> divisor(ll n){
    vector <ll> arr;
    for(ll i = 1; i * i <= n; i ++){
        if(n % i == 0){
            arr.push_back(i);
            if(i * i == n) continue;
            arr.push_back(n / i);
        }
    }
    return arr;
}