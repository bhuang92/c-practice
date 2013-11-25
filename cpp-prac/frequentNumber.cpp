#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{  
    ifstream readFile("example");
    int length;
    readFile >> length; // store the length, first entry
    int example[length]; //initialize the array
    
    for (int i = 0; i<length; i++) 
    {
        readFile>>example[i];
        printf("Stored %d\n", example[i]);
    }

    readFile.close();
    
    //int example[] = {0,0};
    //int length = sizeof(example)/sizeof(int);
    int max=example[0];

    map<int, int> NumberCount;
    for (int i=0;i<length;i++) {
        if(NumberCount[example[i]]==0)
            NumberCount[example[i]]=1;
        else
            NumberCount[example[i]]++;
            if( (i>0) && (NumberCount[example[max]] < NumberCount[example[i]])) 
                max = example[i];
    }
    printf("The most frequent number is %d.\n", max);
    return 0;
}
