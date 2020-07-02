#ifndef DEFENSETOWER_1_H
#define DEFENSETOWER_1_H
#include "towerbaseclass.h"

//防御塔1，继承防御塔父类
class DefenseTower_1 : public TowerBaseClass
{
public:
    DefenseTower_1(const int, const int);

    void Attack(QVector<EnemyBaseClass*>&) override;  //重写攻击函数

};

#endif // DEFENSETOWER_1_H
