
find_package(Qt4 REQUIRED QtCore QtGui)

include( ${QT_USE_FILE} )

include_directories( ${QT_INCLUDES} ${CMAKE_BINARY_DIR} )

add_definitions( -DNDEBUG )
