#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>
#include <regex>

using namespace std;

class ins{
public:
    string arg;
    bool next;
    int number;
    bool visited;
};

vector<ins> exe;
int acc = 0;


int parseLine(string& line) {
    string lineCpy = line;
    ins instruction;
    instruction.arg = line.substr(0, 3);
    instruction.next = (line[4] == '+');
    instruction.number = stoi(lineCpy.erase(0, 5));
    instruction.visited = false;
    exe.push_back(instruction);
}

int execute(ins& instruction){
    if (instruction.visited)
        return 0;
    else
        instruction.visited = true;

    if(instruction.arg == "acc") {
        if(instruction.next)
            acc += instruction.number;
        else
            acc -= instruction.number;

        return 1;
    }

    if(instruction.arg == "jmp") {
        if(instruction.next)
            return instruction.number;
        else
            return -instruction.number;
    }

    return 1;
}


int main() {

    std::string line;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        parseLine(line);
    }

    bool correct = false;
    int tracker = 0;
    while (!correct){
        acc = 0;
        vector<ins> copy = exe;
        int search = tracker;
        while(copy[search].arg == "acc"){
            search++;
        }

        if(copy[search].arg == "nop")
            copy[search].arg = "jmp";
        else
            copy[search].arg = "nop";

        tracker = search + 1;

        bool run = true;
        int current = 0;
        while(run){
            if(current == exe.size() - 1) {
                correct = true;
                run = false;
                execute(copy[current]);
            }
            else if(current >= 0 && current <= exe.size() - 1){
                int i = execute(copy[current]);
                if(i != 0){
                    current += i;
                } else run = false;
            } else run = false;
        }


    }


    cout << acc;
}

