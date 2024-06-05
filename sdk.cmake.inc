
set(QtExtIncludeDir
        ${CMAKE_CURRENT_LIST_DIR}/sdk/include
)
set(QtExtLinkDir "${CMAKE_CURRENT_LIST_DIR}/sdk")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(QtExtLibs hcored hguid hwidgetd hvisiond)
else()
    set(QtExtLibs hcore hgui hwidget hvision)
endif()
