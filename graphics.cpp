#include "graphics.h"
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include "math.h"
#include <QPolygon>
#include <algorithm>
#include <QDir>

graphics::graphics(QWidget *parent) : QWidget(parent)
{

    pos =0;
    timerID = startTimer(83.3);
}

void graphics::showEvent(QShowEvent *event){
    QWidget::showEvent(event); // Call base class handler

    // Only load once when the window first pops up!
    if (!all_Frames.isEmpty()) return;

    QDir dir(":/Frames_test");;
        dir.setFilter(QDir::Files);
        dir.setSorting(QDir::Name | QDir::LocaleAware);

        QStringList fileList = dir.entryList();
        for(int i=0; i<fileList.length();i++){
            int numberofLines;

            int w = width();
            int h= height();
            QString FileName = fileList[i];
            QString fullPath = dir.filePath(FileName);
            QFile file(fullPath);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            in >> numberofLines;
            int k;
            int j;
            QList<QPolygonF> list_of_lines;
            for(k=0; k<numberofLines; k++){
                int dotsperline;
                QPolygonF plyline;
                in>>dotsperline;
                for(j=0;j<dotsperline;j++){
                    float x,y;
                    in >> x;
                    in >>y;
                    plyline << QPointF(x+w/2, h-y-h/2);
                }
                list_of_lines << plyline;
            }
            all_Frames<<list_of_lines;

        }
}

void graphics::timerEvent(QTimerEvent *e){
    Q_UNUSED(e);
    pos += 1;
    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter paint(this);
    paint.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    paint.setRenderHint(QPainter::Antialiasing);
    if(mode ==1){
        DrawDino(paint);
    }


}


void graphics::DrawDino(QPainter& paint){
    //always using mod of 50 to avoid crash
    int safeFrameIndex = (int)pos % all_Frames.length();
        const QList<QPolygonF>& activeFrame = all_Frames[safeFrameIndex];

        for (int i= 0; i<activeFrame.length();i++) {
            paint.drawPolyline(activeFrame[i]);
        }


}




