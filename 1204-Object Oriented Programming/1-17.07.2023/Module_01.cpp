#include <iostream>
#include <conio.h>
using namespace std;

struct Member{
 int id;
 float height;
 float weight;
 bool exist;
};
int total=-1;
struct Member mx[5000];


int menu(){
 int option;
 system("cls");
 cout<<"******* Main Menu ******"<<endl;
 cout<<"1. Add Member"<<endl;
 cout<<"2. Remove Member"<<endl;
 cout<<"3. Update Member"<<endl;
 cout<<"4. Max Height & Weight"<<endl;
 cout<<"5. Min Height and Weight"<<endl;
 cout<<"6. Average Height and Weight"<<endl;
 cout<<"7. BMI Classification"<<endl;
 cout<<"8. Display All"<<endl;
 cout<<"0. Exit"<<endl;
 cout<<"   Enter Your option(1-8):";
 cin>>option;
 return(option);

}

int searchMember(int y){
 int i;
 int flag=-1;
 for(i=0;i<=total;i++)
    if(mx[i].id==y)
      flag=i;
 return(flag);
}


void addMember(){
 int x;
 cout<<"Inside addMember()"<<endl;
 total++;
 cout<<"Enter Member ID:";
 cin>>x;
 if(searchMember(x)==-1){
   mx[total].id=x;
   cout<<"Enter Height:";
   cin>>mx[total].height;
   cout<<"Enter Weight:";
   cin>>mx[total].weight;
   mx[total].exist=true;
   cout<<"Add Member Successful"<<endl;
 }
 else{
    cout<<"Sorry Member ID already exists...try again"<<endl;
    total--;
  }
}

void removeMember(){
 int x,tid;
 cout<<"Enter Member ID:";
 cin>>x;
 tid=searchMember(x);
 if(tid==-1)
    cout<<"Sorry Member NOT exists...."<<endl;
 else{
    mx[tid].exist=false;
    cout<<"Remove Member Successful"<<endl;
 }
}

void updateMember(){
 int x;
 int tid;
 cout<<"Enter Member ID:";
 cin>>x;
 tid=searchMember(x);
 if(tid!=-1){
   cout<<"Old Height:"<<mx[tid].height;
   cout<<"\nEnter new height:";
   cin>>mx[tid].height;
   cout<<"Old Weight:"<<mx[tid].weight;
   cout<<"\nEnter new weight:";
   cin>>mx[tid].weight;

   cout<<"Update Member Successful"<<endl;
 }
 else
    cout<<"Sorry Member ID NOT exists...try again"<<endl;

}

void maxHeightWeight(){
 cout<<"maxHeightWeight() under construction"<<endl;
}

void minHeightWeight(){
 cout<<"minHeightWeight() under construction"<<endl;
}
void avgHeightWeight(){
 cout<<"avgHeightWeight() under construction"<<endl;
}
void bmi(){
 cout<<"bmi() under construction"<<endl;
}

void displayAll(){
 int i,y=0;
 cout<<"----------------"<<endl;
 cout<<"ID Height Weight"<<endl;
 for(i=0;i<=total;i++)
 if(mx[i].exist){
    cout<<mx[i].id<<" "<<mx[i].height<<" "<<mx[i].weight<<endl;
    y++;
 }
 cout<<"Total Members:"<<y<<endl;
 cout<<"----------------"<<endl;
}

int main()
{
  int op;
  for(;;){
   op=menu();
   //cout<<"In main() option="<<op<<endl;

   if(op==0){
    cout<<"End of Program run....";
    break;
   }
   switch(op){
     case 1:addMember();break;
     case 2:removeMember();break;
     case 3:updateMember();break;
     case 4:maxHeightWeight();break;
     case 5:minHeightWeight();break;
     case 6:avgHeightWeight();break;
     case 7:bmi();break;
     case 8:displayAll();break;
   }
   cout<<"Press enter to main menu....";
   getch();
  }
}
