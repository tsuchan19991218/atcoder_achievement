#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < r; i ++)

int main(){
    int n, k; cin >> n >> k;

    ll cnt1 = 0;
    ll cnt2 = 0;
    if(k % 2 == 0){
        cnt1 = n / k;
        cnt2 = n / (k / 2) - cnt1;
    }
    else cnt1 = n / k;

    ll ans = cnt1 * cnt1 * cnt1;
    ans += cnt2 * cnt2 * cnt2;
    cout << ans << endl;
}