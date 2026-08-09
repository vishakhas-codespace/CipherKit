#include <bits/stdc++.h>
using namespace std;

int main() {
    int choice;
    cout << "=============================" << endl;
    cout << "       CIPHERKIT             " << endl;
    cout << "  Mini Encryption Toolkit    " << endl;
    cout << "=============================" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Rail Fence Cipher" << endl;
    cout << "3. Columnar Cipher" << endl;
    cout << "4. Exit" << endl;
    cout << "=============================" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    if(choice == 1) {
        string message;
        int key, encryptChoice;
        cout << "\nEnter message: ";
        cin >> message;
        cout << "Enter key: ";
        cin >> key;
        cout << "1. Encrypt  2. Decrypt: ";
        cin >> encryptChoice;
        string result = "";
        for(int i = 0; i < message.length(); i++) {
            char c = message[i];
            if(encryptChoice == 1) {
                if(c >= 'A' && c <= 'Z')
                    result += (char)(((c-'A')+key)%26+'A');
                else if(c >= 'a' && c <= 'z')
                    result += (char)(((c-'a')+key)%26+'a');
                else result += c;
            } else {
                if(c >= 'A' && c <= 'Z')
                    result += (char)(((c-'A')-key+26)%26+'A');
                else if(c >= 'a' && c <= 'z')
                    result += (char)(((c-'a')-key+26)%26+'a');
                else result += c;
            }
        }
        cout << "\nResult: " << result << endl;

    } else if(choice == 2) {
        string message;
        int rails;
        cout << "\nEnter message: ";
        cin >> message;
        cout << "Enter number of rails: ";
        cin >> rails;
        vector<string> fence(rails);
        int rail = 0, direction = 1;
        for(int i = 0; i < message.length(); i++) {
            fence[rail] += message[i];
            if(rail == 0) direction = 1;
            else if(rail == rails-1) direction = -1;
            rail += direction;
        }
        string result = "";
        for(int i = 0; i < rails; i++) {
            result += fence[i];
        }
        cout << "\nEncrypted: " << result << endl;

    } else if(choice == 3) {
        string message, keyword;
        cout << "\nEnter message: ";
        cin >> message;
        cout << "Enter keyword: ";
        cin >> keyword;
        int cols = keyword.length();
        int rows = ceil((float)message.length() / cols);
        vector<vector<char>> grid(rows, vector<char>(cols, 'X'));
        int k = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(k < message.length())
                    grid[i][j] = message[k++];
            }
        }
        string sortedKey = keyword;
        sort(sortedKey.begin(), sortedKey.end());
        string result = "";
        for(int i = 0; i < cols; i++) {
            char ch = sortedKey[i];
            int col = keyword.find(ch);
            for(int j = 0; j < rows; j++) {
                result += grid[j][col];
            }
        }
        cout << "\nEncrypted: " << result << endl;

    } else if(choice == 4) {
        cout << "Goodbye!" << endl;

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}