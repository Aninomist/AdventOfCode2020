#include iostream
#include vector
#include algorithm

using namespace std;

int pcount = 0;

void parseline(const stdstring& input) {
    stdstring line = input;

    stdstring delim1 = -;
    size_t pos1 = line.find(delim1);
    stdstring int1 = line.substr(0, pos1);
    int lower = stoi(int1);
    line.erase(0, line.find(delim1) + delim1.length());


    stdstring delim2 =  ;
    size_t pos2 = line.find(delim2);
    stdstring int2 = line.substr(0, pos2);
    int upper = stoi(int2);
    line.erase(0, line.find(delim2) + delim2.length());



    stdstring delim3 =  ;
    size_t pos3 = line.find(delim3);
    stdstring char3 = line.substr(0, pos3);
    line.erase(0, line.find(delim3) + delim3.length());


    char match = char3[0];


    int numOcc = stdcount(line.begin(), line.end(), match);

    if(line[upper - 1] == match ^ line[lower - 1] == match) {
        pcount++;
        stdcout  yes  endl;
    }


}

int main() {
    stdvectorint input;

    stdstring line;


    while(stdgetline(stdcin,line)){
        if (line == end)break;
        parseline(line);
    }

    stdcout  pcount;

}