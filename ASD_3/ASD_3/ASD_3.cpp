#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string x;
    Node* Next, * Prev;
};

class List
{
    Node* Head, * Tail;
public:
    List() :Head(NULL), Tail(NULL) {};
    ~List();
    void Show();
    void NewShow();
    void Add(string x);
    void Add_start(string x);
    void Add_middle(string x);
    void Delete_End();
    void Delete_middle();
    void Delete_First();
    void Delete_3();
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

void List::Delete_End()
{
    Node* temp;
    if (Head == NULL) { cout << "List empty" << endl; }
    else
    {
        if (Tail->Prev != NULL)
        {
            temp = Tail->Prev;
            temp->Next = NULL;
            delete Tail;
            Tail = temp;
        }
        else
        {
            cout << "You delete last element";
            Head = Tail = NULL;
        }
    }
}

void List::Delete_First()
{
    Node* temp;
    if (Head == NULL) { cout << "List empty" << endl; }
    else
    {
        if (Head->Next != NULL)
        {
            temp = Head->Next;
            temp->Prev = NULL;
            delete Head;
            Head = temp;
        }
        else
        {
            cout << "You delete last element";
            Head = Tail = NULL;
        }
    }
}

void List::Delete_middle() 
{
    if (Head == NULL) { cout << "List empty" << endl; }
    else
    {
            Node* count = new Node;
            int a = 1;
            for (count = Head; count != Tail; count = count->Next)
            {
                a++;
            }
            if (a>2)
            {
                a = a / 2;
                count = Head;
                for (int i = 0; i < a; i++)
                {
                    count = count->Next;
                }
                count->Prev->Next = count->Next;
                count->Next->Prev = count->Prev;
            }
            else
            {
                cout << "U must enter more than 2 elements!"<<endl;
            }
    }
}

void List::Add(string x)
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

void List::Add_start(string x) 
{
    Node* NewEl = new Node;
    NewEl->Prev = NULL;
    NewEl->x = x;
    Head->Prev = NewEl;
    NewEl->Next = Head;
    Head = NewEl;
}

void List::Add_middle(string x) 
{
    if (Head->Next!=NULL)
    {
        Node* count = new Node;
        int a = 1;
        for (count = Head; count != Tail; count = count->Next)
        {
            a++;
        }
        a = a / 2;
        count = Head;
        for (int i = 1; i < a; i++)
        {
            count = count->Next;
        }
        Node* NewEl = new Node;
        NewEl->x = x;
        NewEl->Next = count->Next;
        NewEl->Prev = count->Prev;
        count->Next = NewEl;
        count->Next->Next->Prev = NewEl;
    }
    else
    {
        cout << "U have only 1 element!" << endl;
    }
}

void List::Show()
{
    Node* tmp = Head;
    while (tmp != NULL)
    {
        cout << tmp->x << " ";
        tmp = tmp->Next;
    }
    cout << endl;
}

void CutMass(char* mass, int n)
{
    char prob(' ');
    int counter = 0;
    int length = 0;
    int j = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        length++;
        if (mass[i] == prob && mass[i + 1] != prob)
        {
            counter++;
            if (counter==2)
            {
                j = i;
            }
            
        }
    }
    cout <<endl<< "Length= " << length<<endl;
    string Another_string;
    y = j;
    while (mass[j+1]!=prob and (j + 1) != (n))
    {
        Another_string = Another_string + mass[j + 1];
        j++;
    }
    int newlength=n-(j-y)-1;
    //cout << "y=" << y;
    //cout << "j" << j;
    //cout << "Another= " << Another_string;  
    char* arr = new char[newlength];
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (!((i > y) && (i < j+2)))
        {
             arr[k] = mass[i];
             k++;
        }
    }
    cout << endl << "--------------------------------" << endl;
    int newcounter=0;
    for (int i = 0; i < newlength; i++)
    {
         cout << arr[i] ;
         newcounter++;
    }
    cout << endl << "NewLength= " << newcounter << endl;
    delete [] mass;
    mass = arr;
 
}

