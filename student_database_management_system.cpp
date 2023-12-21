#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;


struct information
{
    char ID[15];
    string name;
    string cls;
    string Branch;
    string address;
    string email;
    char rollno[15];
    char phoneno[15];
};


void add();
void callExit();
void Main_Data_Search();
void display_list();
void del();
void modify();
void admin_login();
void student_login();
void login();
int admin_logscreen();
int student_logscreen();
void student_menu();
void rec();
void admin_menu();
void rqst_modify();
void Student_Data_Search();
void mainpage();
int logscreen();
void menu();
void date();
void title();

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}


int main()
{
    system("cls");
    mainpage();
    login();
    return 0;
}
void date()
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout << "\n\n\n";
    cout << "\t\t\t\t\t   Date:" << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << endl;
}

void rqst_modify()
{
    char input;
    int ch = 0;
    information c;
    string sid;
    //char cid[20];
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";

    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, sid);

    ifstream fpt("data.txt", ios::binary);
    while (fpt.read((char *)&c, sizeof(c)))
    {
        if (sid == c.name )
        {
            ch = 1;
            break;
        }
    }
    fpt.close();
    if (ch == 1)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "<<==Record Found==>>\n\n";
        cout << "\t\t\t\t";
        cout<<"Press Enter to Send Request to Modify the Records...";
        cin.get();
        cout<<endl<<endl;
        cout << "\t\t\t\t";
        cout<<"Your Request has been Approved. please Wait For confirmation.";
        cout<<endl<<endl;
        cout << "\t\t\t\t";
        cout<<"press Enter to go to Student menu...";
        cin.get();
        student_menu();
    }
    else
    {
        system("cls");
        cin.get();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";

        cout << "<<--Record Was Not Found-->>";
        cout<<endl<<endl;
        cout << "\t\t\t\t\t";
        cout << "Do you want to request again?(y/n)";
        cin >> input;
    if (input == 'Y' || input == 'y')
    {
        rqst_modify();
    }
    else
        student_menu();
    cin.ignore();
    }
}
void title()
{
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t    |STUDENT DATABASE MANAGEMENT SYSTEM|\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
}

void mainpage()
{
    int process = 0;
    system("cls");
    date();
    cout << "\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t    |STUDENT DATABASE MANAGEMENT SYSTEM|\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\n\n\n";
    cout << "\t\t\t\t";
    cout << "Prepared By    ";
    cout << ":";
    cout << "   Team 4  ";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Mini Project   ";
    cout << ":";
    cout << "   Student Database Management System";
    cout << "\n\n";
    cout << "\t\t\t\t    Press Enter to continue......";
    cin.get();
    cout << "\n\n\t\t\t\t Loading";
    for (process = 0; process < 25; process++)
    {
        delay(100);
        cout << ".";
    }
}

void admin_login(){
    information c;
    system("cls");
    admin_logscreen();

}

void student_login()
{
    information c;
    system("cls");
    student_logscreen();
}
void login()
{
    int inputf;
    system("cls");
    information c;
    date();
    cout << "\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t    |STUDENT DATABASE MANAGEMENT SYSTEM|\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout<< "1. Admin Panel."<<endl;
    cout << "\t\t\t\t\t";
    cout<< "2. Student Profile."<<endl;
   // cout << "\t\t\t\t\t";
    cout << "\n\t\t\t\t\tchoose option [1/2] : ";
    cin>> inputf;
    switch(inputf)
    {
    case 1:
        {
            system("cls");
            admin_login();
        }
        break;
    case 2:
        {
            system("cls");
            student_login();
        }
        break;
         default:
    {
        cin.ignore();
        cout << "\n\n\n";
        cout << "\t\t\t\t";
        cout << "      Invalid input!";
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "Press Enter to choose again...";
        cin.get();
        login();
    }
    }

}

