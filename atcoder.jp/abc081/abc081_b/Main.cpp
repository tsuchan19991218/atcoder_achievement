#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a, min_cnt;
    //bool flag = true;
    min_cnt = 1000000000;
    for (int i = 0; i < N; i ++){
        cin >> a;
        if (a % 2 != 0){
            //flag = false;
            min_cnt = 0;
            break;
        }
        int cnt = 0;
        while (a % 2 == 0){
            a /= 2;
            cnt += 1;
        }
        min_cnt = min(min_cnt, cnt);
    }
    cout << min_cnt << endl;
}