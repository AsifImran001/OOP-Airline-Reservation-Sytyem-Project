/**************************AIRPLAIN TICKET RESERVATION SYSTEM *********************************************************
                           DEVELEPED BY:
                           ASIF IMRAN      19011519-134
                           SARAM MUGHIRA   19011519-074
                           M. ZOHAIB       19011519-046*/
#include <iostream>
#include <fstream>
#include <string.h>
#include<cstring>
#include <conio.h>
#include <stdio.h>
#include<typeinfo>
#include<windows.h>
#include<time.h>
#include<algorithm>
using namespace std;
char choice;
void print_header(string name){
            system("cls");
            cout << "\n\t\t\t********************************\n";
            cout << "\t\t\t          "<<name<<"          \n";
            cout << "\t\t\t********************************\n\n";
}
class login
{
    char Username[20];
    int password;
    int Temp_password;
    int Passwprd_retype;
    bool flag = false;

public:
    login()
    {
        strcpy(Username, "None");
        this->password = 0;
    }
    void SetLogin()
    {   print_header("ADDING LOGIN");
        cout << "\t\t\t Please enter  Username : ";
        gets(Username);
        cout << "\t\t\t Please enter  Password : ";
        cin >> Temp_password;
        cout << "\t\t\t Please Re-type  Password : ";
        cin >> Passwprd_retype;
        cin.ignore();
        if (Temp_password == Passwprd_retype)
        {
            this->password = Temp_password;
            ofstream out("Login.dat", ios::binary | ios::app);
            if (this->Username != "None")
                out.write((char *)this, sizeof(*this));
            out.close();
        }
        else
        {
            cout << "in-correct Password or Username...\n Try again.";
            return SetLogin();
        }
    }
    string GetUsername() { return Username; }
    bool ChechLogin()
    {
        char username[20];
        int Password;
        print_header("LOGIN");
        cout <<"\n\t\t\tUsername: ";
        gets(username);
        cout <<"\t\t\tPassword: ";
        cin >> Password;cin.ignore();
        ifstream in("Login.dat", ios::in | ios::binary);
        if (in.is_open())
        {
            in.read((char *)this, sizeof(*this));
            while (!in.eof())
            {
                if (!stricmp(username,this->Username) && Password == this->password)
                {
                    return (flag = true);
                }
                in.read((char *)this, sizeof(*this));
            }
            in.close();
        }
        cin.ignore();
    }
    void printlogin()
    {   int count=0;
        ifstream in("Login.dat", ios::in | ios::binary);
        if (in.is_open())
        {
            in.read((char *)this, sizeof(*this));
            while (!in.eof())
            {    count++;
                cout <<  "\n\n\t\t\t **************Logine "<<count<<"***********\n"<<endl;
                cout <<  "\t\t\t username: " << this->Username << endl;
                cout <<  "\t\t\t password: " << this->password << endl;
                cout <<  "\t\t\t ******************************"<<endl;
                in.read((char *)this, sizeof(*this));
            }
            in.close();
        }
    }
};
class Date_time{

    short Hours;
    short Minutes;
    string Opening_day;
    string Closing_day;
    time_t t = time(NULL); 
    tm *timeptr=localtime(&t); 
    public:
    Date_time()
    {
        this->Hours=8;
        this->Minutes=45;
        this->Opening_day="Monday";
        this->Closing_day="Satureday";
    }
    void Setday()
    {
        cout<<"Enter Opening day: ";cin>>Opening_day;
        cout<<"Enter Closing day: ";cin>>Closing_day;
    }
    void SetTime()
    {
        cout<<"Enter Hours: ";cin>>Hours;
        cout<<"Enter Minutes: ";cin>>Minutes;
    }
    void Print_day()
    {
        cout<<"Opens 24/7\n"<<Opening_day<<" to "<<Closing_day<<endl;
    }
    void Print_Agency_Time()
    {
        cout<<Hours<<":"<<Minutes<<" am"<<endl;
    }
    void Print_Date()
    {
        cout<<(timeptr->tm_mday)<<"/"<<(timeptr->tm_mon)+1<<"/"<<(timeptr->tm_year)+1900;
    }
    void Print_time()
    {
        cout<<(timeptr->tm_hour)<<":"<<(timeptr->tm_min)<<":"<<(timeptr->tm_sec);
    }
    int Get_Hourse(){return (timeptr->tm_hour);}
    int Get_minutes(){return (timeptr->tm_min);}
    int Get_Seconds(){return (timeptr->tm_sec);}
    int Get_year(){return (timeptr->tm_year);}
    int Get_Month(){return (timeptr->tm_mon);}
    int Get_Day(){return (timeptr->tm_mday);}
};
class Person
{
protected:
    char Name[20];
    char Father_Name[20];
    int Date_Of_Birth[3];
    char Gender[7];
    int age;
   long long int CNIC;
   long long int Phone_No;
    char Email[25];

public:
    Person()
    {
        strcpy(Name, "None");
        strcpy(Father_Name, "None");
       Date_Of_Birth[0]=0;
       Date_Of_Birth[1]=0;
       Date_Of_Birth[2]=0;
       CNIC=0;
       Phone_No=0;
        strcpy(Gender,"None");
        strcpy(Email, "None");
        age = 0;
    }
    void Set_Person()
    {   cin.ignore();
        choice='y';
        while(choice !='n'){
        try{
        cout << "\t\t\t Please enter Name: ";
        cin.getline(Name, 20);
        cout << "\t\t\t Please enter Father Name: ";
        cin.getline(Father_Name, 20);
        cout << "\t\t\t Please enter Gender: "; gets(Gender);
        cout << "\t\t\t Please enter Date of Birth(DD/MM/YY): ";
         for(int i=0;i<3;i++)
             {
                 cin>>Date_Of_Birth[i];
                if(!cin)
                 throw 'a';
                if(Date_Of_Birth[i]<=0)
                throw -1;
            }
        cout << "\t\t\t Please enter age: ";
        cin >> age;if(!cin) throw 'a';if(age<=0) throw -1;
        cout << "\t\t\t Please enter CNIC: ";
        cin>>CNIC;if(!cin) throw 'a';if(CNIC<=0) throw -1;
        cout << "\t\t\t Please enter Phone No: ";
        cin>>Phone_No;if(!cin) throw 'a';if(Phone_No<=0) throw -1;
        cin.ignore();
        cout << "\t\t\t Please enter Email: ";
        cin.getline(Email, 125);
        choice='n';
        }
        catch(int){
            
        cout<<"\n\t\t\t Entered Values must be possitive:"<<endl;
        }
        catch(...)
        {  
             cin.clear();//clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//clear out the input buffer
            cout<<"\n\t\t\t Values must be numeric"<<endl;
        }
    }
    }
    void print_person()
    {
        cout << "\t\t\t Name:            " << Name << endl;
        cout << "\t\t\t Father Name:     " << Father_Name << endl;
        cout << "\t\t\t Date Of Birth :  " ;if(Date_Of_Birth[0]<10&&Date_Of_Birth[1]<10) cout<<"0"<<Date_Of_Birth[0]<<"/0"<<Date_Of_Birth[1]<<"/"<<Date_Of_Birth[2]<<endl;else cout<<Date_Of_Birth[0]<<"/"<<Date_Of_Birth[1]<<"/"<<Date_Of_Birth[2]<<endl;
        cout << "\t\t\t Age :            " << age << " years" << endl;
        cout << "\t\t\t Gender:          " << Gender << endl;
        cout << "\t\t\t CNIC:            " << CNIC << endl;
        cout << "\t\t\t Phone No:        " << Phone_No << endl;
        cout << "\t\t\t Email:           " << Email << endl;

    }
    string get_PersonName() { return Name; }
    long int get_personCNIC() { return CNIC; }
    long int get_personPhone() { return Phone_No; }
};
class Passenger : protected Person
{
    
