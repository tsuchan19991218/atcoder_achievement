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
	cout << std::fixed << std::setprecision(15);
	double n; cin >> n;
	vector <double> a(n);
	vector <double> sum_a(n);
	rep(i, n){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	rep(i, n){
		if(i == 0){
			sum_a[i] = a[i];
		}
		else{
			sum_a[i] = sum_a[i-1] + a[i];
		}
	}

	double ans = INF;
	rep(i, n){
		double x = a.at(i) / 2.0;
		ans = min(ans, - sum_a.at(i) + (2 + 2*i - n) * x);
	}
	cout << (ans + sum_a.at(n-1)) / n << endl;;
}