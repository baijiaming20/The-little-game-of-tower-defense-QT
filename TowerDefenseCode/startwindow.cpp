#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewindow.h"        //游戏界面

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    setWindowTitle("开始界面");

    //选择关卡按钮点击
    //第一关
    connect(ui->pushButton_1, &QPushButton::clicked, []()
    {
        int mapArr_1[8][13] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 3, 0, 0, 3, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0,
            0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 1, 0,
            4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 3, 0, 0, 3, 1, 0, 3, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
        };

        GameWindow* gamewindow = new GameWindow(mapArr_1);
        gamewindow->show();
    });

    //第二关
    connect(ui->pushButton_2, &QPushButton::clicked, []()
    {
        int mapArr_1[8][13] =
        {
            0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0,
            0, 0, 0, 1, 3, 0, 0, 0, 3, 1, 0, 0, 0,
            0, 0, 3, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 1, 0, 3, 1, 0, 0, 3, 0, 0, 0,
            0, 1, 3, 1, 1, 1, 1, 0, 0, 1, 1, 1, 4,
            0, 1, 0, 0, 3, 0, 0, 3, 0, 1, 0, 0, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };

        GameWindow* gamewindow = new GameWindow(mapArr_1);
        gamewindow->show();
    });

    //第三关
    connect(ui->pushButton_3, &QPushButton::clicked, []()
    {
        int mapArr_1[8][13] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            2, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 4,
            0, 1, 0, 0, 1, 3, 3, 1, 0, 3, 1, 0, 0,
            0, 1, 3, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
            0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
            0, 1, 0, 3, 1, 0, 0, 1, 3, 0, 1, 0, 0,
            0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };

        GameWindow* gamewindow = new GameWindow(mapArr_1);
        gamewindow->show();
    });

    //第四关
    connect(ui->pushButton_4, &QPushButton::clicked, []()
    {
        int mapArr_1[8][13] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0,
            2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
            0, 0, 3, 0, 0, 0, 1, 3, 0, 3, 0, 0, 0,
            2, 1, 1, 1, 0, 3, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };

        GameWindow* gamewindow = new GameWindow(mapArr_1);
        gamewindow->show();
    });
}

StartWindow::~StartWindow()
{
    delete ui;
}
