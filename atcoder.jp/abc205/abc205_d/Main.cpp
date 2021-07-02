#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;
const double PI = 3.14159265358979323846;

const ll MOD = INFLL;
long long my_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
	cout << std::fixed << std::setprecision(15);
	int n, q; cin >> n >> q;
	vector <ll> a(n);
	rep(i, n) cin >> a.at(i);
	while(q--){
		ll k; cin >> k;
		ll ans = k;
		auto now_itr = a.begin();
		while(1){
			auto next_itr = upper_bound(a.begin(), a.end(), ans);
			ll cnt = next_itr - now_itr;
			if(cnt == 0) break;
			ans += cnt;
			now_itr = next_itr;
		}
		cout << ans << endl;
	}
}