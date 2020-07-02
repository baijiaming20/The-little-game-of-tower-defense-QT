#ifndef MULTIFILESTRUCTURE_H
#define MULTIFILESTRUCTURE_H
//多文件使用的结构和全局函数等

#include <QString>
#include <QVector>

constexpr int mapBlockLen = 80;    //地图块边长
constexpr int halfBlockLen = mapBlockLen >> 1;  //地图块边长的一半

//坐标结构
struct Coor
{
    int x, y;

    Coor(const int x = 0, const int y = 0) : x(x), y(y) {}
};

//坐标和图片路径结构
struct SFCB : public Coor
{
    QString picturePath;    //图片路径

    SFCB() {}
    SFCB(const int x, const int y, const QString path = "") : Coor(x, y), picturePath(path) {}
};


struct HitEffect : public Coor      //命中效果结构
{
    int width, height;
    int index = 1;
    HitEffect(int x, int y, int width, int height) : Coor(x, y), width(width), height(height) {}
};



#endif // MULTIFILESTRUCTURE_H
