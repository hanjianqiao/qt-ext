
set(QtExtIncludeDir
	${CMAKE_CURRENT_LIST_DIR}/include/hcore
	${CMAKE_CURRENT_LIST_DIR}/include/hgui
	${CMAKE_CURRENT_LIST_DIR}/include/hwidget
	${CMAKE_CURRENT_LIST_DIR}/include/hutils
)
set(QtExtLinkDir "${CMAKE_CURRENT_LIST_DIR}")
	
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(QtExtLibs hcored hguid hwidgetd hutilsd)
else()
    set(QtExtLibs hcore hgui hwidget hutils)
endif()
