#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

bool is_lunlun(int n){
    
    int num = n % 10;
    while(1){
        int next_num = n % 10;
        //cout << num << " " << next_num << endl;
        if(abs(num - next_num) > 1){
            return false;
        }
        n /= 10;
        if(n == 0) break;
        num = next_num;
    }
    return true;
}

ll str_to_int(string str){
    reverse(str.begin(), str.end());
    ll d = 1; ll ans = 0;
    for(auto c: str){
        ans += (c - '0') * d;
        d *= 10;
    }
    return ans;
}

set <ll> lunlun;
void make_lunlun(int n, string arr, int l){
    string tmp = to_string(n);
    arr += tmp;
    if(arr.size() == l){
        lunlun.insert(str_to_int(arr));
        return;
    }
    int a = n + 1;
    if(a != 10) make_lunlun(a, arr, l);
    make_lunlun(n, arr, l);
    int b = n - 1;
    if(b != -1) make_lunlun(b, arr, l);
}

int main(){
    int k; cin >> k;
    for(int l = 1; l <= 10; l ++){
        for (int i = 0; i <= 9; i ++) make_lunlun(i, "", l);
    }
    auto itr = lunlun.begin();
    rep(i, k) itr ++;
    cout << *itr << endl;
}