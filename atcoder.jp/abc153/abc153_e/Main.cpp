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
    int h, n; cin >> h >> n;
    vector <int> a(n), b(n);
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
    }

    /*
        dp[i] -> iの威力の攻撃をする最低魔力
    */

   vector <int> dp(h + 5, INF);
   dp.at(0) = 0;

   for(int i = 0; i < n; i ++){
       int atk_point = a.at(i);
       int used_mp = 0;
       for(int j = 1; j <= h; j ++){
           if((j-1) % atk_point == 0) used_mp += b.at(i);
           dp.at(j) = min(dp.at(j), used_mp);
           dp.at(j) = min(dp.at(j), dp.at(max(0, j - atk_point)) + b.at(i));
       }
   }

   cout << dp.at(h) << endl;
}