#ifndef TOWERBASECLASS_H
#define TOWERBASECLASS_H
#include "enemybaseclass.h"     //敌人类

//计算两点之间距离宏
#define DistBetPoints(X1, Y1, X2, Y2)           \
abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))))

extern QVector<HitEffect*> hitEffectVec;    //对游戏界面cpp中的hitEffectVec数组做外部变量声明

//防御塔基类
class TowerBaseClass : protected SFCB
{
protected:
    int disCoorX, disCoorY; //显示坐标
    int width, height;  //防御塔宽高
    double angle = 0.0; //旋转角度

    int range;          //防御塔攻击范围
    int attackPower;    //攻击力
    int value;          //防御塔价值
    bool displayRangeFlag = false;  //显示范围标记

    EnemyBaseClass* targetEnemy = nullptr;  //目标敌人

    //子弹结构
    struct BulletStr : public Coor
    {
        double k = 0.0, b = 0.0;    //用于计算出子弹路径
        bool dirFlag = false;       //移动方向标识
        int attributes;             //属性标识

        //子弹构造
        BulletStr(int x, int y, int attributes = 0) : Coor(x, y), attributes(attributes) {}
    };

    QVector<BulletStr*> BulletVec;  //子弹数组

    int attackInterval;             //统计攻击间隔

    int upgradeValue = 300;         //防御塔升级成本

    int counter = 2;                //计数器

public:
    TowerBaseClass(const int, const int);   //构造

    virtual void Attack(QVector<EnemyBaseClass*>&) = 0;      //攻击函数，参数为敌人对象向量

    Coor getCoor() const;           //返回防御塔真实坐标 *
    QString getPicturePath() const; //返回防御塔图片路径
    int getWidth() const;           //返回防御塔宽高   *
    int getHeight() const;
    double getAngle() const;        //返回防御塔角度
    int getRange() const;           //返回防御塔攻击范围 *
    EnemyBaseClass* getTargetEnemy() const;   //返回目标敌人 *
    QVector<Coor> getAttackCoor() const;      //返回攻击坐标
    int getAttackPower() const;     //返回防御塔攻击力  *
    int getValue() const;           //返回防御塔价值   *
    bool getRangeFlag() const;      //返回显示范围标记
    int getAttackInterval() const;  //返回攻击间隔 *
    Coor getDisCoor() const;        //返回显示坐标 *
    int getUpgradeValue() const;    //返回升级成本 *

    void setCoor(const int, const int);         //设置防御塔坐标
    void setWidthHeight(const int, const int);  //设置防御塔宽高   *
    void setAngle(const double);                //设置防御塔旋转角度
    void setTargetEnemyNull();                  //设置目标敌人为空  *
    void setRangeFlag(const bool);              //设置显示范围标记
    void setAttackInterval(const int);          //设置攻击间隔    *
    void setValue(const int);                   //设置防御塔价值   *
    void setAttackPower(const int);             //设置防御塔攻击力  *
    void setDisCoor(const int, const int);      //设置显示坐标    *
    void setUpgradeValue(const int);            //设置防御塔升级成本 *
    void setRange(const int);                   //设置防御塔攻击范围 *
};

#endif // TOWERBASECLASS_H
