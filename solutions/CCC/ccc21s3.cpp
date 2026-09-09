#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
using namespace std;

class Person {
    public:
    long p;
    int w;
    long d;
};

bool myfunction(Person p1, Person p2) {
    return p1.p < p2.p;
}

map<int, Person> persons;
map<int, long> timeForPos;
long minValueForFinalResult;

void printAlltimeForPos() {
    for(std::map<int, long>::const_iterator it = timeForPos.begin(); it != timeForPos.end(); it++)
    {
        int keyit = it->first;
        long time = it->second;
        // cout << "position of " << keyit << " is using " << time << "\n";
    }
}

long timeforp(int mypos, Person person) {
    long pos = person.p;
    long dis = person.d;
    int wsec = person.w;
    long travel = 0;

    if(mypos > pos) {
        travel = mypos - pos;
    }
    else {
        travel = pos - mypos;
    }
    

    if(travel > dis) {
        travel = travel - dis;
    }
    else {
        travel = 0;
    }

    return travel * wsec;
}

long timeforall(int mypos) {
    if(timeForPos.find(mypos) == timeForPos.end()) {
    }
    else {
        return timeForPos[mypos];
    }
    long timeTotal = 0;
    for(std::map<int, Person>::const_iterator it = persons.begin(); it != persons.end(); it++)
    {
        int keyit = it->first;
        Person personit = it->second;
        long tforp = timeforp(mypos,personit);
        timeTotal = timeTotal + tforp;
    }
    timeForPos[mypos] = timeTotal;
    return timeTotal;
}

void setMinValue(long minValue) {
    if(minValueForFinalResult > minValue)
        minValueForFinalResult = minValue;
}

void setFinalMinValue(int posLeft, int posMid, int posRight) {
            long tForLeft = timeforall(posLeft);
            long tForMid = timeforall(posMid);
            long tForRight = timeforall(posRight);
            setMinValue(tForLeft);
            setMinValue(tForMid);
            setMinValue(tForRight);
}

int checkPos(int posLeft, int posMid, int posRight) {
    printAlltimeForPos();
    if(posLeft==posMid ) {
        if(posMid == posRight || posMid == posRight-1) {
            long tForLeft = timeforall(posLeft);
            long tForMid = timeforall(posMid);
            long tForRight = timeforall(posRight);
            setMinValue(tForLeft);
            setMinValue(tForMid);
            setMinValue(tForRight);
            return -1;
        }
        else {
            int posMid2 = posMid + (posRight-posMid)*0.5;
            checkPos(posMid, posMid2, posRight);
        }        
    }
    if(posRight==posMid) {
        if(posLeft==posMid || posLeft+1 == posMid) {
            long tForLeft = timeforall(posLeft);
            long tForMid = timeforall(posMid);
            long tForRight = timeforall(posRight);
            setMinValue(tForLeft);
            setMinValue(tForMid);
            setMinValue(tForRight);            
            return -1;
        }
        else {
            int posMid2 = posLeft + (posMid-posLeft)*0.5;
            checkPos(posLeft, posMid2, posMid);
        }
    }


    int trend = 0;

    long tForLeft = timeforall(posLeft);
    long tForMid = timeforall(posMid);
    long tForRight = timeforall(posRight);
    long leftTrend = tForMid - tForLeft;
    long rightTrend = tForRight - tForMid;

    if(leftTrend == 0) {
        int posMidnext = posLeft + (posMid-posLeft) * 0.5;
        if(rightTrend >= 0) {
            checkPos(posLeft,posMidnext,posMid);
        }
        else {
            checkPos(posMidnext,posMid,posRight);
        }
    }
    else if(rightTrend == 0) {
        int posMidnext = posLeft + (posMid-posLeft) * 0.5;
        if(leftTrend <= 0) {
            checkPos(posMidnext,posMid,posRight);
        }
        else {
            checkPos(posLeft,posMidnext,posMid);
        }
    }
    else if(leftTrend > 0 && rightTrend > 0) {
        trend = 1;
        int posMidnext = posLeft + (posMid-posLeft) * 0.5;
        checkPos(posLeft, posMidnext, posMid);
    }
    else if(leftTrend < 0 && rightTrend < 0) {
        trend = -1;
        int posMidnext = posMid + (posRight-posMid) * 0.5;
        checkPos(posMid, posMidnext, posRight);        
    }
    else {
        int leftDis = posMid - posLeft;
        int rightDis = posRight - posMid;
        int posMid2 = posLeft + (posMid-posLeft)*0.5;
        if(leftDis > rightDis) {
            posMid2 = posLeft + (posMid-posLeft)*0.5;
        }
        else {
            posMid2 = posMid + (posRight-posMid)*0.5;
            int posMid3 = posMid;
            posMid = posMid2;
            posMid2 = posMid3;
        }
        
        if(true) {
            long tForMid2 = timeforall(posMid2);
            long tForMid = timeforall(posMid);
            if(posLeft + 2 >= posRight ) {
                setFinalMinValue(posLeft, posLeft+1, posLeft+2);
                return -1;
            }
            if(posLeft + 2 >= posMid) {
                checkPos(posMid2,posMid,posRight);
            }
            if(posMid2 + 2 >= posRight) {
                checkPos(posLeft,posMid2,posMid);
            }
            if(tForMid2 <= tForMid) {
                checkPos(posLeft,posMid2,posMid);
            }
            else {
                checkPos(posMid2,posMid,posRight);
            }  
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int line;
    int minpos = 0;
    int maxpos = 0;
    long minTotalTime = __LONG_MAX__;
  
    cin >> line;

    for(int i=1;i<line+1;i++) {
        int pos,wsec,dis;
        cin >> pos >> wsec >> dis;
        if(i == 1) {
            minpos = pos;
            maxpos = pos;
        }
        if(pos < minpos) {
            minpos = pos;
        }
        if(pos > maxpos) {
            maxpos = pos;
        }
        Person person;
        person.p = pos;
        person.w = wsec;
        person.d = dis;
        persons[i] = person;
    }

    int posLeft = minpos;
    int posRight = maxpos;
    int posMid = posLeft + (posRight-posLeft) * 0.5;
    long tForMid = timeforall(posMid);
    minValueForFinalResult = tForMid;

    checkPos(posLeft,posMid,posRight);
    
    cout << minValueForFinalResult;
    return 0;
}