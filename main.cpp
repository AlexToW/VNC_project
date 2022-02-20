#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QWindow>
#include <QDir>
#include <iostream>
#include "main.moc"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScreen *screen = a.primaryScreen();
    QPixmap pixmap = screen->grabWindow(0);
    const QString format = "png";
    QString path = QDir::currentPath() + "\\screen." + format;
    std::cout << path.toStdString().c_str() << std::endl;

    if(pixmap.save(path)) {
        std::cout << "Saved!" << std::endl;
    } else {
        std::cout << "Didn't saved!" << std::endl;
    }
    a->exit();
    return 0;
}
