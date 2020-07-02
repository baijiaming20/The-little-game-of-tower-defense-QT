#include "gamewindow.h"
#include <QMap>
#include "generatepath.h"   //生成路径类
#include <QTimer>
#include <QMediaPlayer>
#include <QPushButton>

//鼠标点击区域宏
#define MouClickRegion(X, Y, Width, Height)     \
(ev->x() >= (X) && ev->x() <= (X) + (Width) &&  \
ev->y() >= (Y) && ev->y() <= (Y) + (Height))

QVector<HitEffect*> hitEffectVec;   //命中效果数组

inline bool GameWindow::spendFunction(TowerBaseClass* tempPtr)  //支出功能
{
    if(!tempPtr) return false;


    if(money - tempPtr->getValue() >= 0)
    {
        money -= tempPtr->getValue();
        moneyLable->setText(QString("金钱：%1").arg(money));
        return true;    //成功支出
    }
    else
    {
        delete tempPtr;
        return false;
    }
}

GameWindow::GameWindow(int mapArr[][13])
{
    setFixedSize(1040, 640);
    setWindowTitle("游戏界面");

    //把参数数组拷贝给成员数组
    memcpy(this->mapArr, mapArr, sizeof(this->mapArr));

    //地图数组值对应的图片路径
    mapValuePicturePathMap.insert(0, "../PictureMaterial/map_block_wall.png");
    mapValuePicturePathMap.insert(1, "../PictureMaterial/map_block_monster_path.png");
    mapValuePicturePathMap.insert(2, "../PictureMaterial/map_block_monster_path.png");
    mapValuePicturePathMap.insert(3, "../PictureMaterial/map_block_tower_ocation.png");
    mapValuePicturePathMap.insert(4, "../PictureMaterial/map_block_monster_path.png");

    //得到生成路径
    QVector<QVector<int*>> tempVec = GeneratePath().getPathVec(mapArr);

    //将int*类型路径转换为Coor
    for (int j = 0; j < tempVec.size(); j++)          //每条路径
    {
        QVector<Coor> enemytempVec_1;
        for (int i = 0; i < tempVec[j].size(); i++)   //每个元素
            enemytempVec_1.push_back({ tempVec[j][i][1] * mapBlockLen, tempVec[j][i][0] * mapBlockLen});

        enemyPathsVec.push_back(enemytempVec_1);
    }

    //用于产生怪物定时器
    QTimer* timer1 = new QTimer(this);
    timer1->start(2000);

    connect(timer1,&QTimer::timeout,[=]() mutable
    {
        switch (tempVec.size())     //检查传入的地图数组有几条路径
        {
        case 1:     //一条路径
            if(counter >= 0 && counter <= 5)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0]));
            else if(counter >= 5 && counter <= 8)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0]));
            else if(counter >= 8 && counter <= 12)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0]));
            else if(counter >= 12 && counter <= 16)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[0]));
            else if(counter >= 16 && counter <= 34)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0])),
                enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[0]));
            else if(counter > 34 && counter < 46)
                enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[0])),
                enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[0]));
            else if(counter == 46) enemyVec.push_back(new Enemy_4(enemyPathsVec[0]));
            break;
        case 2:     //两条路径
            //产生怪物方案
            if(counter >= 0 && counter <= 5)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0]));
            else if(counter >= 5 && counter <= 8)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1]));
            else if(counter >= 8 && counter <= 12)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[1])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0]));
            else if(counter >= 12 && counter <= 16)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[0]));
            else if(counter >= 16 && counter <= 34)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[1]));
            else if(counter > 34 && counter < 46)
                enemyVec.push_back(new Enemy_3(enemyPathsVec[1])), enemyVec.push_back(new Enemy_3(enemyPathsVec[0])),
                enemyVec.push_back(new Enemy_3(enemyPathsVec[1])), enemyVec.push_back(new Enemy_3(enemyPathsVec[0]));
            else if(counter == 46) enemyVec.push_back(new Enemy_4(enemyPathsVec[0]));
            break;
        case 3:
            if(counter >= 0 && counter <= 5)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0]));
            else if(counter >= 5 && counter <= 8)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[2])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1]));
            else if(counter >= 8 && counter <= 12)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[1])), enemyVec.push_back(new Enemy_2(enemyPathsVec[0]));
            else if(counter >= 12 && counter <= 16)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[2]));
            else if(counter >= 16 && counter <= 34)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[2])), enemyVec.push_back(new Enemy_3(enemyPathsVec[2]));
            else if(counter > 34 && counter < 46)
                enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[1])),
                enemyVec.push_back(new Enemy_3(enemyPathsVec[2])), enemyVec.push_back(new Enemy_3(enemyPathsVec[2]));
            else if(counter == 46) enemyVec.push_back(new Enemy_4(enemyPathsVec[0]));
            break;
        case 4:
            if(counter >= 0 && counter <= 5)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0]));
            else if(counter >= 5 && counter <= 8)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1]));
            else if(counter >= 8 && counter <= 12)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[2])), enemyVec.push_back(new Enemy_2(enemyPathsVec[3]));
            else if(counter >= 12 && counter <= 16)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[3])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[2]));
            else if(counter >= 16 && counter <= 34)
                enemyVec.push_back(new Enemy_1(enemyPathsVec[0])), enemyVec.push_back(new Enemy_2(enemyPathsVec[1])),
                    enemyVec.push_back(new Enemy_3(enemyPathsVec[2])), enemyVec.push_back(new Enemy_3(enemyPathsVec[3]));
            else if(counter > 34 && counter < 46)
                enemyVec.push_back(new Enemy_3(enemyPathsVec[0])), enemyVec.push_back(new Enemy_3(enemyPathsVec[1])),
                enemyVec.push_back(new Enemy_3(enemyPathsVec[2])), enemyVec.push_back(new Enemy_3(enemyPathsVec[3]));
            else if(counter == 46) enemyVec.push_back(new Enemy_4(enemyPathsVec[0]));
            break;
        }

        counter++;
    });

    //金钱标签
    moneyLable->move(20, 40);
    moneyLable->setFont(QFont("黑体", 20));
    moneyLable->setText(QString("金钱：%1").arg(money));

    //生命标签
    lifelable->move(20, 90);
    lifelable->setFont(QFont("黑体", 20));
    lifelable->setText(QString("生命：%1").arg(playerHealth));

    //游戏进行，主定时器
    QTimer* timer2 = new QTimer(this);
    timer2->start(110);

    connect(timer2,&QTimer::timeout,[&]()
    {
        //防御塔攻击
        for(auto tower : towerVec)
        {
            QVector<EnemyBaseClass*> tempEnemyVec;

            for(auto &enemy : enemyVec)  //遍历敌人数组，将防御塔范围内的所有敌人插入到临时敌人数组中
                if(DistBetPoints(enemy->getCoor().x + (enemy->getWidth() >> 1), enemy->getCoor().y + (enemy->getHeight() >> 1),
                                tower->getCoor().x + halfBlockLen, tower->getCoor().y + halfBlockLen) <= tower->getRange())
                    tempEnemyVec.push_back(enemy);

            tower->Attack(tempEnemyVec); //把范围内的敌人作为参数传递给防御塔
        }

        //敌人移动
        for (auto enemyIt = enemyVec.begin(); enemyIt != enemyVec.end(); enemyIt++)
            if((*enemyIt)->move() || (*enemyIt)->getHealth() <= 0)          //敌人走到终点或血量为空则删除这个敌人
            {
                for(auto tower : towerVec)  //有防御塔的目标敌人和当前要删除的敌人重合则将防御塔的目标敌人设为空
                    if (tower->getTargetEnemy() == *enemyIt)
                        tower->setTargetEnemyNull();

                if((*enemyIt)->move())  //敌人走到堡垒后，玩家生命值-1
                {
                    playerHealth--;
                    lifelable->setText(QString("生命：%1").arg(playerHealth)); //刷新标签
                    if(!playerHealth)   //玩家生命值为0时，关闭游戏窗口，游戏失败
                    {
                        delete *enemyIt;
                        enemyVec.erase(enemyIt);
                        this->close();
                    }
                }
                else
                     //防御塔击败一个敌人则增加一定量的金钱，并刷新标签内容
                    money += 200, moneyLable->setText(QString("金钱：%1").arg(money));

                delete *enemyIt;
                enemyVec.erase(enemyIt);
                break;
            }

        //显示击中效果
        for(auto hit = hitEffectVec.begin(); hit != hitEffectVec.end(); hit++)
            if((*hit)->index <= 7)
            (*hit)->index++;
        //删除击中效果
        for(auto hit = hitEffectVec.begin(); hit != hitEffectVec.end(); hit++)
            if((*hit)->index >= 8)
            {
                delete *hit;
                hitEffectVec.erase(hit);
                break;
            }

        if((playerHealth > 0) && (!enemyVec.empty()) && (counter > 50))
            victoryFlag = true;   //显示胜利标签

        update();
    });

    //播放背景音乐
    QMediaPlayer* player = new QMediaPlayer();
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("../PictureMaterial/苇名一心.mp3"));
    player->setVolume(50);  //音量
    player->play();

    //范围按钮
    QPushButton* rangesBtn = new QPushButton(this);
    rangesBtn->setGeometry(20, 140, 100, 40);
    rangesBtn->setFont(QFont("黑体", 10));
    rangesBtn->setText("显示范围");

    connect(rangesBtn, &QPushButton::clicked,[=]()
    {
        if(allRanges) rangesBtn->setText("显示范围"), allRanges = false;
        else rangesBtn->setText("隐藏范围"), allRanges = true;
        update();
    });
}

