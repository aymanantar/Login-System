// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login.cpp
// Program Description: login system.
// Last Modification Date: 14/5/2022
// Author1 and ID and Group: 20210080
// Author2 and ID and Group: 20211043
// Author3 and ID and Group: 20210341
// Teaching Assistant: s3,s4.
// Purpose:..........
#include <iostream>
#include <regex>
#include <fstream>
#include<stdio.h>
#include <conio.h>
using namespace std;
string name,password,email,phone;
string EnterEmail ();
string EnterName ();
string EnterPassword ();
string EnterPhoneNum ();
string CaesarCipher (string s);
bool Send_Email;
bool Login ();
bool Register ();
bool ChangePW ();
struct user {string name,email,password,phone;};
int main()
{

    char choise;
    while(1){
    cout << "welcome ya user, what do you want to do\n 1-new reregistration\n 2-login\n 3- change my password \n press 0 to end\n";
    cin>>choise;
      if (choise=='1') {Register();}
      else if (choise=='2') {Login();}
      else if (choise=='3') {ChangePW();}
    else if (choise=='0'){ return 0;  }
}
}
  bool Register(){
    cout<<"Welcome new user, please enter the following...\n\n";
    char dummyname[100];
    char dummypassword[100];
    char dummyemail[100];
    char dummyphone[100];
    EnterName();
    EnterEmail ();
    EnterPassword ();
    EnterPhoneNum ();
    fstream ss;
    ss.open("mytext",ios::in);
    while (!ss.eof()){
     ss.clear(); ss.sync(); ss.getline(dummyname,100,'|');
    ss.clear(); ss.sync(); ss.getline(dummyemail,100,'|');
    ss.clear(); ss.sync(); ss.getline(dummypassword,100,'|');
   ss.clear(); ss.sync(); ss.getline(dummyphone,100);
   if (name==dummyname) {cout<<"sorry this name is already taken, please try again with another \n";return 1;}
   else if (email==dummyemail) {cout<<"sorry this email is already taken, please try again with another \n";return 1;}
   else if (phone==dummyphone) {cout<<"sorry this phone number is already taken, please try again with another \n";return 1;}
    }
    fstream s;
    s.open("mytext",ios::app);
    s<<'\n'<<name<<'|'<<email<<'|'<<password<<'|'<<phone;
    cout<<"than you mr."<<name<<", you are successfully registered \n";
    return 0;

    }

  bool Login() {
    int n=3;bool f;
    char dummyname[100];
    char dummypassword[100];
    char dummyemail[100];
    char dummyphone[100];
    while (1) {
    f=1;
    email=EnterEmail();
    password=EnterPassword();
    fstream ss;
    ss.open("mytext",ios::in);
    while (!ss.eof()){
    ss.clear(); ss.sync(); ss.getline(dummyname,100,'|');
    ss.clear(); ss.sync(); ss.getline(dummyemail,100,'|');
    ss.clear(); ss.sync(); ss.getline(dummypassword,100,'|');
    ss.clear(); ss.sync(); ss.getline(dummyphone,100);
    if(dummyemail==email){
        if (dummypassword==password){
                cout<<"Login successfully , welcome mr."<<dummyname<<'\n';
                name=dummyname; phone=dummyphone;
                 return 1;
        }
        else {
            if (!n){cout<<"you entered your data 3 times wrong, please try again later\n"; return 0;}
             n--; cout<<"the password you entered is not correct, please check the email then login again\n note that you only have "<<n<<" times of trying \n";
             f=0;
             break;
        }
    }
    }
    if (f){
              n--;
             if (!n){cout<<"you entered your data 3 times wrong, please try again later\n"; return 0;}
             cout<<"There is no profile with such email, please check the email then login again\n note that you only have "<<n<<" times of trying \n";

    }
    }
    }
