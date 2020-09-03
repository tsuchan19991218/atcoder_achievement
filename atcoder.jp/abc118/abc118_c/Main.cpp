#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector <int> a;
    long long INF = 1000000000;

    cin >> n;
    int min_a = INF;
    for (int i = 0; i < n; i ++){
        int _a; cin >> _a;
        min_a = min(min_a, _a);
        a.push_back(_a);
    }

    while(1){
        int cnt = 0;
        int new_min_a = INF;
        for (auto itr = a.begin(); itr != a.end(); ++ itr){
            if (*itr % min_a == 0){
                cnt += 1;
            }
            else{
                new_min_a = min(new_min_a, *itr % min_a);
            }
            //*itr %= min_a;
        }
        if(cnt == a.size()){
            break;
        }
        min_a = new_min_a;
    }
    cout << min_a << endl;
}