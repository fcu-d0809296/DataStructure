#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

#define MAXLONG 40
#define MAX 20

struct LongInt
{
	int MyInt[MAXLONG];
	bool IsPositive;
	
	LongInt();
	LongInt(int);
	LongInt(char*);
	int Compare(LongInt);
	bool operator>(LongInt);
	bool operator<(LongInt);
	bool operator==(LongInt);
	LongInt Add(LongInt);
	LongInt operator+(LongInt);
	LongInt Sub(LongInt);
	LongInt operator-(LongInt);
	LongInt Multi(LongInt);
	LongInt Div(LongInt);
	void Show();
	void Zero();
};
//=============================
int main()
{
	srand(time(0));
	LongInt a("9999999999999999999999999999999999999999");
	a.Show();
	LongInt b("3333333333333333333333333333333333333333");
	b.Show();
	LongInt c = a.Div(b);
	c.Show();
//	LongInt b("55555555555555555555");
//	b.Show();
//	LongInt c;
//	c = a.Multi(b);
//	c.Show();
//	LongInt b("123456789012345678901234567890");
//	b.Show();
	return 0;
}

//=============================
LongInt::LongInt()
{
	IsPositive=true;
	Zero();
	for(int i=0;i<MAX;i++)
	{
		MyInt[i]=0;
	}
	for(int i=0;i<MAX-1;i++)
	{
		MyInt[i]=rand()%10;
	}	
}
//=============================
LongInt::LongInt(int num)
{
	IsPositive=true;
	Zero();
	int i=0;
	while(num!=0)	
	{
		MyInt[i]=num%10;
		num=num/10;
		i++;
	}
}
//=============================
LongInt::LongInt(char* str)
{
	int i=0;
	IsPositive=true;
	int count=0;
	Zero();
	while(str[count]!='\0')
		count++;

	i=0;
	while(str[i]!='\0')
	{
		MyInt[count-1-i]=str[i]-'0';
		i++;
	}
	
}
//=============================
void LongInt::Show() 
{
	int headIndex = MAXLONG-1;
	if(!IsPositive)
		printf("-");
	else
		printf(" ");
	
	while(MyInt[headIndex] == 0)
		headIndex--;
	printf("%d\n",headIndex);
	if(headIndex > MAX -1)
		headIndex = MAXLONG;
	else
		headIndex = MAX;

	for(int i=headIndex-1;i>=0;i--)
		printf("%d",MyInt[i]);
		
	printf("\n");
} 
//=============================
void LongInt::Zero()
{
	for(int i=0; i<MAXLONG; i++)
		MyInt[i] = 0;
}
//=============================
int LongInt::Compare(LongInt b)
{
	// �o�̨S��������t
	for(int i=MAX-1;i>=0;i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return 1;
		else if(MyInt[i]<b.MyInt[i])
			return -1;
	}
	return 0;	
}
//=============================
bool LongInt::operator>(LongInt b)
{
	for(int i=MAX-1;i>=0;i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return true;
		else if(MyInt[i]<b.MyInt[i])
			return false;
	}	
	return false;
}
//=============================
bool LongInt::operator<(LongInt b)
{
	for(int i=MAX-1;i>=0;i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return false;
		else if(MyInt[i]<b.MyInt[i])
			return true;
	}	
	return false;
}
//=============================
bool LongInt::operator==(LongInt b)
{
	for(int i=MAX-1;i>=0;i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return false;
		else if(MyInt[i]<b.MyInt[i])
			return false;
	}	
	return true;
}
//=============================
LongInt LongInt::Add(LongInt b)
{
	LongInt temp;
	for(int i=0;i<MAX;i++)
	{
		temp.MyInt[i]=MyInt[i]+b.MyInt[i];
	}
	
	for(int i=0;i<MAX;i++)
	{
		if(temp.MyInt[i]>=10)
		{
			temp.MyInt[i]-=10;
			temp.MyInt[i+1]++;			
		}
	}
	return temp;	
}
//=============================
LongInt LongInt::operator+(LongInt b)
{
	LongInt temp;
	temp=Add(b);
	return temp;
}
//=============================
LongInt LongInt::Sub(LongInt b)
{
	LongInt S1, S2, result;
	if(*this > b)
	{
		S1=*this;
		S2=b;
		result.IsPositive=true;
	}
	else
	{
		S1=b;
		S2=*this;
		result.IsPositive=false;
	}
	for(int i=0;i<MAX;i++)
	{
		result.MyInt[i]=S1.MyInt[i]-S2.MyInt[i];
	}

	for(int i=0;i<MAX;i++)
	{
		if(result.MyInt[i]<0)
		{
			result.MyInt[i]+=10;
			result.MyInt[i+1]--;
		}			
	}
	return result;	
}
//=============================
LongInt LongInt::operator-(LongInt b)
{
	LongInt temp;
	temp=Sub(b);
	return temp;
}
//=============================
LongInt LongInt::Multi(LongInt b)
{
	LongInt temp;
	for(int i=0;i<MAX;i++)
	{
		temp.MyInt[i]=MyInt[i]*b.MyInt[i];
	}
	
	for(int i=0;i<MAX;i++)
	{
		if(temp.MyInt[i]>=10)
		{
			temp.MyInt[i]-=10;
			temp.MyInt[i+1]++;			
		}
	}
	return temp;
}
//=============================
LongInt LongInt::Div(LongInt b)
{
	LongInt temp = *this;
	LongInt result;
	LongInt one("1");
	result.Zero();
	while(temp>b || temp==b){
		temp = temp-b;
		result = result+one;
	}
	if(result<one){
		return 0;
	}else{
		return result;
	}
}







