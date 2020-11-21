#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector <string> str(n + 50);
    int c = 0;
    int ans = 0;
    for(auto chr: s){
        if(chr != 'f' && chr != 'o' && chr != 'x'){
            c ++;
            ans ++;
            continue;
        }
        //cout << chr << endl;
        str.at(c) += chr;
    }

    //for(auto S: str){
        //cout << S << endl;
    //}
    for(auto S: str){
        string box = "";
        //cout << S << endl;
        if(S.size() == 0) continue;
        int tmp = S.size();
        deque <int> index;
        for(int i = 0; i < (int)S.size(); i ++){
            index.push_back(i);
        }
        auto begin = index.begin();
        //auto first = index.begin();
      	//cout << S << endl;
      	bool flag = false;
        for(auto itr = begin; itr != index.end();){
			if(flag) itr = index.begin();
          	flag = false;
            int i = *itr;
          	//cout << i << " " << box << endl;
            //cout << i << endl;
            if(box == "" && S.at(i) != 'f'){
                box = "";
                itr++;
                continue;
            }
            else if(box == "" && S.at(i) == 'f'){
                box += (S.at(i));
                //first = itr;
                itr++;
                continue;
            }
          
          	if(S.at(i) == 'f'){
              box = "f";
              itr++;
              continue;
            }

            if(box == "f" && S.at(i) != 'o'){
                box = "";
                itr++;
                continue;
            }
            else if(box == "f" && S.at(i) == 'o'){
                box += S.at(i);
                itr++;
                continue;
            }

            if(box == "fo" && S.at(i) != 'x'){
                box = "";
                itr++;
                continue;
            }
            else if(box == "fo" && S.at(i) == 'x'){
                box = "";
                //cout << tmp << endl;
                tmp -= 3;
              	if(i == index.back()) break;
                itr -= 2;
                rep(k, 3){
                    //cout << *itr << endl;
                    itr = index.erase(itr);
                }
               	itr -= 2;
                if(index.begin() - itr > 0){
                    flag = true;
                }
                continue;
            }
        }
      /*while(!index.empty()){
        cout << index.front() << " ";
        index.pop_front();
      }*/
      //cout << endl;
		//cout << tmp << endl;
        ans += tmp;
        
    }
    cout << ans << endl;
}