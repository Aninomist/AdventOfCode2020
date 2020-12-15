#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>
#include <regex>

using namespace std;

vector<int> num;



int main() {

    std::string line;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        num.push_back(stoll(line));
    }
    num.push_back(0);

    sort(num.begin(), num.end());
    int device = *(num.end() - 1) + 3;
    num.push_back(device);


    int diffWay = 1;
    vector<int> diffWayOnNum;
    for(int i : num){
        int track = 0;
        if(find(num.begin(), num.end(), i+1) != num.end()) track++;
        if(find(num.begin(), num.end(), i+2) != num.end()) track++;
        if(find(num.begin(), num.end(), i+3) != num.end()) track++;
        if(track != 0) {
            diffWay *= track;
        } else track = 1;

        diffWayOnNum.push_back(track);
    }

    //backtrack
    int total = diffWayOnNum.size();
    long long int backTrack[diffWayOnNum.size()];
    for(int i = 0; i < total; i++) {
        backTrack[i]=0;
    }

    backTrack[total - 1] = 1;
    backTrack[total - 2] = 1;
    backTrack[total - 3] = 1;

    for(int i = 4; i <= total ; i++){
        backTrack[total - i] = 0;
        int toTrack = diffWayOnNum[total - i];
        for(; toTrack >= 1; toTrack--){
            backTrack[total - i] += backTrack[total - i + toTrack];

        }
    }


    cout << backTrack[0];


}

