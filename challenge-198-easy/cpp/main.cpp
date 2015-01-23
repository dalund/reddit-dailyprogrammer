#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string words;
    getline(cin, words);

    stringstream ss(words);


    string a, b, left, right;

    while (ss >> a >> b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(left));
        set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(right));
    }

    
    

    
    cout << "left: " << left << " right: " << right << endl;

    if (left.size() == right.size()) {
        cout << " It's a Tie!";
    } else {
        cout << (right.length() > left.length() ? "Right wins \n" :  "Left wins \n" );
    }
    
    cout << "Letters in the valley: " << left+right << endl;

    
    return 0;
}
