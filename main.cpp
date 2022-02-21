#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QWindow>
#include <QDir>
#include <iostream>
//#include "main.moc"


#define debug


QVector<QVector<QPixmap>> get_screen_parts(QPixmap pixmap, int N, int width, int height) {
     QVector<QVector<QPixmap>> screen_parts(N);
     for(int i = 0; i < N; i++) {
         for(int j = 0; j < N; j++) {
             QPixmap temp = pixmap.copy(i * width, j * height, width, height);
             screen_parts[i].push_back(temp);
         }
     }
     return screen_parts;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScreen *screen = a.primaryScreen();
    QPixmap pixmap = screen->grabWindow(0);

    // chopping up the pixmap on N parts (width, heigth)
    const int N = 4;
    const int width_screen = screen->size().width();
    const int height_screen = screen->size().height();
    int width;
    int height;
    if(width_screen % N == 0 && height_screen % N == 0) {
        width = width_screen / N;
        height = height_screen / N;
    }

    QVector<QVector<QPixmap>> screen_parts = get_screen_parts(pixmap, N, width, height);

    #ifdef debug
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cnt++;
                QString path_tmp = "C:/Users/Alexander/Documents/screen" + QString::number(cnt) + ".png";
                QFile file_tmp(path_tmp);
                if(file_tmp.open(QIODevice::WriteOnly)) {
                    QString msg = "Didn't save (%1)";
                    if(screen_parts[i][j].save(&file_tmp, "PNG")) {
                        QSize size = screen_parts[i][j].size();
                        msg = "Saved (%1)\t %2 x %3";
                        std::cout << msg.arg(cnt).arg(size.width()).arg(size.height()).toStdString() << std::endl;
                    }
                }
            }
        }
    #endif

    QString path = "C:/Users/Alexander/Documents/screen_main.png";
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
