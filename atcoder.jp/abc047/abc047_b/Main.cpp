#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;

    vector <vector<int>> x_y_a(n);
    for(int i = 0; i < n; i ++){
        int x, y, a;
        cin >> x >> y >> a;
        x_y_a[i].push_back(x);
        x_y_a[i].push_back(y);
        x_y_a[i].push_back(a);
    }
    vector <int> w_black(w, 0), h_black(h, 0);

    for (int i = 0; i < n; i ++){
        int a = x_y_a[i][2];
        if (a == 1){
            for (int j = 0; j < x_y_a[i][0]; j ++){
                w_black[j] = 1;
            }
        }
        else if (a == 2){
            for (int j = w - 1; j >= x_y_a[i][0]; j --){
                w_black[j] = 1;
            }
        }
        else if (a == 3){
            for (int j = 0; j < x_y_a[i][1]; j ++){
                h_black[j] = 1;
            }
        }
        else{
            for (int j = h - 1; j >= x_y_a[i][1]; j --){
                h_black[j] = 1;
            }
        }

    }

    size_t cnt_w, cnt_h;
    cnt_w = count_if(w_black.begin(), w_black.end(),
    [](int i)->bool{return (i == 0);}
    );
    cnt_h = count_if(h_black.begin(), h_black.end(),
    [](int i)->bool{return (i == 0);}
    );
    
    cout << cnt_w * cnt_h << endl;
}