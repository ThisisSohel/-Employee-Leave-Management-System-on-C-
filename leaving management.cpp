#include<iostream>
#include<fstream>
using namespace std;
struct leavetype;
struct application;

application *FRONT=NULL;
application *REAR=NULL;

struct faculty
{
    string name;
    string title;
    string department;
    string contactno;
    string address;
    string room;
    string status;
    faculty *next;
    leavetype *leave;
    application *app;
};
struct leavetype
{
    int casualcount=0;
    int emergencycount=0;
    int maternitycount=0;
    int studycount=0;
    int sickcount=0;
    int familycount=0;
    int religiouscount=0;
};
struct application
{
    string leavetype;
    string from;
    string to;
    int days;
    string status;
    application *next;
    faculty *fac;
};
faculty* searchdata(faculty *head,string a,string b,string c)
{
    faculty *p=head;
    int len=a.size();
    string upperstring=a;
    for(int i=0; i<len; i++)
    {
        upperstring[i]=toupper(upperstring[i]);
    }
    while(p!=NULL)
    {
        if(p->department==a || p->department==upperstring && p->room==c && p->contactno==b)
        {
            cout<<"-------------------"<<endl;
            cout<<"Name:        "<<p->name<<endl;
            cout<<"Title:       "<<p->title<<endl;
            cout<<"Department:  "<<p->department<<endl;
            cout<<"Contact No.: "<<p->contactno<<endl;
            cout<<"Address:     "<<p->address<<endl;
            cout<<"Room No.:    "<<p->room<<endl;
            cout<<"Status:      "<<p->status<<endl;
            cout<<"-------------------"<<endl;
            return p;
        }
        p=p->next;
    }
    return p;
}
void showmenu()
{
    cout<<"                  Welcome To Leaving Management System"<<endl;
    cout<<"1. Employee Portal"<<endl;
    cout<<"2. Admin Portal"<<endl;
}
void enqueue(application *node)
{
    if(FRONT==NULL)
    {
        FRONT = node;
        REAR = node;
    }
    else
    {
        REAR ->next = node;
        REAR = node;
    }
}
void dequeue()
{
    FRONT=FRONT->next;
}
void approveapplication()
{
    application *p=FRONT;
    if(FRONT==NULL)
    {
        cout<<"!!! No Application Has Not Created Yet !!!"<<endl;
    }
    else
    {
        cout<<endl<<"!!! Database is showing in Queue order !!!";
    while(p!=NULL)
    {
        cout<<endl<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"             INFORMATION         "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Name:        "<<p->fac->name<<endl;
        cout<<"Title:       "<<p->fac->title<<endl;
        cout<<"Department:  "<<p->fac->department<<endl;
        cout<<"Contact No.: "<<p->fac->contactno<<endl;
        cout<<"Address:     "<<p->fac->address<<endl;
        cout<<"Room No.:    "<<p->fac->room<<endl;
        cout<<"Status:      "<<p->fac->status<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"             Application         "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Leave Type:  "<<p->leavetype<<endl;
        cout<<"From Date:   "<<p->from<<endl;
        cout<<"To Date:     "<<p->to<<endl;
        cout<<"Days:        "<<p->days<<endl;
        cout<<"Status:      "<<p->status<<endl;
        if(p->leavetype=="Casual")
        {
            p->fac->leave->casualcount=p->fac->leave->casualcount+p->days;
        }
        if(p->leavetype=="Emergency")
        {
            p->fac->leave->emergencycount=p->fac->leave->emergencycount+p->days;
        }
        if(p->leavetype=="Maternity(For Female)")
        {
            p->fac->leave->maternitycount=p->fac->leave->maternitycount+p->days;
        }
        if(p->leavetype=="Study")
        {
            p->fac->leave->studycount=p->fac->leave->studycount+p->days;
        }
        if(p->leavetype=="Sickness")
        {
            p->fac->leave->sickcount=p->fac->leave->sickcount+p->days;
        }
        if(p->leavetype=="Family")
        {
            p->fac->leave->familycount=p->fac->leave->familycount+p->days;
        }
        if(p->leavetype=="Religious")
        {
            p->fac->leave->religiouscount=p->fac->leave->religiouscount+p->days;
        }
        p=p->next;
    }
    cout<<endl<<endl<<"Press 1 to Accept & Dequeue the First Application and Any Other Key to Cancel  ";

    int choice;
    cin>>choice;
    if(choice==1)
    {
        p=FRONT;
        p->status="Approved";
        p->fac->status="On Leave";
        dequeue();
        cout<<"!!! Successfully Approved !!!"<<endl;
    }
    else
    {
        cout<<"!!! Canceled !!!"<<endl;
    }
    }
}
void applyforleave(faculty *head)
{
    string dept,cont,room;
    int choice;
    cout<<"-------------------"<<endl;
    cout<<"Please Logon to Your Profile"<<endl;
    cout<<"Department ? ";
    cin>>dept;
    cout<<"Contact No. ? ";
    cin>>cont;
    cout<<"Room No. ? ";
    cin>>room;
    faculty *p=searchdata(head,dept,cont,room);
    if(p==NULL)
    {
        cout<<"!!!Not Found!!!"<<endl;
        return;
    }
    if(p->status=="On leave")
    {
        cout<<"!!!Already On Leave!!!"<<endl;
    }
    else
    {
        application *tempapplication=new(application);
        p->app=tempapplication;
        tempapplication->fac=p;
        p->app->next=NULL;

        application *app=p->app;
        cout<<"Leave Type ? "<<endl;
        cout<<"1. Casual"<<endl<<"2. Emergency"<<endl<<"3. Maternity(For Female)"<<endl<<"4. Study"<<endl<<"5. Sickness"<<endl<<"6. Family"<<endl<<"7. Religious"<<endl;
        cin>>choice;
        cout<<"-------------------"<<endl;
        if(choice==1)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Casual";
        }
        if(choice==2)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Emergency";
        }
        if(choice==3)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Maternity(For Female)";
        }
        if(choice==4)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Study";
        }
        if(choice==5)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Sickness";
        }
        if(choice==6)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Family";
        }
        if(choice==7)
        {
            string from,to;
            int day;
            cout<<"Enter From Date: ";
            cin>>from;
            cout<<"Enter To Date: ";
            cin>>to;
            cout<<"Days: ";
            cin>>day;
            p->app->from=from;
            p->app->to=to;
            p->app->days=day;
            p->app->status="Pending";
            p->app->leavetype="Religious";
        }
        enqueue(app);
    }
}
void viewleavecount(faculty *head)
{
    string dept,cont,room;
    cout<<"-------------------"<<endl;
    cout<<"Please Logon to Your Profile"<<endl;
    cout<<"Department ? ";
    cin>>dept;
    cout<<"Contact No. ? ";
    cin>>cont;
    cout<<"Room No ? ";
    cin>>room;
    faculty *p=searchdata(head,dept,cont,room);
    cout<<"Casual Count=                "<<p->leave->casualcount<<endl;
    cout<<"Emergency Count=             "<<p->leave->emergencycount<<endl;
    cout<<"Maternity Count(For Female)= "<<p->leave->maternitycount<<endl;
    cout<<"Study Count=                 "<<p->leave->studycount<<endl;
    cout<<"Sick Count=                  "<<p->leave->sickcount<<endl;
    cout<<"Family Count=                "<<p->leave->familycount<<endl;
    cout<<"Religious Count=             "<<p->leave->religiouscount<<endl;
}
void viewleaveapplication(faculty *head)
{
    string dept,cont,room;
    cout<<"-------------------"<<endl;
    cout<<"Please Login to Your Profile"<<endl;
    cout<<"Department ? ";
    cin>>dept;
    cout<<"Contact No. ? ";
    cin>>cont;
    cout<<"Room No ? ";
    cin>>room;
    faculty *p=searchdata(head,dept,cont,room);
    if(p==NULL)
    {
        cout<<"!!!Not Found!!!"<<endl;
        return;
    }
    if(p->app!=NULL)
    {
        cout<<"Leave type:  "<<p->app->leavetype<<endl;
        cout<<"From Date:   "<<p->app->from<<endl;;
        cout<<"To Date:     "<<p->app->to<<endl;
        cout<<"Days:        "<<p->app->days<<endl;
        cout<<"Status:      "<<p->app->status<<endl;
    }
    else
    {
        cout<<"!!! Not Applied for Leaving Application !!!"<<endl;
    }
}
void departmentemployee(faculty *head)
{
    faculty *c=head;
    cout<<"-------------------"<<endl;
    cout<<"1. CSE"<<endl<<"2. EEE"<<endl<<"3. GEB"<<endl<<"4. BBA"<<endl<<"5. ECE"<<endl<<"6. Civil Engr."<<endl;
    cout<<"Which Department ? ";
    int choice;
    cin>>choice;
    if(choice==1)
    {
        while(c!=NULL)
        {
            if(c->department=="CSE")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
    else if(choice==2)
    {
        while(c!=NULL)
        {
            if(c->department=="EEE")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
    else if(choice==3)
    {
        while(c!=NULL)
        {
            if(c->department=="GEB")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
    else if(choice==4)
    {
        while(c!=NULL)
        {
            if(c->department=="BBA")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
    else if(choice==5)
    {
        while(c!=NULL)
        {
            if(c->department=="ECE")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
    else if(choice==6)
    {
        while(c!=NULL)
        {
            if(c->department=="Civil Engr.")
            {
                cout<<"-------------------"<<endl;
                cout<<"Name:        "<<c->name<<endl;
                cout<<"Title:       "<<c->title<<endl;
                cout<<"Department:  "<<c->department<<endl;
                cout<<"Contact No.: "<<c->contactno<<endl;
                cout<<"Address:     "<<c->address<<endl;
                cout<<"Room No.:    "<<c->room<<endl;
                cout<<"Status:      "<<c->status<<endl;
                cout<<"-------------------"<<endl;
            }
            c=c->next;
        }
    }
}
faculty* loaddata()
{
    faculty *head=NULL,*p=NULL;
    string name1,title1,department1,contactno1,address1,room1,status1;
    ifstream infile;
    infile.open("Employee Data.txt", ios::in);

    while(infile.eof()==false)
    {
        for(int i=0; i<10; i++)
        {
            getline(infile, name1);
            getline(infile, title1);
            getline(infile, department1);
            getline(infile, contactno1);
            getline(infile, address1);
            getline(infile, room1);
            getline(infile, status1);

            faculty *temp=new(faculty);
            temp->name=name1;
            temp->title=title1;
            temp->department=department1;
            temp->contactno=contactno1;
            temp->address=address1;
            temp->room=room1;
            temp->status=status1;
            temp->next=NULL;
            temp->app=NULL;

            leavetype *templeave=new(leavetype);
            temp->leave=templeave;

            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                p=head;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p->next=temp;
            }
        }
    }
    infile.close();
    return head;
}
int main()
{
    faculty *head=loaddata();
    while(true)
    {
        showmenu();
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"-------------------"<<endl;
            cout<<"1. Apply for Leave"<<endl;
            cout<<"2. View Leave Count"<<endl;
            cout<<"3. Check Leave Application"<<endl;
            cin>>choice;
            if(choice==1)
            {
                applyforleave(head);
            }
            if(choice==2)
            {
                viewleavecount(head);
            }
            if(choice==3)
            {
                viewleaveapplication(head);
            }
        }
        else if(choice==2)
        {
            cout<<"-------------------"<<endl;
            cout<<"1. View & Approve Employee's Application"<<endl;
            cout<<"2. View Employee's Statistics(Departmentwise)"<<endl;
            cin>>choice;
            if(choice==1)
            {
                approveapplication();
            }
            if(choice==2)
            {
                departmentemployee(head);
            }
        }
    }
}
