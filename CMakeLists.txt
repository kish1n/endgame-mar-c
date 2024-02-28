cmake_minimum_required(VERSION 3.27)
project(endgame C)

set(CMAKE_C_STANDARD 11)

include_directories(resource)
include_directories(src)

link_directories(resource/SDL2-2.30.0/lib/x64)
link_directories(resource/SDL2_image-2.8.2/lib/x64)
link_directories(resource/SDL2_mixer-2.8.0/lib/x64)
link_directories(resource/SDL2_ttf-2.22.0/lib/x64)


add_executable(endgame
        resource/header.h
        src/main.c

        src/start_game.c
        src/errs/sdl_init.c
        src/errs/sdl_window.c
        src/errs/sdl_render.c

        src/graphics/load_texture.c
        src/graphics/load_sound.c
        src/graphics/play_sound.c

        src/mechanics/update_hero.c
        src/mechanics/check_collision.c

        src/menu/handle_mouse_button_down.c
        src/menu/init_texture_menu.c
        src/menu/menu_main.c
        src/menu/play_click_sound.c
        src/menu/win_buildFHD.c
        src/menu/win_buildHD.c
        src/menu/win_buildNHD.c
        src/menu/init_texture_menuInGame.c
        src/menu/win_build_Settings.c
        src/menu/win_buildMenuButtons.c

        src/render/render_hero.c
        src/render/render_main.c
        src/render/render_bg.c
        src/render/render_button.c
        src/render/render_all_room.c
        src/render/render_obj.c

        src/entities/room_build.c
        src/entities/init_room.c
        src/entities/board_build.c

        src/entities/objects/first_room/open_book.c
        src/render/ingame_menu_esc_render.c
        src/menu/ingame_main_menu_set.c
        src/menu/ingame_voice_menu_set.c
        src/entities/handle_mouse_click_for_objects.c
        src/entities/nuul_obj.c
        src/mechanics/main_event_handler.c
        src/entities/init_arr4room_1.c
        src/mechanics/game_cutscene.c
        src/entities/door_create.c
        src/render/render_door.c
        src/render/render_room.c
)


target_link_libraries(endgame SDL2 SDL2_ttf SDL2_mixer SDL2_image)