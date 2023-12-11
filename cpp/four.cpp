#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

tuple<vector<int>, vector<int>> parseline(string str){
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

int winning(vector<int> winning, vector<int> card){
    int wins = 0;
    for(int c : card){
        if(find(winning.begin(), winning.end(), c) != winning.end()){
            wins += 1;
        }
    }
    return wins;
}

int scorecard(int i, vector<tuple<vector<int>, vector<int>>> cards){
    auto card = cards[i];
    int wins = winning(get<0>(card), get<1>(card));
    int score = wins;
    for(int j = i + 1; j < i + wins + 1; j++){
        score += scorecard(j, cards);
    }
    return score;
}

int main(){
    ifstream file("../data/day_four.txt");

    string buf;

    int total = 0;

    vector<tuple<vector<int>, vector<int>>> cards;

    while(getline(file, buf)){
        cards.push_back(parseline(buf));
    }

    for(int i = 0; i < cards.size(); i++){
        cout << i << endl;
        total += scorecard(i, cards);
    }

    cout << total + cards.size();

    return 0;
}
