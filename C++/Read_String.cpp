#include <iostream>
#include <algorithm>
 
void fn(char const &c) {
    std::cout << c << ' ';
}
 
void print(const std::string &s) {
    std::for_each(s.begin(), s.end(), fn);
}
 
int main()
{
    std::string s("hello");
    print(s);
 
    return 0;
}