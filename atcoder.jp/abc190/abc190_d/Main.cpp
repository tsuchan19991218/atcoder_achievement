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
    
    ll ans = 0;
    
    for(ll i = 1; i * i <= 2 * n; i ++){
        if(i % 2 == 1){
            if(n % i == 0){
                //cout << i << endl;
                ans ++;
            }
        }
        else if(i % 2 == 0){
            if(n % i != 0 && (2 * n) % i == 0){
                //cout << i << endl;
                ans ++;
            }
        }
    }
    cout << ans * 2 << endl;
}