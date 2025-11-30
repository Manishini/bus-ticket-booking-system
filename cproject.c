#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define SEAT_COUNT 30
#define ROUTE "Dehradun to Haridwar"
#define FARE 180

typedef struct{

int seatNum;
int BookedOrNot;
char name[50];
char phone[15];
}Seat;

 void loadData(Seat s[]);
void saveData(Seat s[]);
void viewMenu();
void viewSeat(Seat s[]);
void bookSeat(Seat s[]);
void cancelSeat(Seat s[]);
void searchSeat(Seat s[]);
void showTicket(Seat *s);
void printTicket(Seat *s);

int main(){
Seat s[SEAT_COUNT];
loadData(s);

int choice;

while(1){
viewMenu();
printf("Enter choice(1-7): ");
scanf("%d",&choice);

switch (choice){
case 1:
viewSeat(s);break;
case 2:
bookSeat(s);break;
case 3:
cancelSeat(s);break;
case 4:
searchSeat(s);break;
case 5:
saveData(s);
printf("Thanks for visiting our site, Goodbye!\n");
exit(0);
case 6:
showTicket(s);break;
case 7:
exit(1);

default:
printf("Invalid choice\n");
}
}
return 0;
}

void viewMenu() {
printf("\nBUS TICKET BOOKING SYSTEM\n");
printf("-----------------------------\n");
printf("1.View Seat Layout\n");
printf("2.Book a seat\n");
printf("3.Cancel Booking\n");
printf("4.Search Seat\n");
printf("5.To save data\n");
printf("6.To Show Ticket\n");
printf("7.To exit\n");
}

void loadData(Seat s[]){
FILE *fp = fopen("details.txt","r");

for(int i=0;i<=SEAT_COUNT;i++){
s[i].seatNum=i+1;
s[i].BookedOrNot = 0;
strcpy(s[i].name, "");
strcpy(s[i].phone, "");
}
if(!fp) return;

for(int i=0;i<SEAT_COUNT; i++){
fscanf(fp,"%d %d %s %s",&s[i].seatNum,&s[i].BookedOrNot,s[i].name,s[i].phone);
}
fclose(fp);
}

void saveData(Seat  s[]){
FILE *fp = fopen("details.txt","w");

for(int i=0;i<SEAT_COUNT; i++){
fprintf(fp, "%d %d %s %s", s[i].seatNum,s[i].BookedOrNot,s[i].name,s[i].phone);
}
fclose(fp);
}

void viewSeat(Seat s[]){
printf("\nSeat layout:\n 0=Free,1=Booked\n\n");

for(int i=0;i<SEAT_COUNT;i++){
printf("%2d[%d]",s[i].seatNum,s[i].BookedOrNot);

if((i+1) % 4 == 0){
printf("\n");
}
}
}
void bookSeat(Seat s[]){

int a;
printf("Enter a seat number(1-30): ");
scanf("%d",&a);
if(a<1 || a>SEAT_COUNT){
printf("Invalid Seat!");
return;
}
if(s[a-1].BookedOrNot){
printf("Seat is already booked\n");
return;
}
printf("Enter passanger name: \n");
scanf(" %25[^\n]",s[a-1].name);

printf("Enter phone number:\n ");
scanf("%s",s[a-1].phone);

s[a-1].BookedOrNot = 1;
printf("Your Seat no.%d is successfully booked!\n",a);

printTicket(&s[a-1]);
}

void cancelSeat(Seat s[]){
int a;
printf("Enter your seat no. for cancellation: \n");
scanf("%d",&a);

if(a<1 || a>SEAT_COUNT){
printf("Invalid Seat!");
return;
}
if(!s[a-1].BookedOrNot){
printf("Seat is already free\n");
return;
}

s[a-1].BookedOrNot=0;
strcpy(s[a-1].name,"");
strcpy(s[a-1].phone,"");

printf("Booking Cancellation Successful\n");
}

void searchSeat(Seat s[]){

int a;
printf("Enter your seat no. for cancellation:\n ");
scanf("%d",&a);

if(a<1 || a>SEAT_COUNT){
printf("Invalid Seat!\n");
return;
}
if(s[a-1].BookedOrNot){
printf("Seat is already booked.\n");
printf("Name:%s\n",s[a-1].name);
printf("Phone No.: %s",s[a-1].phone);
}
else
printf("Seat %d is free\n",a);
}

void showTicket(Seat *s){
int a;
printf("Enter your seat number to display the Ticket:\n ");
scanf("%d",&a);
if(a<0 || a>SEAT_COUNT){
printf("Invalid seat\n");
return;
}
if(!s[a-1].BookedOrNot){
printf("Seat %d is not booked . No Ticket available\n",a);
return;
}
printTicket(&s[a-1]);
}

void printTicket(Seat *s){
printf("\n=================================================\n");
printf("                    BUS TICKET                     \n");
printf("==================================================\n");
printf("\n");
printf("Passanger Name:%s\n",s->name);
printf("Seat no.:%d\n",s->seatNum);
printf("Passanger phone number:%s\n",s->phone);
printf("Route: %s\n",ROUTE);
printf("Fare: Rs.%d\n", FARE);
printf("Status: Confirmed\n");
printf("\n==================================================\n");

}




