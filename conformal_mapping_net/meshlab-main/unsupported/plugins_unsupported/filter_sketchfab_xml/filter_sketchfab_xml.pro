include (../../shared.pri)

HEADERS += \
    filter_sketchfab_xml.h

SOURCES += \
    filter_sketchfab_xml.cpp \
    $$VCGDIR//wrap/ply/plylib.cpp

TARGET = filter_sketchfab_xml

include (../../shared_post.pri)
