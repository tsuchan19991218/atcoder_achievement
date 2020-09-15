#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    vector <pair<ll, ll>> Q(n);
    rep(i, n)cin >> Q.at(i).first >> Q.at(i).second;
    pair <ll, ll> now_t_a = make_pair(1, 1);

    for(auto q: Q){
        ll F = q.first;
        ll S = q.second;

        ll max_div = (now_t_a.first + (F - 1)) / F;
        max_div = max(max_div, (now_t_a.second + (S - 1)) / S);

        F *= max_div;
        S *= max_div;

        //cout << F << " " << S << endl;

        now_t_a = make_pair(F, S);
        
    }

    cout << now_t_a.first + now_t_a.second << endl;
}