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
        QString msg = "Didn't saved!";
        if(pixmap.save(&file, "PNG")) {
            msg = "Saved!";
        }
        std::cout << msg.toStdString() << std::endl;
        file.close();
    } else {
        std::cout << file.errorString().toStdString() << " (" << file.error() << ")" << std::endl;
    }
    a.exit();
    return 0;
}
