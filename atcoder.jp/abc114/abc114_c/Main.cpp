#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

ll str_to_int(string s){
    int f3, f7, f5;
    f3 = f7 = f5 = 0;
    int f0_1 = 0;
    int f0_2 = 0;
    reverse(s.begin(), s.end());
    ll d = 1;
    ll ans = 0;
    for(auto c: s){
        ans += (c - '0') * d;
        d *= 10;
        if(c - '0' == 3)f3 = 1;
        if(c - '0' == 7)f7 = 1;
        if(c - '0' == 5)f5 = 1;
    }
    if(f3 * f7 * f5 != 1) return INFLL;
    for(auto c: to_string(ans)) if(c == '0') return INFLL;
    return ans;
}

vector <string> products = {"0", "3", "5", "7"};
void solve(ll n, string now, int &ans){
    if(now.size() == to_string(n).size()){
        ll num = str_to_int(now);
        if(n >= num){
            //cout << num << endl;
            ans ++;
        }
    }
    else {
        for(auto c: products){
            solve(n, now + c, ans);
        }
    }
}

int main(){
    ll n; cin >> n;
    int ans = 0;
    solve(n, "", ans);
    cout << ans << endl;
}