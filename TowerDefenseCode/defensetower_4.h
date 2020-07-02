#ifndef DEFENSETOWER_4_H
#define DEFENSETOWER_4_H

#include "towerbaseclass.h"

class DefenseTower_4 : public TowerBaseClass
{
public:
    DefenseTower_4(const int, const int);

    void Attack(QVector<EnemyBaseClass*>&) override;
};

#endif // DEFENSETOWER_4_H
