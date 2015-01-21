#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <map>

using namespace std;

class Hangman
{
public:
  Hangman();
  virtual ~Hangman();

  void initGame();
  void startGame();


private:
  string randomWord();
  bool finished();
  map<char, bool> blankWord(string w);
  bool m_cont;
  vector<string> wordList;
  map<char, bool> letters;
  string word;
};

bool Hangman::finished() {
  int i = 0;
  bool finished = false;
  for (auto kv : letters) {
    if (kv.second) {
      i++;
    }
  }

  if (i == letters.size())
    finished = true;

  return finished;
}

void Hangman::initGame() {
  cout << "Welcome to the hangman game " << endl;
  cout << "To quit press C-q " << endl;

  ifstream fin("/usr/share/dict/words");
  if (!fin.is_open()) {
    cout << "no word file" << endl;
  }
    
  string str;
  while(fin >> str) {
    wordList.push_back(str);
  }

  word = randomWord();
  letters = blankWord(word);

}


void Hangman::startGame() {

  string  input;
  while(m_cont) {

    cout << "this is how is is looking blanked: ";
    for (auto c : word) {
      if(letters[c]) {
        cout << c;
      } else {
        cout << "_ " ;
      }
    }
    cout << endl;

    cout << " what is your guess? " << endl;

    char guess;
    cin >> guess;
    auto search = letters.find(guess);
    
    if (search != letters.end()) {
      letters[guess] = true;
    } else {
      cout << " I am sorry, your guess was incorrect" << endl;

    }


    
  if(finished()) {
    cout << "CONGRATS! you solved it" << endl;
    m_cont = false;
  } else {
    // TODO check for nr of tries
  }
  }
  
  
}

Hangman::Hangman()
  : m_cont(true)
{
}

Hangman::~Hangman() {
  // TODO implement me
}


string Hangman::randomWord() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, wordList.size());
  string word =  wordList[dis(gen)];
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
  
}

map<char, bool> Hangman::blankWord(string word) {
  map<char, bool> m;
  for (auto c : word) {
    m[c] = false;
  }
  return m;
}

int main()
{
  Hangman hangman;
  hangman.initGame();
  hangman.startGame();
  
  return 0;
}
