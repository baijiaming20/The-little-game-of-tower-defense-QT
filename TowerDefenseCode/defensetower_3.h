#ifndef DEFENSETOWER_3_H
#define DEFENSETOWER_3_H
#include "towerbaseclass.h"

class DefenseTower_3 : public TowerBaseClass
{
public:
    DefenseTower_3(const int, const int);

    void Attack(QVector<EnemyBaseClass*>&) override;
};

#endif // DEFENSETOWER_3_H
