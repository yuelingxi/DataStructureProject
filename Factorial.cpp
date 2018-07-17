#include <iostream>
using namespace std;
int Factorial(int num)
{
	if(num==1)
		return 1;
	else
		return num*Factorial(num-1);
}
int main()
{
	cout<<Factorial(9);
}