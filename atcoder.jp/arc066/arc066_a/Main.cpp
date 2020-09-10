#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    ll ans = 0;
    int n; cin >> n;
    vector <int> A(n);

    rep(i, n) cin >> A.at(i);

    sort(A.begin(), A.end());
    ll num = A.at(0);
    if (n % 2 == 0 && num != 1){
        cout << ans << endl;
        return 0;
    }
    else if (n % 2 == 1 && num != 0){
        cout << ans << endl;
        return 0;
    }

    bool ng = false;
    rep(i, n){
        if (n % 2 == 0){
            if (i % 2 == 0){
                if (A.at(i) != i + 1){
                    ng = true;
                    break;
                }
            }
            else{
                if (A.at(i) != i){
                    ng = true;
                    break;
                }
            }
        }
        else{
            if (i == 0) continue;
            if (i % 2 == 1){
                if (A.at(i) != i + 1){
                    ng = true;
                    break;
                }
            }
            else{
                if (A.at(i) != i){
                    ng = true;
                    break;
                }
            }
        }
    }

    if(ng) cout << ans << endl;
    else{
        ans = 1;
        rep(i, n / 2){
            ans = ans * 2 % 1000000007;
        }
        cout << ans << endl;
    }

}