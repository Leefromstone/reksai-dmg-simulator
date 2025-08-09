#include "item.h"



void applyItem(Item item, ChampionStats &champ) {

switch(item){
    case titanic:{
champ.bonusad = champ.bonusad + 40;
champ.hp = champ.hp +600;
champ.ad = champ.ad + champ.bonusad;
break;
}
    case stride:
champ.bonusad = champ.bonusad + 40;
champ.attackSpeed = champ.attackSpeed + 0.25;
champ.hp = champ.hp + 450;
champ.ad = champ.ad + champ.bonusad;
break;
    case youmuus:
champ.bonusad = champ.bonusad + 55;
champ.ad = champ.ad + champ.bonusad;
champ.lethality = champ.lethality + 18;
break;
}
}


