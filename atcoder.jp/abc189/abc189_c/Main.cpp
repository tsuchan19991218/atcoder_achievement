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

    int ans = 0;
    for(int i = 0; i < n; i ++){
        int m = a.at(i);
        for(int j = i; j < n; j ++){
            m = min(m, a.at(j));
            ans = max(ans, m * (j - i + 1));
        }
    }
    cout << ans << endl;
}