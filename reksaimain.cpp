#include <iostream>
#include "item.h"
#include <limits>
#include <vector>
#include <algorithm> 
#include <map> 

using namespace std;
int level = 0;
int runes = 0;
int basead = 62;
int basehp = 600;
float baseas = 0.667;

int levelreinfolge;
char itemauswahl;

int adaptivef = 5;
float asrunes = 0.01;

float dmgpercent;

float adgrowth = 3;
float asgrowth = 0.02;
float hpgrowth = 99;

//dummy zeug
int dummyhp;
int dummyres;
float schadensred = 1;

int lvlfirst;
int lvlsecond;
int lvlthird;

int lvlq;
int lvlw;
int lvle;
int lvlr;

int inventar = 0;
//reksai abilities
float reksaiq = 0;
float reksaiw = 0;
float reksaie = 0;
float reksair = 0;

enum Rune {
    CONQUEROR = 1,
    PTA = 2,
    ELECTROCUTE = 3
};

struct AbilityScaling {
    vector<float> baseDamage; 
    vector<float> adRatio;             
    vector<float> bonusAdRatio;         
};

float calculateAbilityDamage(const AbilityScaling& ability, int rank, float totalAD, float bonusAD) {
    if (rank <= 0) return 0.0f;
    if (rank > ability.baseDamage.size()) rank = ability.baseDamage.size();

   
    float base = ability.baseDamage[rank - 1];
    float adScale = ability.adRatio[rank - 1];
    float bonusAdScale = ability.bonusAdRatio[rank - 1];

    return base + adScale * totalAD + bonusAdScale * bonusAD;
}


map<string, Item> itemMap = {
    {"titanic", titanic},
    {"stride", stride},
    {"youmuus", youmuus},
    {"sojin", sojin},
    {"bloodmail", bloodmail},
    {"steraks", steraks},
    {"dd", dd},
    {"maw", maw},
    {"cleaver", cleaver},
    {"serpents", serpents},
    {"mortal", mortal},
    {"syreldas", syreldas}
};

