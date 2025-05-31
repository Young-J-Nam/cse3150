#include <iostream>
#include <algorithm>
#include <vector>

#include "MyIntArrow.h"

using namespace std;

auto isPerfect = [](int candidate) -> bool {
    bool perfectInt = true;
    int sum = 1;
    
    for (int i = 2; i < candidate; i++){
        if (0 == (candidate % i)) {
            sum += i;
        }
    }

    return (sum == candidate);
};

int main() {
    
    string inData;

    cout << "Enter an Integer" << endl;

    cin >> inData;

    int test = stoi(inData);

    if (isPerfect(test)) {
        cout << test << " is perfect" << endl;
    }
    else {
        cout << test << " is not perfect" << endl;
    }

    return 0;
}