#include <QtGui>
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置窗口类型
    QWidget w(NULL,Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowStaysOnTopHint );
    QLabel l(&w);

    l.setText("I'm a label control.");
    w.setWindowTitle("D.T.software");
    w.resize(400,300);
    w.show();
    
    return a.exec();
}
