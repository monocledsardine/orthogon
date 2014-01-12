find_library(ORTHO_LIB REQUIRED)

add_executable(test Game_Test.cpp Test.cpp Suite.cpp)
target_link_libraries(test ORTHO_LIB ${SFML_LIBRARIES})
install(TARGETS test DESTINATION .)