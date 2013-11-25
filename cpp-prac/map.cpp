#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    map<int, string> People;

    //Assign using array notation
    People[3240] = "John";
    People[1235] = "Mary";
    People[1593] = "Jorge";
    People[2111] = "Mariano";

    for (map<int,string>::iterator ii=People.begin();ii!=People.end();++ii)
    {
        cout << ii->first << ": " << ii->second << endl;
    }
}
