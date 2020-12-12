#ifndef EQUIP_H
#define EQUIP_H
#include <QString>

class Equip
{
public:
    Equip(int eva, int dr, int ap, int acc, int dp, QString name, int slot, int cost);
    int eva;
    int dr;
    int ap;
    int acc;
    int dp;
    QString name;
    int slot;
    int cost;
};

#endif // EQUIP_H
