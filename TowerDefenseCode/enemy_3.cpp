#include "enemy_3.h"

Enemy_3::Enemy_3(QVector<Coor> path) : EnemyBaseClass(path)
{
    picturePath = "../PictureMaterial/enemy_2.gif";
    width = 126, height = 126;
    health = 3500.0;
    orihealth = health; //记录开始的生命值
}