    long long int passport;
    int prn;//passenger record number 
    public:
    Passenger():Person()
    {
        passport=0;
        prn=0;
    }
  void Set_passenger()
  { 
      choice='y';
      Set_Person();
      while(choice !='n'){
          try{
         cout << "\t\t\t Please enter Passport #: ";cin>>passport;
         if(!cin) throw 'a';if(passport<=0) throw -1;
         cout<<"\t\t\t Please enter PRN #"; cin>>prn;
         if(!cin) throw 'a';if(prn<=0) throw -1;
         cin.ignore();
        choice='n';
          }
         catch(int){
            system("cls");
            cout<<"\n\t\t\t Entered Values must be possitive:"<<endl;
             cout<<"\n\t\t\t try again.."<<endl;
        }
        catch(...)
        {    system("cls");
             cin.clear();//clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//clear out the input buffer
            cout<<"\n\t\t\t Values must be numeric"<<endl;
            cout<<"\n\t\t\t try again"<<endl;    
        }
      }
      cout<<"\n\t\t\t You have Entered Following Data "<<endl;
        print(1);
         cout<<"\n\t\t\t Are you sure To save this Data ?(y/n) :  ";choice=getche();
         if(choice=='Y'||choice=='y'){
      ofstream fout("Passenger.dat",ios::binary| ios::app);
      if(fout.is_open())
      {
          fout.write((char*)this,sizeof(*this));
      }
      else
      cout<<"\t\t\t ERROR File Not Found"<<endl;
      fout.close();
         }
         else{cout<<"\n\t\t\t Please renter Data "<<endl;return (Set_passenger());}
  }  
  void Display_passenger()
  {
      int count=0;
      ifstream fin("Passenger.dat",ios::binary|ios::in);
      if(fin.is_open())
      {
            fin.read((char*)this,sizeof(*this));
          while(!fin.eof())
          {
            count++;
            print(count);
            fin.read((char*)this,sizeof(*this));
          }
          fin.close();
      }
       else
      cout<<"\t\t\t ERROR File Not Found"<<endl;
  }
  int Search_passenger()
  {
      int PRN; int count=0;bool flag=false;
      cout<<"\t\t\t  Enter Passenger record number  : ";cin>>PRN;
      ifstream fin("Passenger.dat",ios::binary);
      if(fin.is_open())
      {
          fin.read((char*)this,sizeof(*this));
          while(!fin.eof())
              {
              if(PRN==this->prn)
             {      count++;
                    print(count);
                    flag=true;
                    return(this->prn);
             }
          fin.read((char*)this,sizeof(*this));     
          }
          if(flag==false){cout<<"\t\t\t No such record found"<<endl;return (Search_passenger());}
          fin.close();
      }
  }
  void print(int count)
  {
 cout<<"\n\n\t\t\t *******************************"<<endl;
            cout<<"\t\t\t          PASSENGER "<<count<<endl;
            cout<<"\t\t\t *******************************"<<endl;
            print_person();
            cout << "\t\t\t Passport #:      " << passport << endl;
            cout << "\t\t\t PRN #:           " << prn << endl;
  }
  void Delete_passenger(int PRN)
  {
      int prn = PRN;
        ifstream fin;
        ofstream fout;
        fin.open("Passenger.dat",ios::in|ios::binary);
        fout.open("temp.dat",ios::out|ios::binary);
        if(fin.is_open()){
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(prn !=this-> prn)
            {
                fout.write((char *)this,sizeof(*this));
            }
            
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        }
        remove("Passenger.dat");
        rename("temp.dat","Passenger.dat");
        cout<<"\n\t\t\t**********************************"<<endl;
        cout<<"\t\t\t*            SUCCESS!!!         *"<<endl;
        cout<<"\t\t\t**********************************\n";
        Display_passenger();
  }
  void Passenger_menu()
  {
      do
      {     system("cls");
          print_header("PASSENGER MENUE");
          cout<<"\n\t\t\t Choose Menu\n\t\t\t 1.List Passenger.\n\t\t\t 2.Search Passenger.\n\t\t\t 3. Go to back."<<endl;
          cout<<"\n\t\t\t Enter Here: ";choice=getche();
          switch (choice)
          {
          case '1':
                Display_passenger();
              break;
          case '2':
                Search_passenger();
              break;
          case '3':
              break; 
          default:
          cout<<"\n\t\t\t Invalid input"<<endl;
              break;
          }
        cout<<"\n\t\t\t";getch();
      } while (choice !='0');
      
  }
  string Get_passengerName(){return this->Name;}
  long long int Get_passengerCNIC(){return this->CNIC;}
  long long int Get_passengerPassport(){ return this->passport;}
  string Get_gender(){return Gender;}
  int get_passengerPRN(){return this->prn;}
};
class flight{
    private:
    char Plane_Name[20];
    char flight_no[20];
    char Flight_type[20];
    int Arrival_time;
    int Departure_time;
    char source[20];
    char Destination[20];
    int travle_time;
    int Rent;
    public:
    flight()
    {
        strcpy(Plane_Name,"none");
        strcpy(flight_no,"none");
        Arrival_time=0;
        Departure_time=0;
        strcpy(source,"none");
        strcpy(Destination,"none");
        strcpy(Flight_type,"None");
        travle_time=0;
        Rent=0;
    }
    void print()
    {
     cout<<"     "<<Plane_Name<<"\t      "<<flight_no<<"\t\t"<<source<<"\t     "<<Destination<<"\t\t  "<<Arrival_time<<"\t\t"<<Departure_time<<"\t\t    "<<travle_time<<"\t         "<<Rent<<"     "<<Flight_type<<endl;
    }
    void SetFlight( string Type)
    {   print_header("GETTING DATA");
        cout<<"\t\t\t Enter Plane Name :"; gets(Plane_Name);
        cout<<"\t\t\t Enter flight No :"; gets(flight_no); 
        cout<<"\t\t\t Enter Source :";gets(source);
        cout<<"\t\t\t Enter Destination :";gets(Destination);
        cout<<"\t\t\t Enter Arrival Time : ";cin>>Arrival_time;
        cout<<"\t\t\t Enter Departure Time : ";cin>>Departure_time;
        cout<<"\t\t\t Enter traveling Hours :";cin>>travle_time;
        strcpy(this->Flight_type,Type.c_str());
        cout<<"\t\t\t Enter Rent :";cin>>Rent;
        cin.ignore();
    }
    void AddSchedule(string Filename,string type)
    {   SetFlight(type);
        fstream  fout(Filename,ios::out|ios::binary|ios::app);
        if(fout.is_open())
        {
 
               if(Plane_Name!="none" && flight_no != "none"){
                fout.write((char*)this,sizeof(*this));
               }
        }
        else
        {
            cout<<"\t\t\tFile Error !!! File Not Found"<<endl;;
        }
        fout.close();
    }
    void Dispaly_schedule(string FileName)
    {
        int counter=1;
        ifstream fin(FileName,ios::in|ios::binary);
        cout<<"\t*************************************************************************************************************************************************\n";
        cout<<"\tSr# |\tAirplane     | Flight No      |  Source     | Destination    | Departure Time | Arrival Time | Travel Time(hr) | Price   |      Type\n";
        cout<<"\t*************************************************************************************************************************************************\n";
        if(fin.is_open())
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
            cout<<"\t"<<counter;print();
            counter++;
            fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        else
        {
            cout<<"\t\t\t Error !!! File not Found"<<endl;
        }
        
    }
    string Search_flight(string FileName){
        char Temp_source[20];
        char Temp_Destination[20];
        int counter=0;
        bool flag=false;
        cout<<"\t*************************************************************************************************************************************************\n";
        cin.ignore();
        cout<<"\n\t\t\t Enter Source : ";gets(Temp_source);
        cout<<"\t\t\t Enter Destination : ";gets(Temp_Destination);
        ifstream fin(FileName,ios::in|ios::binary);
        if(fin.is_open())
        {
        cout<<"\t*************************************************************************************************************************************************\n";
        cout<<"\tSr# |\tAirplane     | Flight No      |  Source     | Destination    | Departure Time | Arrival Time | Travel Time(hr) | Price   |      Type\n";
        cout<<"\t*************************************************************************************************************************************************\n";
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(!strcmp(Temp_source,this->source) && !strcmp(Temp_Destination,this->Destination))
                { 
                     counter++;
                     cout<<"\t"<<counter;print();
                    flag=true;
                    return flight_no;
                }
            fin.read((char*)this,sizeof(*this));
            }
        }
        else
        {
            cout<<"\t\t\t ERROR !!! FIle Not found"<<endl;
        }
        if(flag==false){cout<<"\t\t\t Record not Found!!"<<endl;
                        cout<<"\t\t\t OR Kindly Check your Spelling "<<endl;
                        cout<<"\t\t\t Do you want to again search ? (y/n)"<<endl;choice=getche();
                        if(choice=='Y' || choice == 'y')
                        return(Search_flight(FileName));
        }
            fin.close();
        
    }
    void Delete_flight(string FileName)
    {
        string Temp_flight_no;
        Temp_flight_no=Search_flight(FileName);
    cout<<"\n\n\t\t\t Are sure to Delete this Data ?\n\t\t\t";getch();
    ifstream fin;
    ofstream fout;
    fin.open(FileName,ios::in|ios::binary);
    if(fin.is_open())
    {
        fout.open("temp.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(Temp_flight_no !=this->flight_no)
            {
                fout.write((char *)this,sizeof(*this));
            }
            
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove(FileName.c_str());
        rename("temp.dat",FileName.c_str());
        cout<<"\n\t\t\t**********************************"<<endl;
        cout<<"\t\t\t*            SUCCESS!!!         *"<<endl;
        cout<<"\t\t\t**********************************\n"<<endl;
        Dispaly_schedule(FileName);
        getch();
    }
    else cout<<"\t\t\tFile is not found";
    }
    string Get_Source(){return this->source;}
    string Get_Destination(){return this->Destination;}
    string Get_PlaneName(){return this->Plane_Name;}
    string Get_FlightNo(){return this->flight_no;}
    string Get_FlightType(){return Flight_type;}
    int Get_rent(){return Rent;}
    string Get_travel_type(){return Flight_type;}
};
class Schedule{
    public:
    flight F;
    void Schedule_menue()
    {
        do{
        system("cls");
        print_header("SCHEDULE MENU");
        cout<<"\n\t\t\t Choose Menue."<<endl;
        cout<<"\t\t\t\t1. Add International Schedule."<<endl;
        cout<<"\t\t\t\t2. Add Domestic Scedule."<<endl;
        cout<<"\t\t\t\t3. List International Scedule."<<endl;
        cout<<"\t\t\t\t4. List Domestic Schedule."<<endl;
        cout<<"\t\t\t\t5. Delete International Scedule."<<endl;
        cout<<"\t\t\t\t6. Delete Domestic Schedule."<<endl;
        cout<<"\t\t\t\t0. Go to Back."<<endl;
        cout<<"\n\t\t\t Enter Here : ";choice=getche();cout<<endl;
        switch (choice)
        {
        case '1':{
            F.AddSchedule("International.dat","International");
            break;
        }
        case '2':{
            F.AddSchedule("Domestic.dat","Domestic");
            break;
        }
        case '3':{
            F.Dispaly_schedule("International.dat");
            break;
        }
        case '4':{
             F.Dispaly_schedule("Domestic.dat");
            break;
        }
        case '5':{
             F.Dispaly_schedule("International.dat");
            F.Delete_flight("International.dat");
            break;
        }
        case '6':{
             F.Dispaly_schedule("Domestic.dat");
            F.Delete_flight("Domestic.dat");
            break;
        }
        case '0':{
            break;
        }
        default:
            cout<<"\n\t\t\tInavalid Input"<<endl;
            break;
        }
        cout<<"\n\t\t\t Press Enter to Continue.";
        getch();
        }while(choice != '0');
    }
};
class Employee : protected Person
{
private:
    int ID_No;
    char Designation[20];

public:
    Employee() : Person()
    {
        ID_No = 0;
        strcpy(Designation, "None");
    }

