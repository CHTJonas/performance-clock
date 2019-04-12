#ifndef PERFCLOCK_H
#define PERFCLOCK_H

#include <QWidget>

class PerformanceClock : public QWidget
{
    Q_OBJECT

public:
    PerformanceClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif
