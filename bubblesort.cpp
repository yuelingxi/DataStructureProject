#include <iostream>
using namespace std;
template <class T>
inline void Swap(T& a,T& b)
{
	T temp=a;
	a=b;
	b=temp;
}
void bubble(int a[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			Swap(a[i],a[i+1]);
}
void bubblesort(int a[],int n)
{
	int i=0;
	for(i=n;i>0;i--)
		bubble(a,i);
}
int main()
{
	int a[]={1,4,2,6,4,8,9};
	bubblesort(a,7);
	int i=0;
	for(i=0;i<7;i++)
		cout<<a[i]<<endl;
}