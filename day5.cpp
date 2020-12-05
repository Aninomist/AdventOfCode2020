#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>

using namespace std;


int parseLine(const string& line){
    string first7 = line.substr(0, 7);
    //cout << first7 <<endl;
    string last3 = line.substr(7, 3);
    //cout << last3 << endl;

    int row = 0;
    int digit = 6;
    for (char &c : first7){
        if (c=='B') row += pow(2, digit);
        digit--;
    }

    int col =0;
    int digit2 = 2;
    for (char &c : last3){
        if (c=='R') col += pow(2, digit2);
        digit2--;
    }

    return row*8+col;
}




int main() {
    //0 for open, 1 for tree
    int highest = 0;

    std::string line;
    std::vector<int> seats;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        int id = parseLine(line);
        seats.push_back(id);

        if ( id > highest) highest = id;
    }

    std::sort(seats.begin(), seats.end());
    int placeholder = 1;
    bool found = false;
    while (!found) {
        if(seats[placeholder] != seats[placeholder - 1] + 1) {
            found = true;
            cout << endl << seats[placeholder] - 1;
        }

        placeholder++;
    }

   //cout << highest;

}

