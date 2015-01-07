#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
    transform(istream_iterator<char>(cin), istream_iterator<char>(), ostream_iterator<string>(cout), [](char const& c)->string{});

    return 0; 
}
