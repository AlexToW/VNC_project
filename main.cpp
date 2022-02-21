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
    //QString path = QDir::currentPath() + "\\screen." + format;
    QString path = "C:/Users/Alexander/Documents/screen.png";
    std::cout << path.toStdString().c_str() << std::endl;
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        if(pixmap.save(&file, "PNG")) {
            std::cout << "Saved!" << std::endl;
        } else {
            std::cout << "Didn't save!" << std::endl;
        }
    }
    a.exit();
    return 0;
}
