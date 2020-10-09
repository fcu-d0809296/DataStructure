#include <stdio.h>

struct myTime {
	int year;
	int month;
	int day;
};
struct myCal {
	myTime inDate;
	myCal();
	myCal(char*);
	myCal(int,int,int);
	int isLeap(int);
	int DiffTime();
	int DiffTime(myTime);
	int GetWeekDay();
	void PrintMonth();
	void PrintYear();
};

///////////////////////////////
int main() {
	myCal d("date.txt");
	//printf("%d.%d.%d %d.%d.%d\n",d.inDate.year,d.inDate.month,d.inDate.day,e.inDate.year,e.inDate.month,e.inDate.day);
	/**
	myCal e(2020,10,1);
	printf("%d",d.DiffTime(e.inDate));
	**/
}
//////////////////////////////
myCal::myCal() {
	printf("no data\n");
} 

myCal::myCal(char *file) {
	FILE *fptr = fopen(file,"r");
	fscanf(fptr,"%d",&inDate.year);
	fscanf(fptr,"%d",&inDate.month);
	fscanf(fptr,"%d",&inDate.day);
	fclose(fptr);
}

myCal::myCal(int y, int m, int d) {
	inDate.year = y;
	inDate.month = m;
	inDate.day = d;
}

int myCal::isLeap(int n) {
	if( n%400==0 || ( n%4==0 && n%100!=0 ) ) {
		return 1;
	} else {
		return 0;
	}
}

int myCal::DiffTime() {
	int totalDays = 0;
	int i;
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=1900; i<inDate.year; i++) {
		if(isLeap(i)) totalDays +=366;
		else totalDays +=365;
	}
	for(i=1; i<inDate.month; i++) {
		totalDays += monthday[i-1];
		if(i==2 && isLeap(inDate.year)) totalDays++;
	}
	totalDays +=inDate.day;
	return totalDays;
}

int myCal::DiffTime(myTime target) {
	myTime begin,end;
	
	if(inDate.year > target.year) {
		end = inDate;
		begin = target;
	}else if(inDate.year < target.year) {
		end = target;
		begin = inDate;
	}else if(inDate.year == target.year) {
		if(inDate.month > target.month) {
			end = inDate;
			begin = target;
		}else if(inDate.month < target.month) {
			end = target;
			begin = inDate;
		}else if(inDate.month == target.month) {
			
			if(inDate.day > target.day) {
				end = inDate;
				begin = target;
				
			}else if(inDate.day < target.day) {
				end = target;
				begin = inDate;
				
			}
		}
	}
	int totalDays = 0;
	int i;
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(begin.year != end.year) {
		for(i=begin.year+1; i<end.year; i++) {
			if(isLeap(i)) totalDays +=366;
			else totalDays +=365;
		}
		
		for(i=begin.month; i<12; i++) {
			totalDays += monthday[i-1];
			if(i==2 && isLeap(end.year)) totalDays++;
		}
		for(i=1; i<end.month; i++) {
			totalDays += monthday[i-1];
			if(i==2 && isLeap(end.year)) totalDays++;
		}
		
		totalDays = totalDays + (monthday[begin.month-1] - begin.day);
		totalDays += end.day;
		
	} else {
		
		if(begin.month != end.month) {
			for(i=begin.month+1; i<end.month; i++) {
				totalDays += monthday[i-1];
				if(i==2 && isLeap(end.year)) totalDays++;
			}
			totalDays = totalDays + (monthday[begin.month-1] - begin.day);
			totalDays += end.day;
		} else {
			totalDays = end.day - begin.day;
		}
	}
	totalDays += 1;//current day
	return totalDays;
}

int myCal::GetWeekDay() {
	int weekday = DiffTime();
	return weekday % 7;
}

void myCal::PrintMonth() {
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	myCal temp(inDate.year,inDate.month,1);
	int weekday = temp.GetWeekDay();
	printf("%10s %10s %10s %10s %10s %10s %10s\n","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday");
	int i,j;
	for(i=0; i<weekday; i++) printf("%10s","");
	for(j=1; j<=monthday[temp.inDate.month-1]; j++) {
		printf("%10d",j);
		if( (i+j)%7 ==0 ) printf("\n");
	}
	if(inDate.month==2 && isLeap(inDate.year)) printf("%10d",29);
}

void myCal::PrintYear() {
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	myCal temp(inDate.year,1,1);
	
	int i,j,l;
	for(l=0; l<12; l++) {
		int weekday = temp.GetWeekDay();
		printf("Month: %d\n",temp.inDate.month);
		printf("%10s %10s %10s %10s %10s %10s %10s\n","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday");
		for(i=0; i<weekday; i++) printf("%10s","");
		for(j=1; j<=monthday[temp.inDate.month-1]; j++) {
			printf("%10d",j);
			if( (i+j)%7 ==0 ) printf("\n");
		}
		if(inDate.month==2 && isLeap(inDate.year)) printf("%10d",29);
		printf("\n---------------------------------------------------\n");
		temp.inDate.month +=1;
	}
}
