

#ifndef CODE_CONVEXHULLALGORITHMS_H
#define CODE_CONVEXHULLALGORITHMS_H

#include "CGALComponents.h"
#include <QtWidgets>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QTranslator>


void drawConvexHullUsingQT(const std::vector<Point> &P,
                        const std::vector<Point> &convexHullPoints,
                        const bool labels) {

    const double pointSize = 4; // adjust this value to change the size of the points
    /***************************************************/
    QPicture pi;
    QPainter canvas(&pi);
    canvas.setRenderHint(QPainter::Antialiasing);
    //canvas.setFont(QFont("Times", 12));
    // DO NOT TOUCH THESE Qt STATEMENTS!!!
    /***************************************************/

    std::vector<QPointF> verticesForQTConvexHull;
    verticesForQTConvexHull.reserve(convexHullPoints.size());
    for( Point p : convexHullPoints )
        verticesForQTConvexHull.emplace_back( QPointF(p.x(),p.y() ) );

    canvas.drawPolygon(&verticesForQTConvexHull[0], (int)verticesForQTConvexHull.size());

    unsigned id = 0;
    for ( Point p : P ) {
        canvas.setBrush(Qt::black);

        canvas.drawEllipse(QPointF(p.x(), p.y()), pointSize, pointSize);
        if(labels) {
            QPointF textPos(p.x() + 4.0, p.y() + 4.0);
            canvas.drawText(textPos, QString(std::to_string(id).c_str()));
        }
        id++;
    }

    for ( Point p : convexHullPoints ) {
        canvas.setBrush(Qt::blue);
        canvas.drawEllipse(QPointF(p.x(), p.y()), pointSize, pointSize);
    }

    /*********************************************/
    canvas.end();
    auto l = new QLabel;
    l->setStyleSheet("QLabel { background-color : white; color : black; }");
    l->setPicture(pi);
    l->setWindowTitle("Polygon Triangulation");
    l->show();
    // l->showMaximized();
    QApplication::exec();
    // DO NOT TOUCH THESE Qt STATEMENTS!!!
    /***************************************************/
}

void plot() {
    // should generate two files a.txt and b.txt
    // a.txt is meant for points generated inside a square (use generatePointsInsideASquare(..) to generate those)
    // b.txt is meant for convex point sets (use generateConvexPointSetsInsideASquare(..) to generate those)
    // Warning: first column must contain the n-values, the second column must contain
    // Graham's Scan runtimes and the third column must contains Jarvis March runtimes

    // use values n = 1K, 2K, ...., 20K, and for every value of n,
    // use 5 pointsets and take the average of 5 runtimes
}

void jarvisMarch(const std::vector<Point> &P, std::vector<unsigned> &idsOfConvexHullPoints) {
    // complete
    // Warning: the point ids in idsOfConvexHullPoints must be in either clockwise or anticlockwise order
}

void grahamsScan(const std::vector<Point> &P, std::vector<unsigned> &idsOfConvexHullPoints) {
    // complete
    // Warning: the point ids in idsOfConvexHullPoints must be in either clockwise or anticlockwise order
}

#endif //CODE_CONVEXHULLALGORITHMS_H
