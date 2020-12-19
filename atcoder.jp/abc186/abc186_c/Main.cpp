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
    int n; cin >> n;
    // vector <int> mod_8(9);
    // ll d = 8;
    // rep(i, 9){
    //     mod_8.at(i) = d;
    //     d *= 8;
    // }

    vector <int> ng_flag(100005, 0);

    for(int num = 1; num <= 100002; num ++){
        int tmp = num;
        for(int i = 0; i < 5; i ++){
            if(tmp % 10 == 7) ng_flag.at(num) = 1;
            tmp /= 10;
        }
        tmp = num;
        for(int i = 0; i < 9; i ++){
            if(tmp % 8 == 7) ng_flag.at(num) = 1;
            tmp /= 8;
        }
    }

    int ans = n;
    for(int num = 1; num <= n; num ++){
        ans -= ng_flag.at(num);
    }
    cout << ans << endl;
}