#include <QCoreApplication>
#include <QImage>
#include <QImageReader>
#include <QDebug>
#include <QResource>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QImage img(":/2.bmp");



    qWarning() << img.load(":/images/img.bmp");

   if (QColor(img.pixel(0,0))==QColor(Qt::black))
    {

    }


   // QRgb p = img.pixel(0, 0);

    return a.exec();
}
