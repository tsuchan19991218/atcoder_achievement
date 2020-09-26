#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const ll INF = 1000000000;

int main(){
    int t; cin >> t;
    while(t --){
        ll n, m, a, b; cin >> n >> m >> a >> b;
        cout << floor_sum(n, m, a, b) << endl;
    }
}