#include <stdio.h>
#include <string.h>
#define INFILE_LOC "5.txt"
#define OUTFILE_LOC "out.txt"
#define MAX 999
struct MyStack {
	int top; //????
	char a[MAX]; //????
	bool IsEmpty(); //????????,???? 1,?? 0
	bool IsFull(); //????????,???? 1,?? 0
	void Push(char); //??????????
	char Pop(); //??????????????	
	void Print();
	MyStack RemoveES();
	
	MyStack() {
		top = -1;
	}  
};

int main() {
	FILE *fptr = fopen(INFILE_LOC, "r");
	FILE *wptr = fopen(OUTFILE_LOC, "w");
	char c;
	MyStack nw;
	int i=0;
  while(fscanf(fptr, "%c", &c) != EOF) { 
  	nw.Push(c);
  }
	//nw.Print();
	MyStack ans;
	ans = nw.RemoveES();
	
	ans.Print();
	fprintf(wptr,"%s",ans.a);
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

void MyStack::Print() {
	int i=0;
	while(a[i] != '\0') {
		printf("%c",a[i]);
		i++;
	}
	printf("\n");
}

MyStack MyStack::RemoveES() {
	MyStack returnS;
	int i = 0, hold;
	while(a[i] != '\0') {
		if(a[i] == 'e') {
			hold = i;
			hold++;
			while(1) {
				if(a[hold] == 's' ) {
					i = ++hold;
					break;
				} else if(a[hold] == '\n') {
					break;
				} else if(a[hold] == 'e') {
					break;
				} else {
					hold++;
				}
			}
		}
		returnS.Push(a[i]);
		
		i++;
	}
	returnS.Push('\0');
	//returnS.a[strlen(returnS.a)-1] = '\0';
	return returnS;
}







