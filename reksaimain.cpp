#include <iostream>
#include "item.h"

using namespace std;
int level = 0;
int runes = 0;
int basead = 62;
int basehp = 600;
float baseas = 0.667;

char itemauswahl;

int adaptivef = 5;
float asrunes = 0.01;



float adgrowth = 3;
float asgrowth = 0.02;
float hpgrowth = 99;

//dummy zeug
int dummyhp;
int dummyres;


enum Rune {
    CONQUEROR = 1,
    PTA = 2,
    ELECTROCUTE = 3
};

int main(){

    cout <<"REKSAI DMG NUMBER TESTER"<<endl;

while(true){
    cout<< "Welches Level soll Reksai in der Simulation haben?: ";
    cin>> level;

if(cin.fail()){
    cout<< "Bitte ein Level zwischen 1 und 18 angeben!\n";
    cin.clear();
    cin.ignore(1000,'\n');
}else if(level<1||level>18){
    cout<< "Bitte ein Level zwischen 1 und 18 angeben!\n";
}else{
    cout<< "Level acceptiert"<<endl;
    break;
}
}


cout<<"\nWelche runen soll reksai haben?"<<endl;
cout<<"1. conq mit 1xadaptive and cupdg\n2. pta mit 2x adap and cupdg \n3. electro mit 2x adap and cheapshot\n\n"<<"Bitte um eingame(1-3): ";

while(true){
    cin>> runes;
if(cin.fail()){
    cout<< "Bitte geben sie 1,2 oder 3 ein!";
    cin.clear();
    cin.ignore(1000,'\n');
}else if(runes<1||runes>3){
    cout<< "Bitte geben sie 1,2 oder 3 ein!";
}else{
    cout<< "Runen acceptiert"<<endl<<endl;
    break;
}
}
//stats für reksai per level
ChampionStats reksai;
reksai.ad = basead + adgrowth*(level-1) + reksai.bonusad;
reksai.attackSpeed = baseas + ((asgrowth*baseas)*(level-1));
reksai.bonusad = 0;
reksai.hp = basehp + hpgrowth*(level-1);

 Rune selectedRune = static_cast<Rune>(runes);
// runen bewerten bzw addeptive force und attack speed für conq und 2 adaptive für den rest
if(runes==CONQUEROR){
    reksai.ad = reksai.ad + adaptivef*0.6;
    reksai.attackSpeed = reksai.attackSpeed + reksai.attackSpeed*asrunes;
}
else{
    reksai.ad = reksai.ad + (adaptivef*0.6)*2;
}


cout<<"Deine aktuellen Stats (ohne Items) lauten:"<<endl<<endl;
cout<<"AD = "<<reksai.ad<<endl;
cout<<"AS = "<<reksai.attackSpeed<<endl;
cout<<"BonusAD = "<<reksai.bonusad<<endl;
cout<<"HP = "<<reksai.hp<<endl<<endl;

//morgen weiter mit header für items 
cout<<"Wähle nun as nächstes deine Items!"<<endl<<endl<<"Zur Auswahl steht Titanic (T), Stride (S) oder Youmuus(Y).";
cin >>itemauswahl;

switch(itemauswahl){
case 'T':
case 't':
applyItem(titanic,reksai);
break;
case 'S':
case 's':
applyItem(stride,reksai);
break;
case 'Y':
case 'y':
applyItem(youmuus,reksai);
break;
}



cout<<"Deine aktuellen Stats mit einem Item lauten:"<<endl<<endl;
cout<<"AD = "<<reksai.ad<<endl;
cout<<"AS = "<<reksai.attackSpeed<<endl;
cout<<"BonusAD = "<<reksai.bonusad<<endl;
cout<<"HP = "<<reksai.hp<<endl;
cout<<"Leahality = "<<reksai.lethality<<endl<<endl;



cout<<"Entscheide nun die Werte des Dummies!"<<endl;
cout<<"Wie viel HP soll der Dummy haben?  ";
cin>>dummyhp;
cout<<endl<<"Wie viel Armor und Magicresist soll der Dummy haben?  ";
cin>>dummyres;
cout<<"\n\nDer Dummy für diesen Simulationsdurchlauf hat "<<dummyhp<<" Lebenspunkte und "<<dummyres<<" Resistencen"<<endl;









return 0;
}
