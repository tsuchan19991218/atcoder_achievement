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
    int h, w; cin >> h >> w;
    vector <vector <int>> a(h, vector<int>(w));
    int m = INF;
    rep(i, h)rep(j, w){
        cin >> a.at(i).at(j);
        m = min(m, a.at(i).at(j));
    }

    int ans = 0;
    for(auto vec: a){
        for(auto num: vec){
            ans += num - m;
        }
    }
    cout << ans << endl;
}