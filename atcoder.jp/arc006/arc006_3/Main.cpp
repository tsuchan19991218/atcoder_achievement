#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    vector <int> box;
    while(n--){
        int w; cin >> w;
        bool flag = false;
        for(auto &num: box){
            if(num >= w){
                num = w;
                flag = true;
                break;
            }
        }
        if(!flag) box.push_back(w);
    }
    cout << box.size() << endl;
}