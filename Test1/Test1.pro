TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    TestSorts.cpp \
    HashTable.cpp \
    LinkedList.cpp \
#    SinglyLinkedLlist.cpp \
    CircularList.cpp

HEADERS += \
    sort.h \
    TestSorts.h \
    HashTable.h \
    LinkedList.h \
#    SinglyLiinkedlist.h \
    CircularList.h
