#include "enemybaseclass.h"
#include <qDebug>
//初始化怪物的坐标
EnemyBaseClass::EnemyBaseClass(QVector<Coor> &path) : SFCB(path.at(0).x, path.at(0).y) , enemyPathVec(path) {}

//怪物移动函数
bool EnemyBaseClass::move()
{
    if(enemyPathVec.empty())
        return true;

    if (enemyPathVec.at(0).y > y) //下
    {
        y += speed;
        return false;
    }

    if (enemyPathVec.at(0).x < x) //左
    {
        x -= speed;
        return false;
    }

    if (enemyPathVec.at(0).x > x) //右
    {
        x += speed;
        return false;
    }

    if (enemyPathVec.at(0).y < y) //上
    {
         y -= speed;
        return false;
    }

    //如果怪物的坐标和路径点坐标重合，则删除这个路径点
    if (enemyPathVec.at(0).y == y && enemyPathVec.at(0).x == x)
        enemyPathVec.erase(enemyPathVec.begin());       //删除第一个路径点

    return false;
}

Coor EnemyBaseClass::getCoor() const     //返回坐标
{
    return Coor(x, y);
}

QString EnemyBaseClass::getPicturePath() const//返回图片路径
{
    return picturePath;
}

int EnemyBaseClass::getWidth() const     //返回宽高
{
    return width;
}

int EnemyBaseClass::getHeight() const
{
    return height;
}

double EnemyBaseClass::getHealth() const    //返回生命值
{
    return health;
}

double EnemyBaseClass::getOrihealth() const //返回开始的生命值
{
    return orihealth;
}

void EnemyBaseClass::setHealth(const int health)         //设置生命值
{
    this->health = health;
}


