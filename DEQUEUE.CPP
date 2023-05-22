#include "iostream.h"
#include "conio.h"

class QUEUE
{
		int *A,size,rear,front;
	public:
		QUEUE(int);
		void ADD_REAR(int);
		int DEL_FRONT();
		int DEL_REAR();
		void LIST_QUE();
};
QUEUE::QUEUE(int par)
{
	size= par;
	A =new int[size+1];
	rear = front = 0;
}
void QUEUE::ADD_REAR(int ele)
{
	if(rear==size)
		cout<<endl<<"Que is full";
	else
	{
		if(front==0)
			front=1;
		rear = rear + 1;
		A[rear] = ele;
	}
}
int QUEUE::DEL_FRONT()
{
	if(front==0)
	{
		cout<<endl<<"Que is empty";
		return NULL;
	}
	else
	{
		int ele = A[front];
		if(front == rear)
			rear =front = 0;
		else
			front = front + 1;
		return ele;
	}
}
int QUEUE::DEL_REAR()
{
	if(front==0)
	{
		cout<<endl<<"Que is empty";
		return NULL;
	}
	else
	{
		ele=A[rear];
		if(rear == front)
			front =rear = 0;
		else
			rear = rear -1;
		return ele;
	}
}
void QUEUE::LIST_QUE()
{
	if(front==0)
		cout<<endl<<"Que is empty";
	else
	{
		cout<<endl<<"Que elements are : ";
		for(int i= front;i<=rear;i++)
			cout<<A[i]<<" ";
	}
}
void MENU()
{
	int n,opt,ele;
	cout<<endl<<"Enter the size of Queue : ";
	cin>>n;
	QUEUE obj(n);

	do
	{
		cout<<endl<<"1 ADD @ REAR";
		cout<<endl<<"2 DEL from FRONT";
		cout<<endl<<"3 DEL from REAR";
		cout<<endl<<"4 EXIT";
		cout<<endl<<"================\n";
		cout<<endl<<"Enter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<endl<<"Enter ele";
				cin>>ele;
				obj.ADD_REAR(ele);
				obj.LIST_QUE();
				break;
			case 2:
				ele = obj.DEL_FRONT();
				if(ele)
					cout<<endl<<"Delted ele = "<<ele;
				obj.LIST_QUE();
				break;
			case 3:
				ele = obj.DEL_REAR();
				if(ele)
					cout<<endl<<"Delted ele = "<<ele;
				obj.LIST_QUE();
				break;
			case 4:
				return;
			default:
				cout<<endl<<"invalid input";
		}
	}while(1);
}
void main()
{
	clrscr();
	MENU();
	getch();
}









