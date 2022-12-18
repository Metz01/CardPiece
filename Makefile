#############################################################################
# Makefile for building: main
# Generated by qmake (3.1) (Qt 6.4.1)
# Project:  OpDeckBuilder.pro
# Template: app
# Command: /usr/bin/qmake6 -o Makefile OpDeckBuilder.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -fPIC -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -Wextra -fPIC -D_REENTRANT $(DEFINES)
INCPATH       = -I. -I. -I/usr/include/qt6 -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui -I/usr/include/qt6/QtCore -I. -I/usr/lib/qt6/mkspecs/linux-g++
QMAKE         = /usr/bin/qmake6
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/bin/qmake6 -install qinstall
QINSTALL_PROGRAM = /usr/bin/qmake6 -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = main1.0.0
DISTDIR = /home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder/build/main1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/lib -Wl,-rpath-link,/usr/lib
LIBS          = $(SUBLIBS) /usr/lib/libQt6Widgets.so /usr/lib/libQt6Gui.so /usr/lib/libGLX.so /usr/lib/libOpenGL.so /usr/lib/libQt6Core.so -lpthread -lGLX -lOpenGL   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = main.cpp \
		models/card/Card.cpp \
		models/card/ColoredCard.cpp \
		models/card/Attacker.cpp \
		models/card/PlayableCard.cpp \
		models/card/card_types/Character.cpp \
		models/card/card_types/Don.cpp \
		models/card/card_types/Leader.cpp \
		utils/database_helper.cpp \
		utils/Enums.cpp \
		utils/JsonParser.cpp \
		widgets/Card_widget.cpp \
		widgets/Main_window.cpp qrc_resources.cpp \
		moc_Card_widget.cpp \
		moc_Main_window.cpp
OBJECTS       = build/main.o \
		build/Card.o \
		build/ColoredCard.o \
		build/Attacker.o \
		build/PlayableCard.o \
		build/Character.o \
		build/Don.o \
		build/Leader.o \
		build/database_helper.o \
		build/Enums.o \
		build/JsonParser.o \
		build/Card_widget.o \
		build/Main_window.o \
		build/qrc_resources.o \
		build/moc_Card_widget.o \
		build/moc_Main_window.o
DIST          = /usr/lib/qt6/mkspecs/features/spec_pre.prf \
		/usr/lib/qt6/mkspecs/common/unix.conf \
		/usr/lib/qt6/mkspecs/common/linux.conf \
		/usr/lib/qt6/mkspecs/common/sanitize.conf \
		/usr/lib/qt6/mkspecs/common/gcc-base.conf \
		/usr/lib/qt6/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt6/mkspecs/common/g++-base.conf \
		/usr/lib/qt6/mkspecs/common/g++-unix.conf \
		/usr/lib/qt6/mkspecs/qconfig.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_gbm_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt6/mkspecs/features/qt_functions.prf \
		/usr/lib/qt6/mkspecs/features/qt_config.prf \
		/usr/lib/qt6/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt6/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt6/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt6/mkspecs/features/toolchain.prf \
		/usr/lib/qt6/mkspecs/features/default_pre.prf \
		/usr/lib/qt6/mkspecs/features/resolve_config.prf \
		/usr/lib/qt6/mkspecs/features/default_post.prf \
		/usr/lib/qt6/mkspecs/features/warn_on.prf \
		/usr/lib/qt6/mkspecs/features/qt.prf \
		/usr/lib/qt6/mkspecs/features/resources_functions.prf \
		/usr/lib/qt6/mkspecs/features/resources.prf \
		/usr/lib/qt6/mkspecs/features/moc.prf \
		/usr/lib/qt6/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt6/mkspecs/features/uic.prf \
		/usr/lib/qt6/mkspecs/features/unix/thread.prf \
		/usr/lib/qt6/mkspecs/features/qmake_use.prf \
		/usr/lib/qt6/mkspecs/features/file_copies.prf \
		/usr/lib/qt6/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt6/mkspecs/features/exceptions.prf \
		/usr/lib/qt6/mkspecs/features/yacc.prf \
		/usr/lib/qt6/mkspecs/features/lex.prf \
		OpDeckBuilder.pro models/card/Card.h \
		models/card/ColoredCard.h \
		models/card/Attacker.h \
		models/card/PlayableCard.h \
		models/card/card_types/CardTypes.h \
		models/card/card_types/Character.h \
		models/card/card_types/Don.h \
		models/card/card_types/Leader.h \
		widgets/Card_widget.h \
		widgets/Main_window.h \
		utils/Constants.h \
		utils/database_helper.h \
		utils/Enums.h \
		utils/JsonParser.h main.cpp \
		models/card/Card.cpp \
		models/card/ColoredCard.cpp \
		models/card/Attacker.cpp \
		models/card/PlayableCard.cpp \
		models/card/card_types/Character.cpp \
		models/card/card_types/Don.cpp \
		models/card/card_types/Leader.cpp \
		utils/database_helper.cpp \
		utils/Enums.cpp \
		utils/JsonParser.cpp \
		widgets/Card_widget.cpp \
		widgets/Main_window.cpp
