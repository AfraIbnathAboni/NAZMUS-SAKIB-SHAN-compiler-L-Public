#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cout << "Enter an expression: ";
    cin >> input;

    string operators = "+-*/%=";
    int count = 0;

    for (char ch : input)
    {
        if (operators.find(ch) != string::npos)
        {
            cout << "operator" << ++count << ": " << ch << endl;
        }
    }

    if (count == 0)
        cout << "No arithmetic operator found." << endl;

    return 0;
}
