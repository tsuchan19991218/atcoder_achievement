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

const int MOD =  1e9 + 7;
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
	int n; cin >> n;
	vector <ll> a(n);
	rep(i, n) cin >> a.at(i);
	vector <ll> dp_plus(n), dp_minus(n), cnt_plus(n), cnt_minus(n);
	dp_plus.at(0) = a.at(0);
	cnt_plus.at(0) = 1;
	for(int i = 1; i < n; i ++){
		cnt_plus.at(i) = cnt_plus.at(i-1) + cnt_minus.at(i-1);
		cnt_minus.at(i) = cnt_plus.at(i-1);
		cnt_plus.at(i) %= MOD;
		cnt_minus.at(i) %= MOD;
		ll cnt = (cnt_plus.at(i) + cnt_minus.at(i)) % MOD;
		dp_plus.at(i) = dp_plus.at(i-1) + dp_minus.at(i-1) + a.at(i) * cnt_plus.at(i);
		dp_plus.at(i) %= MOD;
		dp_minus.at(i) = dp_plus.at(i-1) + ((-a.at(i) + MOD) % MOD) * cnt_minus.at(i);
		dp_minus.at(i) %= MOD;
	}
	cout << (dp_plus.at(n-1) + dp_minus.at(n-1)) % MOD << endl;
}