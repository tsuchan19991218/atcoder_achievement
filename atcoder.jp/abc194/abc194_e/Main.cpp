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
    vector <ll> cnt(n + 5);
    vector <ll> a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    
    int ans = n;
    for(int i = 0; i < n - m + 1; i ++){
        if(i == 0){
            rep(j, m){
                cnt.at(a.at(i + j))++;
            }

            for(int j = 0; j < n + 1; j ++){
                if(cnt.at(j) == 0){
                    ans = j;
                    break;
                }
            }
            //cout << ans << endl;
            continue;
        }

        cnt.at(a.at(i-1)) --;
        cnt.at(a.at(i + m - 1)) ++;
        if(a.at(i-1) < ans && cnt.at(a.at(i-1)) == 0) ans = a.at(i-1);
    }
    
    cout << ans << endl;
}