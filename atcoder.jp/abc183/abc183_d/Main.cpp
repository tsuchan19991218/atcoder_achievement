#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000; 

int main(){
    ll n, w; cin >> n >> w;
    vector <pair<ll, ll>> s(n), t(n);
    ll MAX_T = 0;
    rep(i, n){
        ll _s, _t, _p; cin >> _s >> _t >> _p;
        s.at(i) = make_pair(_s, _p);
        t.at(i) = make_pair(_t, _p);

        MAX_T = max(MAX_T, t.at(i).first);
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    ll need = 0; int s_index = 0; int t_index = 0;
    for(int now = 0; now <= MAX_T; now ++){
        while(s_index < s.size() && s.at(s_index).first <= now){
            need += s.at(s_index).second;
            s_index ++;
        }
        while(t_index < t.size() && t.at(t_index).first <= now){
            need -= t.at(t_index).second;
            t_index ++;
        }
        if(need > w){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}