#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED
class BigNum
{
	private:
	string val;
	int len;
	public:
    BigNum(){val="0";len=1};  //���캯��
    BigNum (const BigNum&); //�������캯��
	BigNum &operator=(const BigNum&) const; //���������
	BigNum &operator+(const BigNum&) const;
	BigNum &operator-(const BigNum&) const;
	BigNum &operator*(const BigNum&) const;
	bool   &operator>(const BigNum&) const;
	bool   &operator<(const BigNum&) const;
	bool   &operator==(const BigNum&)const;

	friend istream &operator>>(istream&,BigNum&);
	friend ostream &operator<<(ostream&,BigNum&);
};


#endif // BIGNUM_H_INCLUDED
