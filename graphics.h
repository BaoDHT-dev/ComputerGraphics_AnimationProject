#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>


class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void DrawDino(QPainter& paint);
    void timerEvent(QTimerEvent *);
    double pos;
    double timerID;


    int mode = 0;
protected:
    void showEvent(QShowEvent *event) override;

private:
    QVector<QList<QPolygonF> > all_Frames;
signals:



public slots:

};

#endif // GRAPHICS_H
