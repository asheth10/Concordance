#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include "concordance.h"

using namespace std;
using namespace CS_concordance;

string get_word(ifstream& infile);

int main()
{
    concordance c;
    const char *s;
    string check;//to check for a word in the concordance
    char answer;//to take user input as y or n
    ifstream inf;
    concordance::word w;
    char inp_file[50];

    cout<<"Enter an input file name: ";
    cin>>inp_file;
    inf.open(inp_file);
    while(!inf)
    {
        cout<<"Please return a valid input file: ";
        cin>>inp_file;
        inf.open(inp_file);
    }
    while(!inf.eof())
    {
        s=get_word(inf).c_str();
        if(isalpha(s[0]))
        {
              strcpy(w,s);
            c.insert(w);
        }

        }
        inf.close();
        cout<<"Do you want to view the concordance?(y/n): ";
        cin>>answer;
        cout<<endl;
        if((answer=='y'||answer=='Y')&& c.length()!=0)
    {
        c.print();
        cout<<"This file contains "<<c.length()<<" distinct words."<<endl<<endl;
    }
    if(c.length()==0)
    {
        cout<<"No text in the file."<<endl;
        return EXIT_SUCCESS;
    }

    cout<<"Do you want to check occurrence of a word in the concordance?(y/n): ";
    cin>>answer;
    cout<<endl;
    while(answer=='y'|| answer=='y')
    {
    cout<<"Enter a word to check the number of time it appears in the concordance: ";
        cin>>check;
        s=check.c_str();
        strcpy(w,s);
        cout<<endl<<"The word "<<check<<" appears "<<c.get_count(w)<<" times"<<endl<<endl;
        cout<<"Look up the count for another word?(y/n): ";
        cin>>answer;
        cout<<endl;
    }
return EXIT_SUCCESS;
}

string get_word(ifstream& infile)
{
    string s;
    int i=0;
    char ch;
    infile.get(ch);
    while(!isalpha(ch)&&!infile.eof())//while not alphabet and not the end of file
        infile.get(ch);//read a character
    while(isalpha(ch)&&!infile.eof()&&s.size()<8)
    {
        s+=tolower(ch);
        infile.get(ch);
    }
    if(s.size()==8)//if length of word is 8 letters
    {
        while(isalpha(ch))
            infile.get(ch);//ignore all following letters
    }
     return s;//return the word
}
