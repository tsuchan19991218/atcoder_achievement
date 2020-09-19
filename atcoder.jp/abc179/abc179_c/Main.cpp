#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < r; i ++)

ll divisor(long long a) {
    ll ans = 1;
    for (ll i = 2; i * i <= a; i++) {
    int cnt = 0;
    while (a % i == 0) {
      cnt++;
      a /= i;
    }
    ans *= (cnt + 1);
    if (a == 1) break;
  }
  if (a != 1) ans *= 2;

  return ans;
}

int main(){
    ll n; cin >> n;
    
    ll ans = 0;
    for(ll i = 1; i < n + 1; i ++){
        ll ue = n - i;
        ll div = divisor(ue);
        ans += div;
    }

    cout << ans - 2 << endl;

}