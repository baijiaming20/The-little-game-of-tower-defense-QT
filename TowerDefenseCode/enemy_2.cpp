#include "enemy_2.h"

Enemy_2::Enemy_2(QVector<Coor> path) : EnemyBaseClass(path)
{
    picturePath = "../PictureMaterial/enemy_3.gif";
    width = 78, height = 86;
    health = 920.0;
    orihealth = health; //记录开始的生命值
}
