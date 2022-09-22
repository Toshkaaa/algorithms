#include <iostream>
using namespace std;
//void MoveFunction(int f,int s,int t,int n) 
//{
//	if (n>0)
//	{
//		MoveFunction(f, t, s, n - 1);
//		cout << "Disc has moved " << n <<" from " << f << " to " << s << endl;
//		MoveFunction(t, s, f,n-1);
//	}
//}
//
//void nsd(int x, int y)
//{
//	if (x==0 || y==0)
//	{
//		cout << "NSD is " << x+y << endl;
//	}
//	else
//	{
//		x > y ? x%=y : y%=x;
//		nsd(x, y);
//	}
//}


int Sum(int n) {
	int sum = 0;
	if (n == 0)
	{
		return 0;
	}
	else
	{
		sum =sum + n % 10;
		sum =sum + Sum(n / 10);
		return sum;
	}
}

int main()
{
	/*int m, n;
	cout << "========== NSD ===========" << endl << endl;
	cout << "Enter your first number: ";
	cin >> m;
	cout << "Enter your second number: ";
	cin >> n;
	nsd(abs(m), abs(n));
    cout << "========== Hanoi ===========" << endl << endl;
	int FirstKernel = 1;
	int SecondKernel = 2;
	int ThirdKernel = 3;
	int count;
	cout << "Enter numbers of discs: ";
	cin >> count;
	MoveFunction(FirstKernel,SecondKernel,ThirdKernel,count);*/

	int num;
	cout << "Enter your number " << endl;
	cin >> num;
	cout<< Sum(num);
}