#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>
#include <regex>

using namespace std;

vector<long long int> num;

const int consider = 25;
int tracker = 25;



int main() {

    std::string line;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        num.push_back(stoll(line));
    }

    bool found = false;
    while(!found){
        long long int target = num[tracker];
        vector<long long int> toSearch(num.begin() + tracker - consider, num.begin() + tracker);
        bool valid = false;
        for(long long int a : toSearch){
            long long int b = target - a;
            auto it = find (toSearch.begin(), toSearch.end(), b);
            if(it != toSearch.end() && *it != a){
                valid = true;
                break;
            }
        }
        if(valid) tracker++;
        else found = true;
    }

    //part 2
    long long int invalid =num[tracker];
    tracker = 0;
    long long int small = 0;
    long long int big = 0;


    bool found2 = false;
    while(!found2){
        vector<int> numVec;
        long long int sum = 0;
        long long int toAdd = tracker;

        while (sum <= invalid){
            if (sum == invalid){
                sort(numVec.begin(), numVec.end());
                small = *numVec.begin();
                big = *(numVec.end() - 1);
                found2 = true;
                break;
            }

            sum += num[toAdd];
            numVec.push_back(num[toAdd]);
            toAdd++;
        }

        tracker++;
    }

    cout << small + big;

}

