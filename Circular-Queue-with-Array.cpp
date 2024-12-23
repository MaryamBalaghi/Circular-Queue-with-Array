#include <iostream>
using namespace std;
class C_queue
{

    int *qu;
    int front;
    int rear;
    int size;
    public:
    C_queue(int c);
    ~C_queue();
    bool Overflow();
    bool Underflow();
    void enqueue(int x);
    int dequeue();
    int retrieve();
};
C_queue::C_queue(int c)
{
    qu= new int[c];
    front =0;
    rear=0;
    size=c;
}
C_queue::~C_queue()
{
    delete []qu;
}
bool C_queue::Underflow()
{
    if(front==rear)
    {return true;}
    else return false;
}
bool C_queue::Overflow()
{
    if((rear+1)%size==front)
    {
        return true;
    }
    else return false;
}
void C_queue::enqueue(int x)
{
    if(Overflow())
    {
        cout<<"Overflow Error!!\n";
    }
    else
    {
        qu[rear]=x;
        rear=(rear+1)%size;
    }
}
int C_queue::dequeue()
{
    if(Underflow())
    {
        cout<<"Underflow Error!!\n";
        return -1;
    }
    else
    {
        int temp=qu[front];
        front=(front+1)%size;
        return temp;
    }
}
int C_queue::retrieve()
{
    if(Underflow())
    {
        cout<<"Underflow Error!!\n";
        return -1;
    }
    else
        return qu[front];
}
int main()
{
    int n;
    cout<<"please, enter the size of queue: ";
    cin>>n;
    C_queue q(n);
    cout<<"+++++Guide+++++\n";
    cout<<"1 for Enqueue\n";
    cout<<"2 for Dequeue\n";
    cout<<"3 for Retrieve\n";
    bool Continue=true;
    int c,x;
    char m;
    while (Continue)
    {
        cout<<"Please enter your choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
            if(!q.Overflow())
            {cout<<"please enter the new number: ";
            cin>>x;
            q.enqueue(x);}
            else cout<<"Error! This queue is overflow! ";
            break;
        case 2:
            if(!q.Underflow())
            {
                cout<<"Front number is: ";
                cout<<q.dequeue()<<"and deleted in queue.";
            }
            else cout<<"Error! This queue is empty.";
            break;
        case 3:
            if(!q.Underflow())
            {
                cout<<"Front number is: ";
                cout<<q.retrieve();
            }
            else cout<<"Error! This queue is empty.";
            break;
        default:
             cout << "\n Invalid choice! Please try again.\n";
            break;
        }
        cout << "\nDo you want to continue? (Y/N): ";
        cin >> m;
        Continue = (m == 'y' || m == 'Y');
    }
}