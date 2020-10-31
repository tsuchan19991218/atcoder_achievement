#include <bits/stdc++.h>
#include <atcoder/all>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

ll M = 998244353;
vector <ll> fac(5000005);

int main(){

    //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
    fac[0] = 1;
    for(ll i = 0; i<5000000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
    }

    int n, K; cin >> n >> K;
    vector <vector<int>> a(n, vector<int>(n));
    rep(i, n)rep(j, n) cin >> a.at(i).at(j);


    dsu yoko(n);
    dsu tate(n);

    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            bool flag = true;
            for(int k = 0; k < n; k ++){
                if(a.at(k).at(i) + a.at(k).at(j) <= K) continue;
                flag = false;
            }
            if(flag) yoko.merge(i, j);
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            bool flag = true;
            for(int k = 0; k < n; k ++){
                if(a.at(i).at(k) + a.at(j).at(k) <= K) continue;
                flag = false;
            }
            if(flag) tate.merge(i, j);
        }
    }
    ll tate_sum = 1;
    ll yoko_sum = 1;
    auto t = tate.groups();
    auto y = yoko.groups();

    for(auto vec: t){
        ll size = vec.size();
        tate_sum *= fac.at(size);
        tate_sum %= M; 
    }
    for(auto vec: y){
        ll size = vec.size();
        yoko_sum *= fac.at(size);
        yoko_sum %= M; 
    }

    cout << (tate_sum * yoko_sum) % M << endl;
}