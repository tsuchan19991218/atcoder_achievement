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
		a.at(i) = _a % 200;
	}
	vector <vector<vector<ll>>> dp(n, vector <vector <ll>>(2, vector<ll>(200)));
	dp.at(0).at(1).at(a.at(0)) = 1;
	dp.at(0).at(0).at(0) = 1;
	rep(i, n){
		if(i == 0) continue;
		rep(j, 200){
			dp.at(i).at(0).at(j) += dp.at(i-1).at(0).at(j) + dp.at(i-1).at(1).at(j);

			dp.at(i).at(1).at((j+a.at(i)) % 200) += dp.at(i-1).at(0).at(j) + dp.at(i-1).at(1).at(j);
		}
	}

	vector <int> b;
	vector <int> c;
	int candidate = 0;

	// rep(i, 200){
	// 	cout << i << " " << dp.at(n-1).at(0).at(i) << " " << dp.at(n-1).at(1).at(i) << endl;
	// }
	int N = min(8, n-1);
	rep(i, 200){
		// cout << i << " " << dp.at(n-1).at(0).at(i) << " " << dp.at(n-1).at(1).at(i) << endl;
		if(dp.at(N).at(0).at(i) + dp.at(N).at(1).at(i) >= 2){
			candidate = i;
		}
		else continue;
		int now = N;
		bool ok = false;
		int now2 = 0;
		int candidate2 = 0;
		while(now >= 0){
			if((dp.at(now).at(0).at(candidate) == 0 || dp.at(now).at(1).at(candidate) == 0) && !ok){ // 枝分かれしてない時
				if(dp.at(now).at(1).at(candidate)){ // now番目を取る場合
					b.push_back(now);
					c.push_back(now);
					candidate = candidate - a.at(now) + 200;
					candidate %= 200;
				}
				now --;
			}
			else{ // 枝分かれ開始点保護
				if(!ok){
					now2 = now - 1;
					candidate2 = candidate;
					b.push_back(now); // bは枝分かれを取る場合
					ok = true;
					candidate = candidate - a.at(now) + 200;
					candidate %= 200;
					now --;
					continue;
				}
			}

			if(ok){
				if(dp.at(now).at(1).at(candidate)){
					b.push_back(now);
					candidate = candidate - a.at(now) + 200;
					candidate %= 200;
				}

				now --;
			}
		}

		//cout << "通過" << endl;
		while(now2 >= 0){
			if(dp.at(now2).at(1).at(candidate2)){
				c.push_back(now2);
				candidate2 = candidate2 - a.at(now2) + 200;
				candidate2 %= 200;
			}
			now2 --;
		}

		if(b.size() == 0 || c.size() == 0){
			b.clear();
			c.clear();
			continue;
		}
		bool tmp = true;
		if(b.size() == c.size()){
			rep(k, b.size()){
				if(b.at(k) == c.at(k)) tmp = false;
			}
		}
		if(!tmp){
			b.clear();
			c.clear();
			continue;
		}
		
		break;
	}

	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	if(b.size() == 0 || c.size() == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << b.size() << " ";
	for(auto num: b) cout << num+1 << " ";
	cout << endl;
	cout << c.size() << " ";
	for(auto num: c) cout << num+1 << " ";
	cout << endl;

}