project ("AISD-LIST")

add_executable (AISD-LIST "src/main.cpp"  "mainlist/list.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AISD-LIST PROPERTY CXX_STANDARD 20)
endif()