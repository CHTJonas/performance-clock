#include <QtWidgets>
#include "performanceclock.h"

PerformanceClock::PerformanceClock(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(50);

    setWindowTitle(tr("Performance Clock"));
    resize(400, 400);
}

void PerformanceClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(4, 20),
        QPoint(-4, 20),
        QPoint(0, -45)
    };

    static const QPoint minuteHand[3] = {
        QPoint(4, 20),
        QPoint(-4, 20),
        QPoint(0, -90)
    };

    static const QPoint secondHand[3] = {
        QPoint(4, 20),
        QPoint(-4, 20),
        QPoint(0, -90)
    };

    QColor clockBackground(255, 255, 255);
    QColor hourColor(0, 0, 0);
    QColor minuteColor(0, 0, 0);
    QColor secondColor(255, 0, 0);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    QRadialGradient backgroundGradient(0, 0, 50);
    backgroundGradient.setColorAt(0, QColor(127, 127, 255));
    backgroundGradient.setColorAt(1, QColor(224, 224, 255));

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(backgroundGradient));
    painter.drawEllipse(QPoint(0,0), 100, 100);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.rotate(30.0 * (time.hour() + time.minute() / 60.0));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    painter.setPen(hourColor);
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    painter.setPen(minuteColor);
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
