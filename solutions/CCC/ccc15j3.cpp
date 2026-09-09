#pragma GCC optimize(2)

#include <iostream>

using namespace std;

string vowels = "aeiou";
string consonants = "bcdfghjklmnpqrstvwxyz";
string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

bool isVowel(char c) {
    bool isV = false;
    for(int i=0;i<vowels.length();i++) {
        if(vowels[i] == c) {
            isV = true;
            break;
        }
    }
    return isV;
}

char nearestVowel(char c) {
    int pos = alphabet.find(c);
    char cReturn = 'a';
    int disN = 1000;
    int posN = alphabet.length() -1;
    int posB = 0;
    for(int i=pos+1;i<alphabet.length();i++) {
        char cToCheck = alphabet[i];
        if(isVowel(cToCheck)==true) {
            disN = i - pos;
            posN = i;
            break;
        }
    }
    int disB = 1000;
    for(int i=pos-1;i>=0;i--) {
        char cToCheck = alphabet[i];
        if(isVowel(cToCheck)==true) {
            disB = pos - i;
            posB = i;
            break;
        }
    }
    if(disB <= disN) {
        cReturn = alphabet[posB];
    }
    else {
        cReturn = alphabet[posN];
    }
    return cReturn;
}

char nextConsonant(char c) {
    int pos = alphabet.find(c);
    char cReturn = 'z';
    if(pos == alphabet.length()-1) {
        cReturn = 'z';
    } else {
        cReturn = alphabet[pos+1];
        if(isVowel(cReturn)==true) {
            cReturn = alphabet[pos+2];
        }
    }
    return cReturn;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input, output = "";

    cin >> input;
    int inputLen = input.length();

    for(int i = 0; i < inputLen; i++) {
        if(isVowel(input[i]) == true) {
            output = output + input[i];
        }
        else {
            char nearestV = nearestVowel(input[i]);
            char nextC = nextConsonant(input[i]);
            output = output + input[i] + nearestV + nextC;
        }
    }
    cout << output;
}