#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QImage img("2.bmp");
    QRgb p = img.pixel(0, 0);

    cerr << p;

    return a.exec();
}