int admin_logscreen()
{
    string admin_username;
    string admin_password;
    int tryCount = 0;
    int maxTries = 3;

    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "admin Username: ";
        cin >> admin_username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "admin Password: ";
        cin >> admin_password;

        if (admin_username == "admin" && admin_password == "admin123")
        {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t   Press Enter to continue...";
            cin.ignore();
            cin.get();
            menu();
            //system("cls");
            //cin.get();

            return 0;
        }
        else
        {
            system("cls");
            tryCount++;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << maxTries - tryCount;
            cin.ignore();
            cin.get();
            if (tryCount >= maxTries)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!";
                cin.get();
                callExit();
                cin.get();
                exit(0);
            }
        }
    }
    while (true);
}
int student_logscreen()
{
    string student_username;
    string student_password;
    int tryCount = 0;
    int maxTries = 3;

    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "student Username: ";
        cin >> student_username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "student Password: ";
        cin >> student_password;

        if (student_username == "student" && student_password == "student123")
        {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t   Press Enter to continue...";
            cin.ignore();
            cin.get();
            student_menu();
            system("cls");
            cin.get();
            return 0;
        }
        else
        {
            system("cls");
            tryCount++;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << maxTries - tryCount;
            cin.ignore();
            cin.get();
            if (tryCount >= maxTries)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!";
                cin.get();
                callExit();
                cin.get();
                exit(0);
            }
        }
    }
    while (true);
}
void menu()
{
    int input;
    system("cls");
    title();
    cout << " 1. Enter new Records\n\n";
    cout << "\t\t\t\t";
    cout << " 2. Modify Records\n\n";
    cout << "\t\t\t\t";
    cout << " 3. Delete Records\n\n";
    cout << "\t\t\t\t";
    cout << " 4. Search and view Records\n\n";
    cout << "\t\t\t\t";
    cout << " 5. Login Page.\n\n";
    cout << "\t\t\t\t";
    cout << " 6. Exit\n\n";
    cout << "\t\t\t\t";
    cout << "Choose options:[1/2/3/4/5/6]:";
    cin >> input;
    switch (input)
    {
    case 1:
    {
        system("cls");
        add();
    }
    break;

    case 2:
    {
        system("cls");
        modify();
        //cin.get();
    }
    break;

    case 3:
    {
        system("cls");
        del();
    }
    break;

    case 4:
    {
        system("cls");
        Main_Data_Search();
    }
    break;

    case 5:
     {
          system("cls");
          login();
     }
     break;

    case 6:
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cin.ignore();
        cout << "\t\t\t\t";
        cout << "This project was made by team 4."   <<endl
             << "\t\t\t\t" <<"team 4: "              <<endl
             << "\t\t\t\t" <<"1. Mahima Mostofa."    <<endl
             << "\t\t\t\t" <<"2. Jeba Afroz Audity." <<endl
             << "\t\t\t\t" <<"3. Naznin Nahar Ritu." <<endl
             << "\t\t\t\t" <<"4. Akib Hasan Niloy."  <<endl
             << "\t\t\t\t" <<"5. Shahiar Kobir."     <<endl
       <<endl<< "\t\t\t\t" <<" THANK YOU";
        cout << "\n\n\n\n";
        exit(0);
    }
    break;

    default:
    {
        cin.ignore();
        cout << "\n\n\n";
        cout << "\t\t\t\t";
        cout << "      Invalid input!";
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "Press Enter to choose again...";
        cin.get();
        menu();
    }
    }
}
void student_menu()
{
    int input;
    system("cls");
    title();
    cout << " 1. Search and view records.\n\n";
    cout << "\t\t\t\t";
    cout << " 2. Data modify request. \n\n";
    cout << "\t\t\t\t";
    cout << " 3. Login Page.\n\n";
    cout << "\t\t\t\t";
    cout << " 4. Exit.\n\n";
    cout << "\t\t\t\t";
    cout << "Choose options:[1/2/3/4]:";
    cin >> input;
    switch (input)
    {
    case 1:
    {
        system("cls");
        Student_Data_Search();
    }
    break;

    case 2:
    {
        system("cls");
        rqst_modify();
    }
    break;

    case 3:
     {
          system("cls");
          login();
     }
     break;
    case 4:
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cin.ignore();
        cout << "\t\t\t\t";
        cout << "This project was made by team 4."   <<endl
             << "\t\t\t\t" <<"team 4: "              <<endl
             << "\t\t\t\t" <<"1. Mahima Mostofa."    <<endl
             << "\t\t\t\t" <<"2. Jeba Afroz Audity." <<endl
             << "\t\t\t\t" <<"3. Naznin Nahar Ritu." <<endl
             << "\t\t\t\t" <<"4. Akib Hasan Niloy."  <<endl
             << "\t\t\t\t" <<"5. Shahiar Kobir."     <<endl
       <<endl<< "\t\t\t\t" <<" THANK YOU";
        cout << "\n\n\n\n";
        exit(0);
    }
    break;

    default:
    {
        cin.ignore();
        cout << "\n\n\n";
        cout << "\t\t\t\t";
        cout << "      Invalid input!";
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "Press Enter to choose again...";
        cin.get();
        student_menu();
    }
    }
}

void add()
{
    information c;
    char input;

    system("cls");
    cout << " " << endl;
    cout << "\t\t\t\t" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << endl;
    cout << "\n" << endl;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t";
    cout << "Enter The Information Below: \n\n";
    cout << "\t\t\t\t";
    cout << "Enter ID        :  ";

    cin.ignore();
    cin.getline(c.ID, sizeof(c.ID));
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Full Name       :  ";
    getline(cin, c.name);
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Class           :  ";
    getline(cin, c.cls);
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Branch          :  ";
    getline(cin, c.Branch);
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Address         :  ";
    getline(cin, c.address);
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Email Address   :  ";
    getline(cin, c.email);
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Roll No.        :  ";
    cin.getline(c.rollno, sizeof(c.rollno));
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Phone No.       :  ";
    cin.getline(c.phoneno, sizeof(c.phoneno));

    ofstream fpt("data.txt", ios::app | ios::binary);
    fpt.write(reinterpret_cast<const char*>(&c), sizeof(c));
    fpt.close();

    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Record added successfully!!";

    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Do you want to add more?(y/n)";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        add();
    }
    else
        menu();
    cin.ignore();
}
void callExit()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";
    //cin.ignore();
    cout << "You are out of the System.";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "   Press Enter to Continue Exit Program...";
    cin.get();
    exit(0);
}

