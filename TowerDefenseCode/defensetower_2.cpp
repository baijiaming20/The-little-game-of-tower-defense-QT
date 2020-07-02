#include "defensetower_2.h"

DefenseTower_2::DefenseTower_2(const int x, const int y) : TowerBaseClass(x, y)
{
    width = 110, height = 80;   //防御塔宽高
    picturePath = "../PictureMaterial/cannon_2.png";    //防御塔图片路径
    range = 230;
    attackPower = 60;
    value = 300;

    attackInterval = 9;
}

void DefenseTower_2::Attack(QVector<EnemyBaseClass*>& enemyVec)
{
    if(attackInterval < 2) attackInterval = 2;  //防御塔攻速上限

    angle += 2; //防御塔旋转
    if(angle >= 360) angle = 0;

    //子弹移动
    for(auto bull : BulletVec)
        switch (bull->attributes)
        {
        case 0: bull->y -= 8; break;
        case 1: bull->y += 8; break;
        case 2: bull->x -= 8; break;
        case 3: bull->x += 8; break;
        }

    //删除范围外的子弹
    for(int i = 0; i < 4; i++)
        for(auto bullit = BulletVec.begin(); bullit != BulletVec.end(); bullit++)
            if(DistBetPoints((*bullit)->x + 15, (*bullit)->y + 15, x + halfBlockLen, y + halfBlockLen) > range)
            {
                delete *bullit;
                BulletVec.erase(bullit);
                break;
            }

    //怪物受到攻击
    for (auto bullIt = BulletVec.begin(); bullIt != BulletVec.end(); bullIt++)    //子弹
        for (auto enemyIt = enemyVec.begin(); enemyIt != enemyVec.end(); enemyIt++)   //敌人
            if ((*bullIt)->x + 15 >= (*enemyIt)->getCoor().x && (*bullIt)->x <= (*enemyIt)->getCoor().x + (*enemyIt)->getWidth() &&
               (*bullIt)->y + 15 >= (*enemyIt)->getCoor().y && (*bullIt)->y <= (*enemyIt)->getCoor().y + (*enemyIt)->getHeight())
            {
                //击中敌人则减掉敌人血量并删除子弹
                (*enemyIt)->setHealth((*enemyIt)->getHealth() - attackPower);

                hitEffectVec.push_back(new HitEffect((*enemyIt)->getCoor().x + ((*enemyIt)->getWidth() >> 1),
                    (*enemyIt)->getCoor().y + ((*enemyIt)->getHeight() >> 1), 80, 80));

                delete *bullIt;
                BulletVec.erase(bullIt);

                goto outLoop;
            }
    outLoop:

    if(enemyVec.empty()) return;    //没有怪物直接返回

    if(counter > attackInterval)
    {
        //新建子弹
        for(int i = 0; i < 4; i++)
            BulletVec.push_back(new BulletStr(x + halfBlockLen, y + halfBlockLen, i));


        counter = 0;
    }

    counter++;
}
