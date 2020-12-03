#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


std::vector<std::vector<bool>> input;

int rightStep = 3;
int downStep = 1;
int entries;
int rowTotal;

void parseline(const std::string& line) {
    std::vector<bool> row;

    for (char const &c : line) {
        row.push_back(c == '#');
    }

    input.push_back(row);
}


int traverse(int right, int down) {
    rowTotal = input.size() - 1;
    int rowCurrent = 0;
    int colCurrent = 0;

    int trees = 0;

    while (rowCurrent < rowTotal) {
        rowCurrent += down;
        colCurrent = (colCurrent + right) % (entries + 1);

        if(rowCurrent <= rowTotal){
            if(input[rowCurrent][colCurrent]){
            trees++;
            //cout << "(" << rowCurrent << "," << colCurrent << ")" <<endl;
            }
        }
    }

    std::cout  <<right << "," << down << ":"<< trees << endl;

    return trees;
}



int main() {
    //0 for open, 1 for tree


    std::string line;


    while(std::getline(std::cin,line)){
        if (line == "end"){
            entries = input[0].size() - 1;
            std::cout << entries << endl;
            break;
        }
        parseline(line);
    }

//    for (const auto& it: input){
//        for (const auto& it2 : it){
//            std::cout << it2;
//        }
//        std::cout << std::endl;
//    }

    long int multiply = 1;

    multiply *= traverse(1,1);
    multiply *= traverse(3,1);
    multiply *= traverse(5,1);
    multiply *= traverse(7,1);
    multiply *= traverse(1,2);

    cout << endl << endl <<  multiply;



}

