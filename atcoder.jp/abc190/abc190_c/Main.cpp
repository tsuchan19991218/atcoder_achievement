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
    int n, m; cin >> n >> m;
    vector <int> a(m), b(m);
    rep(i, m){
        int _a, _b; cin >> _a >> _b;
        _a --;
        _b --;
        a.at(i) = _a;
        b.at(i) = _b;
    }

    int k; cin >> k;
    vector <int> c(k), d(k);
    rep(i, k){
        int _a, _b; cin >> _a >> _b;
        _a --;
        _b --;
        c.at(i) = _a;
        d.at(i) = _b;
    }

    int all_pat = pow(2, k);
    int ans = 0;
    rep(one_pat, all_pat){
        vector <int> is_ok(n, -1);
        rep(i, k){
            if(((one_pat >> i) & 1) == 1){
                is_ok.at(d.at(i)) = 1;
            }
            else{
                is_ok.at(c.at(i)) = 1;
            }
        }
        int tmp = 0;
        rep(i, m){
            if(is_ok.at(a.at(i)) == 1 && is_ok.at(b.at(i)) == 1) tmp ++;
        }
        //cout << tmp << endl;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}