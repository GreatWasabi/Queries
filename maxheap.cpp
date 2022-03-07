#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "maxheap.h"

using namespace std;

string Add_Comma(int x)
{
    string Str;
    stringstream string_stream;
    string_stream << x;
    Str = string_stream.str();
    int len = Str.length();
    for(int i=len-3;i>0;i-=3)
    {
        Str.insert(i, ",");
    }
    return Str;
}

void maxheapifyMen(SOC Array[], int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2;

    if(Array[largest].male<Array[l].male && n>l)
        largest = l;

    if(Array[largest].male<Array[r].male && n>r)
        largest = r;

    if(largest != i)
    {
        SOC temp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = temp;
        maxheapifyMen(Array, n, largest);
    }
}
void maxheapifyWomen(SOC Array[], int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2;

    if(Array[largest].female<Array[l].female && n>l)
        largest = l;

    if(Array[largest].female<Array[r].female && n>r)
        largest = r;

    if(largest != i)
    {
        SOC temp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = temp;
        maxheapifyWomen(Array, n, largest);
    }
}

void maxheapifyTotal(SOC Array[], int n, int i)
{
    int largest = i, l = 2*i+1, r = 2*i+2;

    if(Array[largest].total<Array[l].total && n>l)
        largest = l;

    if(Array[largest].total<Array[r].total && n>r)
        largest = r;

    if(largest != i)
    {
        SOC temp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = temp;
        maxheapifyTotal(Array, n, largest);
    }
}

void buildMaxHeap(SOC Array[], int n, string keyword)
{
    if(keyword == "men")
    {
        for(int i = n/2 - 1 ; i >= 0 ; i--)
            maxheapifyMen(Array, n, i);
    }
    else if(keyword == "women")
    {
        for(int i = n/2 - 1 ; i >= 0 ; i--)
            maxheapifyWomen(Array, n, i);
    }
    else //if(keyword == "total")
    {
        for(int i = n/2 - 1 ; i >= 0 ; i--)
            maxheapifyTotal(Array, n, i);
    }
}

void extractMaxMen(SOC Array[], int size, int Number_of_Occupations)
{
    int i = 0;
    string Result = "";
    while(i < Number_of_Occupations)
    {
        if (size == 0)
            return;
        SOC temp = Array[0];
        Array[0] = Array[size - 1];
        Array[size - 1] = temp;
        size--;
        buildMaxHeap(Array, size, "men");
        i++;
        Result = Result + "\t" + Array[size].occupation + ": " + Add_Comma(Array[size].male) + "\n";
    }
    cout << Result;
}

void extractMaxWomen(SOC Array[], int size, int Number_of_Occupations)
{
    int i = 0;
    string Result = "";
    while(i < Number_of_Occupations)
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            Result = Result + to_string(Array[0].female) + "\n";
            cout << Result;
            size--;
        }
        SOC temp = Array[0];
        Array[0] = Array[size - 1];
        Array[size - 1] = temp;
        size--;
        buildMaxHeap(Array, size, "female");
        i++;
        Result = Result + "\t" + Array[size].occupation + ": " + Add_Comma(Array[size].female) + "\n";
    }
    cout << Result;
}

void extractMaxTotal(SOC Array[], int size, int Number_of_Occupations)
{
    int i = 0;
    string Result = "";
    while(i < Number_of_Occupations)
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            Result = Result + to_string(Array[0].total) + "\n";
            cout << Result;
            size--;
        }
        SOC temp = Array[0];
        Array[0] = Array[size - 1];
        Array[size - 1] = temp;
        size--;
        buildMaxHeap(Array, size, "total");
        i++;
        Result = Result + "\t" + Array[size].occupation + ": " + Add_Comma(Array[size].total) + "\n";
    }
    cout << Result;
}

void readingCSV(string line, SOC &Array)
{
    int count = 1;
    string occupation;
    int male;
    int female;
    int total;
    string soc;
    stringstream string_stream(line);
    while (string_stream >> std::ws) {
        std::string csv_element;

        if (string_stream.peek() == '"')
        {
            string_stream >> quoted(csv_element);
            if(count == 1)
            {
                for(int i = 0; i < csv_element.length(); i++)
                    Array.occupation[i] = csv_element[i];
                occupation = csv_element;
                count++;
            }
            else if(count == 2)
            {
                for(int i = 0; i < csv_element.length(); i++)
                    Array.SOC_code[i] = csv_element[i];
                soc = csv_element;
                count++;
            }
            else if(count == 3)
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.male = stoi(csv_element);
                female = stoi(csv_element);
                count++;
            }
            else if(count == 4)
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.female = stoi(csv_element);
                male = stoi(csv_element);
                count++;
            }
            else
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.total = stoi(csv_element);
                total = stoi(csv_element);
                count=1;
            }
            string discard;
            getline(string_stream, discard, ',');
        }
        else
        {
            std::getline(string_stream, csv_element, ',');
            if(count == 1)
            {
                for(int i = 0; i < csv_element.length(); i++)
                    Array.occupation[i] = csv_element[i];
                occupation = csv_element;
                count++;
            }
            else if(count == 2)
            {
                for(int i = 0; i < csv_element.length(); i++)
                    Array.SOC_code[i] = csv_element[i];
                soc = csv_element;
                count++;
            }
            else if(count == 3)
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.male = stoi(csv_element);
                female = stoi(csv_element);
                count++;
            }
            else if(count == 4)
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.female = stoi(csv_element);
                male = stoi(csv_element);
                count++;
            }
            else
            {
                csv_element.erase(remove(csv_element.begin(), csv_element.end(), ','), csv_element.end()); // imp
                Array.total = stoi(csv_element);
                total = stoi(csv_element);
                count=1;
            }
        }
    }
}

void initialize(SOC Array[], int size)
{
        for(int i = 0; i < NUM_OCC; i++)
        {
            Array[i].occupation[0] = ' ';
            Array[i].SOC_code[0] = ' ';
            Array[i].total = 0;
            Array[i].female = 0;
            Array[i].male = 0;
        }
}
