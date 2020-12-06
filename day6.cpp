#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;


int parseLine(const string& line, int numPeople){
    unordered_map<char, int> map;

    for(char i : line) {
        map[i]++;
    }

    int count = 0;
    for(const auto &[ key, value ] : map){
        if(value == numPeople) count++;
    }

    return count;
}




int main() {
    //0 for open, 1 for tree
    int count = 0;

    std::string line;
    std::vector<int> seats;

    std::string group;
    int numPeople = 0;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        if(!line.empty()){
            numPeople++;
            group += line;
        } else {
            count += parseLine(group, numPeople);
            group = "";
            numPeople = 0;
            //std::cout << count << endl;
        }
    }


   cout << count;

}

