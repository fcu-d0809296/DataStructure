#include<stdio.h>
#include<stdlib.h> 
#define MAX 3

struct MyQueue {
  int front, rear;
  char a[MAX];
  bool IsEmpty(); //????????
  bool IsFull(); //????????
  void enqueue(char); //??????????
  char dequeue(); //???????????
  void showqueue(); //????????
  
  MyQueue() {
    front = rear = 0;
  }
};


int main() {
	MyQueue cirQ;
	char ch=cirQ.dequeue();
	printf("Add a to Queue\n");	
	cirQ.enqueue('a');
	printf("Add b to Queue\n");
	cirQ.enqueue('b');
	printf("Add c to Queue\n");
	cirQ.enqueue('c');
	printf("Add d to Queue\n");
	cirQ.enqueue('d');
	
	printf("%c\n",cirQ.dequeue());
	printf("%c\n",cirQ.dequeue());
	printf("%c\n",cirQ.dequeue());
	printf("%c\n",cirQ.dequeue());

	printf("Add c to Queue\n");
	cirQ.enqueue('c');
	printf("Add d to Queue\n");
	cirQ.enqueue('d');

	printf("%c\n",cirQ.dequeue());
	printf("%c\n",cirQ.dequeue());
  return 0;

}

bool MyQueue::IsEmpty() {
  if(rear == front) 
    return true;
  else 
    return false;
}

bool MyQueue::IsFull() {
  if((rear+1)%MAX == front)
    return true;
  else
    return false;
}


void MyQueue::enqueue(char c) {
  if(IsFull() ) {
    printf("full cannt add %c\n",c);
    return;
  }
  rear = (rear+1)% MAX;
  a[rear] = c;
  
}

char MyQueue::dequeue() {
  char temp;
  if(IsEmpty() ) {
    printf("empty\n");
    return 0;
  }
  front = (front+1)%MAX;
  temp = a[front];
  return temp;
}




