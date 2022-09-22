#include <iostream>
#include <vector>
#include <queue>  
#include <stack>
using namespace std;

struct Node
{
	int x;
	Node* Next, * Prev;
};

class List
{
	Node* Head, * Tail;
public:
	List() :Head(NULL), Tail(NULL) {};
	~List();
	void Add_To_Stack(int x);
	void Show_Stack();
	void Delete_From_Stack();

	void Add_To_Queue(int x);
	void Show_Queue();
	void Delete_From_Queue();
};

List::~List()
{
	Node* tmp;
	while (Head)
	{
		tmp = Head->Next;
		delete Head;
		Head = tmp;
	}
}

/* Стек списком */
int top2 = 1;

void List::Add_To_Stack(int x)
{
	if (top2 != 6)
	{
		Node* NewEl = new Node;
		NewEl->Next = NULL;
		NewEl->x = x;
		if (Head != NULL)
		{
			NewEl->Prev = Tail;
			Tail->Next = NewEl;
			Tail = NewEl;
		}
		else
		{
			NewEl->Prev = NULL;
			Head = Tail = NewEl;
		}
		top2++;
	}
	else
	{
		cout << "Your stack is full! " << endl;
	}
}

void List::Show_Stack()
{
	if (top2 == 1)
	{
		cout << "Your stack is empty!" << endl;
	}
	else
	{
		cout << "Your stack:  ";
		Node* tmp = Head;
		for (int i = 1; i < top2; i++)
		{
			cout << tmp->x << " ";
			tmp = tmp->Next;
		}
		cout << endl;
	}
}

void List::Delete_From_Stack()
{
	if (top2 == 1)
	{
		cout << "Your stack is empty!" << endl;
	}
	else
	{
		Node* temp;
		if (Tail->Prev != NULL)
		{
			temp = Tail->Prev;
			temp->Next = NULL;
			cout << "Element " << Tail->x << " has been removed from the stack!" << endl;
			delete Tail;
			Tail = temp;
		}
		else
		{
			cout << "You delete last element in your stack! Now your stack is empty!";
			Head = Tail = NULL;
		}
		top2--;
	}
}

/* Стек масивом */
int top = 0;

void Show_Stack(int* Stack)
{
	int counter = 0;
	if (top == 0)
	{
		cout << "Stack is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			cout << Stack[i] << " ";
			counter++;
		}
	}
	cout << "There are " << counter << " elements in the Stack!" << endl;
}

void Push(int* Stack, int tmp)
{
	if (top != 20)
	{
		Stack[top] = tmp;
		top++;
	}
	else
	{
		cout << "Stack is full! " << endl;
	}
}

int Pop(int* Stack)
{
	if (top != 0)
	{
		top--;
		cout << "Element " << Stack[top] << " has been removed from the stack! " << endl;
		return Stack[top];
	}
	else
	{
		cout << "Stack is empty! Please fill your stack! " << endl;
	}
}

/* Черга масивом */

int head = 0;
int tail = 0;

void Show_Queue(int* Queue, int n)
{
	if (head == tail)
	{
		cout << "The queue is empty! " << endl;
	}
	else
	{
		cout << "Your queue: ";
		if (tail > head)
		{
			for (int i = head; i < tail; i++)
			{
				cout << Queue[i] << " ";
			}
		}
		else
		{
			for (int i = head; i < n; i++)
			{
				cout << Queue[i] << " ";
			}
			for (int i = 0; i < tail; i++)
			{
				cout << Queue[i] << " ";
			}
		}
		cout << endl;
	}
}
void Enqueue(int* Queue, int x, int n)
{
	if (head == ((tail + 1) % n))
	{
		cout << "The queue is full!" << endl;
	}
	else
	{
		Queue[tail] = x;
		if (tail == n - 1)
		{
			tail = 0;
		}
		else
		{
			tail++;
		}
	}
}

void Dequeue(int* Queue, int n)
{
	int x = Queue[head];
	if (head == tail)
	{
		cout << "The queue is empty! " << endl;
	}
	else
	{
		if (head == n - 1)
		{
			head = 0;
		}
		else
		{
			head++;
		}
		cout << "Element " << x << " has been removed from the queue!" << endl;
	}
}

/* Черга списком */

void List::Add_To_Queue(int x)
{
	Node* NewEl = new Node;
	NewEl->Next = NULL;
	NewEl->x = x;
	if (Head != NULL)
	{
		Tail->Next = NewEl;
		NewEl->Prev = Tail;
		Tail = NewEl;
	}
	else
	{
		NewEl->Prev = NULL;
		Head = Tail = NewEl;
	}
}

void List::Delete_From_Queue()
{
	Node* temp;
	if (Head == NULL) { cout << "Queue is empty" << endl; }
	else
	{
		if (Head->Next != NULL)
		{
			temp = Head->Next;
			temp->Prev = NULL;
			cout << "Element " << Head->x << " has been removed from the queue!" << endl;
			delete Head;
			Head = temp;
		}
		else
		{
			cout << "Element " << Head->x << " has been removed from the queue!" << endl;
			Head = Tail = NULL;
		}
	}
}

