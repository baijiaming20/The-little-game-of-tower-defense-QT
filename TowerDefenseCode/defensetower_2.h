#ifndef DEFENSETOWER_2_H
#define DEFENSETOWER_2_H
#include "towerbaseclass.h"

class DefenseTower_2 : public TowerBaseClass
{
public:
    DefenseTower_2(const int, const int);

    void Attack(QVector<EnemyBaseClass*>&) override;
};

#endif // DEFENSETOWER_2_H
