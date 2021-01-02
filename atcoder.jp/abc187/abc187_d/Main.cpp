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
    int n; cin >> n;
    vector <ll> a(n), b(n);
    ll sum_a = 0;
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
        sum_a += a.at(i);
    }

    priority_queue <ll> que;

    rep(i, n){
        ll value = 2 * a.at(i) + b.at(i);
        que.push(value);
    }

    int ans = 0;
    while(sum_a >= 0){

        sum_a -= que.top();
        que.pop();
        ans ++;
    }

    cout << ans << endl;

}