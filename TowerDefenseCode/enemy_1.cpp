#include "enemy_1.h"

Enemy_1::Enemy_1(QVector<Coor> path) : EnemyBaseClass(path)
{
    picturePath = "../PictureMaterial/enemy_1.gif"; //怪物图片路径
    width = 90, height = 75;    //怪物宽高
    health = 700.0;
    orihealth = health; //记录开始的生命值
}
