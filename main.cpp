#include<bits/stdc++.h>
using namespace std;
void sorted();
void inserted();
void searched();
void deleted();
void updated();
void comparingtwo();
void comparingBesides();
void showall();

///Namespace use///


namespace management{
class info
{
public:
    string name,number;
public:
    info(string name,string number);
    info();

    ///Polymorphism using Virtual function///

    virtual void getinfo()
{
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter mobile no.: ";
    cin>>number;
}
    void showinfo();

    ///Friend Function///

    friend ostream& operator<<(ostream &out,info &abc);
};
    ///Operator overloading///
ostream& operator<<(ostream &out,info &abc)
{
    out<<"Name: "<<abc.name<<endl;
    out<<"Mobile no: "<<abc.number<<endl;
}
    ///setter and getter///
void info::showinfo()
{
   cout<<"Name: "<<name<<endl;
   cout<<"Mobile no: "<<number<<endl;
}
  ///this pointer///

info::info(string name,string number)
{
    this->name=name;
    this->number=number;
}
info::info()
{
    name="";
    number="";
}
    ///Inheritance///

class full_info : public info
{
string email;
public:
    string bg;
public:
       ///parameterized Constructor

   full_info(string a,string b,string c ,string d):info(a,b)
   {
       email=c;
       bg=d;
   }


   ///Copy Constructor

   full_info(const full_info &p)
   {
       name=p.name;
       number=p.number;
       email=p.email;
       bg=p.bg;
   }

   ///Default constructor

   full_info():info()
   {
       email="";
       bg="";
   }
   ///Member function///
   void getinfo()
   {
       cout<<"Enter name: ";
       cin>>name;
       cout<<"Enter mobile no.: ";
       cin>>number;
       cout<<"Enter Email: ";
       cin>>email;
       cout<<"Enter blood group: ";
       cin>>bg;
   }
   string getemail()
   {
       cin>>email;
       return email;
   }
   string getbg()
   {
       cin>>bg;
       return bg;
   }
   full_info& operator[](int i)
   {
    vector<full_info>data;
    full_info cd;

    ///file input

    ifstream fin("output.txt");
    string a;
    ///getline(fin,a);
    while(!fin.eof())
    {
        fin>>cd;
        data.push_back(cd);
    }
    ///Standard Template library
    vector<full_info>::iterator dd;
    int j=1;
    i++;
    for(dd=data.begin();dd!=data.end();dd++,j++)
    {
      if(j==i)
      {
          return *dd;
      }
    }

   }
   ///Destructor
   ~full_info(){};
   friend ostream& operator<<(ostream &out,full_info &abc);
   friend istream& operator>>(istream &in,full_info &tt);
   friend ofstream& operator<<(ofstream& of,full_info &tt);
   friend ifstream& operator>>(ifstream& pf,full_info &tt);
};
ofstream& operator<<(ofstream& of,full_info& tt)
{
    ///formatted input output
    of<<setw(10)<<setiosflags(ios::left)<<tt.name<<"   ";
    of<<setiosflags(ios::left)<<setw(15)<<tt.number<<"  ";
    of<<setw(30)<<setiosflags(ios::left)<<tt.email<<"   ";
    of<<setw(5)<<tt.bg<<endl;
}
ifstream& operator>>(ifstream& pf,full_info &tt)
{
    pf>>tt.name;
    pf>>tt.number;
    pf>>tt.email;
    pf>>tt.bg;
}
istream& operator>>(istream &in,full_info &tt)
{
    cout<<"Enter name: ";
    in>>tt.name;
    cout<<"Enter mobile: ";
    in>>tt.number;
    cout<<"Enter Email: ";
    in>>tt.email;
    cout<<"Enter blood group: ";
    in>>tt.bg;
}

ostream& operator<<(ostream &out,full_info &abc)
{
    out<<"____________________________________________________________________________"<<endl;
    out<<"____________________________________________________________________________"<<endl;
    out<<"Name: "<<abc.name<<endl;
    out<<"Number: "<<abc.number<<endl;
    out<<"Email : "<<abc.email<<endl;
    out<<"Blood Group :  "<<abc.bg<<endl;
}
}
void option()
{
    using namespace management;
    system("cls");
    system("color 1A");
    cout<<endl<<endl<<"\t\t\tWelcome to phonebook management system"<<endl<<endl;

    cout<<"Press 1 for insert"<<endl;
    cout<<"Press 2 for show "<<endl;
    cout<<"Press 3 for delete "<<endl;
    cout<<"Press 4 for update "<<endl;
    cout<<"Press 5 for sort"<<endl;
    cout<<"Press 6 for compare"<<endl;
    cout<<"Press 7 for search"<<endl;
    int x;
    cout<<"\n\t\tEnter your choice  :";
    cin>>x;
    if(x==1)
        inserted();
    else if(x==2)
        showall();
    else if(x==3)
        deleted();
    else if(x==4)
        updated();
    else if(x==5)
        sorted();
    else if(x==6)
        comparingtwo();
    else if(x==7)
        searched();
    else
        cout<<"Invalid selection"<<endl;
}
///Template
template<class T1,class T2>
void comparing(T1 a,T2 b)
{
    cout<<a<<" "<<b<<endl;
}
void comparing(management::full_info a,management::full_info b)
{
    cout<<"\n\t\tComparing Two contact\n\n";
    if(a.name==b.name)
        cout<<"Name is same "<<endl<<endl;
    if(a.number==b.number)
        cout<<"Number is same "<<endl<<endl;
    if(a.bg==b.bg)
        cout<<"Blood group is same"<<endl<<endl;
    cout<<a<<b<<endl;
}
///comparing
void comparingBesides(management::full_info a,management::full_info b)
{
    cout<<"\n\t\tComparing Two contact\n\n";
    if(a.name==b.name)
        cout<<"Name is same "<<endl<<endl;
    if(a.number==b.number)
        cout<<"Number is same "<<endl<<endl;
    if(a.bg==b.bg)
        cout<<"Blood group is same"<<endl<<endl;
    cout<<"First person:                    "<<"   Second Person"<<endl<<endl;
    cout<<setiosflags(ios::left)<<a.name<<setw(40)<<setiosflags(ios::right)<<b.name<<endl;
    cout<<setiosflags(ios::left)<<a.number<<setw(40)<<setiosflags(ios::right)<<b.number<<endl;
    cout<<setiosflags(ios::left)<<a.bg<<setw(40)<<setiosflags(ios::right)<<b.bg<<endl;
    cout<<"            _____________________________________________________"<<endl;
}
void comparingtwo()
{
   int x,y;
   system("cls");
   using namespace management;
   full_info abde;

   cout<<"Enter two index two compare two Contact"<<endl<<endl;;
   cout<<"Enter first index: ";
   cin>>x;
   cout<<"Enter 2nd index: ";
   cin>>y;
   cout<<"\n\n1.press 1 for comparing vertically\n2.press 2 for comparing horizontally"<<endl;
   cout<<"\t\t\nEnter your choice : ";
   int m;
   cin>>m;
   if(m==1)
        comparing(abde[x],abde[y]);
   else if(m==2)
         comparingBesides(abde[x],abde[y]);
   else
    cout<<"Invalid choice"<<endl;

    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();
}


