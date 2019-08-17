#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 
#include "./Bitmap/Bitmap.cpp"
#include "./Color/Color.cpp"
#include <unistd.h>

int main(int argc, char **argv) {
	al_init();
	al_init_image_addon();
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	ALLEGRO_DISPLAY *window = al_create_display(1080, 720);
	AllegroWrappers::Bitmap backbuffer(1080, 720);


	AllegroWrappers::Bitmap image("test.png");

	if(!(image.data->bitmap)) {
	  std::cerr << al_path_cstr(path, '/');
	  return 0;
   	}
	al_set_target_backbuffer(window);

	int frame = 0;
	double time = 0;
	float rot_per_sec = (3.1415/6.0);
	double frame_per_sec = 10;
	while(true){
			std::cout << time << std::endl;
		backbuffer.clear_to_color(AllegroWrappers::Color((unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0));
		backbuffer.draw_scaled_rotated_bitmap(image, image.get_bitmap_width(), image.get_bitmap_height(), 540, 360, (int(al_get_time())%int(frame_per_sec) + 1)/frame_per_sec, (int(al_get_time())%int(frame_per_sec) + 1)/frame_per_sec, rot_per_sec*al_get_time(), 0);
		al_set_target_backbuffer(window);
		al_clear_to_color(al_map_rgb(0,0,0));

		al_draw_bitmap(backbuffer.data->bitmap, 0, 0, 0);

		al_flip_display();

		frame++;
		int x = 1000000.0/frame_per_sec;
		usleep(x);
		time += 1.0/frame_per_sec;
	}

	al_destroy_display(window);
}
