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
	int n; cin >> n;
	vector <int> cnt(n);
	vector <int> a(n);
	rep(i, n){
		int a; cin >> a;
		cnt.at(a-1) = 1;
	}
	bool flag = true;
	rep(i, n){
		if(cnt.at(i) == 0) flag = false;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}