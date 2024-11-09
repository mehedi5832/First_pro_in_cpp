#include<iostream>
#include<string>

using namespace std;

class stack()
{
    private:
        int top;
        int arr[5];

    public:
        stack()
        {

            top= -1;
            for(int i=0; i<5; i++);
            {

                arr[i]=0;
            }
        }

        bool isEmpty()
        {
            if (top== -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if (top==4)
                return true;
            else
                return false;
        }
        void push(int val)
        {
            if(isFull())
            {
                cout<< "stack overflow"<<endl;
            }
            else
            {
                top++; //top 1
                arr[top]= val;

            }
        }
        int pop()
        {
            if(isEmpty())
            {
                cout<< "stack underflow"<<endl;
                return 0;
            }
            else
            {
                int popvalue= arr[top];
                arr[top]= 0;
                top--
                return popvalue;
            }
        }

        int count()
        {
            return (top+1);
        }
        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<< "stack underflow"<<endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }
        void change(int pos, int val)
        {
            arr[pos]= val;
            cout<< "value is changed at location"<<pos<<endl;

        }
        void display()
        {
            cout<< "All value in the stack are"<<endl;
            for (int i= 4; i>0 ; i--)
            {
                cout<< arr[i]<< endl;
            }
        }
};
int main()
{
    stack s1;
    int option, position, value;

    do
    {
        cout<< "what operation do you want to problem? select option number. Enter 0 to Exit."<<endl;
        cout<< "1. Push()"<<endl;
        cout<< "2. Pop()"<<endl;
        cout<< "3. isEmpty()"<<endl;
        cout<< "4. inFull()"<<endl;
        cout<< "5. peek()"<<endl;
        cout<< "6. count()"<<endl;
        cout<< "7. change()"<<endl;
        cout<< "8. display()"<<endl;
        cout<< "9. Clear Screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
        case 1:
            cout<< "Enter an item to push in the stack"<< endl;
            cin>>value;
            s1.push(value);
            break;
        case 2:
            cout<< "Pop finction called - poped value: "<< s1. pop()<< endl;
            break;

        case 3:
            if (s1. isEmpty())
                cout<< "stack is Empty"<<endl;
                else
                    cout<< "stack is not Empty"<<endl;
            break;
        case 4:
            if (s1. isFull())
                cout<< "stack is Full"<<endl;
            elsecout<< "stack is not Full"<<endl;
            break;
        case 5:
            cout<< "Enter position of item you want to peek: "<<endl;
            cin>>position;
            cout<< "peek Function called - "<< endl<<s1.peek(position)
        }

    }while(option!=0);

    return 0;
}
