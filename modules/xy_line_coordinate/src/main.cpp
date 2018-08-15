//зная начальную точку
//зная конечную точку
//вычисляем точки траэктории

//записывает в файл
#include "pch.h"

void calculate(int,int,int);

int coordinate[1][10000];

int main()
{
	int x1=323;
	int y1=145;

	int x2=23;
	int y2=276;
	fstream data("data.txt",  ios::out|ios::trunc);
		if(data)
		{
			cout<<"create"<<endl;
		}
		else
		{
			cout<<"notcreate"<<endl;
		}
		data.close();

	calculate(x1,x2,0);
	cout<<endl;
	calculate(y1,y2,1);

	int x=0;
	int y=1;
	data.open("data.txt",ios::out|ios::app);

	for(int i=0;i!=999;i++)
	{
		data<<coordinate[x][i]<<"............"<<coordinate[y][i]<<endl;
	}
	return 0;
}

void calculate(int startPoint, int finishPoint, int arr)
{
	fstream data("data.txt", ios::out|ios::app);
		if(data)
		{
			cout<<"open"<<endl;
		}
		else
		{
			cout<<"close"<<endl;
		}
	int currPoint;
	
	int i=0;
	for(double t=0.1;t<=1;t+=0.001,i++)
	{
		currPoint = startPoint + (finishPoint - startPoint) * t;
		data<<currPoint<<endl;
		cout<<currPoint<<endl;
		coordinate[arr][i]=currPoint;
	}
}