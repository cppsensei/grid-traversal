add_executable(GridMain src/main.cpp)

target_link_libraries(GridMain PRIVATE gridtraversal)

set_target_properties(GridMain PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "$ORIGIN/../lib"
)

install(TARGETS GridMain
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
