set(GUI_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${GUI_DIR}/include)

set( GUI_HDRS
${GUI_DIR}/include/GUIExport.hpp
${GUI_DIR}/include/GUIWindowNotifier.hpp
${GUI_DIR}/include/GUIQtWin.hpp
)

set( GUI_MOC_HDRS
${GUI_DIR}/include/GUIAbout.hpp
)

set( GUI_SRCS
${GUI_DIR}/src/GUIAbout.cpp
${GUI_DIR}/src/GUIQtWin.cpp
)

set( GUI_RCS
${CMAKE_SOURCE_DIR}/resources/icons.qrc
)

qt4_wrap_cpp( GUI_MOC_SRCS ${GUI_MOC_HDRS} )
qt4_add_resources( GUI_RCS_SRCS ${GUI_RCS} )

set(GUI ${GUI_HDRS} ${GUI_MOC_SRCS} ${GUI_SRCS} ${GUI_RCS_SRCS})

add_library( GDGui SHARED ${GUI} )

target_link_libraries(GDGui ${QT_LIBRARIES})

install( TARGETS GDGui
         ${SHARED_LIB} DESTINATION ${INSTALL_DIR}bin )

# GDINSTALL_H( "Gui" ${GUI_HDRS} ${GUI_MOC_HDRS} )
