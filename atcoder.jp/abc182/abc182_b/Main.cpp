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
    vector <int> a(n);
    rep(i, n) cin >> a.at(i);
    pair <int, int> ans;
    for(int i = 2; i < 1001; i ++){
        int cnt = 0;
        for(auto num: a){
            if(num % i == 0) cnt++;
        }
        if(ans.second <= cnt){
            ans.first = i;
            ans.second = cnt;
        }
    }
    cout << ans.first << endl;
}