#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T09:29:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JNotes
TEMPLATE = app

RESOURCES = application.qrc

SOURCES += main.cpp\
				main_window.cpp \
    notes_page.cpp \
    note.cpp \
    file.cpp \
    exception.cpp \
    create_tab.cpp

HEADERS  += main_window.hpp \
    notes_page.h \
    note.hpp \
    json.hpp \
    file.hpp \
    exception.hpp \
    create_tab.hpp
