#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int INF = 1000000000;

int f(vector <int> &memo, vector <vector<int>> &c, vector <int> &seen, int n);

int main(){
    int h, w; cin >> h >> w;
    vector <vector<int>> c(10);
    
    rep(i, 10){
        rep(j, 10){
            int _c; cin >> _c;
            c.at(i).push_back(_c);
        }
    }

    vector <vector<int>> A(h);

    rep(i, h){
        rep(j, w){
            int a; cin >> a;
            A.at(i).push_back(a);
        }
    }

    rep(k, 10){ //k = 間に挟むやつ　（ワーシャルフロイド法）
        rep(i, 10){
            rep(j, 10){
                c.at(i).at(j) = min(c.at(i).at(j), c.at(i).at(k) + c.at(k).at(j));
            }
        }
    }

    ll ans = 0;
    for(auto l_a: A){
        for(auto num: l_a){
            if(num != -1) ans += c.at(num).at(1);
        }
    }

    cout << ans << endl;
}