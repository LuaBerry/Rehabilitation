#include<iostream>
#include<string>

using namespace std;

int KMP(string str, string key)
{
    int keyNum = key.length();
    int strNum = str.length();

    //Table making
    int* table = new int[keyNum];
    table[0] = 0;

    int count = 0;
    for(int i = 1; i < keyNum - 1;)
    {
        for (int j = 0; j < keyNum - i; j++)
        {
            if(key[i + j] == key[j])
            {
                table[i + j] = ++count;
            }
            else
            {
                table[i + j] = 0;

                if(count) i += count;
                else i += 1;

                count = 0;
                break;
            }
        }
    }

    //KMP Sort

    int i;
    for(i = 0; i <= strNum - keyNum; )
    {
        count = 0;
        for(int j = 0; j < keyNum; j++)
        {
            cout << i << " " << j << " | ";
            if(str[i + j] == key[j])
            { count++; }
            else
            { i += (table[count] + 1); count = 0; }
        }
        if(count == keyNum)
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

    result = KMP(str,key);
    
    if(result != -1)
        cout << str << " has " << key << " at " << result << endl;
    else
        cout << str << " doesn't have " << key << endl;
    return 0;
    
}
/*
ZABCABXACCADEF ABCABD
*/