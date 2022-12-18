######################################################################
# Automatically generated by qmake (3.1) Sat Dec 10 19:09:38 2022
######################################################################

OBJECTS_DIR = build/

TEMPLATE = app
TARGET = main
INCLUDEPATH += .
QT += widgets

#Input
SOURCES+= main.cpp
SOURCES+= models/card/Card.cpp models/card/ColoredCard.cpp models/card/Attacker.cpp models/card/PlayableCard.cpp
SOURCES+= models/card/card_types/*.cpp
SOURCES+= utils/*.cpp
SOURCES+= widgets/Card_widget.cpp widgets/Main_Window.cpp
HEADERS+= models/card/Card.h models/card/ColoredCard.h models/card/Attacker.h models/card/PlayableCard.h
HEADERS+= models/card/card_types/*.h
HEADERS+= widgets/Card_widget.h widgets/Main_Window.h
HEADERS+= utils/*.h
RESOURCES = resources.qrc