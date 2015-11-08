#include "MyWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();

    qApp->setStyleSheet("QWidget{font-family: Calibri; font-size: 12pt;}");

    return app.exec();
}
