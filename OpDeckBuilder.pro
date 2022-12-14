######################################################################
# Automatically generated by qmake (3.1) Sat Dec 10 19:09:38 2022
######################################################################

TEMPLATE = app
TARGET = main
INCLUDEPATH += .
QT += widgets

#Input
SOURCES+= main.cpp
SOURCES+= models/Card.cpp models/ColoredCard.cpp models/Attacker.cpp models/PlayableCard.cpp
SOURCES+= models/card_types/*.cpp
SOURCES+= widgets/Card_widget.cpp widgets/Main_Window.cpp
HEADERS+= models/Card.h models/ColoredCard.h models/Attacker.h models/PlayableCard.h
HEADERS+= models/card_types/*.h
HEADERS+= widgets/Card_widget.h widgets/Main_Window.h
RESOURCES = resources.qrc