//画出地图
void GameWindow::drawMap(QPainter& painter)
{
//    0 墙壁   1 怪物路径   2 怪物出生点   3 防御塔位置   4 堡垒
    Coor fortressCoor;      //记录堡垒的坐标

    for(int j = 0; j < 8; j++)
        for(int i = 0; i < 13; i++)
        {
            switch (mapArr[j][i]) {
            case 4:
                //记录下堡垒的坐标
                fortressCoor.x = i * mapBlockLen, fortressCoor.y = j * mapBlockLen;
                break;
            case 3:
                //将防御塔的坐标插入到数组
                towerPositionsVec.push_back(Coor(i * mapBlockLen, j * mapBlockLen));
                break;
            }

            //根据地图值画出不同图片
            painter.drawPixmap(i * mapBlockLen, j * mapBlockLen, mapBlockLen, mapBlockLen,
                QPixmap(mapValuePicturePathMap[mapArr[j][i]]));
        }


    //最后画出堡垒
    painter.drawPixmap(fortressCoor.x, fortressCoor.y, mapBlockLen, mapBlockLen,
        QPixmap("../PictureMaterial/map_block_fortress.png"));
}

//画出选择框
void GameWindow::drawSelectionFrame(QPainter& painter)
{
    if(!selectionFrame.getDisplay()) return;    //选择框显示状态为假则返回

    //画出选择框
    painter.drawPixmap(selectionFrame.getCoor().x, selectionFrame.getCoor().y,
       selectionFrame.getSelSideLength(), selectionFrame.getSelSideLength(),
       QPixmap("../PictureMaterial/Check_the_tower_effect.png"));

    //画出选中标志2
    painter.drawPixmap(selectionFrame.getCoor().x + ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1),
       selectionFrame.getCoor().y + ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1),
       mapBlockLen, mapBlockLen, QPixmap("../PictureMaterial/Check_the_tower_effect.png"));

    //画出子按钮
    for(int i = 0; i < 4; i++)
    {
        painter.drawPixmap(selectionFrame.getChildButtonArr()[i].x, selectionFrame.getChildButtonArr()[i].y,
            selectionFrame.getButSideLength(), selectionFrame.getButSideLength(),
            QPixmap(selectionFrame.getChildButtonArr()[i].picturePath));

        //画出防御塔图片
        painter.drawPixmap(selectionFrame.getChildButtonArr()[i].x + 10, selectionFrame.getChildButtonArr()[i].y + 10,
            selectionFrame.getButSideLength() - 20, selectionFrame.getButSideLength() - 20,
            QPixmap(selectionFrame.getTowerPicturePathArr()[i]));
    }
}

