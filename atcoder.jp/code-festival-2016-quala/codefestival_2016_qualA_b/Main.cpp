#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int MOD =  INF;
long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n){
		int _a; cin >> _a;
		_a--;
		a.at(i) = _a;
	}
	vector <int> seen(n, -1);
	int ans = 0;
	for(int i = 0; i < n; i ++){
		if(seen.at(i) != -1) continue;
		seen.at(i) = 1;
		if(a.at(a.at(i)) == i){
			ans ++;
			seen.at(a.at(i)) = 1;
		}
	}

	cout << ans << endl;
}