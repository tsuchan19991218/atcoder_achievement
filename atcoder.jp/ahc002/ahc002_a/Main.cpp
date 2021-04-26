#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

mt19937 get_rand_mt(rand()%1000);


int s_y, s_x;
map <pair<int, int>, int> maze2point;
map <pair<int, int>, int> maze2id;
int MAX_id = 0;
int Takahashi_size = 750;

vector <char> directions{'U', 'D', 'R', 'L'};

struct Status {
    double score; //score
    string path;
    vector <int> id_used;
    int now_y, now_x;

    Status():score(), id_used(MAX_id + 5)
    {
        path = "";
        now_y = s_y;
        now_x = s_x;
        score = maze2point[make_pair(now_y, now_x)];
        id_used.at(maze2id[make_pair(now_y, now_x)]) = 1;
    }

    bool operator<(const Status& right) const {
        return score < right.score;
    }

    void walk(){
        // 移動できなくなるまで
        while(1){
            //cout << now_y << " " << now_x << endl;
            shuffle(directions.begin(), directions.end(), get_rand_mt);
            bool is_move = false;
            for(auto direction: directions){
                if(!move(direction)) continue; //その方向に動けない
                else{
                    while(move(direction)){
                        if(rand() % 2 == 0) break;
                    }
                    is_move = true;
                    break;
                }
            }
            if(is_move) continue;
            break;
        }
    }

    void fix_walk(string sub_path){
        now_x = s_x;
        now_y = s_y;
        path = "";
        score = maze2point[make_pair(now_y, now_x)];
        fill(id_used.begin(), id_used.end(), 0);
        id_used.at(maze2id[make_pair(now_y, now_x)]) = 1;
        for(auto direction: sub_path){
            move(direction);
        }
        walk();
    }

    // 移動判定、移動、マス埋め、スコア拾い上げ
    bool move(char direction){
        if(direction == 'U'){
            if(now_y - 1 < 0) return false;
            if(id_used.at(maze2id[make_pair(now_y-1, now_x)])) return false;
            id_used.at(maze2id[make_pair(now_y-1, now_x)]) = 1;
            score += maze2point[make_pair(now_y-1, now_x)];

            now_y --;
            path = path + direction;
            return true;
        }
        if(direction == 'D'){
            if(now_y + 1 >= 50) return false;
            if(id_used.at(maze2id[make_pair(now_y+1, now_x)])) return false;
            id_used.at(maze2id[make_pair(now_y+1, now_x)]) = 1;
            score += maze2point[make_pair(now_y+1, now_x)];
            
            now_y ++;
            path = path + direction;
            return true;
        }
        if(direction == 'R'){
            if(now_x + 1 >= 50) return false;
            if(id_used.at(maze2id[make_pair(now_y, now_x+1)])) return false;
            id_used.at(maze2id[make_pair(now_y, now_x+1)]) = 1;
            score += maze2point[make_pair(now_y, now_x+1)];

            now_x ++;
            path = path + direction;
            return true;
        }
        if(direction == 'L'){
            if(now_x - 1 < 0) return false;
            if(id_used.at(maze2id[make_pair(now_y, now_x-1)])) return false;
            id_used.at(maze2id[make_pair(now_y, now_x-1)]) = 1;
            score += maze2point[make_pair(now_y, now_x-1)];

            now_x --;
            path = path + direction;
            return true;
        }
    }
};

struct Many_Status {
    vector <Status> Takahashi;
    Many_Status():Takahashi(Takahashi_size)
    {
        rep(i, Takahashi_size){
            Takahashi.at(i).walk();
        }
    }

    void copy(){
        vector <Status> _Takahashi(Takahashi_size/2);
        sort(Takahashi.rbegin(), Takahashi.rend());
        rep(i, Takahashi_size/2){
            _Takahashi.at(i) = Takahashi.at(i);
            
            string sub_path = _Takahashi.at(i).path;
            //cout << _Takahashi.at(i).path << "-->" << sub_path.substr(0, sub_path.size()/ 2) << endl;
            if(rand()%5 == 0){
                _Takahashi.at(i).fix_walk(sub_path.substr(0, sub_path.size()/2));
            }
            else{
                _Takahashi.at(i).fix_walk(sub_path.substr(0, sub_path.size() - (min((int)(sub_path.size()), (int)(rand()%50)))));
            }
        }
        for(int i = Takahashi_size/2; i < Takahashi_size; i ++){
            Takahashi.at(i) = _Takahashi.at(i - (Takahashi_size/2));
        }
    }

};

int main(){
    clock_t start = clock();
    cin >> s_y >> s_x;
    rep(i, 50){
        rep(j, 50){
            int t; cin >> t;
            maze2id[make_pair(i, j)] = t;
            MAX_id = max(MAX_id, t);
        }
    }
    rep(i, 50){
        rep(j, 50){
            int p; cin >> p;
            maze2point[make_pair(i, j)] = p;
        }
    }

    Many_Status Takahashis;
    time_t end = clock();
    rep(i, 100000){
        Takahashis.copy();
        // for (auto Takahashi: Takahashis.Takahashi){
        //     cout << "-------------" << endl;
        //     cout << Takahashi.score << endl;
        //     cout << Takahashi.path << endl;
        // }
        end = clock();
        if((double)(end - start) / CLOCKS_PER_SEC * 1000.0 > 1930) break;
    }
    
    sort(Takahashis.Takahashi.rbegin(), Takahashis.Takahashi.rend());
    cout << Takahashis.Takahashi.at(0).path << endl;
}