void List::Show_Queue()
{
	if (Head == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		Node* tmp = Head;
		while (tmp != NULL)
		{
			cout << tmp->x << " ";
			tmp = tmp->Next;
		}
		cout << endl;
	}
}

void PostFix(char* mass, int* Stack)
{
	int tmp;
	int result;
	int curr;
	for (int i = 0; i < 11; i++)
	{
		if (mass[i] == '+' || mass[i] == '-' || mass[i] == '*' || mass[i] == '/')
		{
			if (mass[i] == '+')
			{
				result = Pop(Stack) + Pop(Stack);
			}
			if (mass[i] == '-')
			{
				curr = Pop(Stack);
				result = Pop(Stack) - curr;
			}
			if (mass[i] == '*')
			{
				result = Pop(Stack) * Pop(Stack);
			}
			if (mass[i] == '/')
			{
				curr = Pop(Stack);
				result = Pop(Stack) / curr;
			}
			Push(Stack, result);
			cout << "Pushed! " << result << endl;
		}
		else
		{
			tmp = mass[i];
			Push(Stack, tmp);
			cout << "Pushed! " << tmp << endl;
		}
	}
	Show_Stack(Stack);
	cout << "Result= " << result;
}


/*Стек stl*/

class MyStack
{
private:
	int top = 0;
	int length = 20;
	vector<int>Myarr = vector<int>(length);
public:
	void Add_to_Stack(int x);
	void Show_Stack();
	void Delete_From_Stack();
};

void MyStack::Add_to_Stack(int x)
{
	if (top != length)
	{
		Myarr[top] = x;
		top++;
	}
	else
	{
		cout << "Stack is full! " << endl;
	}
}

void MyStack::Show_Stack()
{
	int counter = 0;
	if (top == 0)
	{
		cout << "Stack is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			cout << Myarr[i] << " ";
			counter++;
		}
	}
	cout << "There are " << counter << " elements in the Stack!" << endl;
}

void MyStack::Delete_From_Stack()
{
	if (top != 0)
	{
		top--;
		cout << "Element " << Myarr[top] << " has been removed from the stack! " << endl;
		//return Myarr[top];
	}
	else
	{
		cout << "Stack is empty! Please fill your stack! " << endl;
	}
}
/*Черга stl*/
class MyQueue
{
	int head = 0;
	int tail = 0;
	int length = 20;
	vector<int>Myarr = vector<int>(length);
public:
	void Enqueue(int x);
	void Show_Queue();
	void Dequeue();
};

void MyQueue::Enqueue(int x)
{
	if (head == ((tail + 1) % length))
	{
		cout << "The queue is full!" << endl;
	}
	else
	{
		Myarr[tail] = x;
		if (tail == length - 1)
		{
			tail = 0;
		}
		else
		{
			tail++;
		}
	}
}

void MyQueue::Dequeue()
{
	int x = Myarr[head];
	if (head == tail)
	{
		cout << "The queue is empty! " << endl;
	}
	else
	{
		if (head == length - 1)
		{
			head = 0;
		}
		else
		{
			head++;
		}
		cout << "Element " << x << " has been removed from the queue!" << endl;
	}
}

void MyQueue::Show_Queue()
{
	if (head == tail)
	{
		cout << "The queue is empty! " << endl;
	}
	else
	{
		cout << "Your queue: ";
		if (tail > head)
		{
			for (int i = head; i < tail; i++)
			{
				cout << Myarr[i] << " ";
			}
		}
		else
		{
			for (int i = head; i < length; i++)
			{
				cout << Myarr[i] << " ";
			}
			for (int i = 0; i < tail; i++)
			{
				cout << Myarr[i] << " ";
			}
		}
		cout << endl;
	}
}




