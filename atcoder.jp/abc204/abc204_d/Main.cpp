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
	vector <int> t(n);
	int T = 0;
	rep(i, n){
		cin >> t.at(i);
		T += t.at(i);
	}
	vector <bool> dp(100000 + 5);
	dp.at(0) = true;
	rep(i, n){
		vector <int> candidate;
		rep(j, 100000 + 3){
			if(dp.at(j) == false) continue;
			candidate.push_back(j + t.at(i));
		}
		for(auto num: candidate){
			dp.at(num) = true;
		}
	}

	int ans = INF;
	for(int i = 0; i < 100000 + 3; i ++){
		if(!dp.at(i)) continue;
		ans = min(ans, max(i, T-i));
	}
	cout << ans << endl;
}