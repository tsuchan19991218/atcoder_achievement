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
    ll k; cin >> k;
    vector <vector<ll>> t(n, vector<ll>(n));
    rep(i, n)rep(j, n) cin >> t.at(i).at(j);

    vector <int> toshi(n - 1);
    for(int i = 1; i < n; i ++){
        toshi.at(i - 1) = i;
    }

    ll ans = 0;
    do{ 
        //for(auto num: toshi) cout << num << " ";
        //cout << endl;
        ll tmp = t.at(0).at(toshi.at(0));
        //cout << tmp << endl;
        for(int i = 0; i < n - 2; i ++){
            tmp += t.at(toshi.at(i)).at(toshi.at(i + 1));
        }
        tmp += t.at(toshi.at(n - 2)).at(0);
        if(tmp == k) ans ++;
        //cout << tmp << endl;
    }while(next_permutation(toshi.begin(), toshi.end()));
    cout << ans << endl;
}