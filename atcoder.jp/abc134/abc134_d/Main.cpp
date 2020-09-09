#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    vector <int> a(n + 1);
    //vector <int> xor_sum(n + 1);

    rep(i, n + 1){
        if (i == 0) continue;
        cin >> a.at(i);
        //xor_sum.at(i) = a.at(i);

        //if (i == 1) continue;
        //xor_sum.at(i) ^= xor_sum.at(i - 1);
    }

    vector <int> ball_cnt(n + 1);
    int M = 0;
    for (int i = n; i >= 1; i --){
        int sum_ball = 0;
        for (int j = i; j < n + 1; j += i){
            sum_ball += ball_cnt.at(j);
        }

        if (sum_ball % 2 == a.at(i)) continue;
        else {
            ball_cnt.at(i) = 1;
            M += 1;
        }
        
    }

    cout << M << endl;
    for (int i = 1; i < n + 1; i ++){
        if (ball_cnt.at(i) == 0) continue;
        cout << i << " ";
    }
    if (M != 0) cout << endl;
    

//     bool ok = true;
//     for (int i = 2; i < n + 1; i ++){
//         for (int j = i; j + i < n + 1; j += i){
//             int xor_range = xor_sum.at(j + i) ^ xor_sum.at(j);
            
//             if (a.at(j) ^ a.at(j + i) != xor_range) ok = false;
//         }
//     }
    
//     if (!ok){
//         cout << -1 << endl;
//     }
//     else{
//         long long ball_cnt = 0;
//         deque <long long> ans;
//         reverse(a.begin(), a.end());

//         //for (auto _a :a) cout << _a << " " << endl;
//         if (a.at(0) == 1){
//             ball_cnt += 1;
//             ans.push_front(1);
//         }
//         for (int i = 1; i < n; i ++){
//             if (a.at(i) ^ a.at(i - 1) == 0) ball_cnt += 0;
//             else ball_cnt += 1;
//             if (ball_cnt == 0) continue;

//             ans.push_front(ball_cnt);
//         }

//         cout << ans.size() << endl;
//         int s = ans.size();
//         rep(i, s){
//             cout << ans.front() << " ";
//             ans.pop_front();
//         }
//         cout << endl;
//     }

}