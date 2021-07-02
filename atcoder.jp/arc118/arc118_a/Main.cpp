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
	int t; cin >> t;
	ll n; cin >> n;
	int now = 0;
	vector <int> now2next(105, -1);
	vector <ll> dist;
	ll ans = 0;
	ll b = 0;
	ll pre_b = 0;
	ll all = 0;
	ll cnt = 0;
	while(n > 0){
		int tmp = (100 - now + t - 1) / t;
		int next = (t * tmp + now) - 100;
		if(now2next.at(now) != -1){
			break;
		}
		now2next.at(now) = next;
		now = next;
		b = tmp;
		n --;
		all += b;
		dist.push_back(b);
		pre_b = b;
		cnt ++;
		//cout << b << endl;
	}

	//cout << n << endl;
	ans = all;
	ans += all * (n / cnt);
	//cout << ans << endl;
	n %= cnt;
	for(auto d: dist){
		if(n == 0) break;
		n--;
		//cout << "jfalk" << d << endl;
		ans += d;
	}

	//cout << ans << endl;

	cout << ((100 + t) * ans / 100) - 1 << endl; 


}