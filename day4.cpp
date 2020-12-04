#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>

using namespace std;



bool parseCredential(string credential) {
    credential.erase(0, 1);
    //std::cout << credential;

    std::vector<string> fields;
    int counter = 0;
    bool hasCid = false;

    while(!credential.empty()){
        string delim = " ";
        size_t col = credential.find(delim);
        string field = credential.substr(0, col);
        credential.erase(0, col + 1);
        fields.push_back(field);
    }

    for(string field : fields) {
        string first3char = field.substr(0, 3);
        field.erase(0, 4);

        if (first3char == "cid"){
            hasCid = true;
            counter++;
        }

        if(first3char == "byr") {
            int year = stoi(field);
            if(year >=1920 && year <= 2002)
                counter++;
        }

        if(first3char == "iyr") {
            int year = stoi(field);
            if(year >=2010 && year <= 2020)
                counter++;
        }

        if(first3char == "eyr") {
            int year = stoi(field);
            if(year >=2020 && year <= 2030)
                counter++;
        }

        if(first3char == "hgt") {
            string measure = field.substr(field.size() - 2);
            if(measure == "cm"){
                field.erase(field.size() - 2);
                int height = stoi(field);
                if(height >=150 && height <=193)
                    counter++;
            } else if(measure == "in") {
                field.erase(field.size() - 2);
                int height = stoi(field);
                if(height >= 59 && height <= 76)
                    counter++;
            }
        }

        if(first3char == "hcl") {
            if(field[0] == '#') {
                field.erase(0, 1);
                if(std::string::npos == field.find_first_not_of("0123456789abcdef"))
                    counter++;
            }
        }

        if(first3char == "ecl") {
            if(field == "amb") {
                counter++;
            }else if(field == "blu"){
                counter++;
            }else if(field == "brn"){
                counter++;
            }else if(field == "gry"){
                counter++;
            }else if(field == "grn"){
                counter++;
            }else if(field == "hzl"){
                counter++;
            }else if(field == "oth"){
                counter++;
            }
        }

        if(first3char == "pid") {
            if(field.size() ==9 && std::string::npos == field.find_first_not_of("0123456789"))
                counter++;
        }
    }

    return (counter == 8 || (counter == 7 && !hasCid));

}



int main() {
    //0 for open, 1 for tree


    std::string line;
    std::string credential;
    int counter = 0;

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        if(!line.empty()){
            credential += " ";
            credential += line;
         } else {
            credential += " ";
            if (parseCredential(credential))
                counter++;
            credential = "";

        }
    }

    cout << counter;

}