int main(){

    cout <<"REKSAI DMG NUMBER TESTER"<<endl;

while(true){
    cout<< "Welches Level soll Reksai in der Simulation haben?: ";
    cin>> level;

if(cin.fail()){
    cout<< "Bitte ein Level zwischen 3 und 18 angeben!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}else if(level<3||level>18){
    cout<< "Bitte ein Level zwischen 3 und 18 angeben!\n";
}else{
    cout<< "Level acceptiert"<<endl<<endl<<endl;
    break;
}
}
cout<<"Wähle aus welche Abilities du wie upgraden möchtest:"<<endl<<"1. Q max\n2. three points into Q into E max\n3. E max\n\n";

while(true){
    cin>> levelreinfolge;

if(cin.fail()){
    cout<< "Bitte geben Sie die Zahl 1,2 oder 3 ein!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}else if(levelreinfolge<1 || levelreinfolge>3){
    cout<< "Bitte geben Sie 1,2 oder 3 ein!";
}else{
    break;
}
}

/*
kp ich mach das neu war etwas lost wie ich das am besten schreiben soll
if(level = 3)
lvlthird = lvlsecond = lvlfirst = 1;
if(level > 3 && level < 6)
lvlfirst = level - 2;
lvlsecond = lvlthird = 1;
if(level = 7)
lvlsecond = lvlthird = 1;
lvlfirst = 4;
if(level = 8)
lvlthird = 1;
lvlsecond = 2;
lvlfirst = 4;
if(level = 9)
lvlthird = 1;
lvlsecond = 2;
lvlfirst = 5;

*/
// 3. lvl reinfolge in falle reksais ihre W

if(levelreinfolge == 1 || levelreinfolge == 3){

if(level >= 3 && level < 14)
lvlthird = 1;
if(level == 14 || level == 15)
lvlthird = level - 12;
if(level == 17 || level == 18)
lvlthird = level - 13;


// second max

if(level >= 3 && level < 8)
lvlsecond = 1;
if(level == 8 || level == 9)
lvlsecond = 2;
if(level == 10 || level == 11)
lvlsecond = 3;
if(level == 12 || level == 13)
lvlsecond = level - 8;
if(level >= 13)
lvlsecond = 5;

//first max

if(level == 3)
lvlfirst = 1;
if(level > 3 && level < 6)
lvlfirst = level - 2;
if(level == 6)
lvlfirst = 3;
if(level == 7 || level == 8)
lvlfirst = 4;
if(level > 8 && level <= 18)
lvlfirst =5;

if(level >= 6 && level < 11)
lvlr = 1;
if(level >= 11 && level < 16)
lvlr = 2;
if(level >= 16)
lvlr = 3;


}
else {

    if(level >= 3 && level < 14)
lvlthird = 1;
if(level == 14 || level == 15)
lvlthird = level - 12;
if(level == 17 || level == 18)
lvlthird = level - 13;

if(level >= 3 && level < 7)
lvlfirst = 1;
if(level >= 7 && level < 11)
lvlfirst = level - 5;
if(level>11)
lvlfirst = 5;

if(level == 3)
lvlsecond = 1;
if(level > 3 && level < 6)
lvlsecond = level - 2;
if(level == 12 || level == 13)
lvlsecond = level - 8;
if(level > 13)
lvlsecond = 5;

}



cout<<"\nWelche runen soll reksai haben?"<<endl;
cout<<"1. conq mit 1xadaptive and cupdg\n2. pta mit 2x adap and cupdg \n3. electro mit 2x adap and cheapshot\n\n"<<"Bitte um eingame(1-3): ";

while(true){
    cin>> runes;
if(cin.fail()){
    cout<< "Bitte geben sie 1,2 oder 3 ein!";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

cout<<"Wählen sie nun als nächstes Ihre Items. Zur Auswahl stehen:"<<endl<<"Titanic OR Stride\nYoumuus\nSojin\nBloodmail\nSteraks\ndd\nmaw\nCleaver\nSerpents\nMortal\nSyreldas\nIf you are done with adding items type X";




vector<Item> build;
string itemname;

for (int i = 0; i < 6; i++) {
    cout << "Item Nummer " << i+1 << " : ";
    cin >> itemname;
    transform(itemname.begin(), itemname.end(), itemname.begin(), ::tolower);

    if (itemname == "x")
        break;
if(itemname == "stride"){
if(find(build.begin(),build.end(),titanic) != build.end()){
cout<<"Remeber that you can only have EITHER stride or titanic!";
}
}
if(itemname == "titanic"){
if(find(build.begin(),build.end(),stride) != build.end()){
cout<<"Remeber that you can only have EITHER stride or titanic!";
}
}




    if (itemMap.find(itemname) != itemMap.end()) {
        Item chosen = itemMap[itemname];   // hier wird chosen angelegt

    if (find(build.begin(), build.end(), chosen) != build.end()) {
        cout << "Dieses Item hast du schon!\n";
        i--;
        } else {
            build.push_back(chosen);
            cout << "Item hinzugefügt: " << itemname << endl;
        }
    } else {
        cout << "Ungültiges Item!\n";
        i--;
}
}


//cout<<"Wähle nun as nächstes deine Items!"<<endl<<endl<<"Zur Auswahl steht Titanic (T), Stride (S) oder Youmuus(Y).";
//cin >>itemauswahl;

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
cout<<"Lethality = "<<reksai.lethality<<endl<<endl;



cout<<"Entscheide nun die Werte des Dummies!"<<endl;
cout<<"Wie viel HP soll der Dummy haben? ";
cin>>dummyhp;
cout<<endl<<"Wie viel Armor und Magicresist soll der Dummy haben? ";
cin>>dummyres;
cout<<"\nDer Dummy für diesen Simulationsdurchlauf hat "<<dummyhp<<" Lebenspunkte und "<<dummyres<<" Resistencen"<<endl;


schadensred = 100/(100 + dummyres);




AbilityScaling reksaiqout{
    {0,0,0,0,0},
    {0.3,0.35,0.4,0.45,0.5},
    {0,0,0,0,0}
};

AbilityScaling reksaiqin{
    {50,80,110,140,170},
    {0,0,0,0,0},
    {0.25,0.25,0.25,0.25,0.25}
};
AbilityScaling reksaiw{
    {30,55,80,105,130},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
AbilityScaling reksaie{
    {100,135,170,205,240},
    {0,0,0,0,0},
    {0.8,0.8,0.8,0.8,0.8}
};
AbilityScaling reksair{
    {150,250,350,350,350},
    {0,0,0,0,0},
    {1,1,1,1,1}
};


if(levelreinfolge < 3){

lvlq = lvlfirst;
lvlw = lvlthird;
lvle = lvlsecond;}
else{
lvlq = lvlsecond;
lvlw = lvlthird;
lvle = lvlfirst;

}

//dmg percent der ult
if(lvlr == 1) dmgpercent = 0.15;
else if(lvlr == 2) dmgpercent = 0.2;
else if(lvlr == 3) dmgpercent = 0.25;



float qdamageout = calculateAbilityDamage(reksaiqout, lvlq, reksai.ad, reksai.bonusad) + reksai.ad;
float qdamagein = calculateAbilityDamage(reksaiqin, lvlq, reksai.ad, reksai.bonusad);
float wdamage = calculateAbilityDamage(reksaiw, lvlw, reksai.ad, reksai.bonusad);
float edamage = calculateAbilityDamage(reksaie, lvle, reksai.ad, reksai.bonusad);
float rdamage = calculateAbilityDamage(reksair, lvlr, reksai.ad, reksai.bonusad)+ dummyhp* dmgpercent ;

cout<<endl<<endl <<"Aktuell macht deine unburrowd Q "<<qdamageout <<" schaden !";
cout<<endl<<"Aktuell macht deine burrowd Q "<<qdamagein <<" schaden !";
cout<<endl<<"Aktuell macht deine W "<<wdamage <<" magicdmg !";
cout<<endl<<"Aktuell macht deine E "<<edamage <<" truedmg !";
cout<<endl<<"Aktuell macht deine Ult "<<rdamage <<" dmg !";




















return 0;
}
