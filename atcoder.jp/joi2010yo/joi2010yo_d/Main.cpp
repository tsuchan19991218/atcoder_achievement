#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {1, 0, -1, 0};
vector <int> dx = {0, 1, 0, -1};

const int INF = 1000000000;

int main(){
    int n, k; cin >> n >> k;
    vector <int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    map <string, int> num_cnt;
    ll ans = 0;
    do{
        // rep(i, n) cout << a.at(i) << " ";
        // cout << endl;
        string now = "";
        for(int i = 0; i < k; i ++) now += to_string(a.at(i));
        if(num_cnt[now] == 0){
            num_cnt[now] = 1;
            ans += 1;
        }
    } while(next_permutation(a.begin(), a.end()));

    cout << ans << endl;
}