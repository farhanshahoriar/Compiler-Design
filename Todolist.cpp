#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include "constants.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

std::ofstream fout;
std::ifstream fin;
struct task{
    std::string taskname,info;
    int date,month,year;
    void fileout(){
        fout<<taskname<<" "<<info<<" "<<date<<" "<<month<<" "<<year<<"\n";
    }
    void filein(){
        fin>>taskname>>info>>date>>month>>year;
    }
    void inputtask(){
        //we will input task details here.

        cout<<"Enter task name: ";
        cin>>taskname;
        cout<<"Enter task information: ";
        cin>>info;
        //getline(cin,inputinfo);//it's not working properly

        cout<<"Enter task date (Format:DD/MM/YYYY): ";
        scanf("%d%*c%d%*c%d",&date,&month,&year);

        //Need to check if input format,added by user is correct. will be done in next update
        if(year<100){
            year+=2000;
            //for year 2018 user can input 2018 or only 18. it will be converted here.
        }
    }

    //overloading operator to sort the task according to time.
    bool operator <(const task &tsk2)const{
        if(year==tsk2.year){
            if(month==tsk2.month){
                //if both month and year same
                return date<tsk2.date;
            }
            else {
                return month<tsk2.month;
            }
        }
        else {
            return year<tsk2.year;
        }
    }
};

class alltask{
    std::vector<task> tasklist,list2;
    public:
    void addtask(){
        task temp;
        temp.inputtask();
        tasklist.push_back(temp);
        system("clear");//Clear display
    }

    void taskoutput(){
        //this is output fucntion to print task info

        int taskno;
        string chk;
        if(tasklist.size()==0){
            cout<<"Task list is empty!"<<endl;
            return;//We can not show the list as it is empty.
        }

        //Soring the task according to date of task.
        sort(tasklist.begin(),tasklist.end());

        cout<<"To open a task Enter the task number form the list below:"<<endl;
        cout<<"Task No\tTask Name"<<endl;

        //Here we will store everything in vector as 0 based index,but user will see as 1 based index
        //So we have to substruct or add 1 sometimes from index.

        for(int i=0;i<tasklist.size();i++){
            cout<<i+1<<".\t"<<tasklist[i].taskname<<endl;
        }
        cin>>taskno;
        system("clear");//Clear display

        cout<<"Task name: "<<tasklist[taskno-1].taskname<<endl;
        cout<<"Info:\n"<<tasklist[taskno-1].info<<endl;
        cout<<"\nDate: "<<tasklist[taskno-1].date<<"/"<<tasklist[taskno-1].month<<"/"<<tasklist[taskno-1].year<<endl;

        cout<<"\n\nEnter 'm' to go main menu or 'r' to remove this note\n";
        do{
            cin>>chk;
            if(chk==Remove){
                tasklist.erase(tasklist.begin()+taskno-1);
                break;
            }
        }while(chk!=backmain);

        system("clear");//Clear display
    }
    void writefile(){
        // Write out a list to a disk file
        fout.open("data.txt");
        fout<<tasklist.size()<<"\n";
        for(int i=0;i<tasklist.size();i++){
            tasklist[i].fileout();
        }
        fout.close();
    }
    void readfile(){
        int sizein;
        fin.open("data.txt");
        fin>>sizein;
        task temp;
        for(int i=0;i<sizein;i++){
            temp.filein();
            tasklist.push_back(temp);
        }
        fin.close();
    }

}taskall;


int main(){
    int option;
    taskall.readfile();
    while(true){
        puts("Chose an option:");
        puts("1.Add a new task\n2.See all task\n3.Exit");
        cin>>option;
        system("clear");//Clear display
        if(option>3||option<1)puts("\nInvalid Option. Try again\n\n");
        //we will use separate function for each option.
        switch(option){
            case 1:
                taskall.addtask();
                break;
            case 2:
                taskall.taskoutput();
                break;
            case 3:
                taskall.writefile();
                return 0;
                break;
        }
    }

    return 0;
}

