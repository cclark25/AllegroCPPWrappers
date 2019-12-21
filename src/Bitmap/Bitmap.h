#ifndef ALLEGRO_WRAPPERS_BITMAP_DEF
#define ALLEGRO_WRAPPERS_BITMAP_DEF

#include "../Color/Color.cpp"
#include "../Transform/Transform.h"
#include <allegro5/allegro.h>
#include <string>

namespace AllegroWrappers {
	class Bitmap {
	  protected:
	  public:
		struct foreign_data {
			ALLEGRO_BITMAP *bitmap;
			unsigned int reference_count;
			Bitmap *parent;
			Transform transform, projection;
		} *data = nullptr;

		// Constructors

		Bitmap(ALLEGRO_BITMAP *base);

		// Creates new bitmap using a width and a height parameters.
		Bitmap(int width, int height);

		// Creates a bitmap that is a reference to another bitmap.
		Bitmap(Bitmap &source);

		// Load a bitmap from a file
		Bitmap(std::string file_path);

		// Object-Oriented wrapper for the al_clone_bitmap() function.
		Bitmap clone();

		// Properties
		// The Object-Oriented Wrappers for bitmap property functions.

		int get_bitmap_flags();

		int get_bitmap_format();

		int get_bitmap_height();

		int get_bitmap_width();

		// UNSTABLE
		// int get_bitmap_depth() {
		//     return al_get_bitmap_depth(data->bitmap);
		// }

		// UNSTABLE
		// int get_bitmap_samples() {
		//     return al_get_bitmap_samples(data->bitmap);
		// }

		Color get_pixel(int x, int y);

		int is_bitmap_locked();

		int is_sub_bitmap();

		Bitmap get_parent_bitmap();

		int get_bitmap_x();
		// Alias to get_bitmap_x()
		int (Bitmap::*get_x_position_in_parent)() =
		    &AllegroWrappers::Bitmap::get_bitmap_x;

		int get_bitmap_y();
		// Alias to get_bitmap_y()
		int (Bitmap::*get_y_position_in_parent)() =
		    &AllegroWrappers::Bitmap::get_bitmap_y;

		void reparent_bitmap(Bitmap parent, int x, int y, int width,
		                     int height);

		// UNSTABLE
		// void get_bitmap_blender(int *op, int *src, int *dst) {}

		// UNSTABLE
		// void get_separate_bitmap_blender(int *op, int *src, int *dst, int
		// *alpha_op, int *alpha_src, int *alpha_dst){}

		// UNSTABLE
		// ALLEGRO_COLOR get_bitmap_blend_color(void) {}

		// UNSTABLE
		// void set_bitmap_blender(int op, int src, int dest) {}

		// TODO: More Unstable functions.

		// Static functions

		static int get_new_bitmap_flags();

		static void set_new_bitmap_flags(int flags);

		static int get_new_bitmap_format();

		static void set_new_bitmap_format(int format);

		static void add_new_bitmap_flag(int flag);

		// UNSTABLE
		// static void set_new_bitmap_depth(int depth){
		//     al_set_new_bitmap_depth(depth);
		// }

		// TODO: Add more unstable static functions.

		// Drawing Operations

		void clear_to_color(Color color);

		void al_clear_depth_buffer(float z);

		void draw_bitmap(Bitmap bitmap, float destination_x,
		                 float destination_y, int flags);

		void draw_tinted_bitmap(Bitmap bitmap, Color tint, float destination_x,
		                        float destination_y, int flags);

		void draw_bitmap_region(Bitmap bitmap, float source_x, float source_y,
		                        float source_width, float source_height,
		                        float destination_x, float destination_y,
		                        int flags);

		void draw_tinted_bitmap_region(Bitmap bitmap, Color tint,
		                               float source_x, float source_y,
		                               float source_w, float source_h,
		                               float destination_x, float destination_y,
		                               int flags);

		// void draw_pixel(float x, float y, Color color) // I'm not bothering
		// to implement this because it would be very innefficient. See also
		// bitmap locks from the allegro documentation.

		void draw_rotated_bitmap(Bitmap bitmap, float center_x, float center_y,
		                         float destination_x, float destination_y,
		                         float angle_radians, int flags);

		void draw_tinted_rotated_bitmap(Bitmap bitmap, Color tint,
		                                float center_x, float center_y,
		                                float destination_x,
		                                float destination_y, float angle,
		                                int flags);

		void draw_scaled_rotated_bitmap(Bitmap bitmap, float center_x,
		                                float center_y, float destination_x,
		                                float destination_y, float xscale,
		                                float yscale, float angle, int flags);

		void draw_tinted_scaled_rotated_bitmap(Bitmap bitmap, Color tint,
		                                       float center_x, float center_y,
		                                       float destination_x,
		                                       float destination_y,
		                                       float xscale, float yscale,
		                                       float angle, int flags);

		void draw_tinted_scaled_rotated_bitmap_region(
		    Bitmap bitmap, float source_x, float source_y, float source_w,
		    float source_h, Color tint, float center_x, float center_y,
		    float destination_x, float destination_y, float xscale,
		    float yscale, float angle, int flags);

		void draw_scaled_bitmap(Bitmap bitmap, float source_x, float source_y,
		                        float source_width, float source_height,
		                        float destination_x, float destination_y,
		                        float destination_width,
		                        float destination_height, int flags);

		void draw_tinted_scaled_bitmap(Bitmap bitmap, Color tint,
		                               float source_x, float source_y,
		                               float source_w, float source_h,
		                               float destination_x, float destination_y,
		                               float destination_w, float destination_h,
		                               int flags);

		// From Transformations
		void use_transform(const Transform trans);
		const Transform get_current_transform(void);
		void use_projection_transform(const Transform transformation);
		const Transform get_current_projection_transform(void);
		// const Transform get_current_inverse_transform(void);

		// Destructor
		~Bitmap();
	};

} // namespace AllegroWrappers

#endif