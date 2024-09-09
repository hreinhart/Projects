#include <iostream>  
#include <string>  
#define max 8 // define the max string  
using namespace std;  
  
string strings[max]; // define max string  
  
// length of the string  
int len(string str)  
{  
    int length = 0;  
    for (int i = 0; str[i] != '\0'; i++)  
    {  
        length++;  
          
    }  
    return length;     
}  
  
// create custom split() function  
void split (string str, char seperator)  
{  
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= len(str))  
    {  
        if (str[i] == seperator || i == len(str))  
        {  
            endIndex = i;  
            string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
        }     
}  
  
int main()  
{  
    string str = "Program, to split strings using custom split function.";  
    char seperator = ' '; // space  
    split(str, seperator);  
    cout <<" The split string is: ";  
    for (int i = 0; i < max; i++)  
    {  
        cout << "\n i : " << i << " " << strings[i];  
    }  
    return 0;  
}  