#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool compareTemp(T x, T y)
{
    if (x == y)
        return true;

    else
        return false;
}

template <typename T>
bool compareTemp(T* x, T* y)
{
    if (*x == *y)
        return true;

    else
        return false;
}

template<>
bool compareTemp <const char*>(const char* x, const char* y)
{
    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] != y[i])
            return false;
    }

    return true;
}

int main()
{
    int x = 'a', y = 97;
    char a = 'a', b = 'a';
    char *aptr = &a, *bptr = &b;
    string str1 = "String", str2 = "String";
    (compareTemp(x, y)) ? cout << "Integers are equal" : cout << "Integers are not equal";
    cout << endl;
    (compareTemp(a, b)) ? cout << "Chars are equal" : cout << "Chars are not equal";   cout << endl;
    (compareTemp(aptr, bptr)) ? cout << "Pointers are equal" : cout << "Pointers are not equal";
    cout << endl;
    (compareTemp(str1, str2)) ? cout << "Strings are equal" : cout << "Strings are not equal";
	cout << endl;

    system("pause");
    return 0;
}