#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

vector <int> is_prime(100000 + 5);
// void make_prime(){

// }

int main(){
    int n; cin >> n;
    vector <int> ans(n, 2);
    ans.at(0) = 1;
    for(int i = 1; i < n; i ++){
        int num = i + 1;
        int now = ans.at(i);
        for(int j = num * 2; j <= n; j += i + 1){
            ans.at(j - 1) = max(ans.at(j-1), now + 1);
            //cout << j << endl;
        }
    }
    // int now = 1;
    // int index = 1;
    // rep(i, n){
    //     if(i + 1 == 2 * index){
    //         now ++;
    //         index = i + 1;
    //     }
    //     cout << now << " ";
    // }
    for(auto num: ans) cout << num << " ";
    cout << endl;
}