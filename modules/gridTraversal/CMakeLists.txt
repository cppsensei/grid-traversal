set(LIBRARY_NAME gridtraversal)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(gridtraversal SHARED
    ${PROJECT_SOURCE_DIR}/Grid.cpp
    ${PROJECT_SOURCE_DIR}/GridImpl.cpp
)

target_include_directories(gridtraversal PUBLIC include PRIVATE headers)

if(BUILD_TESTING)
    add_subdirectory(tst)
endif()

install(TARGETS gridtraversal
    EXPORT gridtraversalTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
