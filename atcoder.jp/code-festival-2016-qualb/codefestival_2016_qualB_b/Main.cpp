#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int cnt_a, cnt_b;
    int passed = 0;
    cnt_a = cnt_b = 0;

    for(auto c: s){
        if(c == 'a'){
            if(passed < a + b){
                passed += 1;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else if(c == 'b'){
            if(passed < a + b && cnt_b < b){
                passed += 1;
                cnt_b += 1;
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
}