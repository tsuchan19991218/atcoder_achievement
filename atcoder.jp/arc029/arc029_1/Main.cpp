#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> t(n);
    for(int i = 0; i < n; i ++) cin >> t.at(i);

    long long ans = 10000000000;
    for(int pat = 0; pat < int(pow(2, n)); pat ++){
        long long ans1, ans2;
        ans1 = ans2 = 0;
        for(int i = 0; i < n; i ++){
            if((pat >> i) & 1){
                ans1 += t.at(i);
            }
            else ans2 += t.at(i);
        }
        ans = min(ans, max(ans1, ans2));
    }

    cout << ans << endl;
}