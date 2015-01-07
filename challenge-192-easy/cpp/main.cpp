#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#


using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}


int main() {

  string sampleInput = "23+9+66";

  vector<string> numbersString = split(sampleInput, '+');

  return 0;

}
