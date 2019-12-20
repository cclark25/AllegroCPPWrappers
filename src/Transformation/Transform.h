#ifndef ALLEGRO_WRAPPERS_TRANSFORM_DEF
#define ALLEGRO_WRAPPERS_TRANSFORM_DEF
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
		Coordinates4D transform_coordinates_4d(float x, float y, float z,
		                                       float w);

		Coordinates3D _transform_coordinates_3d_projective(float x, float y,
		                                                   float z);
		// Apply another transform to this one
		void compose_transform(Transform transformation);

		/*
		    Combines the given transformation with an orthographic
		   transformation which maps the screen rectangle to the given left/top
		   and right/bottom coordinates. near/far is the z range, coordinates
		   outside of that range will get clipped.
		*/
		void orthographic_transform(float left, float top, float right,
		                            float bottom, float near, float far);

		/*
		    Like al_orthographic_transform but honors perspective. If everything
		   is at a z-position of -near it will look the same as with an
		   orthographic transformation.
		*/
		void perspective_transform(float left, float top, float right,
		                           float bottom, float near, float far);
		/*
		    Combines the given transformation with a transformation which
		    translates coordinates by the given vector.
		*/
		void translate_transform_3d(float x, float y);
		/*
		    Combines the given transformation with a transformation which scales
		   coordinates by the given vector.
		*/
		void scale_transform_3d(float xScale, float yScale, float zScale);
		/*
		    Combines the given transformation with a transformation which
		   rotates coordinates around the given vector by the given angle in
		   radians. Note: The vector is assumed to be of unit length (otherwise
		   it will also incur a scale).
		*/
		void rotate_transform_3d(float x, float y, float z, float angle);
		void horizontal_shear_transform(float rotation);
		void vertical_shear_transform(float rotation);
	};
} // namespace AllegroWrappers

#endif