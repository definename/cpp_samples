//��������� ������� ������ ����� � ������ ������� ����� ������������ ���������� �����
//� ���������� ���������

//!!������� � �������

#include "pch.h"
using namespace std;

//������� ������������ ������� �� �����
bool simple(int);

int main()
{
	int x;
	cout<<"enter number"<<endl;
	cin>>x;

	int rightX=x+1;
	int leftX=x-1;
	
	if(x==2)//���� ������� ������ ������� ����� �� ������� ������ ����� ������� ������
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

	//���������� ����� ����� �����
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

//������� ������������ ������� �� �����
bool simple(int num)
{
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)//���� ������ ���� ����� ������� ��� ������ ������ number �� �������
		{
			return false;
		}
	}
	return true;
}