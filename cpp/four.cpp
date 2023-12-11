#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

tuple<vector<int>, vector<int>> parseLine(string str){
    int colonPos = str.find(':'), pipePos = str.find('|');
    stringstream winning = stringstream(str.substr(colonPos + 1, pipePos - colonPos - 1));
    stringstream card = stringstream(str.substr(pipePos + 1));

    vector<int> cardNums, winningNums;

    string buf;

    while(winning >> buf){
        winningNums.push_back(stoi(buf));
    }
    while(card >> buf){
        cardNums.push_back(stoi(buf));
    }

    return make_tuple(winningNums, cardNums);
}

vector<int> winning(vector<int> winning, vector<int> card){
    vector<int> wins;
    for(int c : card){
        if(find(winning.begin(), winning.end(), c) != winning.end()){
            wins.push_back(c);
        }
    }
    return wins;
}

int main(){
    ifstream file("../data/day_four.txt");

    string buf;

    int total = 0;

    while(getline(file, buf)){
        auto pairs = parseLine(buf);
        auto wins = winning(get<0>(pairs), get<1>(pairs));
        for(auto win : wins){
            cout << win << ' ';
        }
        cout << endl;
        if(wins.size() > 0){
            total += pow(2, wins.size() - 1);
        }
    }

    cout << total;

    return 0;
}
