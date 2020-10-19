#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QList>
#include "input.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the view and the scene ****************
    QGraphicsView view;
    view.setFixedSize(800, 500);
    view.setWindowTitle("The Hang Man");
    view.setBackgroundBrush(QBrush(Qt::black));
    QGraphicsScene scene;


    QPixmap background("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/background.png");
    background = background.scaledToWidth(800);
    background = background.scaledToHeight(495);
    QGraphicsPixmapItem boardImages;
    boardImages.setPixmap(background);
    scene.addItem(&boardImages);


    //play background music
    QMediaPlayer * m = new QMediaPlayer();
    m->setMedia(QUrl("qrc:/sound/back.mp3"));
    if(m->isAudioAvailable())
        printf("audio is available!\n");
    else
        qInfo() << m->error();
    m->play();

//    QMediaPlaylist *playlist = new QMediaPlaylist();
//    playlist->addMedia(QUrl("qrc:/sound/back.mp3"));
//    playlist->setPlaybackMode(QMediaPlaylist::Loop);
//    QMediaPlayer *music = new QMediaPlayer();
//    music->setPlaylist(playlist);
//    music->play();


    input coming;
    scene.addItem(&coming);
    coming.setPos(50, 225);
    coming.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    coming.setFocus();
    view.setScene(&scene);
    view.show();
    return a.exec();
}



