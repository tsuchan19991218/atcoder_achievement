#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int MOD =  INF;
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
	int h, w; cin >> h >> w;
	ll ans = 1;
	MOD = 998244353;
	vector <string> s(h);
	vector <vector<ll>> cnt(w + h - 1, vector<ll>(3));
	rep(i, h){
		cin >> s.at(i);
	}
	rep(y, h){
		rep(x, w){
			auto c = s.at(y).at(x);
			if(c == 'R'){
				cnt.at(y + x).at(0) ++;
			}
			if(c == 'B'){
				cnt.at(y + x).at(1) ++; 
			}
			if(c == '.'){
				cnt.at(y + x).at(2) ++; 
			}
		}
	}

	for(auto c: cnt){
		if(c.at(0) && c.at(1)) ans = 0;
		else if(c.at(0) == 0 && c.at(1) == 0) ans *= 2;

		ans %= MOD;
	}
	
	cout << ans << endl;
}