    void Set_employe()
    {   
        print_header("ADDING EMPLOYEE");
        Set_Person();

        cout << "\t\t\t Please Enter ID No: ";
        cin >> ID_No;
        cin.ignore();
        cout << "\t\t\t Please enter Designation: ";
        cin.getline(Designation, 20);
    }
    void Store_Employee(string FileName)
    {
        if (get_PersonName() != "None" && get_personCNIC() != 0)
        { //avoiding to write constructor data
            ofstream fout(FileName, ios::out | ios::app | ios::binary);
            fout.write((char *)this, sizeof(*this));
            fout.close();
            cout<<"\n\t\t\t SUCCESS";
        }
        else
            cout << "\t\t\t Data Not Intialized" << endl;
    }
    void Read_Employee(string File_Name, string E_type)
    {
        int counter = 1;
        ifstream Fin(File_Name, ios::in | ios::binary );
        if (Fin.is_open())
        {
            Fin.read((char *)this, sizeof(*this));
            while (!Fin.eof())
            {
                cout << "\t\t\t****************************\n"<<endl;
                cout << "\t\t\t  " << E_type << " (" << counter << ")\n"<<endl;
                Print_Employee();
                counter++;
                Fin.read((char *)this, sizeof(*this));
            }
            Fin.close();
        }
        else
            cout << "\t\t\t File not Opened" << endl;
    }
    void Print_Employee()
    {
        print_person();
        cout << "\t\t\t ID:              " << ID_No << endl;
        cout << "\t\t\t Designation:     " << Designation << endl;
    }
    int Search(string File_name, string E_type, string s_type) //S_type means to print either searching is for deleting or only search purposes
    {
        int ID;
        bool flag = true, op = true;
        char Designation_temp[20], Name_temp[20];
        strcpy(Designation_temp, "None");
        strcpy(Name_temp, "None");
        bool flag1 = false;
        int counter = 1;
        if (s_type != "Delete")
        {
            do
            {
                cout << "\n\t\t\t Search By :" << endl;
                cout << "\t\t\t 1. Name. " << endl;
                cout << "\t\t\t 2. ID No#." << endl;
                cout << "\t\t\t 3. Designation. :" << endl;
                cout << "\t\t\t 0. Go to Back Menue " << endl;
                cout << "\n\t\t\t Enter Here :";
                choice = getch();
                switch (choice)
                {
                case '1':
                    cout << "\n\t\t\t Enter Name :";
                    gets(Name_temp);
                    flag = false;
                    break;
                case '2':
                    cout << "\n\t\t\t Enter ID # :";
                    cin >> ID;
                    cin.ignore();
                    flag = false;
                    break;
                case '3':
                    cout << "\n\t\t\t Enter Designation :";
                    gets(Designation_temp);
                    flag = false;
                    break;
                case '0':
                    flag = false;
                    op = false;
                    break;
                default:
                    cout << "\t\t\t Invalid input try again";
                    getch();
                }
            } while (flag);
        }
        else
        {
            cout << "\t\t\t Searching for Record." << endl;
            cout << "\t\t\t Enter ID NO to " << s_type << ":";
            cin >> ID;
        }
        if (op == true)
        {
            ifstream fin(File_name, ios::in | ios::binary);
            if (fin.is_open())
            {
                fin.read((char *)this, sizeof(*this));
                cout << "\t\t\t****************************\n" << endl;
                while (!fin.eof())
                {
                    if (ID == this->ID_No || !strcmp(Designation_temp, this->Designation) || !strcmp(Name_temp, this->Name))
                    {
                        cout << "\t\t\t   " << E_type << " (" << counter << ")\n"<< endl;
                        Print_Employee();
                        if (s_type == "Delete")
                            return ID;
                        counter++;
                        flag1 = true;
                        cout << "\n\t\t\t*************<><><><>***************\n"<< endl;
                    }
                    fin.read((char *)this, sizeof(*this));
                }
                if (flag1 == false)
                {
                    cout << "\t\t\t Record Not found" << endl;
                    cout << "\t\t\t****************************\n"<< endl;
                }
                fin.close();
            }
            else
                cout << "\t\t\t File not Found..." << endl;
        }
    }
    void Delete(string filename,string E_type)
    {
        cout << "\t\t\tDELETING......" << endl;
        int ID = Search(filename, E_type, "Delete");
        cout << "\t\t\t Are sure to Delete this Data ?\n\t\t\t" << system("PAUSE");
        ifstream fin;
        ofstream fout;
        fin.open(filename, ios::in | ios::binary);
        if (fin.is_open())
        {
            fout.open("temp.dat", ios::out | ios::binary);
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                if (ID != ID_No)
                {
                    fout.write((char *)this, sizeof(*this));
                }

                fin.read((char *)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove(filename.c_str());
            rename("temp.dat", filename.c_str());
        }
        else
            cout << "\t\t\tFile is not found";
    }

    /*void Update(string filename)
{   char check_name[20];
cout<<"\t\t\t Enter Name to Update Record";gets(check_name);
    fstream file(filename,ios::out|ios::in|ios::ate|ios::binary);
    file.seekg(0);//setting pointer to Fist possition
    int seekp;
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(check_name,Name))
        {
            cout<<"updating record......"<<endl;
            Set_employe();
            file.seekp(file.tellp()-sizeof(Employee));
            file.write((char*)this,sizeof(*this));
        }
    file.read((char*)this,sizeof(*this));
    }
    file.close();
}
*/
};
class Agency
{
    char agency_name[30];
    long int Reg_No;
    int Helpline;
    char Address[50];
    char Email[30];
   long int PhoneNo;

public:
    Agency()
    {
        strcpy(agency_name, "Alflah Tour And Travelars");
        strcpy(Email, "Info@alflah.com");
        PhoneNo=3426065866;
        strcpy(Address, "Main Road Gujrat ,Phalia, Mandi bhauddin");
        Helpline = 1111;
        Reg_No = 444567;
    }
    void set_agency()
    {
        print_header("AGENCY DATA");
        cout << "\t\t\t Enter New Agency Name: ";
        gets(agency_name);
        cout << "\t\t\t Enter New Email :";
        gets(Email);
        cout << "\t\t\t Enter New Phone NO: ";
        cin>>PhoneNo;cin.ignore();
        cout << "\t\t\t Enter New Address :";
        gets(Address);
        cin.ignore();
        cout << "\t\t\t Enter Agency Registration No : ";
        cin >> Reg_No;
        cin.ignore();
        cout << "\t\t\t Enter New Helpline: ";
        cin >> Helpline;
        ofstream fout("Agency.dat", ios::out | ios::binary);
        if (fout.is_open())
        {
            fout.seekp(0);
            fout.write((char *)this, sizeof(*this));
        }
        else
        {
            cout << "\t\t\t ERROR !! File Not Found" << endl;
        }
        fout.close();
    }
    void Print_Agency()
    {
        ifstream fin("Agency.dat", ios::in | ios::binary);
        fin.seekg(0);
        if (fin.is_open())
        {
            fin.read((char *)this, sizeof(*this));
        }
        else
        {
            cout << "\t\t\t ERROR !! File Not Found" << endl;
        }
        fin.close();
        cout << "\t\t\t     " << agency_name << endl
             << endl;
        cout << "\t\t\tEmail:         " << Email << endl;
        cout << "\t\t\tHelpline #     " << Helpline << endl;
        cout << "\t\t\tPhone #        " << PhoneNo << endl;
        cout << "\t\t\tRegistration # " << Reg_No << endl;
        cout << "\t\t\tAddress :      " << Address << endl;
    }
    void Agency_Menue()
    {
        char choice;
        do
        {
            cout << "\n\t\t\t********************************\n";
            cout << "\t\t\t    WELCOME TO AGENCY MENU \n";
            cout << "\t\t\t********************************\n\n";
            cout << "\t\t\tChoose Your Desired Option " << endl;
            cout << "\t\t\t 1. Set Agency " << endl;
            cout << "\t\t\t 2. Check Agency Info. " << endl;
            cout << "\t\t\t 0. Go to Main Menu. " << endl;
            cout << "\t\t\t Enter Here :";
            choice = getche();
            switch (choice)
            {
            case '1':
                set_agency();
                break;
            case '2':
                Print_Agency();
                break;
            case '3':
                break;
            default:
                break;
            }
            system("pause");
        } while (choice != '0');
    }
    string GetAgencyName(){return this->agency_name;}
    int Get_helpline(){return this->Helpline;}
    string Get_email(){return this->Email;}
    string Get_adrres(){return this->Address;}
};
class Seat{
    int seat_NO=0;
    char seat_type[15];
    int tax=0;
    public:
    void Set_seat()
    {   system("cls");
        cout<<"\n\t\t\t Note : If you choose Bussines Class RS 20000 tax will apply.\n ";
        cout<<"\n\t\t\t choose \n";
        cout<<"\t\t\t1. Bussiness Class.\n\t\t\t2. Economy Class"<<endl;
        cout<<"\t\t\t Enter Here : ";choice=_getche();
        switch (choice)
        {
        case '1':
            strcpy(seat_type,"Bussiness");
            tax=tax+20000;
            seat_NO=rand()%20+1;
            break;
        case '2':
            strcpy(seat_type,"Economy");
            tax=0;
            seat_NO=rand()%200+20;
            break;
        default:
            cout<<"\n\t\t\tInvalid input ..try again"<<endl;
            break;
            getch();
            system("cls");
        }
    }
    string Get_seat_type(){return seat_type;}
    int Get_seat_no(){return seat_NO;}
    int Get_tax(){return tax;}
};
class Ticket{
    int Tiket_no;
    char PassengerName[20];
    long long int PassengerCNIC;
   long long Passport;
    char Plane_Name[20];
    char flight_no[20];
    char source[20];
    char Destination[20];
    char Gender[7];
    char Travel_Type[20];
    char date_time[20];
    int Rent;
    int hr,min,sec,y,m,d;
    int seatNO;
    char seat_type[15];
    int prn;

    
public:
    Ticket()
    {
        strcpy(PassengerName,"None");
        Passport=0;
        strcpy(Plane_Name,"None");
        strcpy(flight_no,"None");
        strcpy(Gender,"None");
        strcpy(source,"None");
        strcpy(Destination,"None");
       PassengerCNIC=0;
        strcpy(Travel_Type,"None");
        strcpy(date_time,"None");
        strcpy(seat_type,"None");
        Tiket_no=0;
        seatNO=0;
        Rent=0;
        prn=0;
        hr=min=sec=0;
        y=m=d=0;
    }
    void CopySceduleData(Schedule S,Seat seat)
    {
    strcpy(Plane_Name,S.F.Get_PlaneName().c_str());
    strcpy(flight_no,S.F.Get_FlightNo().c_str());
    strcpy(source,S.F.Get_Source().c_str());
    strcpy(Destination,S.F.Get_Destination().c_str());
    strcpy(Travel_Type,S.F.Get_travel_type().c_str());
    Rent=S.F.Get_rent()+seat.Get_tax();
    seatNO=seat.Get_seat_no();
    }
    void copy_date_time(Date_time Dt){
        hr=Dt.Get_Hourse();min=Dt.Get_minutes();sec=Dt.Get_Seconds();
        y=Dt.Get_year();m=Dt.Get_Month();d=Dt.Get_Day();
    }
    void CopyPassengerdata(Passenger P,Seat seat)
    {
     strcpy(PassengerName,P.Get_passengerName().c_str());
     Passport=P.Get_passengerPassport();
     PassengerCNIC=P.Get_passengerCNIC();
     strcpy(seat_type,seat.Get_seat_type().c_str());
     strcpy(Gender,P.Get_gender().c_str());
     prn=P.get_passengerPRN();
    }
    void Book_Ticket(Schedule S,Passenger P,Date_time Dt,Agency A,Seat seat)
    {
    print_header("TICKET BOOKING MENUE");
    cout<<"\t\t\t Please Choose Menue :"<<endl;
    cout<<"\t\t\t 1. Domestic Traveling.\n\t\t\t 2. International Traveling.\n\t\t\t 0. Go to Back."<<endl;
    cout<<"\t\t\t Enter Here :"; choice=getche();cout<<"\n\n";
    switch (choice)
    {
    case '1':{
        S.F.Dispaly_schedule("Domestic.dat");
        S.F.Search_flight("Domestic.dat");
        CopySceduleData(S,seat);
        print_header("PASSENGER DATA");
        P.Set_passenger();
        Tiket_no=(rand()%300+1);
        seat.Set_seat();
        CopyPassengerdata(P,seat);
        copy_date_time(Dt);
        cout<<"\n\t\t\t Your Have Entered Following Data :\n"<<endl;
        Print_ticket();
        ofstream fout("Ticket.dat",ios::binary|ios::app);
        if(Tiket_no != 0 && Rent!=0)
        fout.write((char*)this,sizeof(*this));
        fout.close();
        print_bill(S,A,Dt,seat);
        pay_bill();
        cout<<"\n\t\t\t Data Suuceefuly Saved"<<endl;
        break;
    }
    case '2':{
        S.F.Dispaly_schedule("International.dat");
        S.F.Search_flight("International.dat");
        CopySceduleData(S,seat);
        print_header("PASSENGER DATA");
        P.Set_passenger();
        Tiket_no=(rand()%300+150);
        seat.Set_seat();
        CopyPassengerdata(P,seat);
        copy_date_time(Dt);
        cout<<"\n\t\t\t Your Have Entered Following Data :\n"<<endl;
        Print_ticket();
        ofstream fout("Ticket.dat",ios::binary|ios::app);
        if(Tiket_no != 0 && Rent!=0)
        fout.write((char*)this,sizeof(*this));
        fout.close();
        print_bill(S,A,Dt,seat);
        pay_bill();
        cout<<"\n\t\t\t Data Suuceefuly Saved"<<endl;
        break;
    }
    case '0':
        break;
    default:
        cout<<"\t\t\t Invalid Input"<<endl;
        break;
    system("pause");
    system("cls");
    }
    }
    void Print_ticket(){
        cout<<"\n\t\t\t****************************"<<endl;
        cout<<"\t\t\t       Ticket# "<<Tiket_no<<endl;
        cout<<"\t\t\t****************************\n"<<endl;
        cout<<"\t\t\t Name :          "<<PassengerName<<endl;
        cout<<"\t\t\t CNIC #          "<<PassengerCNIC<<endl;
        cout<<"\t\t\t Gender :        "<<Gender<<endl;
        cout<<"\t\t\t Passport#       "<<Passport<<endl;
        cout<<"\t\t\t PRN #           "<<prn<<endl;
        cout<<"\t\t\t Plane :         "<<Plane_Name<<endl;
        cout<<"\t\t\t Flight #        "<<flight_no<<endl;
        cout<<"\t\t\t Seat #          "<<seatNO<<endl;
        cout<<"\t\t\t Class :         "<<seat_type<<endl;
        cout<<"\t\t\t Source :        "<<source<<endl;
        cout<<"\t\t\t Destination :   "<<Destination<<endl;
        cout<<"\t\t\t Travel :        "<<Travel_Type<<endl;
        cout<<"\t\t\t Time :          "<<hr<<":"<<min<<":"<<sec<<endl;
        cout<<"\t\t\t Date :          "<<d<<"/"<<m+1<<"/"<<y+1900<<endl;
    }

