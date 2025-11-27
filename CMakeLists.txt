cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME_VAR ray_tracer)
project(abstraction)

# Create the executable from the src
add_executable(${PROJECT_NAME_VAR}
    src/main.cpp
    src/vector2/vector2.cpp
    src/vector3/vector3.cpp
    src/rgb/rgb.cpp
    src/image/image.cpp
    src/ray/ray.cpp
    src/surface/surface.cpp
    src/sphere/sphere.cpp
    src/camera/camera.cpp
    src/surface_group/surface_group.cpp
    src/renderer/renderer.cpp
    src/hit_record/hit_record.h
)
