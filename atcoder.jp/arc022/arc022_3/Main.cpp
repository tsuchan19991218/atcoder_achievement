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

int n;
int bfs(int start, vector <vector<int>>& G){
	int longest_node = -1;
	vector <int> seen(n, -1);
	deque <int> d;
	d.push_back(start);
	seen.at(start) = 1;
	while(d.size()){
		auto now = d.front();
		// cout << now << endl;
		d.pop_front();
		for(auto next: G.at(now)){
			if(seen.at(next) != -1) continue;
			seen.at(next) = 1;
			d.push_back(next);
			longest_node = next;
		}
	}

	return longest_node;
}

int main(){
	cin >> n;
	vector <vector<int>> G(n);
	rep(i, n-1){
		int u, v; cin >> u >> v;
		u--; v--;
		G.at(u).push_back(v);
		G.at(v).push_back(u);
	}
	int v = 0;

	int u = bfs(0, G);
	deque <int> d;
	d.push_back(u);
	vector <int> dist(n, -1);
	dist.at(u) = 0;
	while(d.size()){
		auto now = d.front();
		d.pop_front();
		for(auto next: G.at(now)){
			if(dist.at(next) != -1) continue;
			dist.at(next) = dist.at(now) + 1;
			v = next;
			d.push_back(next);
		}
	}

	cout << u+1 << " " << v+1 << endl;
}