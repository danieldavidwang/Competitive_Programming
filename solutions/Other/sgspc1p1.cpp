#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

const int MM = 2e5+10;
long N;

long a[MM];
string s[MM];

long zeros[100];
long sum[100];
long maxv[100];


string DecimalToBinaryString(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 31; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    // cout<<binary<<endl;
    return binary;
}



int BinaryStringToDecimal(string a) 
{
    int Rslt = 0;
    int Mask = 1;
    for (int i = a.length()-1; i >= 0; --i, Mask <<= 1) {
        if (a.at(i) != '0') {
            Rslt |= Mask;
        }
    }
    return (Rslt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> a[i];
        s[i] = DecimalToBinaryString(a[i]);
        // cout << DecimalToBinaryString(a[i]) << endl;
    }
    long index = 0;
    long maxIndex = 0;
    /* */
    while(index < s[0].length() && maxIndex == 0) {
        for(int i=0;i<N;i++) {
            if(s[i][index] != '0') {
                maxIndex = index;
                break;
            }
        }
        index++;
    }  /* */
    index = maxIndex;
    // cout << "maxIndex:" << maxIndex << endl;
    while(index < s[0].length()) {
        for(int i=0;i<N;i++) {
            // sum[index] = sum[index] + (s[j][index] - '0'); 
            // maxv[index] = maxv[index] + 1;
            int arrv = s[i][index] - '0';
            sum[index] += (arrv * (i+1) * (N-i));
            maxv[index] += (1 * (i+1) * (N-i));
        }
        index++;
    }
    /* 
    index = 0;
    cout << "\nsum is:";
    while(index < s[0].length()) {
        cout << sum[index] << ",";
        index++;
    }

    index = 0;
    cout << "\nmaxv is:";
    while(index < s[0].length()) {
        cout << maxv[index] << ",";
        index++;
    } */
    string result = "";
    index = maxIndex;
    while(index < s[0].length()) {
        if(sum[index]*2 > maxv[index]) {
            result = result + "1";
        }
        else {
            result = result + "0";
        }
        index++;
    }

    // cout << "result is:" << result << endl;
    // cout << "result int is:" << BinaryStringToDecimal(result) << endl;
    cout << BinaryStringToDecimal(result) << endl;
    
    return 0;
}