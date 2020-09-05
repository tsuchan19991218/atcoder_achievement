#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i ++){
        int _a;
        cin >> _a;
        a[i] = _a;
    }
    sort(a.begin(), a.end());

    int now_num = 0;
    int now_cnt = 0;
    int ans = 0;
    for (auto num : a){
        if (now_num != num){
            if (now_cnt < now_num){
                ans += now_cnt;
            }
            now_cnt = 0;
        }

        if (now_cnt == 0){
            now_num = num;
        }

        now_cnt += 1;
        if (now_cnt > now_num){
            ans += 1;
        }
    }

    if (now_cnt < now_num){
        ans += now_cnt;
    }

    cout << ans << endl;
}