QMAKE_TARGET  = main
DESTDIR       = 
TARGET        = main


first: all
####### Build rules

main:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET)  $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: OpDeckBuilder.pro /usr/lib/qt6/mkspecs/linux-g++/qmake.conf /usr/lib/qt6/mkspecs/features/spec_pre.prf \
		/usr/lib/qt6/mkspecs/common/unix.conf \
		/usr/lib/qt6/mkspecs/common/linux.conf \
		/usr/lib/qt6/mkspecs/common/sanitize.conf \
		/usr/lib/qt6/mkspecs/common/gcc-base.conf \
		/usr/lib/qt6/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt6/mkspecs/common/g++-base.conf \
		/usr/lib/qt6/mkspecs/common/g++-unix.conf \
		/usr/lib/qt6/mkspecs/qconfig.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_gbm_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt6/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt6/mkspecs/features/qt_functions.prf \
		/usr/lib/qt6/mkspecs/features/qt_config.prf \
		/usr/lib/qt6/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt6/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt6/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt6/mkspecs/features/toolchain.prf \
		/usr/lib/qt6/mkspecs/features/default_pre.prf \
		/usr/lib/qt6/mkspecs/features/resolve_config.prf \
		/usr/lib/qt6/mkspecs/features/default_post.prf \
		/usr/lib/qt6/mkspecs/features/warn_on.prf \
		/usr/lib/qt6/mkspecs/features/qt.prf \
		/usr/lib/qt6/mkspecs/features/resources_functions.prf \
		/usr/lib/qt6/mkspecs/features/resources.prf \
		/usr/lib/qt6/mkspecs/features/moc.prf \
		/usr/lib/qt6/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt6/mkspecs/features/uic.prf \
		/usr/lib/qt6/mkspecs/features/unix/thread.prf \
		/usr/lib/qt6/mkspecs/features/qmake_use.prf \
		/usr/lib/qt6/mkspecs/features/file_copies.prf \
		/usr/lib/qt6/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt6/mkspecs/features/exceptions.prf \
		/usr/lib/qt6/mkspecs/features/yacc.prf \
		/usr/lib/qt6/mkspecs/features/lex.prf \
		OpDeckBuilder.pro \
		resources.qrc \
		/usr/lib/libQt6Widgets.prl \
		/usr/lib/libQt6Gui.prl \
		/usr/lib/libQt6Core.prl
	$(QMAKE) -o Makefile OpDeckBuilder.pro
/usr/lib/qt6/mkspecs/features/spec_pre.prf:
/usr/lib/qt6/mkspecs/common/unix.conf:
/usr/lib/qt6/mkspecs/common/linux.conf:
/usr/lib/qt6/mkspecs/common/sanitize.conf:
/usr/lib/qt6/mkspecs/common/gcc-base.conf:
/usr/lib/qt6/mkspecs/common/gcc-base-unix.conf:
/usr/lib/qt6/mkspecs/common/g++-base.conf:
/usr/lib/qt6/mkspecs/common/g++-unix.conf:
/usr/lib/qt6/mkspecs/qconfig.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_gbm_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_openglwidgets_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt6/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt6/mkspecs/features/qt_functions.prf:
/usr/lib/qt6/mkspecs/features/qt_config.prf:
/usr/lib/qt6/mkspecs/linux-g++/qmake.conf:
/usr/lib/qt6/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/qt6/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt6/mkspecs/features/toolchain.prf:
/usr/lib/qt6/mkspecs/features/default_pre.prf:
/usr/lib/qt6/mkspecs/features/resolve_config.prf:
/usr/lib/qt6/mkspecs/features/default_post.prf:
/usr/lib/qt6/mkspecs/features/warn_on.prf:
/usr/lib/qt6/mkspecs/features/qt.prf:
/usr/lib/qt6/mkspecs/features/resources_functions.prf:
/usr/lib/qt6/mkspecs/features/resources.prf:
/usr/lib/qt6/mkspecs/features/moc.prf:
/usr/lib/qt6/mkspecs/features/unix/opengl.prf:
/usr/lib/qt6/mkspecs/features/uic.prf:
/usr/lib/qt6/mkspecs/features/unix/thread.prf:
/usr/lib/qt6/mkspecs/features/qmake_use.prf:
/usr/lib/qt6/mkspecs/features/file_copies.prf:
/usr/lib/qt6/mkspecs/features/testcase_targets.prf:
/usr/lib/qt6/mkspecs/features/exceptions.prf:
/usr/lib/qt6/mkspecs/features/yacc.prf:
/usr/lib/qt6/mkspecs/features/lex.prf:
OpDeckBuilder.pro:
resources.qrc:
/usr/lib/libQt6Widgets.prl:
/usr/lib/libQt6Gui.prl:
/usr/lib/libQt6Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile OpDeckBuilder.pro

qmake_all: FORCE


