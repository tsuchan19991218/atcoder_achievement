#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int max_x = 2000000000;

int main(){
    int n;
    int ans = 0;
    cin >> n;
    vector <P> x_l;
    for (int i = 0; i < n; i ++){
        int x, l;
        cin >> x >> l;
        x_l.push_back(P(x - l, x + l));
    }

    sort(x_l.rbegin(), x_l.rend());
    
    auto kagen = max_x;
    for (int i = 0; i < n; i ++){
        if (kagen >= x_l[i].second){
            ans += 1;
            kagen = x_l[i].first;
        }
    }
    cout << ans << endl;
}