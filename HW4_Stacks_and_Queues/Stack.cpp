#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

#define MAX 3

struct MyStack {
	int top; //????
	char a[MAX]; //????
	bool IsEmpty(); //????????,???? 1,?? 0
	bool IsFull(); //????????,???? 1,?? 0
	void Push(char); //??????????
	char Pop(); //??????????????
	
	MyStack() {
		top = -1;
	}  
};


int main() {
  MyStack S1;
  char ch;
  ch = S1.Pop();
  S1.Push('a');
  S1.Push('b');
  S1.Push('c');
  ch =S1.Pop();
  printf("Pop:%c\n",ch);
  ch = S1.Pop();
  printf("Pop:%c\n",ch);
  ch = S1.Pop();
  printf("Pop:%c\n",ch);
  system("pause"); return 0; 
}

bool MyStack::IsEmpty() {
  if(top == -1) 
    return true;
  else 
    return false;
}

bool MyStack::IsFull() {
  if(top == MAX-1) 
    return true;
  else
    return false;
}

void MyStack::Push(char c) {
  if(!IsFull() ) {
    top ++;
    a[top] = c;
  } else {
    printf("Can't Push, It's Full!\n");
  }  
}

char MyStack::Pop() {
  char temp;
  if(!IsEmpty() ) {
    temp = a[top];
    a[top] = NULL;
    top --;
  } else {
    printf("Can't Pop, It's Empty!\n");
  }
  return temp;
}
