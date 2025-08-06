#include <iostream>
#include <string>

using namespace std;

bool isNumericConstant(string s)
{
    if (s.empty())
        return false;

    for (char ch : s)
    {
        if (!isdigit(ch))
            return false;
    }

    return true;
}

int main()
{
    string input;

    cout << "Enter input: ";
    cin >> input;

    if (isNumericConstant(input))
        cout << "This is a numeric constant." << endl;
    else
        cout << "This is not numeric." << endl;

    return 0;
}
