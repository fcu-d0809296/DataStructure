#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8
#define FILELOC "hw2.txt"
struct MyBin {
	int binArr[MAX];
	int dec;
	MyBin(); //Initiallize
	void BinLoad(char *);
	void PrintBin();
	void BinToDec();
	void DecToBin();
	void NotBin(int, int);
	int FindFirstOne();
};

int CalcDec(int,char,int);
int main() {
	MyBin bin1,bin2,binAns;
	FILE* fp_r = fopen(FILELOC,"r");
	if(fp_r != NULL) {
		char temp[MAX] = {0},opr;
		
		fscanf(fp_r,"%s\n",temp);
		bin1.BinLoad(temp);
		bin1.PrintBin();
		
		fscanf(fp_r,"%c",&opr);
		printf(" %c ",opr);
		
		fscanf(fp_r,"%s\n",temp);
		bin2.BinLoad(temp);
		bin2.PrintBin();
		
		bin1.BinToDec();
		bin2.BinToDec();
		printf(" = ");
		
		binAns.dec = CalcDec(bin1.dec, opr, bin2.dec);
		//printf("%d\n",binAns.dec);
		//binAns.PrintBin();
		if(binAns.dec<0){
			//binAns.dec +=1;
			binAns.DecToBin();
			//binAns.PrintBin();
			int index=binAns.FindFirstOne();
			//printf("\n%d\n",index);
			binAns.NotBin(index+1, MAX-1);
			binAns.PrintBin();
			printf(" (%d %c %d = %d)",bin1.dec,opr,bin2.dec,binAns.dec);
		}else {
			binAns.DecToBin();
			binAns.PrintBin();
		}
		
	} else {
		printf("File not Exist.\n");
		return 0;
	}		
}
MyBin::MyBin() {
	for(int i=0;i<MAX;i++) {
		binArr[i]=0;
	}
	dec=0;
}
void MyBin::BinLoad(char *temp) {
	int indexTail; // count length of array
	int i=0;//index of temp
	indexTail = strlen(temp) -1 ;

	while(indexTail >= 0){
		int tempNum;
		if(temp[i]=='0') tempNum = 0;
		if(temp[i]=='1') tempNum = 1;
		binArr[indexTail] = tempNum;
		indexTail--;
		i++;
	}
}

void MyBin::PrintBin() {
	for(int i=MAX-1; i>=0; i--) {
		printf("%d",binArr[i]);
	}
}
void MyBin::BinToDec() {
	int multi2 = 1;
		for (int i=0; i<MAX; i++) {
			dec = dec + (binArr[i] * multi2);
			//printf("%d: %d * %d = %d\n",i,binArr[i],multi2,dec);
			multi2 *=2;	
		}
}
void MyBin::DecToBin() {
	int i=0;
	int temp = dec;
	
	while(temp!=0) {
		binArr[i] = temp%2;
		i++;
		temp = temp/2;
	}
	for(i=0; i<MAX; i++) {
		if(binArr[i] == -1) binArr[i] = 1;
	}

}
int CalcDec(int num1, char opr, int num2) {
	int temp;
	switch(opr) {
		case '+' : {
			temp = num1 + num2;
			break;}
		case '-' : {
			temp = num1 - num2;
			break;}
	}
	return temp;
}
void MyBin::NotBin(int begin, int end) {
	for(int i=begin;i<=end;i++) {
		if(binArr[i]==0)
			binArr[i]=1;
		else
			binArr[i]=0;
	}
}
//========================
int MyBin::FindFirstOne() {
	for(int i=0;i<MAX;i++) {
		if(binArr[i]==1||binArr[i]==-1)
			return i;
	}
	return -1;
}


