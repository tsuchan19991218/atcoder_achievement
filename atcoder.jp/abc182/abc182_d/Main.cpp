#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000; 

int main(){
    ll n; cin >> n;
    vector <ll> a(n);
    rep(i, n) cin >> a.at(i);
    vector <ll> sum_a(n);
    sum_a.at(0) = a.at(0);
    vector <ll> max_sum(n);
    max_sum.at(0) = max(0LL, sum_a.at(0));
    ll box = max_sum.at(0);
    for(int i = 1; i < n; i ++){
        sum_a.at(i) = sum_a.at(i - 1) + a.at(i);
        box = max(box, sum_a.at(i));
        max_sum.at(i) = max(max_sum.at(i), box);
    }

    ll ans = 0;
    ll now = 0;
    for(int i = 0; i < n; i ++){
        ans = max(ans, now + max_sum.at(i));
        now += sum_a.at(i);
    }

    cout << ans << endl;
}