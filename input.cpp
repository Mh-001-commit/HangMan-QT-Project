#include "input.h"
#include<QMediaPlayer>

input::input()
{

    word = "_ _ _ _ _ _ _";
    QFont serifFont("Times", 24, QFont::Bold);
    setFont(serifFont);
    setHtml("<div style='background-color:#FFFFFF;'>" + word + "</div>");

    counter =0;

    images = new QPixmap[5];
    containers= new QGraphicsPixmapItem[5];


    QPixmap face("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/face.png");
    face = face.scaledToWidth(10000);
    face = face.scaledToHeight(100);
    images[0]=face;
    containers[0].setPixmap(face);
    containers[0].setPos(410,120);

    QPixmap body("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/body.png");
    body = body.scaledToHeight(10000);
    body = body.scaledToWidth(85);
    images[1] = body;
    containers[1].setPixmap(body);
    containers[1].setPos(399,194);

    QPixmap Rhand("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/right_hand.png");
    Rhand = Rhand.scaledToHeight(1000);
    Rhand = Rhand.scaledToWidth(50);
    images[2] = Rhand;
    containers[2].setPixmap(Rhand);
    containers[2].setPos(454,142);


    QPixmap Lhand("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/left_hand.png");
    Lhand = Lhand.scaledToHeight(1000);
    Lhand = Lhand.scaledToWidth(43);
    images[3]= Lhand;
    containers[3].setPixmap(Lhand);
    containers[3].setPos(383,142);


    QPixmap legs("C:/Users/Dell/Downloads/hangman_assignment-20201019T135607Z-001.zi/hangman_assignment/legs.png");
    legs = legs.scaledToHeight(10000);
    legs = legs.scaledToWidth(119);
    images[4]=legs;
    containers[4].setPixmap(legs);
    containers[4].setPos(383,259);


}


void input::keyPressEvent(QKeyEvent *event)
{
    QString temp="HANGMAN";
    if(temp.contains((char) event->key()))
    {
       if (((char)event->key())=='H')
           word[0]='H';
       else if (((char)event->key())=='A')
           {word[10]='A';
           word[2]='A';}
       else if (((char)event->key())=='N')
         {word[4]='N';
          word[12]='N';}
       else if (((char)event->key())=='G')
           word[6]='G';
       else if (((char)event->key())=='M')
           word[8]='M';

  }
    else
     {

        scene()->addItem(&containers[counter]);
        counter++;

        if (counter==5)
        {
            msgBox.setText("YOU LOST");
            QMediaPlayer * y = new QMediaPlayer();
            y->setMedia(QUrl("qrc:/sound/no.mp3"));
            if(y->isAudioAvailable())
                printf("audio is available!\n");
            else
                qInfo() << y->error();
            y->play();
            msgBox.exec();

        }

 }
        setHtml("<div style='background-color:#FFFFFF;'>" + word + "</div>");
        if (word=="H A N G M A N"){
            msgBox.setText("YOU WON");
            QMediaPlayer * z = new QMediaPlayer();
            z->setMedia(QUrl("qrc:/sound/yes.mp3"));
            if(z->isAudioAvailable())
                printf("audio is available!\n");
            else
                qInfo() << z->error();
            z->play();
            msgBox.exec();
        }


}


char input:: getletter(){return letter;}
