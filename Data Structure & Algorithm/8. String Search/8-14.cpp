#include<iostream>
#include<string>
#include<limits>
using namespace std;

int skip[UCHAR_MAX];

int BoyerMoore(string str, string key)
{
    int keyNum = key.length();
    int strNum = str.length();

    for(int i = 0; i < UCHAR_MAX; i++)
    {
        skip[i] = keyNum;
    }
    for(int i = 0; i < keyNum - 1; i++)
    {
        skip[key[i]] = keyNum - i - 1;
    }

    for(int i = 'A'; i <= 'Z'; i++)
    {
        cout << skip[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < strNum - 1;)
    {
        for (int j = keyNum - 1; j >= 0; j--)
        {
            cout << i << " " << j << " | ";
            if(str[i + j] != key[j])
            {
                i += skip[str[i + j]];
                break;
            }
            else if(j == 0)
            {
                return i;
            }
        }
    }

    return -1;

}

int main()
{
    string str;
    string key;
    int result;

    cout << "Input text: ";
    cin >> str;
    cout << "Input key: ";
    cin >> key;

    result = BoyerMoore(str,key);
    
    if(result != -1)
        cout << str << " has " << key << " at " << result << endl;
    else
        cout << str << " doesn't have " << key << endl;
    return 0;
    
}