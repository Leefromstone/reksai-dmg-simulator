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
    float lethality = 0;
};

void applyItem(Item item, ChampionStats &champ);


#endif