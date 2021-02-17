#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

pair <int, int> check(int n){
    string tmp = to_string(n);
    int l, r;
    l = tmp.at(0) - '0';
    r = tmp.at(tmp.size() - 1) - '0';

    return make_pair(l, r);
}

int main(){

    int n; cin >> n;
    int n_keta = to_string(n).size();
    int n_l, n_r;
    n_l = check(n).first;
    n_r = check(n).second;

    int bet_num = 0;
    string sn = to_string(n);
    int _ = 1;
    for(int i = sn.size() - 2; i > 0; i--){
        bet_num += _ * (sn.at(i) - '0');
        _ *= 10;
    }

    int ans = 0;
    for(int a = 1; a <= n; a ++){
        if(a % 10 == 0) continue;

        auto p = check(a);
        int r = p.first;
        int l = p.second;

        //bが一桁の場合（１通り）
        if(r == l) ans ++;
        //bが二桁の場合（１通り）
        if(10 * l + r <= n) ans ++;

        if(n_keta <= 2) continue;

        int b_keta = 3;

        int d = 10;
        while(b_keta < n_keta){
            ans += d;
            d *= 10;
            b_keta ++;
        }

        if(l > n_l){
            ans += 0;
        }
        else if(l < n_l){
            ans += d;
        }
        else{
            if(r > n_r){
                ans += bet_num;
            }
            else{
                ans += bet_num + 1;
            }
        }

        // cout << l << " " << r << endl;
        // cout << a << " " << ans << endl;
    }


    cout << ans << endl;
}