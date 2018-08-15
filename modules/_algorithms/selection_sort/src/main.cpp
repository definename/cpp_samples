//ñîðòèðîâêà âûáîðêîé íå ðóêóðñèâíàÿ

#include "pch.h"

int selectionSort(int [], int, int);

int main()
{
	srand(int (time(0)));

	const int size=100;
	int data[size]={0};//íåñîðòèðîâàííûé ìàññèâ
	int element=0;//åëåìåíò 

	//çàïîëíÿåì ìàññèâ ÷èñëàìè
	for (int i=0;i!=size;i++)
	{
		data[i]=rand()%1000;
	}
	
	//âûâîäèì íåñîðòèðîâàííûé ìàññèâ
	cout<<"not sorted array."<<endl;
	for (int j=0;j!=size;j++)
	{
		cout << data[j]<<" ";
	}
	cout << endl;

	//ôóíêöèÿ ðåêóðñèâíîé ñîðòèðîâêè
	selectionSort(data, size, element);

	//âûâîäèì ñîðòèðîâàííûé ìàññèâ
	cout<<"\nsorted array.enjoy."<<endl;
	for (int j=0;j!=size;j++)
	{
		cout << data[j]<<" ";
	}
	cout << endl;
	return 0;
}

//ñîðòèðóåì ìàññèâ ïî âîçðîñòàíèþ
int selectionSort(int data[], int size, int element)
{
  for(int j=0;j!=size;j++)
  {
	
		for(int i=j;i!=size;i++)//íà÷èíàÿ ñ element
		{
			int move=data[j];
			if (data[i]<=data[j])//ñðàâíèâàåì âñå ýëåìåíòû ìàññèâà data[] c data[element]
			{
				data[j]=data[i];
				data[i]=move;
			}
		}
	}
	return 0;
}
