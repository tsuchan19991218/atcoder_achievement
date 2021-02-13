#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        ll ans = 0;
        ans = (r - l + 1) * (r - l + 1);
        ans -= (r - l + 1) * l;
        if(r - 2 * l >= 0){
            ans -= (r * (r - 2 * l + 1)) / 2;
        }
        cout << max(ans, 0LL) << endl;
    }

}