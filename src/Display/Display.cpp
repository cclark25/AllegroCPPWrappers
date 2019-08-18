#ifndef ALLEGRO_WRAPPERS_DISPLAY_DEF
#define ALLEGRO_WRAPPERS_DISPLAY_DEF
#include <allegro5/allegro.h>
#include "../Bitmap/Bitmap.cpp"
#include <stdexcept>

namespace AllegroWrappers {
	class Display {
		private:
			// TODO: convert this into a function that takes the current thread and sees if there is already a display on this thread.
			static bool exists_on_thread; 
		protected:
			Bitmap *backbuffer = nullptr;
		public:
			struct foreign_data {
				ALLEGRO_DISPLAY* display;
				unsigned int reference_count;
			} *data = nullptr;

			// Constructors

			Display(int width, int height){
				// Ensures there is only ever one Display on the thread. This is necessary as there is no way to set the current display of the thread.
				// For now it is just a boolean, but in the future it will be a function taking a thread pointer so that separate threads can have their own Displays.
				if(Display::exists_on_thread){
					throw std::logic_error("Tried to create new Display when one already exists on thread!");
				}
				data = new foreign_data();
				data->display = al_create_display(width, height);
				data->reference_count = 1;
				backbuffer = new Bitmap(al_get_backbuffer(data->display));
				Display::exists_on_thread = true;
			}

			Display(Display &origin): backbuffer(origin.backbuffer){
				data = origin.data;
				data->reference_count++;
			}

			// Backbuffer retreiver

			Bitmap get_backbuffer(){
				return *backbuffer;
			}


			// Member functions
			void flip_display(void){
				al_flip_display();
			}



			// Destructor
			~Display(){
				data->reference_count--;
				if(data->reference_count == 0){
					al_destroy_display(data->display);
					delete data; 
				}
			}
	};


	bool Display::exists_on_thread = false;
}

#endif