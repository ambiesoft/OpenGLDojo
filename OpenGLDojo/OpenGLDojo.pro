TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    G:\vcpkg\packages\freeglut_x86-windows\include

SOURCES += \
    Ball.cpp \
    OpenGLDojo.cpp \
    Rect.cpp \
    font.cpp

HEADERS += \
    Ball.h \
    Rect.h \
    font.h

message($$QMAKESPEC)
win32 {
    message("win32")

    win32-g++ {
        message("win32-g++")
        Debug::LIBS += -LG:/vcpkg/packages/freeglut_x86-windows/debug/lib/ -lfreeglutd
        LIBS += -lopengl32 -lGlu32
    }
    win32-msvc* {
        message("win32-msvc*")
        Debug::LIBS += G:/vcpkg/packages/freeglut_x86-windows/debug/lib/freeglutd.lib
        Release::LIBS += G:/vcpkg/packages/freeglut_x86-windows/lib/freeglut.lib

# not work for "add build library search path to PATH"
#        LD_LIBRARY_PATH = G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        DT_RPATH = G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        RPATH = G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        RUNPATH = G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        LIBPATH = G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        LIBS += G:/vcpkg/packages/freeglut_x86-windows/debug/bin
#        INCLUDEPATH += G:/vcpkg/packages/freeglut_x86-windows/debug/bin

    }

}
