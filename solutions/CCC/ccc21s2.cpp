#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <sstream>  
#include <vector>
#include <map>
#include <string>

using namespace std;

class Rule {
    public:
    char type;
    int number;
    int count;
};

bool board[5000010];

map<string,Rule> rules;

void printboard(int row, int col) {
    for(int i=1;i<row*col+1;i++) {
        cout << board[i] << "\n";
    }
}

void flipit(Rule rule,int row, int col) {
    char c = rule.type;
    int num = rule.number;
    if(c == 'R') {
        int index = (num-1)*col + 1;
        for(int j=1;j<col+1;j++) {
            if(board[index] == true) {
                board[index] = false;
            }
            else 
                board[index] = true;
            index=index+1;
            // cout << "flip";
        }
    }
    else if(c == 'C') {
        int index = num;
        // cout << "flip at" << index;

        for(int k=1;k<row+1;k++) {
            if(board[index] == true) {
                board[index] = false;
            }
            else 
                board[index] = true;
            index=index+col;
        }
    }
    // cout << "for line:" << i << "\n";
    // checkboard(row,col);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int row, col;
    int line;

    cin >> row >> col;
    cin >> line;

    for(int i=1;i<line+1;i++) {
        Rule rule;
        cin >> rule.type >> rule.number;
        rule.count = 1;

        stringstream ss;
        string key;
        ss << rule.type << rule.number;
        ss >> key;

       
        if(rules.find(key) == rules.end()) {
            rules[key] = rule;
        }
        else { 
            Rule ruleinmap = rules[key];
            ruleinmap.count = ruleinmap.count + 1;
            rules[key] = ruleinmap;
        }
    }

    for(int i=1;i<row*col+1;i++) {
        board[i] = false;
    }
    
    
int count = 0;
    int countC = 0;
    int countR = 0;
    for(std::map<string, Rule>::const_iterator it = rules.begin(); it != rules.end(); it++)
    {
        string keyit = it->first;
        Rule ruleit = it->second;
        
        int c = ruleit.count;
        if(c % 2 == 1) {
            if(ruleit.type == 'R') {
                countR = countR + 1;
            }
            else if(ruleit.type == 'C') {
                countC = countC + 1;
            }
        }
    }

    count = (row - countR)*countC + (col-countC)*countR;

    cout << count;
    return 0;
}