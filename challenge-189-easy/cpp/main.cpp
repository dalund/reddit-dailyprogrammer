#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;


vector<string> readWordsFile() {
  ifstream fin("/usr/share/dict/words");
  vector<string> words;
  string str;
  while(fin >> str) {
    words.push_back(str); 
  }
  return words;
}


string getRandomWord(const vector<string>& allWords) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, allWords.size());
  string word = allWords[dis(gen)];

  return word;
}

int main() {

  vector<string> words = readWordsFile();
  map<char, bool> wordState;
  string gameWord = getRandomWord(words);
  for (auto c : gameWord) {
    wordState[c] = false;
  }

  bool runGame = true;
  char nextGuess;
  // Game loop
  while(runGame) {
    cout << " This is your progress so far";
    for (auto c : gameWord) {
      if(wordState[c]) {
        cout << c << " ";
      } else {
        cout << "_ ";
      }
    }
    cout << " What is your next guess? ";
    cin >> nextGuess;
  }
  return 0;
} 
