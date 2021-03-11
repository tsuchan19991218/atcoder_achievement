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
    vector <int> a(n);
    vector <int> cnt(1000005);
    int unique = 0;
    rep(i, n){
        cin >> a.at(i);
        if(cnt.at(a.at(i)) == 0) unique ++;
        cnt.at(a.at(i)) ++;
    }

    //cout << unique << endl;

    int tmp = 0;
    for(auto num: cnt){
        if(num == 0) continue;
        tmp += (num - 1);
    }
    if(tmp % 2 == 0) cout << unique << endl;
    else cout << unique - 1 << endl;

}