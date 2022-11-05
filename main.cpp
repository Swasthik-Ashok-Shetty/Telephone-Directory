#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<regex>
using namespace std;
void line(char ch='-', int n=120)
{
	for(int i=0;i<n;i++)
		cout<<ch;
}

class Telephone
{
	private:char name[60];
			char add[100];
			char place[30];
			char phone[15];
			char email[80];
	public: // input data from keyboard
			void input()
			{   cout<<"\n Enter Name :";
				fflush(stdin);
				cin.getline(name,60);
				cout<<"\n Enter Address :";
				fflush(stdin);
				cin.getline(add,100);
				cout<<"\n Enter Place :";
				fflush(stdin);
				cin.getline(place,30);
				number: cout<<"\n Enter Phone No :";
				fflush(stdin);
				cin.getline(phone,15);
				int checknum = isValidnum(phone);
				if(checknum)
                {   email:cout<<"\n Enter Email Id :";
                    fflush(stdin);
                    cin.getline(email,80);
                    int checkemail = isValidemail(email);
                    if(!checkemail)
                    {   cout<<" Invalid Email"<<endl;
                        goto email;
                    }
                }
                else
                {   cout<<" Invalid Phone Number"<<endl;
                    goto number;
                }
			}
			int count_record()
			{   int rec=0;
				ifstream fin;
				fin.open("telephone.dat",ios::binary);
				while(fin.read((char*)this,sizeof(Telephone)))
                    rec++;
				fin.close();
			 	return rec;
			}
			// menus
			void main_menu();
			void search_menu();
			void report_menu();
            //Records
            void add_new_record();
			void delete_record();
			void modify_record();
			void clear_database();

			// search options
			void search_name();
			void search_phone();
			void search_email();
			void search_place();
			void search_gen();
			// report options
			void report_total();
			void report_name_phone();
			void report_name_email();
			//Validations
			int isValidemail(string);
			int isValidnum(string);

};

