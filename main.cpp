#include <QApplication>
#include "performanceclock.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    PerformanceClock clock;
    clock.show();
    return app.exec();
}
