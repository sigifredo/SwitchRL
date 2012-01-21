
set(CMAKE_BUILD_TYPE Release)

# Configuración de variables para la instalación
if(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
    set(INSTALL_DIR "/usr/")
    set(SHARED_LIB LIBRARY)
elseif(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
    set(INSTALL_DIR "")
    set(SHARED_LIB RUNTIME)
endif()

if(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
    SET(QT_LIBS ${QT_LIBRARIES})
    LIST(REMOVE_ITEM QT_LIBS  "optimized" )
    LIST(REMOVE_ITEM QT_LIBS  "debug" )
    FOREACH(next_ITEM ${QT_LIBS})
        STRING(REPLACE ".a" ".dll"  QTLIB_  ${next_ITEM} )
        STRING(REPLACE "/lib/lib" "/bin/" QTLIB   ${QTLIB_} )
        LIST(APPEND QT_LIBS_TO_INSTALL ${QTLIB})
    ENDFOREACH()
endif()

#MinGW dll
IF(MINGW)
    FIND_LIBRARY(MINGW_RUNTIME_DLL "mingwm10.dll" HINTS ${CMAKE_FIND_ROOT_PATH}/sys-root/mingw/bin)
        IF(MINGW_RUNTIME_DLL)
	    INSTALL(FILES ${MINGW_RUNTIME_DLL} DESTINATION bin)
        ELSE()
            MESSAGE(SEND_ERROR "Could not find mingwm10.dll which is needed for a proper install")
        ENDIF()

        FIND_LIBRARY(MINGW_GCC_RUNTIME_DLL "libgcc_s_dw2-1.dll" HINTS ${CMAKE_FIND_ROOT_PATH}/sys-root/mingw/bin)
        IF (MINGW_GCC_RUNTIME_DLL)
            INSTALL(FILES ${MINGW_GCC_RUNTIME_DLL} DESTINATION bin)
        ELSE()
            MESSAGE(SEND_ERROR "Could not find libgcc_s_dw2-1.dll which is needed for a proper install")
	ENDIF()
ENDIF()

INSTALL(FILES ${QT_LIBS_TO_INSTALL} DESTINATION bin)

set(CPACK_PACKAGE_NAME "SwitchRL")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "")
set(CPACK_PACKAGE_VERSION "0.5.5")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "5")
set(CPACK_PACKAGE_VERSION_PATCH "5")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "WSS")

set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENCIA.txt)

set(CPACK_NSIS_MENU_LINKS "./${INSTALL_DIR}bin/SwitchRL.exe" "SwitchRL")

macro(GDINSTALL_H DIR)
  foreach(VAL ${ARGN})
    if(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
      install(FILES ${VAL} DESTINATION /usr/include/${DIR} )
    elseif(${CMAKE_HOST_SYSTEM} MATCHES "Windows")
      install(FILES ${VAL} DESTINATION include/${DIR} )
    endif()
  endforeach(VAL)
endmacro(GDINSTALL_H)
