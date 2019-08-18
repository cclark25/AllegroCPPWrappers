#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include "./Bitmap/Bitmap.cpp"
#include "./Color/Color.cpp"
#include "./Display/Display.cpp"
#include <unistd.h>

int main(int argc, char **argv) {
	al_init();
	al_init_image_addon();
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	//ALLEGRO_DISPLAY *window = al_create_display(1080, 720);
	AllegroWrappers::Bitmap backbuffer(1080, 720);
	
	AllegroWrappers::Display test_display(1080, 720);

	AllegroWrappers::Bitmap image("test.png");

	test_display.get_backbuffer().draw_bitmap(image, 0, 0, 0);
	test_display.flip_display();

	usleep(5000000);
}
