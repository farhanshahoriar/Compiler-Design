#include <iostream>
#include <stdio.h>
using std::string;
using std::cin;
using std::cout;

struct task{
    std::string taskname,info;
    int date,month,year;
    task();
    task(std::string name,std::string tinfo,int _date,int _month, int _year){
        taskname=name;
        info=tinfo;
        date=_date;
        month=_month;
        year=_year;
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
            year+=2000;//for year 2018 user can input 2018 or only 18. it will be converted here.
        }
    }
};

int main(){

    return 0;
}

