set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${BASE_DIR}/include)

# add_definitions( -static )

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

target_link_libraries( base ${QT_LIBRARIES})
target_link_libraries( SwitchRL base )

install( TARGETS SwitchRL base
         RUNTIME DESTINATION ${INSTALL_DIR}bin
         LIBRARY DESTINATION ${INSTALL_DIR}bin )
