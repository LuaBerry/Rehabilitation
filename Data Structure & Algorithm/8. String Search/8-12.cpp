#include<iostream>
#include<string>

using namespace std;

int BruteForce(string str, string key)
{
    int flag;
    int i;
    for(i = 0; i <= str.length() - key.length(); i++)
    {
        flag = 1;
        for(int j = 0; j < key.length(); j++)
            if(str[i + j] != key[j])
            {
                flag = 0;
                break;
            }
        if(flag)
        {
            return i;
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

    result = BruteForce(str,key);
    if(result != -1)
        cout << str << " has " << key << " at " << result << endl;
    else
        cout << str << " doesn't have " << key << endl;
    return 0;
}