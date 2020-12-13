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
    ll n, m; cin >> n >> m;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    vector <ll> a(m);
    ll k = n;
    rep(i, m){
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    rep(i, m){
        if(i > 0){
            if(a.at(i) - a.at(i - 1) - 1 == 0) continue;
            k = min(k, (a.at(i) - a.at(i - 1) - 1));
        }
        else{
            if(a.at(i) - 1 == 0) continue;
            k = min(k, a.at(i) - 1);
        }
    }
    if(a.at(m - 1) != n){
        k = min(k, n - a.at(m - 1));
    }
    if(k == n && m > 0) k = 0;
    //cout << k << endl;
    ll pre = 0;
    deque <ll> d;
    for(auto num: a){
        //cout << num - pre - 1 << endl;
        if(num - pre - 1 == 0){
            pre = num;
            continue;
        }
        d.push_back(num - pre - 1);
        pre = num;
    }
    if (n != pre) d.push_back(n - pre);
    ll ans = 0;
    while(!d.empty()){
        //cout << d.front() << endl;
        //ans += d.front() - k + 1;
        ans += (d.front() + k - 1) / k;
        d.pop_front();
    }
    cout << ans << endl;
}