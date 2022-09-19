#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
T2 topla(T1 deger1, T2 deger2) {
  return deger1 + deger2;
}

int main()
{
    cout << topla(1, 2.6);
}