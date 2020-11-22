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
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    if(r1 == r2 && c1 == c2){
        cout << 0 << endl;
        return 0;
    }
    if(r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3){
        cout << 1 << endl;
        return 0;
    }


    for(int i = -3; i <= 3; i ++){
        for(int j = -3; j <= 3; j ++){
            ll x = r1 + i;
            ll y = c1 + j;
            if(abs(r1 - x) + abs(c1 - y) > 3) continue;
            // if((r2 + c2) % 2 == (x + y) % 2){
            //     cout << 2 << endl;
            //     return 0;
            // }
            if(x + y == r2 + c2 || x - y == r2 - c2 || abs(x - r2) + abs(y - c2) <= 3){
                cout << 2 << endl;
                return 0;
            }
        }
    }

    if((r2 + c2) % 2 == (r1 + c1) % 2){
                cout << 2 << endl;
                return 0;
            }

    cout << 3 << endl;
}