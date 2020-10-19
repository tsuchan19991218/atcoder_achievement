#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    map <string, int> cnt;
    string ans = "";
    rep(i, n){
        string s; cin >> s;
        if(cnt[s] == 0){
            cnt[s] = 1;
        }
        else cnt[s] ++;
        if(ans == "") ans = s;
        if(cnt[s] > cnt[ans]) ans = s;
    }
    cout << ans << endl;
}