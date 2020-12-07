#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>
#include <regex>

using namespace std;

class contain{
public:
    string color;
    int number;
};

map<string, vector<contain>> rules;


int parseLine(const string& line) {
    std::string rule = line;
    rule.pop_back();
    std::string delim1 = " bags contain ";
    int first = rule.find(delim1);
    std::string token = rule.substr(0, first);
    rule.erase(0, first + delim1.length());

    if(rule == "no other bags") {
        //cout << "no other bags";
        return 0;
    }

    //cout << token << endl << rule;

    std::string delim2 = ", ";
    int start;
    int end = 0;
    vector<string> out;
    while ((start = rule.find_first_not_of(delim2, end)) != std::string::npos)
    {
        end = rule.find(delim2, start);
        out.push_back(rule.substr(start, end - start));
    }

    vector<contain> contains;
    for(auto i : out) {
        int num = i[0] - 48;
        string color = i.substr(2, i.find(" bag") - 2);
        //std::cout << color<< " " << num << endl;
        contain bag;
        bag.color = color;
        bag.number = num;
        contains.push_back(bag);
    }

    rules.insert(pair<string, vector<contain>>(token, contains));

    return 1;
}

bool DFS(contain contains) {
    string toFind = contains.color;
    if (toFind == "shiny gold") return 1;
    auto it = rules.find(toFind);
    if( it == rules.end()){
        return false;
    } else {
        vector<contain> moreBags = it->second;
        for(contain i : moreBags){
            if (DFS(i) == 1) return true;;
        }
        return false;
    }
}

int DFS_count(contain contains, int multiply) {
    string toFind = contains.color;
    auto it = rules.find(toFind);
    if( it == rules.end()){
        return multiply;
    } else {
        int temp_count = 1;
        vector<contain> moreBags = it->second;
        for(contain i : moreBags){
            temp_count += DFS_count(i,i.number);
        }
        return temp_count*multiply;
    }
}


int main() {
    //0 for open, 1 for tree
    int count = 0;

    std::string line;
    std::vector<int> seats;


    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        parseLine(line);
    }


//    for(const auto &[key, contains] : rules) {
//        bool has = false;
//        for(auto contain : contains){
//            if(DFS(contain)) {
//                has = true;
//            }
//        }
//        if(has) count++;
//    }


    auto it = rules.find("shiny gold");
    vector<contain> shinyGold = it->second;
    for(auto contain : shinyGold){
        count += DFS_count(contain, contain.number);
    }

    cout << count;
}