void Main_Data_Search(int menuType)
{
    int ch = 0;
    information c;
    string sid;
    //char cid[20];
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";

    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, sid);
   // cout << "\t\t\t\t\t";
    //cout << "Enter ID: ";
    //cin.ignore();
    //cin>>cid;

    ifstream fpt("data.txt", ios::binary);
    while (fpt.read((char *)&c, sizeof(c)))
    {
        if (sid == c.name )//&& cid==c.ID)
        {
            ch = 1;
            break;
        }
    }
    fpt.close();
    if (ch == 1)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "<<==Search Successful==>>\n\n";

        cout << "\t\t\t\t";
        cout << "ID              : " << c.ID << endl<<endl;;
        cout << "\t\t\t\t";
        cout << "Full Name       : " << c.name << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Class           : " << c.cls << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Branch          : " << c.Branch << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Address         : " << c.address << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Email Address   : " << c.email << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Roll No.        : " << c.rollno << "  ";
        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Phone No.       : " << c.phoneno << "  ";
        cout << "\n\n";

        cout << "\t\t\t\t";
        cout << "Press Enter For ";
         if (menuType == 1)
            cout << "Main Menu...";
        else if (menuType == 2)
            cout << "Student Profile Menu...";
        cin.get();
        if (menuType == 1)
            menu();
        else if (menuType == 2)
            student_menu();
    }
    else
    {
        system("cls");
        cin.get();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";

        cout << "<<--Record Was Not Found-->>";
        cout << "\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "Press Enter For ";
        if (menuType == 1)
            cout << "Main Menu...";
        else if (menuType == 2)
            cout << "Student Profile Menu...";
        cin.get();
        if (menuType == 1)
            menu();
        else if (menuType == 2)
            student_menu();
    }
}

void Main_Data_Search()
{
    Main_Data_Search(1);
}

void Student_Data_Search()
{
    Main_Data_Search(2);
}
void display_list()
{
    information c;
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "\n";

    ifstream fpt("data.txt", ios::binary);
    while (fpt.read((char *)&c, sizeof(c)))
    {
        cout << "\t\t\t\t";

        cout << "ID              : " << c.ID << endl;
        cout << "\t\t\t\t";
        cout << "Full Name       : " << c.name << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Class           : " << c.cls << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Branch          : " << c.Branch << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Address         : " << c.address << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Email Address   : " << c.email << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Roll No.        : " << c.rollno << "  ";

        cout << "\n\n";
        cout << "\t\t\t\t";
        cout << "Phone No.       : " << c.phoneno << "  ";
    }
    fpt.close();
}


void del()
{
    information c;
    int ch = 0;
    string sid;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";
    cin.ignore();
    cout << "Enter Full Name:";
    getline(cin, sid);
    cout << "\t\t\t\t\t";

    ifstream fpt("data.txt", ios::binary);
    ofstream temp("temp.txt", ios::binary);
    while (fpt.read((char *)&c, sizeof(c)))
    {
        if (sid != c.name)
        {
            temp.write((char *)&c, sizeof(c));
        }
        else
        {
            ch = 1;
        }
    }

    fpt.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "\n";
    cout << "\t\t\t\t\t";

    cout << "Record Deleted Successfully.\n";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press Enter For Main Menu...";
    cin.get();
    menu();


    if (ch == 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cin.ignore();
        cout << "<<--Record Not Found-->>";
        cout << "\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "Press Enter For Main Menu...";
        cin.get();
        menu();
    }
}

void modify()
{
    information c;
    string mid;
    int found = 0;
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";
    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, mid);

    ifstream fpt("data.txt", ios::binary);
    ofstream temp("temp.txt", ios::binary);

    while (fpt.read((char *)&c, sizeof(c)))
    {
        if (mid != c.name)
        {
            temp.write((char *)&c, sizeof(c));
        }
        else
        {
            cin.ignore();
            cout << "\t\t\t\t\t";
            cout << "Enter ID: ";
            cin.getline(c.ID, sizeof(c.ID));
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Full Name: ";
            cin.ignore();
            getline(cin, c.name);
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Class: ";
            getline(cin, c.cls);
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Branch: ";
            getline(cin, c.Branch);
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Address: ";
            getline(cin, c.address);
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Email Address: ";
            getline(cin, c.email);
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Roll No.: ";
            cin.getline(c.rollno, sizeof(c.rollno));
            cout << "\n";
            cout << "\t\t\t\t\t";
            cout << "Enter Phone No.: ";
            cin.getline(c.phoneno, sizeof(c.phoneno));
            temp.write((char *)&c, sizeof(c));
            found = 1;
        }

    }

    fpt.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
    if (found == 0)
    {
        system("cls");
        cin.ignore();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "<<--Record Not Found-->>";
        cout << "\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "Press Enter For Main Menu...";
        cin.get();
        menu();
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "Record Updated Successfully.\n";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Press Enter For Main Menu...";
        cin.get();
        menu();
    }
}
