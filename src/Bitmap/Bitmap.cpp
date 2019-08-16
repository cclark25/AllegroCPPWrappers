#include <allegro5/allegro.h>
#include <string>

namespace AllegroWrappers {
    class Bitmap {
        public:
            struct foreign_data {
                ALLEGRO_BITMAP* bitmap;
                unsigned int reference_count;
                Bitmap* parent ;
            } *data = nullptr;

            Bitmap(ALLEGRO_BITMAP *base){
                data = new foreign_data();
                data->reference_count = 1;
                data->bitmap = base;
            }

        public:
            // Constructors


            // Creates new bitmap using a width and a height parameters.
            Bitmap(int width, int height){
                data = new foreign_data();
                data->bitmap = al_create_bitmap(width, height);
                data->reference_count = 1;
            }

            // Creates a bitmap that is a reference to another bitmap.
            Bitmap(Bitmap &source){
                data = source.data;
                data->reference_count++;
            }

            Bitmap(std::string file_path){
                data = new foreign_data();
                data->bitmap = al_load_bitmap(file_path.c_str());
                data->reference_count = 1;
            }

            // Object-Oriented wrapper for the al_clone_bitmap() function.
            Bitmap clone(){
                ALLEGRO_BITMAP* base = al_clone_bitmap(data->bitmap);
                Bitmap result(base);
                return result;
            }




            // Properties
            // The Object-Oriented Wrappers for bitmap property functions.

            int get_bitmap_flags() { 
                return al_get_bitmap_flags(data->bitmap);
            }

            int get_bitmap_format() { 
                return al_get_bitmap_format(data->bitmap);
            }

            int get_bitmap_height() { 
                return al_get_bitmap_height(data->bitmap);
            }

            int get_bitmap_width() { 
                return al_get_bitmap_width(data->bitmap);
            }

            // UNSTABLE 
            // int get_bitmap_depth() { 
            //     return al_get_bitmap_depth(data->bitmap);
            // }

            // UNSTABLE
            // int get_bitmap_samples() { 
            //     return al_get_bitmap_samples(data->bitmap);
            // }

            ALLEGRO_COLOR get_pixel(int x, int y) { 
                return al_get_pixel(data->bitmap, x, y);
            }

            int is_bitmap_locked() { 
                return al_is_bitmap_locked(data->bitmap);
            }

            int is_sub_bitmap() { 
                return al_is_sub_bitmap(data->bitmap);
            }

            Bitmap get_parent_bitmap() { 
                return *(data->parent);
            }

            int get_bitmap_x() { 
                return al_get_bitmap_x(data->bitmap);
            }
            int get_x_position_in_parent(){     // Alias
                return get_bitmap_x();
            } 

            int get_bitmap_y() { 
                return al_get_bitmap_x(data->bitmap);
            }
            int get_y_position_in_parent(){     // Alias
                return get_bitmap_y();
            } 

            void reparent_bitmap(Bitmap parent, int x, int y, int width, int height){
                al_reparent_bitmap(data->bitmap, parent.data->bitmap, x, y, width, height);
                data->parent = &parent;
            }

            // UNSTABLE
            // void get_bitmap_blender(int *op, int *src, int *dst) {}

            // UNSTABLE
            // void get_separate_bitmap_blender(int *op, int *src, int *dst, int *alpha_op, int *alpha_src, int *alpha_dst){}

            // UNSTABLE
            // ALLEGRO_COLOR get_bitmap_blend_color(void) {}

            // UNSTABLE 
            // void set_bitmap_blender(int op, int src, int dest) {}

            // TODO: More Unstable functions. 



            // Static functions

            static int get_new_bitmap_flags(){
                return al_get_new_bitmap_flags();
            }

            static void set_new_bitmap_flags(int flags){
                return al_set_new_bitmap_flags(flags);
            }

            static int get_new_bitmap_format(){
                return al_get_new_bitmap_format();
            }

            static void set_new_bitmap_format(int format){
                return al_set_new_bitmap_format(format);
            }

            static void add_new_bitmap_flag(int flag){
                return al_add_new_bitmap_flag(flag);
            }

            // UNSTABLE
            // static void set_new_bitmap_depth(int depth){
            //     al_set_new_bitmap_depth(depth);
            // }

            // TODO: Add more unstable static functions.




            // Destructor
            ~Bitmap(){
                data->reference_count--;
                if(data->reference_count == 0){
                    al_destroy_bitmap(data->bitmap);
                    delete data; 
                }
            }
    };

}