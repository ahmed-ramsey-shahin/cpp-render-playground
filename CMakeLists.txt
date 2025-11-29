cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME_VAR ray_tracer)
project(abstraction)

# Create the executable from the src
add_executable(${PROJECT_NAME_VAR}
    src/HitRecord/HitRecord.h
    src/main.cpp
    src/AmbientLight/AmbientLight.cpp
    src/Camera/Camera.cpp
    src/Image/Image.cpp
    src/Light/Light.cpp
    src/Material/Material.cpp
    src/PointLight/PointLight.cpp
    src/Ray/Ray.cpp
    src/Renderer/Renderer.cpp
    src/RGB/RGB.cpp
    src/Scene/Scene.cpp
    src/Sphere/Sphere.cpp
    src/Surface/Surface.cpp
    src/SurfaceGroup/SurfaceGroup.cpp
    src/Triangle/Triangle.cpp
    src/Vector2/Vector2.cpp
    src/Vector3/Vector3.cpp
    src/IdealDiffuseMaterial/IdealDiffuseMaterial.cpp
)
