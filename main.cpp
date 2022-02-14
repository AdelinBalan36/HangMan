#include <iostream>
#include <graphics.h>
#include <cstring>
#include <fstream>
#include <time.h>
using namespace std;
int v[90];

///---------- CUVANT
void cuvant(char s[20])
{
    srand(time(NULL));
    int n,i=1;
    ifstream f("cuvinte.in");
    n=rand()%11;
    while(f>>s && n!=i)
    {
        i++;
    }
}
///---------- AFISARE
void AfisareTabela(char s[20],int vieti)
{
    if(vieti==6)
        readimagefile("6.jpg",0,160,500,500);
    else if(vieti==5)
        readimagefile("5.jpg",0,160,500,500);
    else if(vieti==4)
        readimagefile("4.jpg",0,160,500,500);
    else if(vieti==3)
        readimagefile("3.jpg",0,160,500,500);
    else if(vieti==2)
        readimagefile("2.jpg",0,160,500,500);
    else if(vieti==1)
        readimagefile("1.jpg",0,160,500,500);
    else if(vieti==0)
        readimagefile("0.jpg",0,160,500,500);
    int i,n;

    n=strlen(s);
    for(i='A'; i<='Z'; i++)
        if(i==(int)s[0] || i==(int)s[n-1])
            v[i]++;

    cout<<endl<<endl;
    for(i='A'; i<='Z'; i++)
    {
        if(v[i]>0)
            cout<<"[-]"<<" ";
        else
            cout<<"["<<(char)i<<"]"<<" ";
        if(i==77)
            cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Vieti ramase: "<<vieti<<endl;

    for(i=0; i<n; i++)
        if(i==0 || i==n-1 || v[(int)s[i]]>0)
            cout<<s[i]<<" ";
        else
            cout<<" _ ";
    cout<<endl<<endl;
}
///-----------Citirea de la tastatura a caracaterului
void CitireCaracter(char &a)
{
    cout << "ALEGETI O LITERA ";
    cin>>a;
    if(a>=97 && a<=122)
    {
        a=a-32;
    }
    else if(isalpha(a)==0)
        cout<<"Nu ai introdus o litera. Te rugam sa introduci o litera";
    v[(int)a]++;

}
///--------------Verificarea Literei
void VerificareCaracter(char s[20],char a,int &vieti)
{
    int ok=0;
    if(strchr(s,a)!=0)
        ok=1;
    if(ok==0)
        vieti--;
}
int VerificareCuvant(char s[20],int &vieti)
{
    int ok=1,i;
    for(i=0; i<strlen(s); i++)
        if(v[(int)s[i]]==0)
            ok=0;
    if(ok==1)
       readimagefile("felicitari.jpg",0,160,500,500);
      return ok;
}
void SfarsitDeJoc()
{
    cout<<"Jocul a luat sfarsit ";
    readimagefile("sfarsit.jpg",0,0,500,500);
}
void IncepeJocul(char s[20],char a,int &vieti)
 {   cuvant(s);
     while(vieti>0)
    {
        cout<<"MULT SUCCES";
        AfisareTabela(s,vieti);
        CitireCaracter(a);
        VerificareCaracter(s,a,vieti);
        system("CLS");
        if(VerificareCuvant(s,vieti)==1)
            break;
    }
    if(vieti>0)
         cout<<"Cuvantul ghicit este "<<s;
      else{
            cout<<"Imi pare rau insa nu ai ghicit cuvantul -_- "<<endl;
            cout<<"Cuvantul necunoscut era "<<s<<endl;
            SfarsitDeJoc();
      }

 }
///----------INT MAIN()
int main()
{
    initwindow(500,500,"SPANZURATOAREA");
    readimagefile("titlu.jpg",0,0,500,150);
    char s[20],a;
    int vieti=6;
    IncepeJocul(s,a,vieti);


    getch();

    return 0;
}
