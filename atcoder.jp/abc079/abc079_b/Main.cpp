#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll get_lucas(vector <ll> &memo, int n);


int main(){
    int n; cin >> n;
    vector <ll> memo(90, -1);
    memo.at(0) = 2; memo.at(1) = 1;
    cout << get_lucas(memo, n) << endl;
}

ll get_lucas(vector <ll> &memo, int n){
    if (memo.at(n) != -1) return memo.at(n);

    memo.at(n) = get_lucas(memo, n - 1) + get_lucas(memo, n - 2);
    return memo.at(n);
}
