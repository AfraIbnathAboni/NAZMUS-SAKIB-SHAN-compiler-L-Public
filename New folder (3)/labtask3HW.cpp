#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isDelimiter(char ch) {
    string delimiters = ";,(){}[]";
    for (int i = 0; i < delimiters.length(); i++) {
        if (delimiters[i] == ch) {
            return true;
        }
    }
    return false;
}

bool isInteger(string str) {
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool isRealNumber(string str) {
    if (str.empty()) return false;
    bool dotFound = false;
    for (char ch : str) {
        if (ch == '.') {
            if (dotFound) return false;
            dotFound = true;
        } else if (!isdigit(ch)) {
            return false;
        }
    }
    return dotFound;
}

int main() {
    ifstream file("code.txt");
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string token = "";

        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];

            if (isspace(ch)) {
                if (!token.empty()) {
                    if (isInteger(token))
                        cout << "Integer: " << token << endl;
                    else if (isRealNumber(token))
                        cout << "Real Number: " << token << endl;
                    token = "";
                }
            }
            else if (isDelimiter(ch)) {
                if (!token.empty()) {
                    if (isInteger(token))
                        cout << "Integer: " << token << endl;
                    else if (isRealNumber(token))
                        cout << "Real Number: " << token << endl;
                    token = "";
                }
                cout << "Delimiter: " << ch << endl;
            }
            else if (ch == '.') {
                token += ch;
            }
            else if (isalnum(ch)) {
                token += ch;
            }
            else {
                if (!token.empty()) {
                    if (isInteger(token))
                        cout << "Integer: " << token << endl;
                    else if (isRealNumber(token))
                        cout << "Real Number: " << token << endl;
                    token = "";
                }
            }
        }

        if (!token.empty()) {
            if (isInteger(token))
                cout << "Integer: " << token << endl;
            else if (isRealNumber(token))
                cout << "Real Number: " << token << endl;
        }
    }

    file.close();
    return 0;
}
