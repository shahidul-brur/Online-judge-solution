#include <iostream>
using namespace std;
 
int main() 
{
	int n, n1, n2;
	while(cin>>n)
	{
		n1 = n/10;
		n2 = n1/10 * 10 + n%10;
		cout << max(n, max(n1, n2)) << "\n";
	}
	return 0;
}