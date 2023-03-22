#include<iostream>
#include<string>

using namespace std;

class lms{
    private:
    
    string ep_name;
    float salary;
    int pl=14;
    int unpaid_leave=0;
    int casual=20;
    int sick_leave=15;
    int study_leave=10;
    int parental_leave=40;

    float deduction=0;

    public:
    int ep_id;
    lms(int a,string b,float c){
        this->ep_id=a;
        this->ep_name=b;
        this->salary=c;
    }
    void set_data(int i){
        
            cout<<"\t\t Enter employee ID of employee "<<i+1<<" : ";
            cin>>ep_id;
            cout<<"\t\t Enter employee name of employee : ";
            cin.ignore();
            getline(cin,ep_name);
            cout<<"\t\t Enter salary of employee "<<ep_name<<" : ";
            cin>>salary;
    }

    void get_data(){
        cout<<"\t\t Employee ID: "<<ep_id<<endl;
        cout<<"\t\t Employee name: "<<ep_name<<endl;
        cout<<"\t\t Salary of employee "<<ep_name<<" : "<<salary<<endl;
        cout<<"\t\t Deductions: "<<deduction<<endl;
    }

    void apply_leave(){
        int option,days;
        cout<<"\t\t Select \n \t\t1.Paid Leave \n \t\t2.Unpaid Leave";
        cout<<"\n \t\t3.Casual \n \t\t4.Sick leave \n \t\t5.Study leave \n \t\t6.Parental leave \n ";
        cin>>option;
        if(option==1){
            cout<<"\t\t Enter the number of paid leaves you want: ";
            cin>>days;
            if(days>pl){
                cout<<"\t\t You only have "<<pl<<" paid leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                pl=pl-days;
                cout<<"\t\t Leave granted and you have "<<pl<<" paid leaves left"<<endl;
            }
        }
        else if(option==2){
            cout<<"\t\t Enter the number of unpaid leaves you want: ";
            cin>>unpaid_leave;
            cout<<"\t\t "<<unpaid_leave<<" Leave granted "<<endl;
            deduction= unpaid_leave*(salary/365);
        }

        else if(option==3){
            cout<<"\t\t Enter the number of Casual leaves you want: ";
            cin>>days;
            if(days>casual){
                cout<<"\t\t You only have "<<casual<<" casual leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                casual=casual-days;
                cout<<"\t\t Leave granted and you have "<<casual<<" paid leaves left"<<endl;
            }
        }

        else if(option==4){
            cout<<"\t\t Enter the number of sick leaves you want: ";
            cin>>days;
            if(days>sick_leave){
                cout<<"\t\t You only have "<<sick_leave<<" sick leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                sick_leave=sick_leave-days;
                cout<<"\t\t Leave granted and you have "<<sick_leave<<" sick leaves left"<<endl;
            }
        }

        else if(option==5){
            cout<<"\t\t Enter the number of study leaves you want: ";
            cin>>days;
            if(days>study_leave){
                cout<<"\t\t You only have "<<study_leave<<" study leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                study_leave=study_leave-days;
                cout<<"\t\t Leave granted and you have "<<study_leave<<" study leaves left"<<endl;
            }
        }

        else if(option==6){
            cout<<"\t\t Enter the number of parental leaves you want: ";
            cin>>days;
            if(days>parental_leave){
                cout<<"\t\t You only have "<<parental_leave<<" parental leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                parental_leave=parental_leave-days;
                cout<<"\t\t Leave granted and you have "<<parental_leave<<" parental leaves left"<<endl;
            }
        }

        else{
            cout<<"Invalid selection"<<endl;
        }

    }

    void get_leave_data(){
        cout<<"\t\t Paid leave: "<<pl<<endl;
        cout<<"\t\t Unpaid leave: "<<unpaid_leave<<endl;
        cout<<"\t\t Deductions on unpaid leave: "<<deduction<<endl;
        cout<<"\t\t Casual leave: "<<casual<<endl;
        cout<<"\t\t Sick leave: "<<sick_leave<<endl;
        cout<<"\t\t Study leave: "<<study_leave<<endl;
        cout<<"\t\t Parental leave: "<<parental_leave<<endl;
    }
    friend int found(lms,int);
 
};
int  found(lms ep[],int e_id){
        int f=-1;
        for(int i=0;i<13;i++){
            
            if(ep[i].ep_id==e_id)
                f=i;
            
        }
        return f;
        
    }


int main(){
    int operation,e_id,status,n=0;
    char decision;
    lms ep[13]={(lms(121,"Sunil",12500000)),(lms(46,"Gauri",100000000)),(lms(51,"Harshit",12500000)),
    (lms(66,"Manish",1000000)),(lms(131,"Vidushi",10000000)),(lms(107,"Shurti",120000)),
    (lms(77,"Nishika",125000)),(lms(1," ",0)),(lms(1," ",0)),(lms(1," ",0)),(lms(1," ",0)),(lms(1," ",0)),(lms(1," ",0))};


    
    label:
    cout<<"-----------------LEAVE MANAGEMENT SYSTEM----------------- \n \n";
    cout<<"\t\t 1.Enter Employee Data \n";
    cout<<"\t\t 2.Check Employee Data \n";
    cout<<"\t\t 3.Apply for leave\n";
    cout<<"\t\t 4.Check leave data \n \n";
    cout<<"\t\t What operation do you want to perform (select: 1, 2, 3, 4): ";
    cin>>operation;

    switch (operation)
    {
    case 1:
        cout<<"\t\t Enter the no. of employees you want to add: ";
        cin>>n;

        for(int i=7;i<7+n;i++){
                ep[i].set_data(i);
            
        }
        break;
    case 2:

            cout<<"\n \t\t Details are: \n";
            for(int i=0;i<7+n;i++){
                ep[i].get_data();
            }
        
        break;
    
    case 3:
    
        cout<<"\t\t Enter your employee ID: ";
        cin>>e_id;
        int x,r;
        r=3;
        x = found(ep,e_id);
        while(r){
        if(x==-1){
            cout<<"INVALID EMPLOYEE ID!!!\n";
            cout<<"Enter correct id: ";
            int temp;
            cin>>temp;
            e_id=temp;
            x=found(ep,e_id);
        }
        else ep[found(ep,e_id)].apply_leave();r--;}
        
        
        break;

    case 4:
        cout<<"\t\t Enter your employee ID: ";
        cin>>e_id;
        
        r=3;
        x = found(ep,e_id);
        while(r){
        if(x==-1){
            cout<<"Enter correct id: ";
            int temp;
            cin>>temp;
            e_id=temp;
            x=found(ep,e_id);
        }
        else ep[x].get_leave_data();r--;}
        
        
        break;

    default:
        cout<<"\t\t Enter valid operation"<<endl;
        goto label;
        break;
    }   

    B:

    cout<<"\t\t Do you want to continue using the Leave Management System(y/n): ";
    cin>>decision;
    cout<<endl;

    if(decision=='y' || decision=='Y')
    {
        goto label;
    }

    else if(decision=='n' || decision=='N'){
        cout<<"\t\t Thank you for using our Leave Management System";
    }

    else{
        cout<<"\t\t Enter Valid character"<<endl;
        goto B;
    }
    return 0;
}