//Searching Fucntions
void Telephone:: search_name()
{   cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tName Search\n";
    line();
    cout<<"\n";
	ifstream fin;
	fin.open("telephone.dat",ios::binary);
    fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {    cout<<"\nTelephone Directory Is Empty"<<endl;
         fin.close();
    }
    else
    {   char tname[60];
        int found =0;
        fflush(stdin);
        cout<<"\n Enter Name  :";
        cin.getline(tname,60);
        fin.seekg(0);
        fin.read((char*)this,sizeof(Telephone));
        while(!fin.eof())
        {   if(strcmpi(name,tname)==0)
                {   found =1;
                    cout<<"\n\n \t\t\t\t\t\tRecord Details\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
            fin.read((char*)this,sizeof(Telephone));
        }
        fin.close();
        if(found==0)
            cout<<"\n Record Not Found.....";
    }
    cout<<"\n\nPress Any Key To Return To Search Menu...\n";
    line();
    cout<<"\n";
    getch();
	return;
}

void Telephone:: search_gen()
{   cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tGeneral Search\n";
    line();
    cout<<"\n";
	ifstream fin;
	fin.open("telephone.dat",ios::binary);
    fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {    cout<<"\nTelephone Directory Is Empty"<<endl;
         fin.close();
    }
    else
    {   string key;
        int found =0;
        fflush(stdin);
        cout<<"\n Enter Keyword  :";
        cin>>key;
        fin.seekg(0);
        fin.read((char*)this,sizeof(Telephone));
        while(!fin.eof())
        {   string sname = name;
            string sphone=phone;
            string semail=email;
            string sadd=add;
            string splace=place;
            size_t findn = sname.find(key);
            size_t findp = splace.find(key);
            size_t finda = sadd.find(key);
            size_t findph = sphone.find(key);
            size_t findem = semail.find(key);
            if(findn!=string::npos||findp!=string::npos||finda!=string::npos||findem!=string::npos||findph!=string::npos)
                {   found =1;
                    cout<<"\n\n \t\t\t\t\t\tRecord Details\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
            fin.read((char*)this,sizeof(Telephone));

        }
        fin.close();
        if(found==0)
            cout<<"\n Record Not Found.....";
    }
    cout<<"\n\nPress Any Key To Return To Search Menu...\n";
    line();
    cout<<"\n";
    getch();
	return;
}

void Telephone:: search_place()
{   cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tPlace Search\n";
    line();
    cout<<"\n";
	ifstream fin;
	fin.open("telephone.dat",ios::binary);
	fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {    cout<<"\nTelephone Directory Is Empty"<<endl;
         fin.close();
    }
    else
    {   char tplace[30];
        int found =0;
        fflush(stdin);
        cout<<"\n Enter Place Name  :";
        cin.getline(tplace,30);
        fin.seekg(0);
        fin.read((char*)this,sizeof(Telephone));
        while(!fin.eof())
        {   if(strcmpi(place,tplace)==0)
                {   found =1;
                    cout<<"\n\n \t\t\t\t\t\tRecord Details\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
            fin.read((char*)this,sizeof(Telephone));
        }
        fin.close();
        if(found==0)
            cout<<"\n Record not found.....";
    }
    cout<<"\n\nPress Any Key To Return To Search Menu...\n";
    line();
    cout<<"\n";
    getch();
	return;
}

void Telephone:: search_phone()
{   cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tPhone Search\n";
    line();
    cout<<"\n";
	ifstream fin;
	fin.open("telephone.dat",ios::binary);
	fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {    cout<<"\nTelephone Directory Is Empty"<<endl;
         fin.close();
    }
    else
    {   int found =0;
        char tphone[15];
        fflush(stdin);
        cout<<"\n Enter Phone Number  :";
        cin.getline(tphone,15);
        fin.seekg(0);
        fin.read((char*)this,sizeof(Telephone));
        while(!fin.eof())
        {   if(strcmpi(phone,tphone)==0)
                {   found =1;
                    cout<<"\n\n \t\t\t\t\t\tRecord Details\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
            fin.read((char*)this,sizeof(Telephone));
        }
        fin.close();
        if(found==0)
            cout<<"\n Record not found.....";
    }

	cout<<"\n\nPress Any Key To Return To Search Menu...\n";
    line();
    cout<<"\n";
    getch();
	return;
}

void Telephone:: search_email()
{
	cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tEmail Search\n";
    line();
    cout<<"\n";
	ifstream fin;
	fin.open("telephone.dat",ios::binary);

	fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {   cout<<"\nTelephone Directory Is Empty"<<endl;
        fin.close();
    }
    else
    {   char temail[80];
        int found =0;
    	fflush(stdin);
        cout<<"\n Enter Email ID  :";
        cin.getline(temail,80);
        fin.seekg(0);
        fin.read((char*)this,sizeof(Telephone));
        while(!fin.eof())
        {   if(strcmpi(email,temail)==0)
                {   found =1;
                    cout<<"\n\n \t\t\t\t\t\tRecord Details\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
            fin.read((char*)this,sizeof(Telephone));
        }
        fin.close();
        if(found==0)
            cout<<"\n Record not found.....";
    }
	cout<<"\n\nPress Any Key To Return To Search Menu...\n";
    line();
    cout<<"\n";
    getch();
	return;
}

//Menu Functions
void Telephone::main_menu(){
	int choice;
	while(1)
    {   system("cls");
		cout<<"\n\t\t\t\t\t  Telephone Diary";
		cout<<"\n\n\t\t1.	Add New Record";
		cout<<"\n\n\t\t2.	Delete Record";
		cout<<"\n\n\t\t3.	Modify Record";
		cout<<"\n\n\t\t4.	Search Menu";
		cout<<"\n\n\t\t5.	Report Menu";
		cout<<"\n\n\t\t6.      Clear Telephone Diary";
		cout<<"\n\n\n\n\t\t Enter Any Other Value To Exit...";
		cout<<"\n\n\t\t\t\t Enter Your choice(1..6) :";
		cin>>choice;
		switch(choice)
		{   case 1: add_new_record();
					break;
			case 2: delete_record();
					break;
			case 3: modify_record();
					break;
			case 4: search_menu();
					break;
			case 5: report_menu();
					break;
            case 6: clear_database();
                    break;
			default:exit(0);
		}
	}
	return;
}

void Telephone::search_menu(){
	int choice;
	do{
		system("cls");
		cout<<"\n\t\t\t\t\t  SEARCH MENU";
		cout<<"\n\n\t\t1.	Name";
		cout<<"\n\n\t\t2.	Phone No";
		cout<<"\n\n\t\t3.	Email";
		cout<<"\n\n\t\t4.	Place";
		cout<<"\n\n\t\t5.	General";
		cout<<"\n\n\t\t6.	Exit To Main Menu";
		cout<<"\n\n\n\n\t\tEnter Any Other Value To Exit...";
		cout<<"\n\n\t\t\t\t Enter Your choice(1..5) :";
		cin>>choice;
		switch(choice)
		{   case 1: search_name();
					break;
			case 2: search_phone();
					break;
			case 3: search_email();
					break;
            case 4: search_place();
					break;
            case 5: search_gen();
                    break;
			case 6: break;
			default:exit(0);
		}
	}while(choice!=6);
	return;
}

void Telephone::report_menu(){
	int choice;
	do{ system("cls");
		cout<<"\n\t\t\t\t\t  REPORT  MENU";
		cout<<"\n\n\t\t1.	Total Record";
		cout<<"\n\n\t\t2.	Name - Phone";
		cout<<"\n\n\t\t3.	Name- Email";
		cout<<"\n\n\t\t4.	Exit To Main Menu";
		cout<<"\n\n\n\n\t\tEnter Any Other Value To Exit...";
		cout<<"\n\n\t\t\t\t Enter Your choice(1..4) :";
		cin>>choice;
		switch(choice)
		{   case 1: report_total();
					break;
			case 2: report_name_phone();
					break;
			case 3: report_name_email();
					break;
			case 4: break;
			default: exit(0);
		}
	}while(choice!=4);
	return;
}

//Record Functions
void  Telephone::add_new_record()
 {  int flag=0;
    cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tInsert Record\n";
    line();
    cout<<"\n";
 	ofstream fout;
 	fout.open("temp.dat",ios::binary|ios::trunc);
 	input();
 	fout.write((char *)this, sizeof(Telephone));
 	fout.close();
 	ifstream fin;
 	fin.open("temp.dat",ios::binary);
 	fin.read((char *)this, sizeof(Telephone));
 	char a[60];
 	strcpy(a,name);
 	char b[100];
    strcpy(b,add);
 	char c[30];
    strcpy(c,place);
 	char d[15];
    strcpy(d,phone);
 	char e[80];
    strcpy(e,email);
 	fin.close();
 	fstream fo;
 	fo.open("telephone.dat",ios::in | ios::binary | ios::out);
 	if(fo.fail())
    {   fout.open("telephone.dat",ios::binary);
        fout.close();
        fo.open("telephone.dat",ios::in | ios::binary | ios::out);
    }
    while (!fo.eof())
    {   fo.read((char*)this, sizeof(Telephone));
        if (fo)
        {   if (strcmpi(name,a)==0||strcmpi(phone,d)==0||strcmpi(email,e)==0)
            {   flag=1;
                if(strcmpi(name,a)==0)
                    cout<<"\n Record With Same Name Exists..\n";
                if(strcmpi(phone,d)==0)
                    cout<<"\n Record With Same Phone Exists..\n";
                if(strcmpi(email,e)==0)
                {   cout<<"\n Record With Same Email Exists..\n";
                    cout <<"\n Do You Wanna Force Add.....\n1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {   flag = 0;
                        break;
                    }
                }
                cout<<"Please Modify Contact\n";
                break;
            }
        }
    }
    fo.close();
 	if(flag == 0)
    {   ifstream input;
        ofstream copya;
        input.open("temp.dat",ios::binary);
        input.read((char*)this, sizeof(Telephone));
        copya.open("telephone.dat",ios::binary|ios::app);
        copya.write((char*)this, sizeof(Telephone));
        input.close();
        copya.close();
        cout<<"\n\nRecord Added\n";
    }
    remove("temp.dat");
    cout<<"\nPress Any Key To Return To Main Menu...\n";
    line();
    cout<<"\n";
    getch();
 }

 void  Telephone::modify_record()
{   char a[40];
    cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tModify Record\n";
    line();
    cout<<"\n";
    fstream fs;
    fs.open("telephone.dat",ios::in | ios::binary | ios::out);
    fs.seekg(0, ios::end);
    if (fs.tellg() == 0)
    {   cout<<"\nTelephone Directory Is Empty"<<endl;
        fs.close();
    }
    else
    {   int pos, flag = 0;
        fs.seekg(0);
        cout<<"\nEnter Old Name,Phone Or Email:\n";
        fflush(stdin);
        cin.getline(a,40);
        while (!fs.eof())
        {   pos = fs.tellg();
            fs.read((char*)this, sizeof(Telephone));
            if (fs)
            {   if (strcmpi(name,a)==0||strcmpi(phone,a)==0||strcmpi(email,a)==0)
                {   flag = 1;
                    input();
                    fs.seekp(pos);
                    fs.write((char*)this, sizeof(Telephone));
                    cout << "\nRecord Successfully Modified \n";
                    break;
                }
            }
        }
        fs.close();
        if (flag==0)
            cout << "\nRecord Not Found \n";
    }

    cout<<"\nPress Any Key To Return To Main Menu...\n";
    line();
    cout<<"\n";
    getch();
}

void  Telephone::delete_record()
{   char a[40];
    cout<<"\n";
    line();
    cout<<"\n\t\t\t\t\t\tDelete Record\n";
    line();
    cout<<"\n";
    ifstream fin;
    fin.open("telephone.dat", ios::in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);
    fin.seekg(0, ios::end);
    if (fin.tellg() == 0)
    {   cout<<"\nTelephone Directory Is Empty"<<endl;
        fin.close();
    }
    else
    {   int flag = 0;
        cout<<"\nEnter Name,Phone Or Email:\n";
        fflush(stdin);
        cin.getline(a,40);
        fin.seekg(0);
        while (!fin.eof())
        {   fin.read((char*)this, sizeof(Telephone));
            if (fin)
            {   if (strcmpi(name,a)==0||strcmpi(phone,a)==0||strcmpi(email,a)==0)
                {   flag = 1;
                    cout << "The Deleted Record Is:\n\n";
                    cout<<"\n Name    :"<<name;
                    cout<<"\n Address :"<<add;
                    cout<<"\n Place   :"<<place;
                    cout<<"\n Phone   :"<<phone;
                    cout<<"\n Email   :"<<email;
                }
                else
                {   fout.write((char*)this, sizeof(Telephone));
                }
            }
        }
        fout.close();
        fin.close();
        if (flag == 1)
        {   remove("telephone.dat");
            rename("temp.dat", "telephone.dat");
            cout << "\n\nRecord Successfully Deleted \n";
        }

        else
            cout << "\n\nRecord Not Found \n";
    }
    cout<<"\nPress Any Key To Return To Main Menu...\n";
    line();
    cout<<"\n";
    getch();
}

 void Telephone::clear_database()
 {  ofstream fout;
    fout.open("telephone.dat", ios::out |ios::trunc);
    fout.close();
    cout<<"\n";
    line();
    cout<<"\nTelephone Diary Cleared\n";
    line();
    cout<<"\n\n\nPress Any Key To Return To Main Menu...\n";
    line();
    cout<<"\n";
    getch();
 }

//Report Functions
void Telephone::report_total()
{   ifstream fin;
	int no=0;
	int row=0;
	int page=1;
	int total_pages;
	int rec=0;
	rec = count_record();
	total_pages = rec/5;
	if(rec%5!=0)
		total_pages++;
    cout<<"\nPress Any Key To View Record...";
	getch();
	fin.open("telephone.dat",ios::binary);
	system("cls");
	cout<<"\n\t\t\t\t\t Telephone Diary";
	cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
	line();
	cout<<"\nS.No \tName \t\t\t\tPlace \t\t\tPhone \t\t\tEmail\n";
	line();
	fin.read((char*)this,sizeof(Telephone));
	while(!fin.eof())
    {   row++;
        no++;
        if(row>5)
        {   page++;
            row =0;
            cout<<"\nPress Any Key To Change Page...";
            getch();
            system("cls");
            cout<<"\n\t\t\t\t\t Telephone Diary";
            cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
            line();
            cout<<"\nS.No \tName \t\t\t\tPlace \t\t\tPhone \t\t\tEmail\n";
            line();
        }
        cout<<"\n"<<setw(8)<<left<<no;
        cout<<setw(32)<<left<<name;
        cout<<setw(24)<<left<<place;
        cout<<setw(24)<<left<<phone;
        cout<<email<<"\n";
        fin.read((char*)this,sizeof(Telephone));
    }
	fin.close();
	cout<<"\n\n\nPress Any Key To Return To Record Menu..."<<endl;
	getch();
	return ;
}

void Telephone::report_name_phone()
{   ifstream fin;
	int row=0;
	int page=1;
	int total_pages;
	int rec=0;
	int no=0;
	rec = count_record();
	total_pages = rec/5;
	if(rec%5!=0)
		total_pages++;
    cout<<"\nPress Any Key To View Record...";
	getch();
	fin.open("telephone.dat",ios::binary);
	system("cls");
	cout<<"\n\t\t\t\t\t Telephone Diary";
	cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
	line();
	cout<<"\nS.No \t\tName \t\t\t\t\tPhone\n";
	line();
	fin.read((char*)this,sizeof(Telephone));
	while(!fin.eof())
    {   row++;
        no++;
        if(row>5)
        {   page++;
            row =0;
            cout<<"\nPress Any Key To Change Page...";
            getch();
            system("cls");
            cout<<"\n\t\t\t\t\t Telephone Diary";
            cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
            line();
            cout<<"\nS.No \t\tName \t\t\t\t\tPhone\n";
            line();
        }
        cout<<"\n"<<setw(14)<<left<<no;
        cout<<"\t"<<setw(40)<<left<<name;
        cout<<phone<<"\n";
        fin.read((char*)this,sizeof(Telephone));
    }
	fin.close();
	cout<<"\n\n\nPress Any Key To Return To Record Menu..."<<endl;
	getch();
	return ;
}

void Telephone::report_name_email()
{   ifstream fin;
	int row=0;
	int page=1;
	int total_pages;
	int rec=0;
	int no=0;
	rec = count_record();
	total_pages = rec/5;
	if(rec%5!=0)
		total_pages++;
    cout<<"\nPress Any Key To View Record...";
	getch();
	fin.open("telephone.dat",ios::binary);
	system("cls");
	cout<<"\n\t\t\t\t\t Telephone Diary";
	cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
	line();
	cout<<"\nS.No \t\tName \t\t\t\t\tEmail\n";
	line();
	fin.read((char*)this,sizeof(Telephone));
	while(!fin.eof())
    {   row++;
        no++;
        if(row>5)
        {   page++;
            row =0;
            cout<<"\nPress Any Key To Change Page...";
            getch();
            system("cls");
            cout<<"\n\t\t\t\t\t Telephone Diary";
            cout<<"\n       \t\t\t\t\t\t\t\t\t\t\t\t Page :"<<page<<"of"<<total_pages<<"\n";
            line();
            cout<<"\nS.No \t\tName \t\t\t\t\tEmail\n";
            line();
        }
        cout<<"\n"<<setw(14)<<left<<no;
        cout<<"\t"<<setw(40)<<left<<name;
        cout<<email<<"\n";
        fin.read((char*)this,sizeof(Telephone));
    }
	fin.close();
	cout<<"\n\n\nPress Any Key To Return To Record Menu..."<<endl;
	getch();
	return ;
}
//Checking Functions
// C++ program to check if given mobile number
// is valid.
#include <iostream>
#include <regex>
using namespace std;

int Telephone::isValidnum(string s)
{
    // is regular expression. With the help of
    // regular expression we can validate mobile
    // number.
    // 1) Begins with 0 or 91
    // 2) Then contains 7 or 8 or 9.
    // 3) Then contains 9 digits
  const regex pattern("(0|91)?[7-9][0-9]{9}");
  if(regex_match(s, pattern))
    return 1;
  else
    return 0;
}
int Telephone::isValidemail(string s)
{
    /*Defining The regular expression
    The \w matches any character in any case any number of times.
    Then the \.|_ matches if a dot or underscore is present 0 or 1 times.
    Then \w again match n characters.
    Then @ matches the @ in the email.
    Then we again check for n characters and a ‘.’ and a word after it, which must be present at least one or more times.
    */
   const regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   if(regex_match(s, pattern))
        return 1;
   else
        return 0;
}
int main()
{   Telephone T;
	T.main_menu();
	return 0;
}
