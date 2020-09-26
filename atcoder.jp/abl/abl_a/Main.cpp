#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 1000000000;

int main(){
    int k; cin >> k;
    string ans = "ACL";
    k --;
    rep(i, k) ans += "ACL";
    cout << ans << endl;
}