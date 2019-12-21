#include "./src/Bitmap/Bitmap.h"
#include "./src/Color/Color.cpp"
#include "./src/Display/Display.h"
#include "./src/Events/EventQueue.cpp"
#include "./src/Timer/Timer.cpp"
#include "./src/Transformation/Transform.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

double framerate = 90.00;

void create_display(std::string name) {
	AllegroWrappers::Display test_display(160, 90);
	for (int i = 0; i < 5; i++) {
		test_display.set_window_title(name + " " + std::to_string(i + 1));
		usleep(1000000);
	}
	usleep(1000000);
}

int main(int argc, char **argv) {
	al_init();
	al_init_image_addon();
	// ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	// std::thread t1(create_display, "Main"), t2(create_display, "Secondary");
	
	AllegroWrappers::Coordinates3D coord(0,0,0);
	for(int i = 0; i < 100000000; i++){
		AllegroWrappers::Transform t;
		t.identity_transform();
		t.translate_transform(120, 156);
		t.rotate_transform(3.14159 / 2.0);
		coord = t.transform_coordinates_3d(coord.x, coord.y, coord.z);
		//std::cout << "X: " << coord.x << "\tY: " << coord.y << "\tZ: " << coord.z << std::endl;
	}
	
}
