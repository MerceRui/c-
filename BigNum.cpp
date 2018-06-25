#include <iostream>
#include <string>
#include"BigNum.h"
using namespace std;
void sti(const string a,int *b)
{
	int i;
	for(i=0;i<a.length();i++)
	{
		b[a.length()-i-1]=a[i]-'0';
	}
}
BigNum::BigNum(const BigNum& b)//拷贝构造
{
	len=b.len;
	val=b.val;
}
BigNum& BigNum::operator=(const BigNum& b) //重载赋值
{
	BigNum a;
	a.len=b.len;
	a.val=b.val;
	return a;
}
BigNum& BigNum::operator+( BigNum& b) //重载加法
{
	BigNum a,t;
	if(a.len<b.len) t=b,b=a,a=t;
	int i,j;
     for(i=a.len-1,j=b.len-1;i>=0;i--,j--)
{
         a.val[i]=(a.val[i]+(j>=0?b.val[j]-'0':0));
         if(a.val[i]>'9')
         {
             a.val[i] -=10;
             if(i) a.val[i-1]++;
            else a.val='1'+a.val;
         }
}
return a;
}
BigNum& BigNum::operator-( BigNum& b)
{
	BigNum a,t;
	int i,j,f=0;
	if(a.len<b.len||(a.len==b.len&&a.val<b.val))
		{t=b,b=a,a=t;f=1;}
	for(i=a.len-1,j=b.len-1;i>=0;i--,j--)
	{
	   if(j>=0){
		if(a.val[i]<b.val[j]) {a.val[i-1]--;a.val[i]+=10;}
	    a.val[i]=a.val[i]-(b.val[j]-'0');
	   }
	}
	if(f) a.val="-"+a.val;
	return a;
}
BigNum& BigNum::operator*(const BigNum& b)const
{
	BigNum a;
	int c[a.len+b.len]={0},av[a.len],bv[b.len];
	int i,j;
    sti(a.val,av);
    sti(b.val,bv);
     a.val="";
    for(i=0;i<a.len;i++){
		for(j=0;j<b.len;j++)
		c[i+j]+=av[i]+bv[j];
    }
    for(i=0;i<a.len+b.len;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	while(c[j]==0)
		j--;
	for(j=a.len+b.len-1;j>=0;j--)
	{
      a.val+=(char)(c[j]+'0');
	}
	return a;
}
istream& operator>>(istream& in,BigNum& b)
{
	in>>b.val;
	b.len=b.val.length();
	return in;
}
ostream& operator<<(ostream&out, BigNum& b)
{
	cout<<b.val;
	return out;
}
bool BigNum::operator>(const BigNum& b)const
{
	BigNum a;
	if(a.len>b.len||(a.len==b.len&&a.val>b.val)) return true;
	else return false;
}
bool BigNum::operator<(const BigNum& b)const
{
	BigNum a;
	if(a.len>b.len||(a.len==b.len&&a.val>b.val)) return false;
	else return true;
}
bool BigNum::operator==(const BigNum& b)const
{
	BigNum a;
	if((a.len==b.len)&&(a.val==b.val)) return true;
	else return false;
}
