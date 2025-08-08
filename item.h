#ifndef ITEMS_H
#define ITEMS_H

enum Item {
    titanic,
    stride,
    youmuus
};
struct ChampionStats {
    float ad;
    float bonusad;
    float attackSpeed;
    float hp;
    float leathality;
};

void applyItem(Item item, ChampionStats &champ);


#endif