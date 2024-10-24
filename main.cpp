#include <iostream>
using namespace std;

int solnum = 0; // declared globally so that I don't have to pass it as a parameter.

//Ok function from Dumb8queens
//No modification needed
bool ok(int arr[], int x) {
    for (int i = 0; i < x; i++) {
        if (arr[x] == arr[i] || (x - i) == abs(arr[x] - arr[i])) {
            return false;  // Conflict found
        }
    }
    return true;  // No conflict found
}

//Print function from 8Queens1D with gotos
void print(int Q[]) {
    solnum++;
    cout << "Solution Number: #" << solnum << "#" << endl;

//1D Array representation
    cout << "Array Representation" << endl;
    //Changed to for loop instead of a range based because Array decays into pointer.
    for(int i=0; i<8; i++){
        cout << Q[i] << " ";
    }
    cout << endl;

//8x8 board representation
    cout << "Board Representation: " << endl;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (Q[r] == c) {
                cout << " Q ";
            } else {
                cout << " _ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//Using recursive function from 8Numbers and modifying it to place 8 queens.
//Removed helper array
void placequeens(int queen[], int row){
    if (row==8) {
        print(queen); // print the result
        return;
    }
    for (int i = 0; i<8; i++){
        queen[row]= i; // place the number
        if (ok(queen, row)) placequeens(queen, row+1); // if the number is valid, move onto next square.
    }
}

int main(){
    int q[8]{0};
    placequeens(q, 0);
    return 0;
}