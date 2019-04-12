QT += widgets

HEADERS       = performanceclock.h
SOURCES       = performanceclock.cpp \
                main.cpp

QMAKE_PROJECT_NAME = widgets_performanceclock

# install
target.path = performanceclock
INSTALLS += target