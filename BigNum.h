#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED
class BigNum
{
	private:
	string val;
	int len;
	public:
    BigNum(){val="0";len=1};  //构造函数
    BigNum (const BigNum&); //拷贝构造函数
	BigNum &operator=(const BigNum&) ; //重载运算符
	BigNum &operator+( BigNum&) ;
	BigNum &operator-( BigNum&) ;
	BigNum &operator*(const BigNum&) const;
	bool   &operator>(const BigNum&) const;
	bool   &operator<(const BigNum&) const;
	bool   &operator==(const BigNum&)const;

	friend istream &operator>>(istream&,BigNum&);
	friend ostream &operator<<(ostream&,BigNum&);
};


#endif // BIGNUM_H_INCLUDED
