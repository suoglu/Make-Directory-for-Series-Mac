#include <iostream>
#include <string>
#include <string.h>
#include <sys/stat.h>

using namespace std;

char numToStr(int num)
//only used to convert single digit number to char
{
    if(num < 0 | num > 9)
    {
        cout << "Use single digit\n";
    }
    return (num + 48);
}

string intToStr(int i)
//converts integer to string
{
    string result = "";
    
    if(i == 0)
        return "0";
    
    while(i != 0)
    {
        result = numToStr(i % 10) + result;
        i = i / 10;
    }
    
    return result;
}


int main(int argc, char const *argv[])
{
    
    string path = getenv("USER");
    path = "/Users/" + path + "/Desktop/";
    
    cout << "Series name: ";
    string hold;
    
    getline(cin, hold);
    
    
    path = path + hold;
    
    cout << "Season number: ";
    int s, e;
    cin >> s;
    cout << "Episode count: ";
    cin >> e;
    
    mkdir(path.c_str(), ACCESSPERMS);
    cout << "Making...\n";
    cout << path << endl;
    path = path + "/s" + intToStr(s);
    mkdir(path.c_str(), ACCESSPERMS);
    cout << path << endl;
    path = path + "/e";
    for(int j = 1; j <= e; j++)
    {
        hold = path + intToStr(j);
        mkdir(hold.c_str(), ACCESSPERMS);
        cout << hold << endl;
    }
    
    
  return 0;
}
