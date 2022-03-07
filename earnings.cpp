#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "earnings.h"

string readInput(string str)
{
    stringstream stream(str);
    string word;
    string result = " ";
    int i = 1;
    while (stream >> word)
    {
        if (i == 2)
        {
            if (word == "ratio")
            {
                result = word;
            }
            else{
                result = word;
            }
        }
        if (i == 3 || i == 4)
        {
            result = result + " " + word;
        }
        i++;
    }
    return result;
}
