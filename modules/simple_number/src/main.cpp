//находим все простые числа до введенного
#include "pch.h"

using namespace std;

void simple_number(int);

int main()
{
	int number;
	cout<<"enter number"<<endl;
	cin>>number;

	simple_number(number);

	cout<<"genius"<<endl;
	return 0;
}

void simple_number(int num)
{
	int exit=0;
	for(int i=2;i!=num;i++)
	{
		exit=0;
		for(int j=2;j<=sqrt(i);j++)
		{
			
			if(i%j==0)//если j делится на i без остачи значит i не простое число
			{
				exit=1;
				break;
			}
		}

		if(exit==0)//если exit равно нулю значит число простое, выводим его
		{
			cout<<i<<" ";
		}
	}
}