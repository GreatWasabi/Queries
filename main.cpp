#include <iostream>
#include <fstream>
#include <sstream>
#include "maxheap.h"
#include "earnings.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    fstream file;
    file.open("queries.txt");
    fstream FILE;
    FILE.open("Occupation-Dist-All-1999.csv",ios::in);
    string String;
    while(file.good())
    {
        getline(file, String);
        stringstream stream(readInput(String));
        string word;
        string category;
        string value;
        stream >> word;
        stream >> category;
        stream >> value;
        string query = "find " + word + " " + category + " " + value;
        if(word == "max")
        {
            SOC *findMax = new SOC[NUM_OCC];
            string max_string;
            for (int line_num = 0; getline(FILE, max_string) && line_num <= 4; line_num++)
                if (line_num == 4)
                    break;
            if (file.is_open())
                for (int line_num = 0; getline(FILE, max_string); line_num++)
                    readingCSV(max_string, findMax[line_num]);
            buildMaxHeap(findMax, NUM_OCC, category);
            if(category == "men")
            {
                cout << "Query: " << query << endl << endl;
                cout << "Top " << value <<" occupations in 1999 for male workers:" << endl;
                extractMaxMen(findMax, NUM_OCC, stoi(value));
            }
            else if(category == "women")
            {
                cout << "Query: " << query << endl << endl;
                cout << "Top " << value <<" occupations in 1999 for female workers:" << endl;
                extractMaxWomen(findMax, NUM_OCC, stoi(value));
            }
            else
            {
                cout << "Query: " << query << endl << endl;
                cout << "Top " << value <<" occupations in 1999 for total workers:" << endl;
                extractMaxTotal(findMax, NUM_OCC, stoi(value));
            }
            delete[] findMax;
            FILE.close();
        }
        cout << endl;
    }
}
