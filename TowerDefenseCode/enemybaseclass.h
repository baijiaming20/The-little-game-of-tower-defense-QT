#ifndef ENEMYBASECLASS_H
#define ENEMYBASECLASS_H
#include "multifilestructure.h"

//敌人基类
class EnemyBaseClass : protected SFCB
{
protected:
    static constexpr int speed = 10;     //每次循环敌人移动的像素数量

    int width, height;  //宽高
    double health;         //生命值
    double orihealth;      //记录最开始的生命值

    QVector<Coor> enemyPathVec;     //敌人移动路径

public:
    EnemyBaseClass(QVector<Coor>&);  //构造
    bool move();              //怪物移动
//    void attack();

    Coor getCoor() const;     //返回坐标
    QString getPicturePath() const;//返回图片路径
    int getWidth() const;     //返回宽高
    int getHeight() const;
    double getHealth() const;    //返回生命值
    double getOrihealth() const; //返回开始的生命值

    void setHealth(const int);         //设置生命值

};

#endif // ENEMYBASECLASS_H
