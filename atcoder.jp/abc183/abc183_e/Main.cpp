#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000; 

ll mod = 1000000007;

int main(){
    int h, w; cin >> h >> w;
    vector <string> s(h + 1);
    rep(i, h){
        string str; cin >> str;
        str = "$" + str; 
        s.at(i + 1) = str;
    }
    //vector <vector<vector<ll>>> dp(h + 1, vector<ll>(w + 1, vector<ll>(3)));
    vector <vector<ll>> dp(h + 1, vector<ll>(w + 1));
    dp.at(1).at(1) = 1;
    vector<ll> sum_hidari(h + 1), sum_ue(w + 1);
    vector <vector<ll>> sum_naname(h + 1, vector<ll>(w + 1));
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(s.at(i).at(j) == '#'){
                sum_ue.at(j) = 0;
                sum_hidari.at(i) = 0;
                int M = max(i, j);
            int m = min(i, j);
            M -= m;
            m = 1; M ++;
                if(i > j){
                sum_naname.at(M).at(m) = 0;
                //value = sum_naname.at(M).at(m);
            }
            else{
                sum_naname.at(m).at(M) = 0;
                //value = sum_naname.at(m).at(M);
            }
                continue;
            }
            if(i == 1 && j == 1) continue;
            int M = max(i, j);
            int m = min(i, j);
            M -= m;
            m = 1; M ++;
            sum_hidari.at(i) += dp.at(i).at(j - 1);
            sum_hidari.at(i) %= mod;
            sum_ue.at(j) += dp.at(i - 1).at(j);
            sum_ue.at(j) %= mod;
            ll value;
            if(i > j){
                sum_naname.at(M).at(m) += dp.at(i - 1).at(j - 1);
                value = sum_naname.at(M).at(m);
                sum_naname.at(M).at(m) %= mod;
            }
            else{
                sum_naname.at(m).at(M) += dp.at(i - 1).at(j - 1);
                value = sum_naname.at(m).at(M);
                sum_naname.at(m).at(M) %= mod;
            }
            //sum_naname.at(i).at(j) += dp.at(i - 1).at(j - 1);
            dp.at(i).at(j) += sum_hidari.at(i) + sum_ue.at(j) + value;
            dp.at(i).at(j) %= mod;

            //cout << i << " " << j << " " << " " << sum_hidari.at(i) << " " << sum_ue.at(j) << " " << dp.at(i).at(j) << endl;
        }
    }
    cout << dp.at(h).at(w) % mod << endl;
    // cout << sum_naname.at(1).at(2) << endl;
}