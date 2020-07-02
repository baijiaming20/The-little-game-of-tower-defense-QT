#include "towerbaseclass.h"

//构造函数初始化坐标
TowerBaseClass::TowerBaseClass(const int x, const int y) : SFCB(x, y)
{
    disCoorX = x, disCoorY = y;    //将防御塔真实坐标赋给显示坐标
}

Coor TowerBaseClass::getCoor() const      //返回防御塔坐标
{
    return Coor(x, y);
}

QString TowerBaseClass::getPicturePath() const//返回防御塔图片路径
{
    return picturePath;
}

int TowerBaseClass::getWidth() const     //返回防御塔宽高
{
    return width;
}

int TowerBaseClass::getHeight() const
{
    return height;
}

double TowerBaseClass::getAngle() const     //返回防御塔角度
{
    return angle;
}

int TowerBaseClass::getRange() const      //返回防御塔攻击范围
{
    return range;
}

EnemyBaseClass* TowerBaseClass::getTargetEnemy() const      //返回目标敌人
{
    return targetEnemy;
}

QVector<Coor> TowerBaseClass::getAttackCoor() const  //返回攻击坐标
{
    QVector<Coor> tempAttackec;
    for(auto bull : BulletVec)  //遍历子弹数组，把子弹数组的坐标全部给临时数组
        tempAttackec.push_back(Coor(bull->x, bull->y));

    return tempAttackec;    //返回
}

int TowerBaseClass::getAttackPower() const     //返回防御塔攻击力
{
    return attackPower;
}

int TowerBaseClass::getValue() const           //返回防御塔价值
{
    return value;
}

bool TowerBaseClass::getRangeFlag() const      //返回显示范围标记
{
    return displayRangeFlag;
}

int TowerBaseClass::getAttackInterval() const  //返回攻击间隔
{
    return attackInterval;
}

Coor TowerBaseClass::getDisCoor() const        //返回防御塔显示坐标
{
    return Coor(disCoorX, disCoorY);
}

int TowerBaseClass::getUpgradeValue() const    //返回升级成本 *
{
    return upgradeValue;
}

void TowerBaseClass::setCoor(const int x, const int y)         //设置防御塔坐标
{
    this->x = x, this->y = y;
}

void TowerBaseClass::setWidthHeight(const int width, const int height)  //设置防御塔宽高
{
    this->width = width, this->height = height;
}

void TowerBaseClass::setAngle(const double angle)       //设置防御塔旋转角度
{
    this->angle = angle;
}

void TowerBaseClass::setTargetEnemyNull()               //设置目标敌人为空
{
    targetEnemy = nullptr;
}

void TowerBaseClass::setRangeFlag(const bool flag)      //设置显示范围标记
{
    displayRangeFlag = flag;
}

void TowerBaseClass::setAttackInterval(const int attackInterval) //设置攻击间隔
{
    this->attackInterval = attackInterval;
}

void TowerBaseClass::setValue(const int value)                   //设置防御塔价值   *
{
    this->value = value;
}

void TowerBaseClass::setAttackPower(const int attackPower)       //设置防御塔攻击力  *
{
    this->attackPower = attackPower;
}

void TowerBaseClass::setDisCoor(const int x, const int y)      //设置显示坐标    *
{
    disCoorX = x, disCoorY = y;
}

void TowerBaseClass::setUpgradeValue(const int upgradeValue)   //设置防御塔升级成本 *
{
    this->upgradeValue = upgradeValue;
}

void TowerBaseClass::setRange(const int range)                 //设置防御塔攻击范围 *
{
    this->range = range;
}



