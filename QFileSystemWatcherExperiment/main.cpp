#include <QtCore/QCoreApplication>
#include "Watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher w;

    w.addPath("/home/delphi/text.txt");
    w.addPath("/home/delphi/workspace");

    
    return a.exec();
}
