#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE *book,*student;

class Book
{
public:
char bname[20];
char author[20];
int bookno;

void addbook();
void searchbook();
void showallb();
void removeb();
};

class Student
{
public:
char sname[20];
int enrollno;
int token;
int fine;
char issuedb[3][20];


void initialise();
void addstudent();
void showalls();
void searchstudent();
void issue();
void returnbook();
};

void Student::initialise()
{
fine=token=0;
strcpy(issuedb[0],"NULL");
strcpy(issuedb[1],"NULL");
strcpy(issuedb[2],"NULL");
}

void start()
{
clrscr();
gotoxy(30,6);
cout<<"LIBRUARY MANAGEMENT";
gotoxy(36,8);
cout<<"SYSTEM";
gotoxy(6,17);
cout<<"MADE BY:- Ashutosh";
gotoxy(11,19);
cout<<"Btech 3rd year";
getch();
}

void selectoption()
{
int ch;
Book b;
Student s;
while(1)
{
clrscr();
gotoxy(25,6);
cout<<"--------------------------------\n";
gotoxy(33,7);
cout<<"SELECT A CHOICE";
gotoxy(25,8);
cout<<"--------------------------------\n";
cout<<"1.Add a book\n";
cout<<"2.Show all book\n";
cout<<"3.Search a book\n";
cout<<"4.Remove a book\n";
cout<<"5.Add a student record\n";
cout<<"6.Show detail of all student\n";
cout<<"7.Search a student\n";
cout<<"8.Issue a book\n";
cout<<"9.Return a book\n";
cout<<"10.Exit\n";
cin>>ch;
switch(ch)
{
case 1: b.addbook();
	cout<<"\nBook added sucessfully";
	getch();
	break;
case 2: b.showallb();
	break;
case 3: b.searchbook();
	break;
case 4: b.removeb();
	cout<<"Book removed sucessfully";
	 break;
case 5: s.addstudent();
	cout<<"\nStudent details sucessfully added in records\n";
	break;
case 6: s.showalls();
	 break;
case 7: s.searchstudent();
	 break;
case 8:  s.issue();
	 break;
case 9:  s.returnbook();
	 break;
case 10: exit(0);

default :cout<<" WRONG CHOICE Enter a valid choice";
	 getch();
	 break;
}
}
}


void Book :: addbook()
{
char a;
do
{
clrscr();
cout<<"Enter book name\n";
cin>>bname;
cout<<"\nEnter author name\n";
cin>>author;
cout<<"\nEnter book number(Not more than 5 digits)\n";
cin>>bookno;
book=fopen("book.txt","a");
fprintf(book,"%s     %s     %d\n",bname,author,bookno);
fclose(book);
cout<<"Do you want to add more books (y/n)";
a=getch();
}while(a=='y'||a=='Y');
}


void Book ::searchbook()
{
char x[20],a;
do
{
book=fopen("book.txt","r");
clrscr();
cout<<"\nEnter book name\n";
cin>>x;
int i=0;
while(fscanf(book,"%s%s%d",bname,author,&bookno)!=EOF)
{
if(strcmpi(x,bname)==0)
{
i++;
cout<<"Book name is\n "<<bname;
cout<<"\nAuthor is \n"<<author;
cout<<"\nBook number is \n"<<bookno;
break;
}
}
if(i==0)
{
cout<<"\nThere is no such book in records\n";
}
cout<<"\nDo you want to search more books(y/n)\n" ;
a=getche();
}while(a=='y'||a=='Y');
}

void Book :: showallb()
{
int y=8;
clrscr();
gotoxy(2,4);
cout<<"------------------------------------------------------------";
gotoxy(3,5);
cout<<"BOOK NAME";
gotoxy(2,6);
cout<<"------------------------------------------------------------";
gotoxy(28,5);
cout<<"AUTHOR NAME";
gotoxy(48,5);
cout<<"BOOK NUMBER";
book=fopen("book.txt","r");
while(fscanf(book,"%s%s%d",bname,author,&bookno)!=EOF)
{
gotoxy(4,y);
cout<<bname;
gotoxy(30,y);
cout<<author;
gotoxy(50,y);
cout<<bookno;
y++;
}
getch();
}

void Book ::removeb()
{
char x[20],a;
FILE *temp;
do
{
clrscr();
book=fopen("book.txt","r");
if(book==NULL)
{
cout<<"Cannot open book.txt";
break;
}
cout<<"\nEnter book name to be removed\n";
cin>>x;
int i=0;
temp=fopen("temp.txt","w");
if(temp==NULL)
{
cout<<"Cannot open temp.txt\n";
}

while(fscanf(book,"%s%s%d",bname,author,&bookno)!=EOF)
{
if(strcmpi(x,bname)!=0)
{
fprintf(temp,"%s      %s     %d\n",bname,author,bookno);
}
else
{
i++;
}
}
fclose(book);
fclose(temp);
remove("book.txt");
if(i==0)
{
cout<<"Book not found in records\n";
}
else
{
rename("temp.txt","book.txt");
}
cout<<"\nDo you want to remove more books(y/n)\n" ;
a=getche();
}while(a=='y'||a=='Y');
}

