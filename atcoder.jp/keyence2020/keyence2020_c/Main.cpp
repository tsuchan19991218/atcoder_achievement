#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, s;
    cin >> n >> k >> s;
    long long INF = 10000000000;
    vector <long long> ans(n, INF);
    for (int i; i < k; i ++){
        ans[i] = s;
    }
    for (int i; i < n; i ++){
        if (ans[i] == INF){
            if (s == 1000000000){
                ans[i] = 1;
            }
            else{
                ans[i] = 1000000000;
            }
        }
    }
    for (int i; i < n; i ++) cout << ans[i] << " ";
    cout << endl;
}