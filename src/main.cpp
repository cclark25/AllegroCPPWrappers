#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include "./Bitmap/Bitmap.cpp"
#include "./Color/Color.cpp"


int main(int argc, char **argv) {
    al_init();
    al_init_image_addon();
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    ALLEGRO_DISPLAY *window = al_create_display(1080, 720);


    AllegroWrappers::Bitmap image("test.png");

    if(!(image.data->bitmap)) {
      std::cerr << al_path_cstr(path, '/');
      return 0;
   }
   
    al_set_target_bitmap(al_get_backbuffer(window));
    al_clear_to_color(al_map_rgb(0,255, 0));
    al_draw_bitmap_region(image.data->bitmap, 0, 0, image.get_bitmap_width()/2.0, image.get_bitmap_height(), 0, 0, 0);
    //al_draw_rotated_bitmap(image, 0, 0, 0, 0, 3.14, 0);
    std::cout << bool(al_get_new_bitmap_flags() & ALLEGRO_CONVERT_BITMAP) << "\n";

    al_flip_display();

    unsigned char r = 1;
    unsigned char g = 2;
    unsigned char b = 3;
    unsigned char a = 4;
    AllegroWrappers::Color test_color(r,g,b,a);
    
    al_unmap_rgb(test_color, &r, &g, &b);

    std::cout << "r: " << (int)test_color.r_char() << std::endl; 
    std::cout << "g: " << (int)test_color.g_char() << std::endl; 
    std::cout << "b: " << (int)test_color.b_char() << std::endl; 
    std::cout << "a: " << (int)test_color.a_char() << std::endl; 
    float z = 0;
    std::cout << "float size: " << (int)sizeof z << std::endl; 


    sleep(10);

    al_destroy_display(window);
}
