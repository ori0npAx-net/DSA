#include <iostream>
#include <string>
using namespace std;

struct snode{
    string SeatNum;
    snode* snext;
    
};
struct cnode{
    string CourNum;
    cnode* cnext;
    snode* studlist;
};

cnode* clist=NULL;

void insert_course(string CourNum){
    cnode* temp= new cnode; //cnode* temp=(cnode*)malloc(sizeofarray(cnode));
    temp->CourNum=CourNum;
    temp->cnext=NULL;
    temp->studlist=NULL;
    
    if (clist==NULL){
        clist= temp;
        return;
    }
    cnode *Ccurr=clist;
	while (Ccurr->cnext!=NULL){	//staying in the loop till we get a node(curr->next) which is null
		Ccurr=Ccurr->cnext;	
	}
	Ccurr->cnext=temp;
}

void insert_studentIn(string SeatNum, string CourNum){
    cnode* Ccurr=clist;
    while (Ccurr!=NULL){
        if (CourNum==Ccurr->CourNum){
            //snode* temp;
            snode* temp= new snode; 
            temp->snext=NULL;
            temp->SeatNum=SeatNum;
            if(Ccurr->studlist==NULL){
                Ccurr->studlist=temp;
                return;
            }else{
            snode* Scur=Ccurr->studlist;
            while (Scur->snext!=NULL){
                Scur=Scur->snext;
            }
            Scur->snext=temp;
        }
        return;
    }
    Ccurr=  Ccurr->cnext;
}
}
void DisplayALL(){
    cout<<"the list is:\n";
    if (clist==NULL){
        cout<<"EMPTY\n";
        return;
    }
    cnode* Ccurr=clist;
    while (Ccurr!=NULL){        //clist or Ccurr
       cout<<"\nCOURSE:"<<Ccurr->CourNum;
       snode* Scur=Ccurr->studlist;
       if (Scur==NULL){
        cout<<"\nno students enrolled.";
       }else{
        while(Scur!=NULL){
        cout<<"\nseat no.:"<<Scur->SeatNum;
        Scur=Scur->snext;
       }
    }
    //    cout<<"this course has no student list";
       Ccurr=Ccurr->cnext;
    }
    //cout<<"the list is empty"; //yeh case already handle hogaya tou ab koi maqsad nahi isko print karwany ka
}

// void DelCourse(CourNum){

// }
// void SearchCourse(CourNum){

// }
// void DisplayCourses(){

// }
// void DelStudentfrom (seatno,courseno){

// }
// void DelStudent(seatno){

// }
// void SearchStudentIn(seatno){

// }
// void SearchStudent(seatno){

// }
// void DisplayStudentlistOf(courseno){

// }



int main(){
    insert_course("cs451");
    insert_course("cs452");
    insert_studentIn("b6060","cs451");
    insert_studentIn("b6781","cs451");
    DisplayALL();
    insert_course("cs455");
    insert_studentIn("9090")
//exit 
}