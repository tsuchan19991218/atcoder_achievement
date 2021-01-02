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
    vector <double> x(n), y(n);
    rep(i, n) cin >> x.at(i) >> y.at(i);
    int ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            double a = (y.at(j) - y.at(i))/(x.at(j) - x.at(i));
            if(abs(a) <= 1){
                ans ++;
            }
        }
    }
    cout << ans << endl;
}