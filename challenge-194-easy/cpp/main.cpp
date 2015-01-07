 #include <iostream>
 #include <string>
 #include <iterator>
 #include <algorithm>
 using namespace std;
int main()
{
    transform(istream_iterator<char>(cin), istream_iterator<char>(), ostream_iterator<string>(cout), [](char const& c)->string{
            static bool escaped = false;
            static bool opened = false;
            if (escaped)
            {
                escaped = false;
                switch(c)
                {
                    case '\\':
                        return "\\";
                        break;
                    case '\"':
                        return "\"";
                        break;
                    case 'n':
                        return "\n";
                        break;
                    default:
                        throw invalid_argument(string() + c);
                        break;
                }
            }
            else if(c ==  '"')
            {
                opened = !opened;
                return "";
            }
            else if(!opened)
            {
                if(!isspace(c))
                {
                    throw invalid_argument(string() + c);
                }

                return "";
            }
            else if(c == '\\')
            {
                escaped = true;
                return "";
            }
            else
            {
                return string() + c;
            }
        });

    return 0; 
}
