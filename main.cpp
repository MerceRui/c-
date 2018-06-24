#include <iostream>
using namespace std;
#include <string>
#include <vector>
int main()
 {
 	int b[5],i;
 	string a;
 	for(i=0;i<5;i++)
	cin>>b[i];
    for(i=0;i<5;i++)
		a+=(char)(b[i]+'0');
 	cout<<a;
	return 0;
}
