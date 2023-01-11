/*
*   IEEE-754 Floating Point Converter
*/
#include <iostream>

using namespace std;

int main()
{
    float x = 3.14;
    cout << "3.14 -> 0x" << hex << *((int *)&x) << endl;

    int y = 0x4048f5c3;
    cout << "0x0x4048f5c3 -> " << dec << *((float *)&y) << endl;
    return 0;
}