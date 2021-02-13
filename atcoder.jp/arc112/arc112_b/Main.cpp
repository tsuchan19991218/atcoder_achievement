#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    ll x, c; cin >> x >> c;

        ll ans = 0;
    if(x >= 0){
        ans += min(x+1, (c/2) + 1);

        if(c % 2 == 1){
            
            ll max_minus = -(max(0LL, x - (c/2)));
            ll min_minus = -(x + (c / 2));

            if(x == 0){
                max_minus = -(min(1LL, c/2));
                min_minus = -(c / 2);
            }

            ans += max_minus - min_minus + 1;
            if(max_minus == 0) ans --;
        }
        else{
            ll max_minus = -(max(0LL, x - (c/2) + 1));
            ll min_minus = -(x + (c / 2) - 1);
            
            if(x == 0){
                max_minus = -(min(1LL, c/2));
                min_minus = -(c / 2);
            }

            ans += max_minus - min_minus + 1;
            if(max_minus == 0) ans --;
        }

        ans += max(0LL, ((c - 2)/2));
    }
    else{
        ans += (c / 2) + 1;

        if(c % 2 == 1){
            
            ll max_minus = -(x - (c/2));
            ll min_minus = -(min(0LL, x + (c/2)));


            ans += max_minus - min_minus + 1;
            if(min_minus == 0) ans --;
        }
        else{
            ll max_minus = -(x - (c/2) + 1);
            ll min_minus = -(min(0LL, x + (c / 2) - 1));

            ans += max_minus - min_minus + 1;
            if(min_minus == 0) ans --;
        }

        ans += min(-x, (max(0LL,(c - 2)/2)));
    }

    cout << ans << endl;
}