void ShowMass(char* mass, int n)
{
    char prob(' ');
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (mass[i] != 'a' && mass[i] != 'b' && mass[i] != 'c' && mass[i] != 'd' && mass[i] != 'e' && mass[i] != 'f' && mass[i] != 'g' && mass[i] != 'h'
            && mass[i] != 'i' && mass[i] != 'j' && mass[i] != 'k' && mass[i] != 'l' && mass[i] != 'm' && mass[i] != 'n' && mass[i] != 'o' && mass[i] != 'p'
            && mass[i] != 'q' && mass[i] != 'r' && mass[i] != 's' && mass[i] != 't' && mass[i] != 'u' && mass[i] != 'v' && mass[i] != 'w' && mass[i] != 'x'
            && mass[i] != 'y' && mass[i] != 'z' && mass[i] != prob)
        {
            cout << endl << "Enter only small leters of English alphabet ! Please come back later))) " << endl;
            return;
        }
        if (mass[0] == prob or mass[n] == prob)
        {
            cout << endl << "Spacebar must not be at the or at he start of mass! " << endl;
            return;
        }
        if (mass[i] == prob && mass[i + 1] == prob)
        {
            cout << endl << "There must be one spacebar between words!  " << endl;
            return;
        }

    }
    if (counter > 1)
    {
        cout << endl << "Please wait , the programm is calculating and typeing... " << endl <<
            "Please notice that this programm nust double the first letter if the word has an even number of letters"
            << " and delete the last letter if the word has an odd number of letters." << endl << endl;
        string First_string, Another_string;
        for (int i = 0; mass[i] != prob; i++)
        {
            First_string = First_string + mass[i];
        }
        cout << First_string << " ";

        for (int i = 0; i != n; i++)
        {
            if (mass[i] == prob)
            {
                while (mass[i + 1] != prob and (i + 1) != (n))
                {
                    Another_string = Another_string + mass[i + 1];
                    i++;
                }
                if (First_string != Another_string)
                {
                    int j = 0;
                    for (int a = 0; a < Another_string.size(); a++)
                    {
                        j++;
                    }
                    if (j % 2 == 0)
                    {
                        string result;
                        for (int b = 0; b < Another_string.length() + 1; b++)
                        {
                            result += Another_string[b];
                            if (b == 0)
                            {
                                result += Another_string[b];
                            }
                        }
                        result.erase(result.length() - 1, 1);
                        Another_string = result;
                    }
                    else
                    {
                        Another_string.erase(Another_string.length() - 1, 1);
                    }
                    cout << Another_string << " ";
                }
                Another_string = "";
            }
        }
        cout << endl << endl << "Your massive is higher! " << endl;
    }
    else
    {
        cout << "Enter more than 2 words and with one spacebar between them!" << endl;
    }
}

void List::Delete_3() 
{
    int counter = 0;
    Node* cur = Head;
    while (cur != NULL)
    {
        counter++;
        cur = cur->Next;
    }
    if (counter>3)
    {
        cur = Head;
        int a = 1;
        while (a != 3)
        {
            cur = cur->Next;
            a++;
        }
        cur->Prev->Next = cur->Next;
        cur->Next->Prev = cur->Prev;
    }
   
}

void List::NewShow()
{

    int counter = 0;
    Node* cur = Head;
    for (int i = 0; i < cur->x.length(); i++)
    {
        if (cur->x[i]!='a' && cur->x[i]!= 'b' && cur->x[i] != 'c' && cur->x[i] != 'd' && cur->x[i] != 'e' && cur->x[i] != 'f' && cur->x[i] != 'g' && cur->x[i] != 'h'
            && cur->x[i] != 'i' && cur->x[i] != 'j' && cur->x[i] != 'k' && cur->x[i] != 'l' && cur->x[i] != 'm' && cur->x[i] != 'n' && cur->x[i] != 'o' && cur->x[i] != 'p'
            && cur->x[i] != 'q' && cur->x[i] != 'r' && cur->x[i] != 's' && cur->x[i] != 't' && cur->x[i] != 'u' && cur->x[i] != 'v' && cur->x[i] != 'w' && cur->x[i] != 'x'
            && cur->x[i] != 'y' && cur->x[i] != 'z')
        {
            cout << endl << "Enter only small leters of English alphabet ! Please come back later))) " << endl;
            return;
        }
    }
    cur = Head;
    while (cur != NULL)
    {
        counter++;
        cur = cur->Next;
    }
    if (counter > 2)
    {
        cout << "There are your list: " << endl;
        int j = 0;
        Node* tmp = Head;
        while (tmp != NULL)
        {
            if ((tmp->x != Head->x) || (tmp == Head))
            {
                for (int i = 0; i < tmp->x.size(); i++)
                {
                    j++;
                }
                if (j % 2 == 0)
                {
                    string result;
                    for (int i = 0; i < tmp->x.length() + 1; i++)
                    {
                        result += tmp->x[i];
                        if (i == 0)
                        {
                            result += tmp->x[i];
                        }
                    }
                    result.erase(result.length() - 1, 1);
                    tmp->x = result;
                }
                else
                {
                    tmp->x.erase(tmp->x.length() - 1, 1);
                }
                cout << tmp->x << " ";
            }
            tmp = tmp->Next;
        }
    }
    else
    {
        cout << "You have entered less than 2 elements, that why list haven't been showhed! " << endl;
    }
}

int main()
{
    //List list;
    //string MyString;
    //int message;
    //cout << "This is programm of creating and showing list of string elements! Please enter more than 2 elements! " << endl<<endl;
    //while (true)
    //{
    //    cout << "Enter elemet of your list: " << endl;
    //    cin >> MyString;
    //    list.Add(MyString);
    //    cout << "Do u want ot add one more element to your list? ( 1 - Yes; 0 - No )" << endl;
    //    cin >> message;
    //    if (!message)
    //    {
    //        break;
    //    }
    //}
    //list.Show();
    ////list.NewShow();
    //list.Delete_3();
    //list.Show();


    string Mystring;
    cout << "This is programm of creating and showing massive of char elements! Please enter more than 2 elements!  " << endl << endl;
    cout << "Please enter only small English  letters! There must be one spacebar between words!Spacebar must not be at the or at he start of mass!" << endl << endl;
    cout << "Enter your massive: " << endl;
    getline(cin, Mystring);
    char* arr = new char[Mystring.length()];
    for (int i = 0; i < Mystring.length(); i++)
    {
        arr[i] = Mystring[i];
    }
    CutMass(arr, Mystring.length());


    ///* cout << endl << "--------------------------------" << endl;
    // for (int i = 0; i < Mystring.length(); i++)
    // {
    //     cout << arr[i] ;
    // }*/
   // delete[] arr;
}
