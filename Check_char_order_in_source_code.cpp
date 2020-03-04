/*  Check char order in source code v1 - check if str has char in correct order.

    Correct char order example:      { ( [ ] ) }     { ( ) [ ] }     { } [ ( ) ]        ( [ ] { } )         [ ] ( { } ) .

    Incorrect char order example:    { ) ] [ ( }     { [ ( ] ) }     { } [ ( ) }        ( [ ] } { )         { ( ] } ( ) .
*/

#include <iostream>                     //Standard input output library.
#include <string>                       //Library for .length() .
#include <vector>                       //Library for vector container.
#include <cstdlib>                      //Library for getchar() .

using namespace std;

string str;

vector<char> Char_arr;

bool Check_array()
{
    if (Char_arr.size() % 2 == 0 && Char_arr.size() >= 2)
    {
        while (Char_arr.size() >= 2)
        {
            bool not_found = true;

            for (unsigned int i = 1; i < Char_arr.size(); i++)
            {
                if ((int(Char_arr.at(0)) + 2 == int(Char_arr.at(i)) && (i % 2) != 0) || (int(Char_arr.at(0)) + 1 == int(Char_arr.at(i)) && (i % 2) != 0))
                {
                    Char_arr.erase(Char_arr.begin() + i);

                    Char_arr.erase(Char_arr.begin());

                    not_found = false;

                    break;
                }
            }

            if (not_found)
            {
                return false;
            }
        }
    }

    else
    {
        return false;
    }

    return true;
}

int main()
{
    str = { "{([])}" };

    int len = str.length();

    for (int a = 0; a < len; a++)
    {
        Char_arr.push_back(str[a]);
    }

    if (Check_array())
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;
    }

    getchar();

    return 0;
}