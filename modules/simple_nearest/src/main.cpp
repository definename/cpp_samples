//программа находит первое слева и справа простое число относительно введенного числа
//и определ€ет ближайшее

//!!задание в люксофт

#include "pch.h"
using namespace std;

//функци€ определ€юща€ простое ли число
bool simple(int);

int main()
{
	int x;
	cout<<"enter number"<<endl;
	cin>>x;

	int rightX=x+1;
	int leftX=x-1;
	
	if(x==2)//если введено первое простое число то выводим только самое ближнее справа
	{
		while(true)
		{
			if(simple(rightX)!=true)
			{
				rightX++;
			}
			else
			{
				break;
			}
		}
		cout<<"right nearest simple number "<<rightX<<endl;
	}
	else
	{
		while(true)
		{
			if(simple(rightX)!=true)
			{
				rightX++;
			}
			else
			{
				break;
			}
		}
		cout<<"right nearest simple number "<<rightX<<endl;
		
		while(true)
		{
			if(simple(leftX)!=true)
			{
				leftX--;
			}
			else
			{
				break;
			}
		}
		cout<<"left nearest simple number "<<leftX<<endl;
	}

	//определ€ем какое число ближе
	if((x-leftX)<=(rightX-x))
	{
		cout<<"nearest "<<leftX<<endl;
	}
	else
	{
		cout<<"nearest "<<rightX<<endl;
	}

	return 0;
}

//функци€ определ€юща€ простое ли число
bool simple(int num)
{
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)//если хот€бы одно число делитс€ без остачи значит number не простое
		{
			return false;
		}
	}
	return true;
}