int main()
{
	//Стек масивом 
	/*
int MyStack[4];
int tmp;
cout << " Choose what u want to do: \n";
cout << "1. Add element to the stack\n";
cout << "2. Remove element from the stack\n";
cout << "3. Show elements of stack\n";
cout << "0. Exit\n";
while (true)
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice==1 || choice==2 || choice==3 || choice==0)
		{
			break;
		}
		else cout << "Invalid input,please try again\n";
	}
	if (choice == 0) break;
	switch (choice)
	{
		case 1:
		{
			cout << "Enter your element: ";
			cin >> tmp;
			Push(MyStack, tmp);
			break;
		}
		case 2:
		{
			Pop(MyStack);
			break;
		}
		case 3:
		{
			Show_Stack(MyStack);
			break;
		}
	}
}*/

// Стек списком 
/*int tmp;
List MyStack;
cout << " Choose what u want to do: \n";
cout << "1. Add element to the stack\n";
cout << "2. Remove element from the stack\n";
cout << "3. Show elements of stack\n";
cout << "0. Exit\n";
while (true)
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice==1 || choice==2 || choice==3 || choice==0)
		{
			break;
		}
		else cout << "Invalid input,please try again\n";
	}
	if (choice == 0) break;
	switch (choice)
	{
		case 1:
		{
			cout << "Enter your element: ";
			cin >> tmp;
			MyStack.Add_To_Stack(tmp);
			break;
		}
		case 2:
		{
			MyStack.Delete_From_Stack();
			break;
		}
		case 3:
		{
			MyStack.Show_Stack();
			break;
		}
	}
}*/
//Черга масивом
	/*int tmp;
int MyQueue[7];
int length = 7;
cout << " Choose what u want to do: \n";
cout << "1. Add element to the queue \n";
cout << "2. Remove element from the queue\n";
cout << "3. Show elements of queue\n";
cout << "0. Exit\n";
while (true)
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice==1 || choice==2 || choice==3 || choice==0)
		{
			break;
		}
		else cout << "Invalid input,please try again\n";
	}
	if (choice == 0) break;
	switch (choice)
	{
		case 1:
		{
			cout << "Enter your element: ";
			cin >> tmp;
			Enqueue(MyQueue,tmp,length);
			break;
		}
		case 2:
		{
			Dequeue(MyQueue,length);
			break;
		}
		case 3:
		{
			Show_Queue(MyQueue,length);
			break;
		}
	}
}*/

//Черга списком 
/*List MyQueue;
int tmp;
cout << " Choose what u want to do: \n";
cout << "1. Add element to the queue \n";
cout << "2. Remove element from the queue\n";
cout << "3. Show elements of queue\n";
cout << "0. Exit\n";
while (true)
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice==1 || choice==2 || choice==3 || choice==0)
		{
			break;
		}
		else cout << "Invalid input,please try again\n";
	}
	if (choice == 0) break;
	switch (choice)
	{
		case 1:
		{
			cout << "Enter your element: ";
			cin >> tmp;
			MyQueue.Add_To_Queue(tmp);
			break;
		}
		case 2:
		{
			MyQueue.Delete_From_Queue();
			break;
		}
		case 3:
		{
			MyQueue.Show_Queue();
			break;
		}
	}
	}*/


	//int Mystack[20];

	char vuraz[11] = { 100,3,'-',2,'-',5,'/',5,6,'*','-' };
	// (А-B-С)/D-E*F
	// AB-C-D/EF*-
	// (100-3-2)/5-5*6

	//PostFix(vuraz, Mystack);

	/*Чергга stl*/
	//queue<int> myQueue;
	//int tmp;
	//cout << " Choose what u want to do: \n";
	//cout << "1. Add element to the queue\n";
	//cout << "2. Remove element from the queue\n";
	//cout << "3. Show elements of queue\n";
	//cout << "0. Exit\n";
	//while (true)
	//{
	//	int choice;
	//	while (true)
	//	{
	//		cin >> choice;
	//		if (choice == 1 || choice == 2 || choice == 3 || choice == 0)
	//		{
	//			break;
	//		}
	//		else cout << "Invalid input,please try again\n";
	//	}
	//	if (choice == 0) { break; }
	//	switch (choice)
	//	{
	//	case 1:
	//	{
	//		cout << "Enter your element: ";
	//		cin >> tmp;
	//		myQueue.push(tmp);
	//		break;
	//	}
	//	case 2:
	//	{
	//		myQueue.pop();
	//		break;
	//	}
	//	case 3:
	//	{
	//		if (myQueue.empty())
	//		{
	//			cout << "Queue is empty!" << endl;
	//		}
	//		else 
	//		{
	//			queue<int>temp = myQueue;
	//			while (!temp.empty())
	//			{
	//				int value = temp.front();
	//				temp.pop();
	//				cout << value << " ";
	//			}
	//			cout << endl;
	//			cout << "There are " << myQueue.size() << " elements in the queue!" << endl;
	//		}
	//		
	//		break;
	//	}
	//	}
	//}

	/*стек stl*/
	stack <int> Mystack;
	int tmp;
	cout << " Choose what u want to do: \n";
	cout << "1. Add element to the stack\n";
	cout << "2. Remove element from the stack\n";
	cout << "3. Show elements of stack\n";
	cout << "0. Exit\n";
	while (true)
	{
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3 || choice == 0)
			{
				break;
			}
			else cout << "Invalid input,please try again\n";
		}
		if (choice == 0) { break; }
		switch (choice)
		{
		case 1:
		{
			cout << "Enter your element: ";
			cin >> tmp;
			Mystack.push(tmp);
			break;
		}
		case 2:
		{
			Mystack.pop();
			break;
		}
		case 3:
		{
			if (Mystack.empty())
			{
				cout << "Stack is empty!" << endl;
			}
			else
			{
				stack <int>temp = Mystack;
				while (!temp.empty())
				{
					cout << temp.top() << "  ";
					temp.pop();
				}
				cout << endl;
				cout << "There are " << Mystack.size() << " elements in the stack!" << endl;
			}
			break;
		}
		}
	}
}
