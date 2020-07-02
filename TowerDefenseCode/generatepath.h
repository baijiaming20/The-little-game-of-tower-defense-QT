#ifndef GENERATEPATH_H
#define GENERATEPATH_H
#include <QVector>

//生成路径
class GeneratePath
{
private:
    QVector<QVector<int*>> dfs_res;       //存路的向量
    QVector<int*> temp_vector;
    int dirctions[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };        //上下左右移动的距离

    //检查此位置是否可以走
    int check(int x, int y, int(*my_map)[13])
    {
        if (x < 0 || y < 0 || x >= 8 || y >= 13 || (my_map[x][y] != 1 && my_map[x][y] != 4))
            return 0;

        return 1;
    }

    //深度优先搜索
    void dfs(int i, int j, int(*my_map)[13])
    {
        temp_vector.push_back(new int[2]{ i,j });

        for (int k = 0; k < 4; k++)
        {
            int x = i + dirctions[k][0];
            int y = j + dirctions[k][1];

            if (check(x, y, my_map))
                if (my_map[x][y] == 4)
                {
                    temp_vector.push_back(new int[2]{ x,y });
                    dfs_res.push_back(temp_vector);
                    return;
                }
                else
                {
                    my_map[i][j] = -1;
                    dfs(x, y, my_map);
                    my_map[i][j] = 1;
                }
        }

        temp_vector.pop_back();
    }

    //2 起点 4终点 1可以走的路
    void find_road(int(*my_map)[13])
    {
        dfs_res.clear();
        temp_vector.clear();

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 13; j++)
                // cout<< my_map[i][j];
                if (my_map[i][j] == 2)
                {
                    temp_vector.clear();
                    dfs(i, j, my_map);
                }
    }

public:
    QVector<QVector<int*>> getPathVec(int(*my_map)[13])    //生成路径并返回
    {
        find_road(my_map);
        return dfs_res;
    }
};

#endif // GENERATEPATH_H
