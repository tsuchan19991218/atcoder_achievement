#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

ll get_x(ll X){
    ll tmp = 0;
    //cout << X << " :";
    for(ll i = 1; i * i <= X; i ++){
        if(X % i == 0) tmp += 2;

        if(i * i == X && X % (i * i) == 0) tmp --;
    }
    //cout << tmp << endl;
    return tmp;
}

int main(){
    int k; cin >> k;
    ll ans = 0;
    for(int X = 1; X <= k; X ++){
        //if(k % X != 0) continue;
        ans += get_x(X) * (k / X);
    }
    cout << ans << endl;
}