    void List_tickets()
    {
        ifstream fin("Ticket.dat",ios::binary|ios::in);
        if(fin.is_open()){
            fin.seekg(0);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                Print_ticket();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        else
        {
            cout<<"\t\t\t Error File Not opened"<<endl;
        }
        
    }
    int Search_ticket()
    {
        cin.ignore();
        char temp_name[20];
        int temp_ticketNo;
        strcpy(temp_name,"None");
        cout<<"\n\t\t\t Please Choose "<<endl;
        cout<<"\t\t\t 1. Search by Name :"<<"\n\t\t\t 2. Search by ticket No."<<"\n\t\t\t 0. Go to Back."<<endl;
        cout<<"\t\t\t  Ente Here :  ";choice=getche();
        switch (choice)
        {
        case '1':
            cout<<"\n\t\t\t Please Enter Passenger Name : ";gets(temp_name);
            break;
        case '2':
            cout<<"\n\t\t\t Please Enter Ticket # : ";cin>>temp_ticketNo;cin.ignore();
            break;
        case '0':
            break;
        default:
            cout<<"\t\t\t Inavlid Input "<<endl;
            break;
            getch();
        }
        
        ifstream fin("Ticket.dat",ios::binary);
        if(fin.is_open()){
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(!strcmp(temp_name,this->PassengerName)|| temp_ticketNo == this->Tiket_no){
                Print_ticket();
                return(this->prn);
                }
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
        else
        {
            cout<<"\t\t\t File Not Opened "<<endl;
        }
        
    }
    void Cancel_ticket(Passenger P)
    {
        int temp_prn=Search_ticket();
        cout<<"\t\t\t Reminder........"<<endl;
        cout<<"\t\t\t Are you sure to cancel this ticket.(y/n) : ";choice=getche();
        if(choice=='y' || choice == 'Y'){
        ifstream fin("Ticket.dat",ios::in|ios::binary);
        ofstream fout("temp.dat",ios::out|ios::binary);
        if(fin.is_open()){
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
            if(temp_prn != this->prn)
            {
                fout.write((char*)this,sizeof(*this));
            }
             fin.read((char*)this,sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("Ticket.dat");
            rename("temp.dat","Ticket.dat");
            cout<<"\n\t\t\t Ticket has been canceled..."<<endl;
         }
        else
        cout<<"\t\t\t File not opened"<<endl;
        P.Delete_passenger(temp_prn);
     }
    else
    {
        cout<<"\t\t\t Ticket is not Canceled..."<<endl;
    }
    }
    void print_bill(Schedule S,Agency A,Date_time Dt,Seat seat)
    {
        cout<<"\n\n\t\t\t************************************\n";
        cout<<"\t\t\t*             BILL                 *\n";
        cout<<"\t\t\t************************************\n";
        cout<<"\t\t\t      "<<A.GetAgencyName()<<"\n"<<endl;
        cout<<"\t\t\t";Dt.Print_Date();cout<<"                 ";Dt.Print_time();cout<<endl;
        cout<<"\n\t\t\t Name :                    "<<PassengerName<<endl;
        cout<<"\t\t\t Passport#:                "<<Passport<<endl;
        cout<<"\t\t\t Class :                   "<<seat_type<<endl;
        cout<<"\t\t\t Seat # :                  "<<seatNO<<endl;
        cout<<"\t\t\t class tax :               "<<seat.Get_tax()<<endl;
        cout<<"\t\t\t ticket price :            "<<S.F.Get_rent()<<endl;
        cout<<"\n\t\t\t************************************\n";
        cout<<"\t\t\tTotal                      "<<seat.Get_tax()+S.F.Get_rent()<<" Rs"<<endl;
        cout<<"\t\t\t************************************\n";
        cout<<"\t\t\t\t For any Query "<<endl;
        cout<<"\t\t\t Contact us at:"<<endl;
        cout<<"\n\t\t\t Helpline # "<<A.Get_helpline();
        cout<<"\n\t\t\t Email :    "<<A.Get_email();
        cout<<"\n\t\t\t Address :  "<<A.Get_adrres();
        cout<<"\n\t\t\t************************************\n";
    }
    void pay_bill()
    {
        long int creditNumber;
        char password[20];
        cout<<"\n\t\t\tChoose Your Payment Method"<<endl;
        cout<<"\n\t\t\t1. Cash\n\t\t\t2. Credit Card."<<endl;
        cout<<"\n\t\t\t Enter Here : ";choice=getche();cout<<"\n";
        switch (choice)
        {
        case '1':
            cout<<"\t\t\t Payment Successfull"<<endl;
            break;
        case '2':
            cout<<"\t\t\t Enter Card number: ";cin>>creditNumber;cin.ignore();
            cout<<"\t\t\t Enter Password :   ";gets(password);
            cout<<"\t\t\t Payment Successfull"<<endl;
            break;
        default:
            cout<<"\n\t\t\t Invlaid input"<<endl;
            break;
        }
        cout<<"\n\t\t\t Press enter to continue";getch();
    }
    void Ticket_menu(Schedule S,Passenger P,Date_time Dt,Agency A,Seat seat)
    {
        do
        {   system("cls");
            print_header("TICKET MENU");
            cout<<"\n\t\t\t Choose Menu:"<<endl;
            cout<<"\n\t\t\t 1.Book Ticket.\n\t\t\t 2. List Tickets.\n\t\t\t 3. Search Ticket.\n\t\t\t 4. Cancel Ticket.\n\t\t\t 0.Go to back."<<endl;
            cout<<"\n\t\t\t Enter Here: ";choice=getche();cout<<endl;
            switch (choice)
            {
            case '1':
                Book_Ticket(S,P,Dt,A,seat);
                break;
            case '2':
                List_tickets();
                break;
            case '3':
                Search_ticket();
                break;
            case '4':
                Cancel_ticket(P);
                break;  
            case '0':
                break;
            default:
            cout<<"\n\t\t\t Invalid input try again."<<endl;
                break;
            }
            getch();
        } while (choice !='0');
        
    }
};
class Booking_Agent : public Employee
{
public:
    void Set_Booking_agent()
    {
        cin.ignore();
        Set_employe();
        Store_Employee("Booking_agent.dat");
    }
    void Print_BookingAgent()

    {
        cout << "\t\t\t***************" << endl;
        Read_Employee("Booking_agent.dat", "Booking Agent");
    }
    void Search_Agent()
    {
        Search("Booking_agent.dat", "Booking Agent", "Search");
    }
    void Delete_Agent()
    {
        Delete("Booking_agent.dat","Booking Agent");
    }
    void Update_Booking_agent()
    {
        // Update("Booking_agent.dat");
        cout << "\t\t\tRecord updated" << endl;
    }
    void Booking_agent_menu(login log)
    {
        bool flag = true;
        do
        {
            system("cls");
            print_header("BOOKING AGENT MENU");
            cout << "\t\t\t Choose Menue.\n" << endl;
            cout << "\t\t\t (1) Add Agent." << endl;
            cout << "\t\t\t (2) Search Agent." << endl;
            cout << "\t\t\t (3) Delete Agent." << endl;
            cout << "\t\t\t (4) List Agents." << endl;
             cout<< "\t\t\t (0) Go to back."<<endl;
            cout << "\t\t\t Enter Here :";
            choice = getche();
            cout << endl;
            switch (choice)
            {
            case '1':
                Set_Booking_agent();
                log.SetLogin();
                break;
            case '2':
                Search_Agent();
                break;
            case '3':
                Delete_Agent();
                break;
            case '4':
                Print_BookingAgent();
                break;
            case '0':
                flag=false;
                break;
            default:
                cout << "\t\t\t Invalid Input" << endl;
                cout << "\t\t\t choose any other Option" << endl;
                break;
            }
            cout << "\t\t\t Do you want to Continue...(y/n)";
            choice = getche();
            cout << endl;
            system("cls");
        } while (flag);
    }
    void Booking_Agent_access_Menu(Ticket tk,Schedule S,Date_time Dt,Agency A,Seat seat,Passenger P)
    {
        char choice;
         do
    {   
        print_header("BOOKING AGENT MENUE");
        cout<<"\t\t\t Chose your Desired Option,"<<endl;
        cout<<"\t\t\t 1 Ticket Menu"<<endl;
        cout<<"\t\t\t 2 Scedule Menu."<<endl;
        cout<<"\t\t\t 3 Passenger Menu."<<endl;
        cout<<"\t\t\t 0 Go to Main Menu"<<endl;  
        cout<<"\n\t\t\t Enter Here : ";choice=getche();cout<<endl;
        switch (choice)
        {
        case '1':
            tk.Ticket_menu(S,P,Dt,A,seat);
            break;
        case '2':
            S.Schedule_menue();
            break;
        case '3':
            P.Passenger_menu();
            break;
        case '0':
            break;
        default:
            cout<<"\n\t\t\tInvalid Input "<<endl;
            break;
        }
        system("cls");
    } while (choice != '0');
    
    }
};
class Manager : public Employee
{

public:
    void Set_maneger()
    {
        Set_employe();
        Store_Employee("Maneger.dat");
    }
    void About_Maneger()
    {
        Read_Employee("Maneger.dat", "Manager");
    }
    void MAnager_Menu(Booking_Agent BA, Agency A, Schedule S,login log)
    {
        do
        {  
            print_header("MANAGER MENU");
            cout << "\t\t\tChoose Your desired option." << endl;
            cout << "\t\t\t 1. Agency Menue" << endl;
            cout << "\t\t\t 2. Booking Agent Menue" << endl;
            cout << "\t\t\t 3. Schedule Menu ." << endl;
            cout << "\t\t\t 4. Add Manager." << endl;
            cout << "\t\t\t 5. About Manager." << endl;
            cout << "\t\t\t 6. List Logins." << endl;
            cout << "\t\t\t 0. Go to main Menu." << endl;
            cout << "\t\t\t  Enter Here :";
            choice = getche();
            switch (choice)
            {
            case '1':
                A.Agency_Menue();
                break;
            case '2':
                BA.Booking_agent_menu(log);
                break;
            case '3':
               S.Schedule_menue();
                break;
            case '4':
                Set_maneger();
                log.SetLogin();
                break;
            case '5':
                About_Maneger();
                break;
            case '6':
                log.printlogin();
                break;
            case '0':
                break;
            default:
            {
                cout << "\n\t\t\t Invalide Choice" << endl;
                break;
            }
            }
             getch();
             system("cls");
        } while (choice != '0');
    }
};
void Dashboard()
{
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t   * ************ *     **************    ***********       **********    \n";
	cout<<"\t\t\t\t\t\t\t   ****************     **************    ***********       ***********     \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **        **     **          **   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **        **     **               \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **        **     **               \n";
	cout<<"\t\t\t\t\t\t\t   ****************           **          ***********      **************   \n";
	cout<<"\t\t\t\t\t\t\t   ****************           **          ***********      **************   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **      **                   **   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **       **                  **   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **        **     **          **   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **         **     ************   \n";
	cout<<"\t\t\t\t\t\t\t   **            **           **          **          **     ***********     \n\n\n";
	cout<<" \t\t\t\t\t\t\t                      AIRPLANE TICKET RESERVATION SYSTEM                    \n";
    cout<<"\n\n \t\t\t\t\t\t\t\t\t\tAll right reserved to Asif & group"<<endl;
    cout<<"\n\n \t\t\t\t\t\t\t\t\t\t    Press Enter To Continue: ";getch();
    cout<<"\n\n \t\t\t\t\t\t\t\t\t\t    Loading ";
    for(int i=0;i<8;i++)
    {
        Sleep(300);
        cout<<"* ";
    }
    cout<<"\n\n \t\t\t\t\t\t\t\t\t\t    Loading Complete  ";Sleep(1000);
    system("cls");
    cout<<endl;
}
void Credit()
{
    	cout <<"\n\n\n                     __________________________________________________________________  " << endl;
		cout << "                   |__________________________________________________________________| " << endl;
		cout << "                   ||                          AIRPLANE                              || " << endl;
		cout << "                   ||                  TICKET RESERVATION SYSTEM                     || " << endl;
		cout << "                   ||****************************************************************|| " << endl;
		cout << "                   ||_______________________________________________________________ || " << endl;
		cout << "                   ||                       PROJECT MADE BY :-                       || " << endl;
		cout << "                   ||                                                                || " << endl;
		cout << "                   ||              ASIF IMRAN            19011519-134                || " << endl;
		cout << "                   ||              SARAM MUGHIRA         19011519-074                || " << endl;
		cout << "                   ||              M.ZOHAIB              19011519-046                || " << endl;
		cout << "                   ||                                                                || " << endl;
		cout << "                   ||____________________   ENTER ENTER TO QUIT    __________________|| " << endl;
		cout << "                   |_________________________________________________________________ | " << endl;   
        cout << "                                                    ";getch();cout<<endl;
}
int main()

{
    Ticket tk;
    Agency A;
    Schedule S;
    Passenger P;
    Date_time Dt;
    Seat seat;
    login log;
    Employee E;
    Booking_Agent BA;
    Manager M;
    char Choice1;

    Dashboard();
   do
    {   system("cls");
        print_header("MAIN MENU");
        cout << "\n\t\t\t\t 1.Login" << endl;
        cout << "\t\t\t\t 0.Close Program." << endl;
        cout << "\n \t\t\t Enter Here: ";
        Choice1 = getche();
        switch (Choice1)
        {
        case '1':
            if (log.ChechLogin() == true && log.GetUsername() == "Asif imran")
            {   print_header(log.GetUsername());
                cout<<"\n";
                M.MAnager_Menu(BA, A, S,log);
            }
            else if (log.ChechLogin() == true);
            {
                print_header(log.GetUsername());
                cout<<"\n";
                BA.Booking_Agent_access_Menu(tk,S,Dt,A,seat,P);
            }
            break;
        case '0':
            Credit();
            cout << "                       Loading ";
            for(int i=0;i<9;i++)
            {
                Sleep(250);
                cout<<"* ";
            }
            system("cls");
            exit(0);
        default:
            cout << "\t\t\t invalid Input..try again" << endl;
            break;
        }
    } while (Choice1 != '0');
    
}
