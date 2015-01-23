#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsISBN(string isbn) {
    // Remove all dashes
    isbn.erase(remove(isbn.begin(), isbn.end(), '-'), isbn.end());

    if (isbn.length() != 10 || isbn.find_first_not_of("0123456789X") != string::npos ) {
        return false;
    }

    int i = 10;
    int a = 0;
    for (auto c : isbn) {
        if (c == 'X') {
            a += 10;
        } else {
            a += (i-- * (c - '0') ); // c-'0' converts to int
        }

    }

    return !(a % 11);
}

int main()
{
    cout << IsISBN("0-7475-3269-9") << endl;

    return 0;
}
