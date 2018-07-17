#include <iostream>
using namespace std;
template <class T>
inline void Swap(T& a,T& b)
{
	T temp=a;
	a=b;
	b=temp;
}
void insert(int a[],int n,int x)
{
	int i,j;
	for(i=0;i<n;i++)
		if(x<a[i])
			break;
		for(j=n;j>=i;j--)
		a[j]=a[j-1];
	a[i]=x;
}
void insertsort(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=a[i];
		insert(a,i,j);
	}

}
int main()
{
	int a[]={1,4,2,6,4,8,9};
	insertsort(a,7);
	int i=0;
	for(i=0;i<7;i++)
		cout<<a[i]<<endl;

}