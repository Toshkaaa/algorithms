#include <iostream>
using namespace std;

void GenerateMass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 200 - 100;
	}
}

void GetMass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] <<"   ";
	}
	cout << endl << endl;
}

void Method_1(int* mass, int n)
{
	int minimun;
	int tmp;
	for(int b = 0; b < n; b++)
	{
		int index=b;
		minimun = mass[b];
		for (int i = b; i < n; i++)
		{
			if (minimun > mass[i])
			{
				minimun = mass[i];	
				index = i;
			}
		}
		if (minimun!=mass[b])
		{
			tmp = mass[b];
			mass[b] = minimun;
			mass[index] = tmp;
		}
	}
}



int main()
{
	int size;
	srand(time(NULL));
	cout << "Enter your size of massive: " << endl;
	cin >> size;
	int* arr = new int[size];
	GenerateMass(arr, size);
	GetMass(arr, size);
	Method_1(arr, size);
	GetMass(arr, size);
	delete[] arr;
	return 0;
}

