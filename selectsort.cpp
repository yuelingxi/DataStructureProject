#include <iostream>
using namespace std;
template <class T>
inline void Swap(T& a,T& b)
{
	T temp=a;
	a=b;
	b=temp;
}
void selectsort(int a[],int n)
{
	int i,j;
	for(i=n-1;i>=0;i--)
		for(j=0;j<i;j++)
			if(a[j]>=a[i])
				Swap(a[i],a[j]);
	
}
int main()
{
	int a[]={1,4,2,6,4,8,9};

	selectsort(a,7);
	int i=0;
	for(i=0;i<7;i++)
		cout<<a[i]<<endl;

}