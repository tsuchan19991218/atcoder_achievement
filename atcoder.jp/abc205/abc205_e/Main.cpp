#include <bits/stdc++.h>
#include <math.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;
const double PI = 3.14159265358979323846;

const int MAX = 3000000 + 5;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	cout << std::fixed << std::setprecision(15);
	ll n, m, k; cin >> n >> m >> k;
	COMinit();
	if(n - m > k){
		cout << 0 << endl;
		return 0;
	}
	cout << (comb(n+m, n) - comb(n+m, n-(k+1)) + MOD) % MOD << endl;
}