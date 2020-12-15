#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <string>
#include <math.h>
#include <unordered_map>
#include <regex>

using namespace std;

//0 empty, 1 occupied, 2 floor
vector<vector<int>> board;
vector<vector<int>> nextBoard;
int rowCount;
int colCount;
bool notSame = false;

void print() {
    for(auto i : board) {
        for(auto j : i) {
            if(j == 0) cout << 'L';
            if(j == 1) cout << '#';
            if(j == 2) cout << '.';
            std::cout <<  " ";
        }
        std::cout << endl;
    }
    std::cout<< "========================" << endl;
}

void nextIteration(){
    for(int row = 1; row < rowCount -1; row++) {
        for(int col = 1; col < colCount - 1; col++){
            int count = 0;

            //Top left
            int i = 1;
            bool found = false;
            while(!found){
                int rowToFind = row - i;
                int colToFind = col - i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            //Top
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row - i;
                int colToFind = col;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            //Top Right
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row - i;
                int colToFind = col + i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }


            //Bottom Left
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row + i;
                int colToFind = col - i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            //Bottom
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row + i;
                int colToFind = col;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            //Bottom Right
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row + i;
                int colToFind = col + i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            //Left
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row ;
                int colToFind = col - i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }
            // Right
            i = 1;
            found = false;
            while(!found){
                int rowToFind = row;
                int colToFind = col + i;
                if(rowToFind < 0 || colToFind < 0 || rowToFind > rowCount - 1 || colToFind > colCount - 1){
                    found = true;
                } else {
                    if(board[rowToFind][colToFind] == 1) {
                        count++;
                        found = true;
                    } else if(board[rowToFind][colToFind] == 0) {
                        found = true;
                    }
                }
                i++;
            }

            if(board[row][col] == 0 && count == 0) {
                nextBoard[row][col] = 1;
                notSame = true;
            }
            if(board[row][col] == 1 && count >= 5) {
                nextBoard[row][col] = 0;
                notSame = true;
            }

        }
    }
}



int main() {

    std::string line;

    board.emplace_back();

    while(std::getline(std::cin,line)){
        if (line == "end"){
            break;
        }
        vector<int> row;
        row.push_back(2);
        for(char i : line){
            if(i == 'L') row.push_back(0);
            else row.push_back(2);
        }
        row.push_back(2);
        board.push_back(row);
    }

    board.emplace_back();

    rowCount = board.size();
    colCount = board[1].size();

    for(int i = 0; i < colCount; i++) {
        board[0].push_back(2);
        board[board.size()-1].push_back(2);
    }

    //print();

    do {
        nextBoard = board;
        notSame = false;
        nextIteration();
        board = nextBoard;
        //print();
    } while(notSame);

    int numSeats = 0;
    for(int row = 1; row < rowCount -1; row++) {
        for (int col = 1; col < colCount - 1; col++) {
            if(board[row][col] == 1) numSeats++;
        }
    }

    cout << numSeats;





}