///Functor
class functor
{
public:

    bool operator()(management::full_info a,management::full_info b)
    {
        return a.name<b.name;
    }
};
///Insertion
void inserted()
{
    system("cls");
    system("color 1A");
    using namespace management;

    ///Dynamic memory allocation

    full_info *abc;
    abc=new full_info;
    abc->getinfo();
    ofstream fout("output.txt",fstream::app);
    fout<<*abc;
    fout.close();


    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();
}

///Search function

void searched()
{
    system("cls");
    system("color 1A");
    using namespace management;
    ifstream fin("output.txt");
    int n;
    cout<<"1.press 1 for name \n2.press 2 for number\n3.press 3 for blood group\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>n;

    ///getline after cin

    char src[100];
    cin.ignore();
    cout<<"Enter something to search: ";
    cin.getline(src,100);
    string a;
    getline(fin,a);
    int pp=0;
    while(!fin.eof())
    {
        getline(fin,a);
        int k=a.length();
        if(a.find(src)<k)
        {
            stringstream sin(a);
            ///stringstream
            string x,b,c,d;
            sin>>x>>b>>c>>d;
            cout<<"__________________________________________"<<endl;
            cout<<"__________________________________________"<<endl;
            cout<<"Name: "<<x<<endl;
            cout<<"Mobile no:"<<b<<endl;
            cout<<"Email: "<<c<<endl;
            cout<<"Blood_group"<<d<<endl;
            pp=1;
        }
    }
    if(pp==0)
        cout<<"Not found "<<endl;
    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();


}
///Delete
void deleted()
{
    system("cls");
    system("color 1A");
    string nam;
    cout<<"Enter a name you wanted to delete: ";
    cin>>nam;
    using namespace management;
    vector<full_info>data;
    full_info cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    int p=0;
    while(!fin.eof())
    {
        fin>>cd;
        if(cd.name.compare(nam)==0)
        {
            p=1;
        }
        else
            data.push_back(cd);
    }
    data.pop_back();
    fin.close();
    if(p==0)
        cout<<nam<<" Not found "<<endl;
    else
    {
        ofstream fout("output.txt");
        vector<full_info>::iterator dd;
        fout<<a<<endl;
        for(dd=data.begin();dd!=data.end();dd++)
           {
            fout<<*dd;
            cout<<*dd;
           }
    }

    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();
}
///Update
void updated()
{
    system("cls");
    system("color 1A");
    string nam;
    cout<<"Enter a name you wanted to update: ";
    cin>>nam;
    using namespace management;
    vector<full_info>data;
    full_info cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    int p=0;
    while(!fin.eof())
    {
        fin>>cd;
        if(cd.name.compare(nam)==0)
        {
            p=1;
            cout<<"Do you want to change your name: "<<endl;
            cout<<"1.press 1 for yes \n2.press 2 for no\n\t\tEnter your choice: ";
            int x;
            cin>>x;
            if(x==1)
            {
                cout<<"Enter new name: ";
                cin>>cd.name;
            }

            cout<<"Do you want to change your Mobile: "<<endl;
            cout<<"1.press 1 for yes \n2.press 2 for no\n\t\tEnter your choice: ";
            cin>>x;
            if(x==1)
            {
                cout<<"Enter new number: ";
                cin>>cd.number;
            }
            cout<<"Do you want to change your email: "<<endl;
            cout<<"1.press 1 for yes \n2.press 2 for no\n\t\tEnter your choice: ";
            cin>>x;
            if(x==1)
            {
                cout<<"Enter new email: ";
                cd.getemail();
            }
            cout<<"Do you want to change your Blood_group: "<<endl;
            cout<<"1.press 1 for yes \n2.press 2 for no\n\t\tEnter your choice: ";
            cin>>x;
            if(x==1)
            {
                cout<<"Enter new blood_group: ";
                cd.getbg();
            }
            data.push_back(cd);
        }
        else
            data.push_back(cd);
    }
    data.pop_back();
    fin.close();
    system("cls");
    if(p==0)
        cout<<nam<<" Not found "<<endl;
    else
    {
        ofstream fout("output.txt");
        vector<full_info>::iterator dd;
        fout<<a<<endl;
        for(dd=data.begin();dd!=data.end();dd++)
           {
            fout<<*dd;
            cout<<*dd;
           }
    }


    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();

}

