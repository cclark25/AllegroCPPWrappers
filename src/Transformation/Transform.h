#include <allegro5/allegro.h>

namespace AllegroWrappers {
	struct Coordinates {
		float x;
		float y;
	};
	struct Coordinates3D : Coordinates {
		float z;
	};
	struct Coordinates4D : Coordinates3D {
		float w;
	};
	
	class Transform {
	  protected:
	  public:
		struct foreign_data {
			ALLEGRO_TRANSFORM *transform;
			unsigned int reference_count;
		} *data = nullptr;

		// Constructors

		// Warning: This constructor is to wrap existing ALLEGRO_TRANSFORM
		// objects in the class wrapper. It will not manage the memory that the
		// original object was held in.
		Transform(ALLEGRO_TRANSFORM *base);

		Transform();

		Transform(Transform &source);

		Transform copy_transform();

		void invert_transform();
		void transpose_transform();
		bool check_inverse(float tolerance);
		void identity_transform();
		void build_transform(float xTranslation, float yTranslation,
		                     float xScale, float yScale, float rotation);
		// Places camera at "position", looks toward direction of point "lool",
		// and orients itself using "up" to detemine which way should be up.
		void build_camera_transform(float position_x, float position_y,
		                            float position_z, float lookDir_x,
		                            float look_y, float look_z, float up_x,
		                            float up_y, float up_z);
		void translate_transform(float horizontal, float vertical);
		void rotate_transform(float angle);
		void scale_transform(float xScale, float yScale);
		// Use this Transform to transform to transform 2D coordinates.
		Coordinates transform_coordinates(float x, float y);
		// Use this Transform to transform to transform 3D coordinates.
		Coordinates3D transform_coordinates_3d(float x, float y, float z);
		// Use this Transform to transform to transform 4D coordinates.
		Coordinates4D transform_coordinates_4d(float x, float y, float z, float w);
		void al_transform_coordinates_3d_projective();
		void al_compose_transform();
		void al_orthographic_transform();
		void al_perspective_transform();
		void al_translate_transform_3d();
		void al_scale_transform_3d();
		void al_rotate_transform_3d();
		void al_horizontal_shear_transform();
		void al_vertical_shear_transform();
	};
} // namespace AllegroWrappers