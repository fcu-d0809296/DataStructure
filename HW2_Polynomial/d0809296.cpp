#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct polynomial {
  int coef ; //�h�������Y��
  int expon ; //�h����������
};

struct MyPoly {
  polynomial terms[MAX] ; //�h�����}�C
  int size ; //�h�����j�p
  MyPoly(); //�غc�l ��l�� size = 0
  MyPoly(const char*); //�غc�l Ū�J�ɮ�
  void ShowPoly( ) ; //�L�X�h�������e
  MyPoly Add(MyPoly) ; //�h�����ۥ[
  void SingleMult(int) ; //�N�h�������W�@�Y��
  int Lead_Exp() ; //�^�Ǧh�������̤j���ƪ�����
  void Attach(float, int) ; //�s�W 1 �Ӷ�����h������
  void Remove(int); //�R���h���������Y�@����
  MyPoly Mult(MyPoly); //�h�����ۭ�
};
int cpr(int ,int);

int main() {
  int i,input;
  while (1) {
  	printf( 
		"1. Read Polynomial\n"
		"2. Show\n"
		"3. Add\n"
		"4. Poly multiply by NUM\n"
		"5. Print Leading Expon.\n"
		"6. Add a expon. and coef.\n"
		"7. Delete a NUM\n"
		"8. Multiply two Poly.\n"
		"option: "
		);
		scanf("%d",&input);
		printf("\n");
		switch(input) {
			case 1: {
				MyPoly poly1("B1.txt");
  			MyPoly poly2("B2.txt");
				break;
			}
			case 2: {
				poly1.ShowPoly();
				poly2.ShowPoly();
				break;
			}
			case 3: {			
			  MyPoly poly3 = poly1.Add(poly2);
			  poly3.ShowPoly();
				break;
			}
			case 4: {
				int num;
				printf("Enter a NUM\n")
				scanf("%d",num);
				poly1.SingleMult(num);
				poly1.ShowPoly();
				break;
			}
			case 5: {
				printf("%d\n",poly1.Lead_Exp());
				break;
			}
			case 6: {
				printf("Enter c and e:\n")
				scanf("%f %d",&c,&e);
				poly1.Attach(c,e);
				poly1.ShowPoly();
				break;
			}
			case 7: {
				int num;
				printf("Enter a NUM\n")
				scanf("%d",num);
				poly1.Remove(num);
				poly1.ShowPoly();
				break;
			}
			case 8: {
			  MyPoly poly4 = poly1.Add(poly2);
			  poly4.ShowPoly();
				break;
			}
		}
	}
}

MyPoly::MyPoly() {
  size = 0;
}

MyPoly::MyPoly(const char *filename) {
  FILE *fptr=NULL;
	size = 0;
  fptr = fopen(filename, "r");
  
  while( !feof(fptr)) {
    fscanf(fptr,"%d %d",&terms[size].coef, &terms[size].expon);
    size++;
  }
}

void MyPoly::ShowPoly() {
  for(int i=0; i<size; i++ ) printf("%dx^%d + ",terms[i].coef, terms[i].expon);
  printf("\b\b \n");
}

MyPoly MyPoly::Add(MyPoly p2) { 
  MyPoly tempPoly;
  int indexA = 0, indexB=0;
  while(indexA < size && indexB < p2.size) {
    if(terms[indexA].expon > p2.terms[indexB].expon) {
      tempPoly.Attach(terms[indexA].coef, terms[indexA].expon);
      indexA++;
    }else if(terms[indexA].expon < p2.terms[indexB].expon) {
      tempPoly.Attach(p2.terms[indexB].coef, p2.terms[indexB].expon);
      indexB++;
    } else {
      int sum = terms[indexA].coef + p2.terms[indexB].coef;
      if(sum) {
        tempPoly.Attach(sum,terms[indexA].expon);
        indexA++;indexB++;
      }
    }
  } 
  for(int i=indexA; i<size; i++)
    tempPoly.Attach(terms[i].coef, terms[i].expon);
  for(int i=indexB; i<p2.size; i++)
    tempPoly.Attach(p2.terms[i].coef, p2.terms[i].expon);

  return tempPoly;
}

int MyPoly::Lead_Exp() {
  int max=0;
  for(int i=0; i<size; i++) {
    if(terms[i].expon > max)
      max = terms[i].expon;
  }
  return max;
}

void MyPoly::Attach(float c, int e) {
  terms[size].coef = c;
  terms[size].expon = e;
  size++;
}

void MyPoly::Remove(int e) {
  int i = 0;
  while(i < size) {
    if(terms[i].expon == e)
      break;
    i++;
  }
  while(i < size) {
    terms[i] = terms[i+1];
    i++;
  }
  size --;
}

void MyPoly::SingleMult(int n) {
	for(int i=0; i<size; i++)
		terms[i].coef	*= n;
}

MyPoly MyPoly::Mult(MyPoly p2) {
	MyPoly tempPoly2;
	int indexA=0, indexB=0;
	//printf("size: %d\n",tempPoly2.size);
	tempPoly2.ShowPoly();
	while(indexA < size) {
		indexB=0;
		MyPoly tempPoly1;
		while(indexB < p2.size) {
			
			polynomial tempNum;
			tempNum.coef = terms[indexA].coef * p2.terms[indexB].coef;
			tempNum.expon = terms[indexA].expon + p2.terms[indexB].expon;
			tempPoly1.Attach(tempNum.coef, tempNum.expon);
			indexB++;
			
		}	
		//tempPoly1.ShowPoly();
		
		tempPoly2 = tempPoly2.Add(tempPoly1);
		
		indexA++;
		
	}
	
	return tempPoly2;
}

