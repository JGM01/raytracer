cmake_minimum_required(VERSION 3.19)

project(raytracer VERSION 1.0
                  DESCRIPTION "C implementation of ray tracing in a weekend."
                  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(raytracer src/main.c src/vec3.c src/ray.c)

target_include_directories(raytracer PRIVATE include)