//画出防御塔、按钮、防御塔攻击范围
void GameWindow::drawTower(QPainter& painter)
{
    for(auto &tower : towerVec)
    {
        painter.setBrush(QBrush(Qt::NoBrush));  //清除画刷样式
        //画出全局防御塔范围
        if(allRanges)
            painter.setPen(QPen(Qt::black)),
            painter.drawEllipse(QPoint(tower->getCoor().x + halfBlockLen, tower->getCoor().y + halfBlockLen), tower->getRange(), tower->getRange());

        //画出被点击防御塔的范围和升级按钮图片
        if(tower->getRangeFlag())
        {
            painter.drawPixmap(tower->getCoor().x + 10, tower->getCoor().y - 80, 60, 60, QPixmap("../PictureMaterial/Upgrade_button.png")); //升级按钮
            painter.drawPixmap(tower->getCoor().x + 10, tower->getCoor().y + 100, 60, 60, QPixmap("../PictureMaterial/tearDown_button.png")); //升级按钮
            painter.setFont(QFont("黑体", 16));
            painter.drawText(tower->getCoor().x + 10, tower->getCoor().y - 80, QString("%1").arg(tower->getUpgradeValue()));    //画出升级成本文字
            painter.setPen(QPen(Qt::red));
            painter.drawEllipse(QPoint(tower->getCoor().x + halfBlockLen, tower->getCoor().y + halfBlockLen), tower->getRange(), tower->getRange());
        }

        //画出防御塔
        painter.translate(tower->getCoor().x + halfBlockLen, tower->getCoor().y + halfBlockLen);     //设置旋转中心
        painter.rotate(tower->getAngle());                     //旋转角度
        painter.translate(-(tower->getCoor().x + halfBlockLen), -(tower->getCoor().y + halfBlockLen));    //原点复位

        painter.drawPixmap(tower->getDisCoor().x, tower->getDisCoor().y, tower->getWidth(), tower->getHeight(), QPixmap(tower->getPicturePath()));
        painter.resetTransform();   //重置调整
    }
}

