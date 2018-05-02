#include <QCoreApplication>
#include <QImage>
#include <QImageReader>
#include <QDebug>
#include <QResource>
#include <QFile>
#include <bits/stdc++.h>
#include <QPixmap>


struct top
{
    int x, y;
    top() {}
    top(int _x, int _y)
    {
        x =_x;
        y =_y;
    }
    bool operator==(top p)
    {
        return  p.x == x && p.y == y ? true : false;
    }
};

int field[1000][1000];
int n = 601, m = 601;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int d[1000][1000];
top p[1000][1000];

void bfs(top s, top f)
{

    std::queue<top> q;

    q.push(s);
    p[s.x][s.y] = s;

    while(!q.empty())
    {
        top v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            if(!d[v.x + dx[i]][v.y + dy[i]] && v.x + dx[i] >=0 && v.x + dx[i] < n && v.y + dy[i] >=0 && v.y + dy[i] < m && field[v.x +dx[i]][v.y + dy[i]] == 0)
            {
                q.push(top(v.x + dx[i], v.y + dy[i]));
                d[v.x + dx[i]][v.y + dy[i]] = d[v.x][v.y] + 1;
                p[v.x + dx[i]][v.y + dy[i]] = v;
                if(q.back() == f)
                    return;

            }
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QImage img(":/img.png");



    for(int i = 0; i < 601; i++){
       for(int j = 0; j < 601; j++){
        if (QColor(img.pixel(i, j)) == QColor(Qt::white))
            field[j][i] = 0;
        else
           field[j][i] = -1;
       }

      }

   /* for(int i = 0; i < 601; i++){
       for(int j = 0; j < 601; j++){
            printf("%d", field[i][j]);

       }
       printf("\n");

      }*/

    top s(0, 1), f(599, 600);

    bfs(s, f);

   qWarning() << QString::number(d[f.x][f.y]);

    return a.exec();
}
