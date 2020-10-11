#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    vector <int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    int ans = a.at(0);
    rep(i, n){
        ans = gcd(ans, a.at(i));
    }
    cout << ans << endl;
}