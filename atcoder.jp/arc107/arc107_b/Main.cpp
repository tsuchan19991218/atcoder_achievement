#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n, k; cin >> n >> k;
    ll ans = 0;
    ll A = 2 * n;
    ll C = A - k;
    while(A >= 2){
        //cout << A << " " << C << endl;
        if((C >= 2 && C <= 2 * n) && (A >= 2 && A <= 2 * n)){
            //cout << A << " " << C << endl;
            ans += ((A - 1) - (max((A - 1 - n), 0LL) * 2)) * ((C - 1) - (max((C - 1 - n), 0LL) * 2));
            //cout << ans << endl;
            A --;
            C = A - k;
        }
        else{
            A --;
            C = A - k;
            continue;
        }
    }
    cout << ans << endl;
}