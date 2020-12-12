#include "equip.h"

Equip::Equip(int eva, int dr, int ap, int acc, int dp, QString name, int slot, int cost)
{
    this->eva = eva;
    this->dr = dr;
    this->ap = ap;
    this->acc = acc;
    this->dp = dp;
    this->name = name;
    this->slot = slot;
    this->cost = cost;
}
