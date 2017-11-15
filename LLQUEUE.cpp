/********************************************
ENESHAN ALTUNLU
PROF. F. ALJAMAL
Due Date:11/03/17
Program Description:Implemetation of Queue By DLL
********************************************/
#include <iostream>
#include <fstream>
using namespace std;

typedef int INFO_RC;
struct NODE;
typedef NODE *PT_NODE;
	struct NODE
	{
		INFO_RC info;
		PT_NODE next;
	};
	struct QUEUE{
		PT_NODE front;
		PT_NODE back;
	};
void create_queue(QUEUE &);
void purge_Queue(QUEUE &);
bool EmptyCheck(QUEUE &);
void deq(QUEUE &);
void enq(QUEUE &,const int &);
void Print_1(QUEUE &,fstream &);
void showchoices();

int main()
{	
	fstream dataFile;
	dataFile.open("LLQUEUE.txt", ios::out);
	int A;
	QUEUE Yo;
	int choice;
	create_queue(Yo);
	showchoices();
	cin >> choice;
	while(choice < 1 || choice > 5)
	{
		cout << "Please enter valid choice: ";
		cin >> choice;
	}
	while(choice != 5)
	{
		switch(choice)
		{
			case 1:
				cout << "Please enter item to queue: ";
				cin >> A;
				enq(Yo, A);
			break;
			case 2:
				cout << "Dequeuing..." << endl;
				deq(Yo);
			break;
			case 3:
				Print_1(Yo,dataFile);
			break;	
			case 4:
				purge_Queue(Yo);
			break;
		}	
		cout << "Please enter your choice: ";	
		cin >> choice;
	}
	
}
void showchoices()
{
	cout << "Enter 1 to Enq\n";
	cout << "Enter 2 te Deq" << endl;
	cout << "Enter 3 to Print" << endl;
	cout << "Enter 4 to Purge" << endl;
	cout << "Enter 5 to exit" << endl;
	cout << "Enter your choice here: ";
}
void create_queue(QUEUE &q)
{
	q.front = q.back = NULL;
}
bool EmptyCheck(QUEUE &p)
{ 	// Checks if queue is Empty
	return(!p.front);
}
void purge_Queue(QUEUE &p)
{
	p.front = p.back = NULL;
}
void deq(QUEUE &p)
{
	if(p.front==NULL)
	{
		cout << "There is nothing to dequeue" << endl;
	}
	else
	{
		p.front =  p.front -> next;
	}
}
void enq(QUEUE &q, const INFO_RC & item)
{
	PT_NODE  P = new NODE;
  	P -> info = item;
  	P -> next = NULL;
	 if(q.front == NULL)
     	q.front = P;  
 	else
    	q.back -> next = P;
    	q.back = P;
}
void Print_1(QUEUE &p,fstream &file)
{
	NODE *temp;
        temp = p.front;
        if (p.front == NULL)
            cout<<"Queue is empty\n";
        else
            {	
			cout<<"Queue is :\n";
            while(temp != NULL)
            {
            	file << temp->info << " | ";
                cout<<temp->info << " | ";
                temp = temp->next;
            }
	}
}