///View
void showall()
{
    system("cls");
    system("color 1A");
    using namespace management;
    vector<full_info>data;
    full_info cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    while(!fin.eof())
    {
        fin>>cd;
        data.push_back(cd);
        ///cout<<cd;
    }
    fin.close();
    data.pop_back();
    ofstream fout("output.txt");
    sort(data.begin(),data.end(),functor());
    vector<full_info>::iterator dd;
    fout<<a<<endl;
    system("cls");
    for(dd=data.begin();dd<data.end();dd++)
    {
        fout<<*dd;
        cout<<*dd<<endl<<endl;
    }

    cout<<"1.Press 1 for exit \n 2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();
}
///Sort
void sorted()
{
    system("cls");
    system("color 1A");
    using namespace management;
    vector<full_info>data;
    full_info cd;
    ifstream fin("output.txt");
    string a;
    getline(fin,a);
    while(!fin.eof())
    {
        fin>>cd;
        data.push_back(cd);
        ///cout<<cd;
    }
    fin.close();
    data.pop_back();
    ofstream fout("output.txt");
    cout<<"1.press 1 for sort by name \n2.press 2 for search by blood_group"<<endl;
    int lala;
    cout<<"\t\t Enter your choice: ";
    cin>>lala;

       ///lambda expression

    if(lala==1)
        {sort(data.begin(),data.end(),functor());}
    else if(lala==2)
        {sort(data.begin(),data.end(),[](full_info a,full_info b)->bool{return a.bg<b.bg;});}
    vector<full_info>::iterator dd;
    fout<<a<<endl;
    system("cls");
    for(dd=data.begin();dd<data.end();dd++)
    {
        fout<<*dd;
        cout<<*dd<<endl<<endl;
    }

    cout<<"1.Press 1 for exit \n2.Press 2 for go to main menu"<<endl;
    int ppp;
    cout<<"\t\tEnter your choice : ";
    cin>>ppp;
    if(ppp==1)
        return;
    else
        option();
}
///         Main        ////
///**************************************///

int main()
{
    using namespace management;
    system("color 1A");
    option();
}

