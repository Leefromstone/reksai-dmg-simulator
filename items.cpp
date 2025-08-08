#include "item.h"



void applyItem(Item item, ChampionStats &champ) {

switch(item){
    case titanic:
champ.bonusad +40;
champ.hp +600;
break;
    case stride:
champ.bonusad + 40;
champ.attackSpeed + 0.25;
champ.hp + 450;
break;
    case youmuus:
champ.bonusad + 55;
champ.leathality + 18;
break;
}
}