bool ChangePW () {
    string pw,pw1,pw2,Swap;
    char dummyname[100];
    char dummypassword[100];
    char dummyemail[100];
    char dummyphone[100];
        cout<<"first you have to login \n";
        if (Login()){
                cout<<"to change your password, please enter your old password\n";
                char ch; while ((ch=getch())!= 13) {cout<<'*';pw+=ch;}cout<<endl;pw=CaesarCipher(pw);
                if (pw==password){

                cout<<"now, enter the new password \n";
                pw1=EnterPassword();
                cout<<"finally, re-enter the new password \n";
                pw2=EnterPassword();
                if (pw1==pw2){
                cout<<"thank you Mr."<<name<<", now your password is successfully updated\n";
fstream s,ss;
ss.open("mytext",ios::in);
s.open("dummy",ios::out);s.clear();s.close();
s.open("dummy",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();ss.getline(dummyname,100,'|');
ss.clear();ss.sync();ss.getline(dummyemail,100,'|');
ss.clear();ss.sync();ss.getline(dummypassword,100,'|');
ss.clear();ss.sync();ss.getline(dummyphone,100);
if (dummyname==""){break;}
if (dummyname==name){s<<'\n'<<dummyname<<'|'<<dummyemail<<'|'<<pw1<<'|'<<dummyphone;}
else {s<<'\n'<<dummyname<<'|'<<dummyemail<<'|'<<dummypassword<<'|'<<dummyphone;}
}
s.close();s.open("mytext",ios::out);s.clear();s.close();
ss.close();ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,Swap);
s<<'\n'<<Swap;
}
}
else {cout<<"sorry two passwords don't match \n";}
                }
                 else {cout<<"wrong old password, please try again later\n";}
        }

else {cout<<"login failed, please try again later\n";}
}
string EnterEmail (){
while (1){
cout<<"enter the email, email should be in this form (example@example.example) :\n";
cin.clear(); cin.sync(); getline(cin,email);
regex valid_email ("[a-z+0-9+A-Z][a-z+0-9+A-Z]*[@][a-z+A-Z][a-z+A-Z]*[.][a-z+A-Z][a-z+A-Z]*");
if (regex_match(email,valid_email)  ){break;}
cout<<" wrong email, please try again..... \n";
}
return email;
}

string EnterName () {
while (1){
cout<<"enter the name, name should start with capital (upper-case) latter and contains only Latin latter, spaces, or ' - ' symbol :\n";
cin.clear(); cin.sync(); getline(cin,name);
regex valid_name ("[A-Z][-+(a-z)+(A-Z)+( )]+");
if (regex_match(name,valid_name)  ){break;}
cout<<" invalid name, please try again..... \n";
}
return name;
}

string EnterPassword () {
char ch;
while (1){
password="";
bool a=0,b=0,c=0,d=0,e=0;
cout<<"enter the password .... \n password should be at least 8 chars , including upper and lower case latters and including symbols :\n";
while ((ch=getch())!= 13){
// checking if given char was a backspace ...
 if (ch == 8){password.pop_back();}
// checking the strong password criteria -----
// including numbers ?
else if (ch>='0' && ch<='9') {a=1;}
// including upper case ?
else if (ch>='A' && ch<='Z') {b=1;}

// including lower case ?
else if (ch>='a' && ch<='z') {c=1;}

// including symbols ?
else if (ch>32 && ch<96) {d=1;}

//--------------------------------------------
cout<<'*'; password+=ch;
}
cout<<endl;
// last criteria, is password length at least 8 ?---------
if (password.size()>7) {e=1;}
//--------------------------------------------------------
if ( a&&b&&c&&d&&e ) {break;}
cout<<"this password is too week and invalid, please check the strong password criteria and try again \n";
}
password=CaesarCipher(password);
return password ;
}

string EnterPhoneNum () {
while (1){
bool f=1;
phone="";
cout<<"enter the egyption key (+2) followed by your 11-digits phone number \n (ex: +201123992319)\n";
cin.clear(); cin.sync(); getline (cin,phone);
//checking if the number consists of 13 digits starting with the key +2
if (phone[0]!='+'||phone[1]!='2'||phone.size()!=13){cout<<"incorrect phone number, please check the phone number criteria and try again\n"; continue;}
// checking that there is no chars or symbols only digits in range 0-9 ,
for (int i=2;i<13;i++){
        if (phone[i]<'0'||phone[i]>'9'){
            cout<<"incorrect phone number, please check the phone number criteria and try again\n";
            f=0;break;
           }
        }
//----------------------------------------------------------------------------------------------
if(f) break;
}
return phone;
}
string CaesarCipher(string s) {
    for (int i=0 ;i<s.size();i++){
              if (s[i]==122) {s[i]=97;}
              else if (s[i]==90) {s[i]=65;}
              else {s[i]++;}
    }
    return s;

}


