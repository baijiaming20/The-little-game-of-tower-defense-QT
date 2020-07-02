#ifndef ENEMY_1_H
#define ENEMY_1_H
#include "enemybaseclass.h"

//敌人1，继承敌人父类
class Enemy_1 : public EnemyBaseClass
{
public:
    Enemy_1(QVector<Coor>);
};

#endif // ENEMY_1_H