void Student :: addstudent()
{
char a;
initialise();
student =fopen("student.txt","a");
do
{
clrscr();
cout<<"Enter student's name\n";
cin>>sname;
cout<<"Enter student's enrollment number\n";
cin>>enrollno;
fprintf(student,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
cout<<"Do you want to add more student details(y/n)\n";
fflush(student);
a=getche();
}while(a=='y'||a=='Y');
fclose(student);
}

void Student :: showalls()
{
clrscr();
int i,y=8,z;
gotoxy(2,4);
cout<<"--------------------------------------------------------------------------";
gotoxy(3,5);
cout<<"STUDENT NAME";
gotoxy(2,6);
cout<<"--------------------------------------------------------------------------";
gotoxy(18,5);
cout<<"ENROLLMENT NUMBER";
gotoxy(38,5);
cout<<"FINE";
gotoxy(54,5);
cout<<"ISSUED BOOKS";
student=fopen("student.txt","r");

while(fscanf(student,"%s%d%d%d%s%s%s",sname,&enrollno,&token,&fine,issuedb[0],issuedb[1],issuedb[2])!=EOF)
{
z=48;
gotoxy(5,y);
cout<<sname;
gotoxy(22,y);
cout<<enrollno;
gotoxy(40,y);
cout<<fine;
for(i=0;i<3;i++)
{
gotoxy(z,y);
cout<<i+1;
cout<<"." <<issuedb[i];
z=z+11;
}
y++;
}
getch();

}


void Student :: issue()
{
FILE *temp;
char a,n[10];
int roll,i;
do
{
clrscr();
i=0;
cout<<"Enter your enrollno\n";
cin>>roll;

student=fopen("student.txt","r");
if(student==NULL)
{
cout<<"Cannot open student file/n";
}

temp=fopen("temp.txt","a");
if(temp==NULL)
{
cout<<"Cannot open temp file\n";
}

while(fscanf(student,"%s%d%d%d%s%s%s",sname,&enrollno,&token,&fine,issuedb[0],issuedb[1],issuedb[2])!=EOF)
{
if(token==3 && roll==enrollno)
{
i++;
cout<<"Maximum 3 books can be issued\n";
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
continue;
}

if(roll==enrollno)
{
i++;
cout<<"Enter the book name to be issued\n" ;
int y=0,x=0;
for(;x<3;x++)
{
if(strcmp(issuedb[x],"NULL")==0)
{
y=x;
break;
}
}
cin>>issuedb[y];
token++;
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);

}

else
{
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
}

}
fclose(student);
fclose(temp);
remove("student.txt");
rename("temp.txt","student.txt");
if(i==0)
{
cout<<"Rollno not found in records\n";
}
cout<<"Do you want to issue more books(y/n)\n";
a=getche();
}while(a=='y'||a=='Y');
}


void Student ::searchstudent()
{
char x[20],a;
do
{
clrscr();
student=fopen("student.txt","r");
cout<<"\nEnter student name\n";
cin>>x;
int j,i=0;
while(fscanf(student,"%s%d%d%d%s%s%s",sname,&enrollno,&token,&fine,issuedb[0],issuedb[1],issuedb[2])!=EOF)
{
if(strcmpi(x,sname)==0)
{
i++;
cout<<"Student name is\n"<<sname;
cout<<"\n\nEnrollment number is \n"<<enrollno;
cout<<"\n\nBook issued are\n";
for(j=0;j<token;j++)
{
cout<<j+1;
cout<<"." ;
cout<<issuedb[j];
cout<<"\n";
}
cout<<"\nFine is \n"<<fine;
cout<<"\n";
break;
}
}
if(i==0)
{
cout<<"\nThere is no such student in records\n";
}
cout<<"\nDo you want to search details of more students(y/n)\n" ;
a=getche();
}while(a=='y'||a=='Y');
}

void Student::returnbook()
{
FILE *temp;
char a,n[10];
int roll,i;
do
{
clrscr();
i=0;
cout<<"Enter your enrollno\n";
cin>>roll;

student=fopen("student.txt","r");
if(student==NULL)
{
cout<<"Cannot open student file/n";
}

temp=fopen("temp.txt","a");
if(temp==NULL)
{
cout<<"Cannot open temp file\n";
}

while(fscanf(student,"%s%d%d%d%s%s%s",sname,&enrollno,&token,&fine,issuedb[0],issuedb[1],issuedb[2])!=EOF)
{
if(roll==enrollno)
{
i++;
cout<<"Enter the book name to be returned\n" ;
cin>>n;
if(strcmpi(n,issuedb[0])==0)
{
strcpy(issuedb[0],"NULL");
token=token-1;
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
}

else if(strcmpi(n,issuedb[1])==0)
{
strcpy(issuedb[1],"NULL");
token=token-1;
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
}

else if(strcmpi(n,issuedb[2])==0)
{
strcpy(issuedb[2],"NULL");
token=token-1;
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
}

else
{
cout<<"This book is not issued by you";
}

}
else
{
fprintf(temp,"%s     %d     %d     %d     %s     %s     %s\n",sname,enrollno,token,fine,issuedb[0],issuedb[1],issuedb[2]);
}

}
fclose(student);
fclose(temp);
remove("student.txt");
rename("temp.txt","student.txt");
if(i==0)
{
cout<<"Rollno not found in records\n";
}
cout<<"Do you want to return more books(y/n)\n";
a=getche();
}while(a=='y'||a=='Y');
}


void main()
{
clrscr();
start();
selectoption();
getch();
}
