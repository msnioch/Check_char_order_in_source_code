/*  Check char order in source code v1 - check if file has char in correct order.

    Correct char order example:      { ( [ ] ) }     { ( ) [ ] }     { } [ ( ) ]        ( [ ] { } )         [ ] ( { } ) .

    Incorrect char order example:    { ) ] [ ( }     { [ ( ] ) }     { } [ ( ) }        ( [ ] } { )         { ( ] } ( ) .
*/

#include <iostream>     //Standard input output library.
#include <string>       //Library for .length() .
#include <list>         //Library for list container.
#include <fstream>      //Library for external files.
#include <cstdlib>      //Library for getchar() .

using namespace std;

string file_patch;

fstream file;

list<char> Char_arr;

bool Check_array()
{
    if (Char_arr.size() % 2 == 0 && Char_arr.size() >= 2)
    {
        while (Char_arr.size() >= 2)
        {
            list<char>::iterator it = Char_arr.begin();

            bool not_found = true;

            int i = 0;

            for (advance(it, 1); it != Char_arr.end(); it++)
            {
                i++;

                if ((int(*Char_arr.begin()) + 2 == int(*it) && (i % 2) != 0) || (int(*Char_arr.begin()) + 1 == int(*it) && (i % 2) != 0))
                {
                    Char_arr.erase(it);

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

bool Check_File_Patch(string& patch)                                        //Check if Question.txt patch is correct.
{
    file.open(patch, ios::in);                                              //Open file to read.

    if (!file.good())                                                       //If patch isn't correct.
    {
        cout << "\nWrong file patch!\nPlease write the correct file patch or write END then press ENTER to exit application: ";

        cin >> patch;                                                       //Change patch or exit application with END.

        if (patch == "END")
        {
            exit(0);                                                        //Exit application.
        }

        return false;                                                       //If Question.txt patch isn't correct return false.
    }

    else
    {
        file.close();                                                       //Close file.

        return true;                                                        //If Question.txt patch is correct return true.
    }
}

void Save_File_Char(string file_patch)
{
    string current_line;

    file.open(file_patch, ios::in);                                         //Open file to read.

    while (getline(file, current_line))
    {
        int char_number = current_line.length();

        for (int current_char = 0; current_char < char_number; current_char++)
        {
            if (current_line[current_char] == '{' || current_line[current_char] == '}' ||

                current_line[current_char] == '(' || current_line[current_char] == ')' ||

                current_line[current_char] == '[' || current_line[current_char] == ']')
            {
                Char_arr.push_back(current_line[current_char]);
            }
        }
    }

    file.close();                                                           //Close file.
}

int main()
{
    cout << "Please enter file patch to check:";

    cin >> file_patch;

    while (!Check_File_Patch(file_patch));

    Save_File_Char(file_patch);

    if (Check_array())
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;
    }

    getchar();      getchar();

    return 0;
}