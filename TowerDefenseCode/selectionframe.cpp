#include "selectionframe.h"

SelectionFrame::SelectionFrame()
{
    //选择框图片路径
    picturePath = "../PictureMaterial/Bottom_selection_box.png";

    //设置子按钮图片路径
    for (auto &childButton : childButtonArr)
        childButton.picturePath = "../PictureMaterial/High-level_selection_box.png";
}

Coor SelectionFrame::getCoor() const       //返回坐标
{
    return Coor(x, y);
}

QString SelectionFrame::getPicturePath() const //返回图片路径
{
    return picturePath;
}

bool SelectionFrame::getDisplay() const    //返回显示状态
{
    return display;
}

const SFCB* SelectionFrame::getChildButtonArr() const    //返回子按钮数组
{
    return childButtonArr;
}

unsigned int SelectionFrame::getSelSideLength() const    //返回选择框边长
{
    return seleSideLength;
}

unsigned int SelectionFrame::getButSideLength() const    //返回子按钮边长
{
    return childButLength;
}

const QString* SelectionFrame::getTowerPicturePathArr() const   //返回防御塔图片路径数组
{
    return towerPicturePathArr;
}

void SelectionFrame::setCoor(const int x , const int y)  //设置坐标
{
    this->x = x, this->y = y;   //设置选择框坐标

    //设置子按钮的具体坐标
    const int butCenterCoorX = this->x + (seleSideLength >> 1) - (childButLength >> 1);
    const int butCenterCoorY = this->y + (seleSideLength >> 1) - (childButLength >> 1);

    for (auto &childButton : childButtonArr)
    {
        childButton.x = butCenterCoorX;
        childButton.y = butCenterCoorY;
    }

    const int dFC = 100;        //子按钮距中心的距离

    childButtonArr[0].y -= dFC; //上
    childButtonArr[1].x -= dFC; //左
    childButtonArr[2].x += dFC; //右
    childButtonArr[3].y += dFC; //下
}

void SelectionFrame::setDisplay(const bool display)      //设置显示状态
{
    this->display = display;
}
