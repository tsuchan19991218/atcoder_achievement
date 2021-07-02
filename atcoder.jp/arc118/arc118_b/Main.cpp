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
	int k; cin >> k;
	double n, m; cin >> n >> m;
	vector <double> a(k);
	vector <ll> ans(k);
	vector <pair<double, int>> partOfSyosu(k);
	ll rest = 0;
	rep(i, k){
		cin >> a.at(i);
		ans.at(i) = a.at(i) * (m / n);
		rest += ans.at(i);
		partOfSyosu.at(i) = make_pair(a.at(i) * (m / n) - ans.at(i), i);
	}
	rest = m - rest;
	sort(partOfSyosu.rbegin(), partOfSyosu.rend());

	while(rest > 0){
		for(auto syosu_index: partOfSyosu){
			ans.at(syosu_index.second) ++;
			rest --;
			if(rest == 0) break;
		}
	}

	for(auto ans: ans) cout << ans << " ";
	cout << endl;
	
}