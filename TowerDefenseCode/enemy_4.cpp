#include "enemy_4.h"

Enemy_4::Enemy_4(QVector<Coor> path) : EnemyBaseClass(path)
{
    picturePath = "../PictureMaterial/enemy_4.gif";
    width = 280, height = 132;
    health = 49500.0;
    orihealth = health; //记录开始的生命值
}
