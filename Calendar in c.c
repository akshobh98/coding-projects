//**************************************************
//
// Akshobh Mirapurkar
// Calendar in c
//
//
//**************************************************
#include<stdio.h>
void eventLoop();
void writeMenu();
int isLeapYear(int year);
int handler(char event);
void testLeapYear();
int getDaysinMonth(int year, int month);
void testDaysinMonth();
void waitUp();
int validYear(int year);
int validMonth(int month);
int validDay(int year, int month, int day);
int isValidDate(int year,int month,int day);
void testValidDate();
int getDayinYear(int year, int month, int day);
void testDayinYear();
void writeDate(int year, int month, int day);
void testWriteDate();
const int FALSE=0;
const int TRUE=1;
const int EXIT_SUCCESS=0;

int main(){
    printf("\n\nProject 2.\n\n");
    eventLoop();
    printf("\n\nEnd of Project 2.\n\n");
    return EXIT_SUCCESS;
}



void eventLoop(){
    int done=FALSE;
    char event;
    while (!done){
        writeMenu();
        scanf(" %c", &event);
        fflush(stdin);
        done=handler(event);
    }
}

int handler(char event){
    int month;
    int year;
    int day;
    switch(event){
        case 'H':
        case 'h':
            printf("\nHello from Akshobh!\n");
            waitUp();
            printf("----------------------------------------------------");
            break;
        case 'L':
        case 'l':
            testLeapYear();
            printf("----------------------------------------------------");
            break;
        case 't':
        case 'T':
            testDaysinMonth();
            waitUp();
            printf("----------------------------------------------------");
            break;
        case 'v':
        case 'V':
             testValidDate();
             waitUp();
             printf("----------------------------------------------------");
            break;
        case 'g':
        case 'G':
            testDayinYear();
            waitUp();
            printf("----------------------------------------------------");
            break;
        case 'w':
        case 'W':
            testWriteDate();
            waitUp();
            printf("----------------------------------------------------");
            break;
        case 'q':
        case 'Q':
            return TRUE;
        default:
            printf("\nBad Input. Try again.\n");
            printf("----------------------------------------------------");
        }
    return FALSE;
}

void writeMenu(){
     printf("\nProgram 2");                                         printf("\n\nAkshobh Mirapurkar");
     printf("\n\nChoose one of the following:\n\n");
     printf("\n H: Hello from programmer");
     printf("\n L: Test for leap year.");
     printf("\n C: Calender.");
     printf("\n Q: Quit");
     printf("\n\nEnter a choice in {H, L, T, V, G, W, Q} :");
}

void testLeapYear(){
    int year;
    printf("\nEnter a year:");
    scanf("%d", &year);
    if (isLeapYear(year)) {
        printf("\n%d is a leap year!", year);
    } else {
        printf("\n%d is not a leap year", year);
    }
    waitUp();
}

int isLeapYear(int year){
    if ((year % 400==0)){
        return TRUE;
    } else if(year%4==0 && year%100!=0){
       return TRUE;
    } else {
        return FALSE;
    }
}

void waitUp(){
  printf("\nEnter any key to continue:");
  char key;

  scanf(" %c", &key);
}

int getDaysinMonth(int year, int month){
        switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year)){
                return 29;
            }else{
                return 28;
            }
        default:
            return -1;
    }
}

void testDaysinMonth(){
    int month;
    printf("\nEnter month:");
    scanf(" %d",&month);
    if (!validMonth(month)) {
        printf("\nBad month entered. Try again.");
        return;
    }
    int year;
    printf("\nEnter year:");
    scanf(" %d",&year);
    if (!validYear(year)) {
        printf("\nBad year entered. Try again.");
        return;
    }
    int days = getDaysinMonth(year,month);
    printf("%d", days);


}

int validYear(int year){
    if(year>0){
        return TRUE;
    } else {
        return FALSE;
    }
}

int validMonth(int month){
    if(month>=1 && month<=12){
        return TRUE;
    } else {
        return FALSE;
    }
}

int validDay(int year, int month, int day){
    if(day>=1 && day<=getDaysinMonth(year,month)){
        return TRUE;
    } else {
        return FALSE;
    }
}

int isValidDate(int year,int month,int day){
    if (!validYear(year)) {
        return FALSE;
    }
    if (!validMonth) {
        return FALSE;
    }
    if (!validDay(year, month, day)) {
        return FALSE;
    }
    return TRUE;
}

void testValidDate(){
    int year;
    int month;
    int day;
    printf("\nProvide date information in yyyy mm dd format.");
    printf("\nEnter year:");
    scanf("%d",&year);
    if(!validYear(year)){
        printf("\nBad year entered.");
        return;
    }
    printf("\nEnter month:");
    scanf("%d",&month);
    if(!validMonth(month)){
        printf("\nBad month entered.");
        return;
    }
    printf("\nEnter day:");
    scanf("%d",&day);
    if(!validDay(year,month,day)){
        printf("\nBad day entered.");
        return;
    }
    if(isValidDate(year,month,day)){
        printf("%d/%d/%d",year,month,day);
    } else {
        printf("\nBad date entered.");
    }
}

int getDayinYear(int year, int month, int day){
    int sum=0;
    int i;
    for(i=1; i < month; i += 1) {
        sum+=getDaysinMonth(year, i);
    }
    sum += day;
    return sum;
}

void testDayinYear(){
    printf("\n\n\n");
    printf("\nTest day in a year");
    int year;
        printf("\nEnter the year:");
        scanf("%d",&year);
        if(!validYear(year)){
            printf("\nBad year entered.");
            return;
        }
    int month;
        printf("\nEnter month:");
        scanf("%d",&month);
        if(!validMonth(month)){
            printf("\nBad month entered.");
            return;
        }
    int day;
        printf("\nEnter day:");
        scanf("%d",&day);
        if(!validDay(year,month,day)){
            printf("\nbad date entered.");
            return;
        }
    if(isValidDate(year,month,day)){
        printf("\nDay in year is %d", getDayinYear(year,month,day));
    } else {
        printf("\nBad date entered.");
    }

}

void writeDate(int year, int month, int day){
    if(!isValidDate(year,month,day)){
        printf("\nYear %d, month %d, day %d is NOT valid date.",year,month,day);
    } else {
        printf("\nYear %d, month %d, day %d is the day number %d in the year",year,month,day,getDayinYear(year,month,day));
    }
}

void testWriteDate(){
   int year;
        printf("\nEnter the year:");
        scanf("%d",&year);
        if(!validYear(year)){
            printf("\nBad Year entered.");
            return;
        }
    int month;
        printf("\nEnter month:");
        scanf("%d",&month);
        if(!validMonth(month)){
            printf("\nBad month entered.");
            return;
        }
    int day;
        printf("\nEnter day:");
        scanf("%d",&day);
        if(!validDay(year,month,day)){
            printf("\nBad day entered.");
            return;
        }
    writeDate(year,month,day);
}

