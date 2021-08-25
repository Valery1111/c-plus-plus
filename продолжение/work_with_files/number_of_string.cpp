#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("out.txt");
    string str, type1 = "//", type2 = "/*", type3 = "*/";
    size_t prostoy, slojn_otk, slojn_zak;
    if (!in.is_open())
    {
        cout << "FILE HAD NOT BEEN  READ!\n";
        return -1;
    }
    else
    {
        int flag = 0;
        while (in.eof() != 1)
        {
            getline (in, str);
            while ((str.find(type1) !=  string::npos) || (str.find(type2) !=  string::npos) ||  (flag == 1))
            {
                prostoy = str.find(type1);
                slojn_otk = str.find(type2);
                slojn_zak = str.find(type3);
                if (flag == 0)
                {
                    if (slojn_otk < prostoy)
                    {
                        if ((slojn_zak !=  string::npos))
                        {
                            str.erase (slojn_otk, slojn_zak + 2 );
                        }
                        else
                        {
                            str.erase (str.begin() + slojn_otk, str.end());
                            flag = 1;
                            break;
                        }
                    }
                    else
                    {
                        str.erase (prostoy);
                        break;
                    }
                }
                else
                {
                    if (slojn_zak !=  string::npos)
                    {
                        str.erase (0, slojn_zak + 2);
                        flag = 0;
                    }
                    else
                    {
                        str.erase (0);
                        break;
                    }
                }
            }
            if (str.empty() != 1)
                out << str << endl;
        }
    }
        in.close();
        out.close();
        system ("out.txt");
        return 0;
}