void GameWindow::drawEnemy(QPainter& painter)   //画出敌人和血条
{
    for(auto enemy : enemyVec)
    {
        (enemy->getHealth() / enemy->getOrihealth()) >= 0.5 ?
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern)) :     //设置画刷形式
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawRect(enemy->getCoor().x, enemy->getCoor().y - 10, enemy->getWidth() * (enemy->getHealth() / enemy->getOrihealth()), 6);    //画出敌人血条
        painter.drawPixmap(enemy->getCoor().x, enemy->getCoor().y, enemy->getWidth(), enemy->getHeight(), enemy->getPicturePath());
    }
}

void GameWindow::drawBull(QPainter& painter)           //画出子弹
{
    for (auto tower : towerVec) //遍历防御塔数组
        for(auto bullcoor : tower->getAttackCoor())
            painter.drawPixmap(bullcoor.x, bullcoor.y, 30, 30, QPixmap("../PictureMaterial/bullet_1.png"));
}

void GameWindow::drawHitEffect(QPainter& painter)   //画出命中效果
{
    for (auto hit : hitEffectVec)   //画出命中效果
        painter.drawPixmap(hit->x - 40, hit->y - 40, hit->width, hit->height, QPixmap(QString("../PictureMaterial/ExplosionEffect%1.png").arg(hit->index)));
}

//绘图函数
void GameWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    drawMap(painter);       //画出地图
    drawBull(painter);      //画出子弹
    drawEnemy(painter);     //画出怪物
    drawTower(painter);     //画出防御塔
    drawHitEffect(painter); //画出命中效果

    drawSelectionFrame(painter);    //画出选择框

    if(victoryFlag)         //画出游戏胜利提示
        painter.setPen(QPen(Qt::white)), painter.setFont(QFont("楷体", 110)), painter.drawText(176, 350, "游戏胜利");
}