all: Makefile main

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents resources.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/qt6/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents models/card/Card.h models/card/ColoredCard.h models/card/Attacker.h models/card/PlayableCard.h models/card/card_types/CardTypes.h models/card/card_types/Character.h models/card/card_types/Don.h models/card/card_types/Leader.h widgets/Card_widget.h widgets/Main_window.h utils/Constants.h utils/database_helper.h utils/Enums.h utils/JsonParser.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp models/card/Card.cpp models/card/ColoredCard.cpp models/card/Attacker.cpp models/card/PlayableCard.cpp models/card/card_types/Character.cpp models/card/card_types/Don.cpp models/card/card_types/Leader.cpp utils/database_helper.cpp utils/Enums.cpp utils/JsonParser.cpp widgets/Card_widget.cpp widgets/Main_window.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		/usr/lib/qt6/rcc \
		assets/OP01-006.png
	/usr/lib/qt6/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/qt6/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -Wextra -fPIC -dM -E -o moc_predefs.h /usr/lib/qt6/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_Card_widget.cpp moc_Main_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Card_widget.cpp moc_Main_window.cpp
moc_Card_widget.cpp: widgets/Card_widget.h \
		moc_predefs.h \
		/usr/lib/qt6/moc
	/usr/lib/qt6/moc $(DEFINES) --include /home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder/moc_predefs.h -I/usr/lib/qt6/mkspecs/linux-g++ -I/home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder -I/home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder -I/usr/include/qt6 -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui -I/usr/include/qt6/QtCore -I/usr/include/c++/12.2.0 -I/usr/include/c++/12.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/12.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include-fixed -I/usr/include widgets/Card_widget.h -o moc_Card_widget.cpp

moc_Main_window.cpp: widgets/Main_window.h \
		moc_predefs.h \
		/usr/lib/qt6/moc
	/usr/lib/qt6/moc $(DEFINES) --include /home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder/moc_predefs.h -I/usr/lib/qt6/mkspecs/linux-g++ -I/home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder -I/home/metz/it/projects/cpp/qt/OPDeckBuilder/OpDeckBuilder -I/usr/include/qt6 -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtGui -I/usr/include/qt6/QtCore -I/usr/include/c++/12.2.0 -I/usr/include/c++/12.2.0/x86_64-pc-linux-gnu -I/usr/include/c++/12.2.0/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include-fixed -I/usr/include widgets/Main_window.h -o moc_Main_window.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

build/main.o: main.cpp widgets/Main_window.h \
		models/card/card_types/Leader.h \
		models/card/Attacker.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h \
		utils/database_helper.h \
		models/card/card_types/CardTypes.h \
		models/card/card_types/Character.h \
		models/card/PlayableCard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o main.cpp

build/Card.o: models/card/Card.cpp models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Card.o models/card/Card.cpp

build/ColoredCard.o: models/card/ColoredCard.cpp models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/ColoredCard.o models/card/ColoredCard.cpp

build/Attacker.o: models/card/Attacker.cpp models/card/Attacker.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Attacker.o models/card/Attacker.cpp

build/PlayableCard.o: models/card/PlayableCard.cpp models/card/PlayableCard.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/PlayableCard.o models/card/PlayableCard.cpp

build/Character.o: models/card/card_types/Character.cpp models/card/card_types/Character.h \
		models/card/Attacker.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h \
		models/card/PlayableCard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Character.o models/card/card_types/Character.cpp

build/Don.o: models/card/card_types/Don.cpp models/card/card_types/Don.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Don.o models/card/card_types/Don.cpp

build/Leader.o: models/card/card_types/Leader.cpp models/card/card_types/Leader.h \
		models/card/Attacker.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Leader.o models/card/card_types/Leader.cpp

build/database_helper.o: utils/database_helper.cpp utils/database_helper.h \
		models/card/card_types/CardTypes.h \
		models/card/card_types/Character.h \
		models/card/Attacker.h \
		models/card/ColoredCard.h \
		models/card/Card.h \
		utils/JsonParser.h \
		utils/Constants.h \
		utils/Enums.h \
		models/card/PlayableCard.h \
		models/card/card_types/Leader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/database_helper.o utils/database_helper.cpp

build/Enums.o: utils/Enums.cpp utils/Enums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Enums.o utils/Enums.cpp

build/JsonParser.o: utils/JsonParser.cpp utils/JsonParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/JsonParser.o utils/JsonParser.cpp

build/Card_widget.o: widgets/Card_widget.cpp widgets/Card_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Card_widget.o widgets/Card_widget.cpp

build/Main_window.o: widgets/Main_window.cpp widgets/Main_window.h \
		widgets/Card_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Main_window.o widgets/Main_window.cpp

build/qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_resources.o qrc_resources.cpp

build/moc_Card_widget.o: moc_Card_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_Card_widget.o moc_Card_widget.cpp

build/moc_Main_window.o: moc_Main_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_Main_window.o moc_Main_window.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

.SUFFIXES:

