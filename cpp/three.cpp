#include <fstream>
#include <vector>
#include <iostream>
#include <tuple>
#include <math.h>
#include <algorithm>

using namespace std;

vector<tuple<int, int>> stars(vector<string> lines){
    vector<tuple<int, int>> is;

    for(int i = 0; i < lines.size(); i++){
        for(int j = 0; j < lines[0].size(); j++){
            if(lines[i][j] == '*'){
                is.push_back(make_tuple(i, j));
            }
        }
    }
    return is;
}

vector<tuple<int, int>> adjacent_numis(tuple<int, int> ij, vector<string> lines){

    int i = get<0>(ij), j = get<1>(ij);
    int offset[] = {-1, 0, 1};
    vector<tuple<int, int>> is;

    for(int v: offset){
        int i2 = i + v;
        for(int h: offset){
            int j2 = j + h;
            if(v == 0 && h == 0 
                || i2 < 0 || i2 == lines.size() 
                || j2 < 0 || j2 == lines[0].size()){
                continue;
            }
            if(isdigit(lines[i2][j2])){
                if(is.size() >= 1){
                    tuple<int, int> last = is.back();
                    if(get<0>(last) == i2 && isdigit(lines[i2][j2 - 1])){
                        continue;
                    }
                }
                is.push_back(make_tuple(i2, j2));
            }
        }
    }
    return is;
}

int get_num(tuple<int, int> ij, vector<string> lines){
    string num;
    string line = lines[get<0>(ij)];

    int curi = get<1>(ij);
    while(isdigit(line[curi])){
        num.insert(0, 1, line[curi]);
        curi -= 1;
        if(curi < 0){
            break;
        }
    }
    curi = get<1>(ij) + 1;
    while(isdigit(line[curi])){
        num.push_back(line[curi]);
        curi += 1;
    }
    return stoi(num);
}

int main(){
    ifstream file("../data/day_three.txt");
    string str;
    vector<string> lines;

    while(getline(file, str)){
        lines.push_back(str);
    }
    file.close();

    vector<tuple<int, int>> ss = stars(lines);
    int total;

    for(auto i : ss){
        vector<tuple<int, int>> adjs = adjacent_numis(i, lines);
        if(adjs.size() < 2){
            continue;
        }
        int ratio = 1;
        for(auto j: adjs){
            ratio *= get_num(j, lines);
        }
        total += ratio;
    }
    cout << total;
    return 0;
}
