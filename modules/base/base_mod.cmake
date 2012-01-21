set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${BASE_DIR}/include)

# add_definitions( -static )

set(HDRS
${BASE_DIR}/include/IO.hpp
)

set(MOC_HDRS
${BASE_DIR}/include/Principal.hpp
${BASE_DIR}/include/Label.hpp
)

set(SRCS
${BASE_DIR}/src/Principal.cpp
${BASE_DIR}/src/Label.cpp
${BASE_DIR}/src/IO.cpp
)

qt4_wrap_cpp(MOC_SRCS ${MOC_HDRS})

add_library(base SHARED
${HDRS}
${MOC_SRCS}
${SRCS}
)
set(WSS ${BASE_DIR}/src/main.cpp)

if(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
	LIST(APPEND WSS resources/wss.rc)
endif()

add_executable( wss WIN32 ${WSS} )

target_link_libraries( base GDGui ${QT_LIBRARIES})
target_link_libraries( wss base )

install( TARGETS wss base
         RUNTIME DESTINATION ${INSTALL_DIR}bin
         LIBRARY DESTINATION ${INSTALL_DIR}bin )
