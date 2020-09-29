#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int x; cin >> x;
    int _x = x % 100;
    rep(a, 100)rep(b, 50)rep(c, 33)rep(d, 25)rep(e, 20){
        int sum = a + 2 * b + 3 * c + 4 * d + 5 * e;
        if(_x != sum % 100) continue;
        if(x - _x < (a + b + c + d + e) * 100) continue;
        cout << 1 << endl;
        return 0;
    }

    cout << 0 << endl;
}