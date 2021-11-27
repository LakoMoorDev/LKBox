cmake_minimum_required(VERSION 3.0.0)
project(LKBox VERSION 0.1.0)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build Shared Libraries" ON) 
#include_directories(lib/LKBox/include/LKBox)
#set (CMAKE_EXE_LINKER_FLAGS "-Wl, -allow-multiple-definition")
#Dear ImGui
set(IMGUI_DIR src/imgui)

#glfw
add_subdirectory(lib/glfw)

include_directories(lib/glfw/include)
link_directories(lib/glfw/lib)

include_directories(lib/glad/include)

#glad
add_subdirectory(lib/glad/)

#glm
add_subdirectory(lib/glm)

include_directories(lib/glm)
link_directories(lib/glm/lib)

#bullet
#add_subdirectory(lib/bullet3-2.85.1)

#include_directories(lib/bullet3-2.85.1/src)
#link_directories(lib/bullet3-2.85.1/lib)

#assimp
add_subdirectory(lib/assimp)

include_directories(lib/assimp/include)
link_directories(lib/assimp/lib)

#rapidjson
add_subdirectory(lib/rapidjson)

include_directories(lib/rapidjson/include)
link_directories(lib/rapidjson/lib)

#stb
add_subdirectory(lib/stb)

include_directories(lib/stb/include)
link_directories(lib/stb/lib)


add_library(
        LKBox
        SHARED
        src/Core/Core.cpp
        #src/Core/debug.cpp
        include/LKBox/Core.h
        src/Config/JsonParser.h
        #include/LKBox/Debug.h
        ${IMGUI_DIR}/imgui_impl_opengl3.cpp 
        ${IMGUI_DIR}/imgui_impl_glfw.cpp 
        ${IMGUI_DIR}/imgui.cpp 
        ${IMGUI_DIR}/imgui_draw.cpp 
        ${IMGUI_DIR}/imgui_demo.cpp 
        ${IMGUI_DIR}/imgui_tables.cpp 
        ${IMGUI_DIR}/imgui_widgets.cpp
)

set_target_properties(LKBox PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(LKBox PROPERTIES SOVERSION 1)

set_target_properties(LKBox PROPERTIES PUBLIC_HEADER include/LKBox/Core.h)

#install(TARGETS mylib
 #   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
 #   PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

target_link_libraries(LKBox PUBLIC glfw ${GLFW_LIBRARY} glad glm ${GLM_LIBRARY} assimp ${ASSIMP_LIBRARY} stb)