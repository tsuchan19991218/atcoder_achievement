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
    ll n; cin >> n;
    string s_n = to_string(n);

    ll ans = 0;
    if(s_n.size() <= 3){
        cout << 0 << endl;
    }
    else if(s_n.size() <= 6){
        cout << n - 999 << endl;
    }
    else if(s_n.size() <= 9){
        ans += 999999 - 999;
        ans += (n - 999999) * 2;
        cout << ans << endl;
    }
    else if(s_n.size() <= 12){
        ans += 999999 - 999;
        ans += (999999999 - 999999) * 2;
        ans += (n - 999999999) * 3;
        cout << ans << endl;
    }
    else if(s_n.size() <= 15){
        ans += 999999 - 999;
        ans += (999999999 - 999999) * 2;
        ans += (999999999999 - 999999999) * 3;
        ans += (n - 999999999999) * 4;
        cout << ans << endl;
    }
    else{
        ans += 999999 - 999;
        ans += (999999999 - 999999) * 2;
        ans += (999999999999 - 999999999) * 3;
        ans += (999999999999999 - 999999999999) * 4;
        ans += 5;
        cout << ans << endl;
    }
    

}