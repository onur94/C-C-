#include <iostream>

using namespace std;

void print() { }

template<typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl;
    print(var2...);
}

int main()
{
    print(56, "test", 3.14, 'x');
    return 0;
}
