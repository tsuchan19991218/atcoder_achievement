#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
	int n; cin >> n;
	vector <ll> a(n);
	rep(i, n){
		ll _a; cin >> _a;
		_a %= 200;
		a.at(i) = _a;
	}
	vector <vector<ll>> cnt(n, vector<ll>(200));
	for(int i = n-2; i >= 0; i --){
		rep(j, 200){
			cnt.at(i).at(j) = cnt.at(i+1).at(j) + (a.at(i+1) == j);
		}
	}
	ll ans = 0;
	rep(i, n){
		ans += cnt.at(i).at(a.at(i));
	}

	cout << ans << endl;

}