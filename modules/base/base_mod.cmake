set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${BASE_DIR}/include)

FILE(STRINGS "${BASE_DIR}/include/version.hpp" SWRL_HEADER REGEX "^#define SWRL_VERSION \"[^\"]*\"$")

STRING(REGEX REPLACE "^.*SWRL_VERSION \"([0-9]+).*$" "\\1" SWRL_VERSION_MAJOR "${SWRL_HEADER}")
STRING(REGEX REPLACE "^.*SWRL_VERSION \"[0-9]+\\.([0-9]+).*$" "\\1" SWRL_VERSION_MINOR  "${SWRL_HEADER}")
STRING(REGEX REPLACE "^.*SWRL_VERSION \"[0-9]+\\.[0-9]+\\.([0-9]+).*$" "\\1" SWRL_VERSION_REV "${SWRL_HEADER}")
SET(SWRL_VERSION_STRING "${SWRL_VERSION_MAJOR}.${SWRL_VERSION_MINOR}.${SWRL_VERSION_REV}")


set(HDRS
${BASE_DIR}/include/IO.hpp
${BASE_DIR}/include/QtWin.hpp
${BASE_DIR}/include/WindowNotifier.hpp
)

set(MOC_HDRS
${BASE_DIR}/include/About.hpp
${BASE_DIR}/include/Principal.hpp
${BASE_DIR}/include/Label.hpp
)

set(SRCS
${BASE_DIR}/src/About.cpp
${BASE_DIR}/src/IO.cpp
${BASE_DIR}/src/Label.cpp
${BASE_DIR}/src/Principal.cpp
${BASE_DIR}/src/QtWin.cpp
)

qt4_wrap_cpp(MOC_SRCS ${MOC_HDRS})
qt4_add_resources( RCS_SRCS ${CMAKE_SOURCE_DIR}/resources/icons.qrc )

add_library(base SHARED
${HDRS}
${MOC_SRCS}
${SRCS}
${RCS_SRCS}
)

set(SRL ${BASE_DIR}/src/main.cpp)

if(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
	LIST(APPEND SRL resources/SwitchRL.rc)
endif()

add_executable( SwitchRL WIN32 ${SRL} )

target_link_libraries( base ${QT_LIBRARIES} )
target_link_libraries( SwitchRL base ${QT_LIBRARIES} )

SET_TARGET_PROPERTIES( base PROPERTIES VERSION ${SWRL_VERSION_STRING} )
SET_TARGET_PROPERTIES( base PROPERTIES SOVERSION ${SWRL_VERSION_MAJOR} )

install( TARGETS SwitchRL base
         RUNTIME DESTINATION ${INSTALL_DIR}bin
         LIBRARY DESTINATION ${INSTALL_DIR}bin )
