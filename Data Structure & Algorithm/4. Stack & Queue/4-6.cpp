#include<iostream>
#include"IntQueue.h"

using namespace std;

int main()
{
    IntQueue* que;
    que = new IntQueue;

    int menu, x, res;

    if(Initialize(que, 8))
    {
        cout << "Failed to Initialize Stack.\n";

        return 1;
    }
    else
    {
        cout << "Initialize successful.\n";
    }
    while(true)
    {
        cout << "Current data size: "<< Size(que) << " of " << Capacity(que) << "\n";
        cout << "1. Enque 2. Deque 3. Peek 4. Print 5. Search 6. Clear 0. Exit: ";
        cin >> menu;

        if(!menu) break;

        switch(menu)
        {
            case 1:
                cout << "Input number: ";
                cin >> x;
                if(Enque(que, x)+1)
                    cout << "Enque Successful.\n";
                else
                    cout << "Enque Failed, Please check the capacity.\n";
                break;
            case 2:
                if(Deque(que, &x)+1)
                    cout << "Deque Successful. Output: " << x << endl; 
                else
                    cout << "Deque Failed, Please check if the queue is empty.\n";
                break;
            case 3:
                if(Peek(que, &x)+1)
                    cout << "Peek Successful. Output: " << x << endl;
                else
                    cout << "Peek Failed, Please check if the queue is empty.\n";
                break;
            case 4:
                Print(que);
                break;
            case 5:
                cout << "Input number: ";
                cin >> x;
                res = Search(que,x);
                if(res == -1)
                {
                    cout << "Search Failed.\n";
                }
                else
                {
                    cout << x << " is at " << res << endl;
                }
                break;
            case 6:
                Clear(que);
                cout << "Clear Que.\n";
                break;    
        }
    }

    Terminate(que);

    delete que;
    
    return 0;
}