#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n; cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);
    rep(i, n){
        cin >> a.at(i);
        if(i > 0){
            a.at(i) = max(a.at(i), a.at(i-1));
        }
    }
    rep(i, n) cin >> b.at(i);
    vector <ll> ans(n);
    ll B = 0;
    rep(i, n){
        if(i == 0){
            ans.at(i) = a.at(i) * b.at(i);
            B = b.at(i);
            continue;
        }

        if(b.at(i) >= B){
            ans.at(i) = a.at(i) * b.at(i);
            B = b.at(i);
            continue;
        }

        if(ans.at(i-1) <= a.at(i) * b.at(i)){
            ans.at(i) = a.at(i) * b.at(i);
            B = b.at(i);
            continue;
        }

        ans.at(i) = ans.at(i-1);
    }
    for(auto ans: ans){
        cout << ans << endl;
    }
}