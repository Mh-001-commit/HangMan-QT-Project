#ifndef INPUT_H
#define INPUT_H


#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtDebug>
#include <QList>
#include <QString>
#include <QFont>
#include <QDebug>
#include <QMessageBox>


class input : public QGraphicsTextItem
{
    Q_OBJECT
public:
    input();
    char getletter();
    QString word;
private:
    QFont style;
    char letter;
    int counter;
    QPixmap* images;
    QGraphicsPixmapItem* containers;
    QMessageBox msgBox;
private slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // INPUT_H
