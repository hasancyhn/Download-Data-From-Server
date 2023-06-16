#include "wget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wget w;
    w.show();
    return a.exec();
}
