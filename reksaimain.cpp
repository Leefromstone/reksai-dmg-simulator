#include <iostream>
using namespace std;

int level=0;
int runes =0;

struct ChampionStats {
    float ad;
    float bonusad;
    float attackSpeed;
    float hp;
};
float adgrowth=3;
float asgrowth =0.02;
float hpgrowth =99;


int main()
{
    
    
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
}
else{
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
}
else{
    cout<< "Runen acceptiert"<<endl<<endl;
    break;
}
}
//stats für reksai per level
ChampionStats reksaistats;
reksaistats.ad=62+adgrowth*(level-1);
reksaistats.attackSpeed=0.667+((asgrowth*0.667)*(level-1));
reksaistats.bonusad=0;
reksaistats.hp=600+hpgrowth*(level-1);

// runen bewerten bzw addeptive force und attack speed für conq und 2 adaptive für den rest
if(runes==1){
    reksaistats.ad = reksaistats.ad + 3;
    reksaistats.attackSpeed = reksaistats.attackSpeed + 0.0667;
}
else{
    reksaistats.ad = reksaistats.ad + 6;
}


cout<<"Deine aktuellen Stats (ohne Items) lauten:"<<endl<<endl;

cout<<"AD = "<<reksaistats.ad<<endl;
cout<<"AS = "<<reksaistats.attackSpeed<<endl;
cout<<"BonusAD = "<<reksaistats.bonusad<<endl;
cout<<"HP = "<<hpgrowth<<endl<<endl;

//morgen weiter mit header für items 
cout<<"Wähle nun as nächstes deine Items!"<<endl<<endl<<"Zur auswahl stehen Titanic ";


return 0;
}
