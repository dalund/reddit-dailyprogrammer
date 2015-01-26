#include <vector>
#include <random>
#include <iostream>
using namespace std;





class PasswordGenerator {
public:

    PasswordGenerator(int len);

    string GeneratePassword();
private:

    char RandomChar();
    string m_validChars = "123456789";
    int m_len;
    uniform_int_distribution<> m_dis;
    mt19937 m_gen;

};

PasswordGenerator::PasswordGenerator(int len)
    : m_len(len)
{
    random_device rd;
    mt19937 gen(rd());
    m_gen = gen;
    uniform_int_distribution<> dis(0, m_validChars.length() - 1);
    m_dis = dis;
}



string PasswordGenerator::GeneratePassword() {
    string pass = "";
    for (int i = 0; i < m_len; i++) {
        char c = RandomChar();
        pass += c;
    }
    return pass;
}


char PasswordGenerator::RandomChar() {
    char c =  m_validChars[m_dis(m_gen)];
    return c;
 
}

int main()
{
    int N;
    int n;
    cout << "Welcome! How many passwords?" << endl;
    cin >> N;
    cout << "How long should they be? " << endl;
    cin >> n;


    PasswordGenerator* passwordGenerator = new PasswordGenerator(n);

    for (int i = 0; i < N; i++) {
        cout << passwordGenerator->GeneratePassword() << endl;
    }
    
    return 0;
}