//鼠标点击事件
void GameWindow::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() != Qt::LeftButton) //鼠标左键点击
        return;

    for (auto &tower : towerVec)         //判断升级和拆除按钮的点击
        if (tower->getRangeFlag())
        {
            //升级按钮的边长为70
            if (MouClickRegion(tower->getCoor().x + 10, tower->getCoor().y - 80, 60, 60))    //鼠标点击
            {
                if(money - tower->getUpgradeValue() < 0) break;

                money -= tower->getUpgradeValue();   //升级防御塔价格upgradeValue
                moneyLable->setText(QString("金钱：%1").arg(money));   //刷新标签

                constexpr double iM = 1.05;          //放大图片倍率
                //设置防御塔的坐标
                tower->setDisCoor(tower->getDisCoor().x - ((int)(tower->getWidth() * iM - tower->getWidth()) >> 1),
                    tower->getDisCoor().y - ((int)(tower->getHeight() * iM - tower->getHeight()) >> 1));
                //增加防御塔图片宽高
                tower->setWidthHeight(tower->getWidth() * iM, tower->getHeight() * iM);
                //设置防御塔目标敌人为空
                tower->setTargetEnemyNull();
                //设置防御塔攻击间隔
                tower->setAttackInterval(tower->getAttackInterval() - 1);
                //设置防御塔价值
                tower->setUpgradeValue(tower->getUpgradeValue() + 200);
                //设置防御塔攻击力
                tower->setAttackPower(tower->getAttackPower() + 50);
                //设置防御塔攻击范围
                tower->setRange(tower->getRange() + 10);
            }

            //拆除按钮点击
            if (MouClickRegion(tower->getCoor().x + 10, tower->getCoor().y + 100, 60, 60))
            {
                money += tower->getValue() * 0.8;   //拆除防御塔返还该防御塔价值的0.8倍
                delete tower;
                towerVec.erase(&tower);
            }

            break;
        }


    //选择框为显示状态时判断子按钮点击
    if(selectionFrame.getDisplay())
    {
        for (int i = 0; i < 4; i++)
            if (MouClickRegion (
                selectionFrame.getChildButtonArr()[i].x, selectionFrame.getChildButtonArr()[i].y,
                selectionFrame.getButSideLength(), selectionFrame.getButSideLength()))
            {
                //防御塔位置原坐标
                const Coor towerPoscoor(selectionFrame.getCoor().x + ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1),
                    selectionFrame.getCoor().y + ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1));

                //根据i将不同的防御塔对象插入到数组
                TowerBaseClass* tempTowerObj = nullptr;
                switch (i) {
                case 0:
                    tempTowerObj = new DefenseTower_1(towerPoscoor.x, towerPoscoor.y);
                    if(!spendFunction(tempTowerObj)) break;     //支出功能

                    towerVec.push_back(tempTowerObj);
                    break;
                case 1:
                    tempTowerObj = new DefenseTower_2(towerPoscoor.x, towerPoscoor.y);
                    if(!spendFunction(tempTowerObj)) break;

                    towerVec.push_back(tempTowerObj);
                    break;
                case 2:
                    tempTowerObj = new DefenseTower_3(towerPoscoor.x, towerPoscoor.y);
                    if(!spendFunction(tempTowerObj)) break;

                    towerVec.push_back(tempTowerObj);
                    break;
                case 3:
                    tempTowerObj = new DefenseTower_4(towerPoscoor.x, towerPoscoor.y);
                    if(!spendFunction(tempTowerObj)) break;

                    towerVec.push_back(tempTowerObj);
                }

                selectionFrame.setDisplay(false);
                update();
                return;
            }
    }


    //判断防御塔位置的点击
    for (auto towerPosition : towerPositionsVec)
        if (MouClickRegion(towerPosition.x, towerPosition.y, mapBlockLen, mapBlockLen))
        {
            for (auto tower : towerVec) //检查当前位置上是否已经有防御塔
                if (tower->getCoor().x == towerPosition.x && tower->getCoor().y == towerPosition.y) //有防御塔则显示该防御塔范围、显示升级按钮
                {
                    for (auto tower : towerVec)
                        if (tower->getRangeFlag()) tower->setRangeFlag(false); //先取消显示所有防御塔的范围

                    tower->setRangeFlag(true);          //设置被点击的显示范围标记为真
                    selectionFrame.setDisplay(false);
                    update();
                    return;
                }

            for (auto tower : towerVec)
                if (tower->getRangeFlag()) tower->setRangeFlag(false);

            //设置选择框坐标
            selectionFrame.setCoor
                (towerPosition.x - ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1),
                 towerPosition.y - ((selectionFrame.getSelSideLength() - mapBlockLen) >> 1));
            selectionFrame.setDisplay(true);    //设置选择框的显示状态为true

            update();   //调用绘图函数
            return;
        }

    for (auto tower : towerVec)     //点击其他地方取消显示防御塔范围
        if (tower->getRangeFlag()) { tower->setRangeFlag(false); break; }

    selectionFrame.setDisplay(false);   //点击其他地方则取消显示选择框
    update();
}

//析构
GameWindow::~GameWindow()
{
//释放内存
    for(auto it = towerVec.begin(); it != towerVec.end(); it++) //防御塔对象数组
    {
        delete *it;
        it = nullptr;
    }

    towerVec.clear();

    for(auto it = enemyVec.begin(); it != enemyVec.end(); it++) //敌人对象数组
    {
        delete *it;
        it = nullptr;
    }

    enemyVec.clear();

    for(auto it = hitEffectVec.begin(); it != hitEffectVec.end(); it++) //命中效果数组
    {
        delete *it;
        it = nullptr;
    }

    hitEffectVec.clear();

}
