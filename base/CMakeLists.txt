project(base)

find_package(OpenGL REQUIRED)


add_library(base include/base/glwindow.h src/glwindow.cc)

target_compile_definitions(base
    PUBLIC
      _CRT_SECURE_NO_WARNINGS
      GLFW_INCLUDE_NONE
    PUBLIC
      $<$<CONFIG:Debug>:GL_BASE_DEBUG>
      $<$<CONFIG:RelWithDebInfo>:GL_BASE_DEBUG>
      $<$<CONFIG:Release>:GL_BASE_RELEASE>
      $<$<CONFIG:MinSizeRel>:GL_BASE_RELEASE>
)

target_include_directories(base PUBLIC ${CMAKE_SOURCE_DIR}/base/include PRIVATE ${CMAKE_SOURCE_DIR}/third_party/glfw3/include)

target_link_libraries(base glad glfw OpenGL::GL)