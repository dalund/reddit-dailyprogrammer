#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
  map<string, int> occurences;
  string str;
  ifstream fin("book.txt");
  while(fin >> str){
    occurences[str] += 1;
  }

  for(auto kv : occurences)
    cout << kv.first << " : " << kv.second << endl;

}
