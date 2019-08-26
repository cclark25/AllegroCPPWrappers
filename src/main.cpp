#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include "./Bitmap/Bitmap.cpp"
#include "./Color/Color.cpp"
#include "./Display/Display.cpp"
#include "./Events/EventQueue.cpp"
#include "./Timer/Timer.cpp"
#include <unistd.h>
#include <string>

double framerate = 90.00;

int main(int argc, char **argv) {
	al_init();
	al_init_image_addon();
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	AllegroWrappers::Bitmap backbuffer(1080, 720);
	
	AllegroWrappers::Display test_display(1080, 720);
	test_display.set_window_title("Test Window!");
	AllegroWrappers::EventQueue queue;
	AllegroWrappers::Timer timer(1.0/framerate);
	AllegroWrappers::Bitmap image("test.png");
	AllegroWrappers::EventSource source = timer.get_timer_event_source();
	queue.register_event_source(source);
	timer.start_timer();	
	double time = al_get_time();
	while(true){
		queue.await_next_event();
		test_display.get_backbuffer().draw_bitmap(image, 0, 0, 0);
		test_display.flip_display();
		std::cout << "Frame rate: " << 1.0/(al_get_time() - time) << "\n";
		time = al_get_time();
		
	}

}
