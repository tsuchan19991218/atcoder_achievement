#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
    int n, k; cin >> n >> k;
    vector <ll> A(n);
    rep(i, n){
        cin >> A.at(i);
    }

    sort(A.rbegin(), A.rend());
    if (A.at(0) < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll g = A.at(0);
    rep(i, n){
        g = gcd(g, A.at(i));
    }

    if (k % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

}