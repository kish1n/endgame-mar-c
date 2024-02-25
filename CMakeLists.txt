cmake_minimum_required(VERSION 3.27)
project(endgame C)

set(CMAKE_C_STANDARD 11)

include_directories(resource)
include_directories(src)

link_directories(resource/SDL2-2.30.0/lib/x64)

add_executable(endgame
        resource/header.h
        src/entities/main_hero.c
        src/entities/room_build.c
        src/errs/sdl_init.c
        src/errs/sdl_window.c
        src/errs/sdl_render.c
        src/mechanics/update_hero.c
        src/render/render_hero.c
        src/render/render_room.c
        src/main.c
        src/render/render_main.c
        src/mechanics/check_collision.c)

target_link_libraries(endgame SDL2)