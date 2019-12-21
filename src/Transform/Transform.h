#ifndef ALLEGRO_WRAPPERS_TRANSFORM_DEF
#define ALLEGRO_WRAPPERS_TRANSFORM_DEF
#include <allegro5/allegro.h>

namespace AllegroWrappers {
	struct Coordinates {
		float x;
		float y;
		Coordinates(float xVal, float yVal) : x(xVal), y(yVal) {}
	};
	struct Coordinates3D : Coordinates {
		float z;
		Coordinates3D(float xVal, float yVal, float zVal)
		    : z(zVal), Coordinates(xVal, yVal) {}
	};
	struct Coordinates4D : Coordinates3D {
		float w;
		Coordinates4D(float xVal, float yVal, float zVal, float wVal)
		    : w(zVal), Coordinates3D(xVal, yVal, zVal) {}
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

		~Transform();

		void invert_transform();
		/*
		    Transposes the matrix of the given transform. This can be used for
		   inversing a rotation transform.
		 */
		void transpose_transform();
		/*
		    Checks if the transformation has an inverse using the supplied
		    tolerance. Tolerance should be a small value between 0 and 1, with
		   1e-7 being sufficient for most applications.
		*/
		bool check_inverse(float tolerance);
		/*
		    Sets the transformation to be the identity transformation. This is
		   the default transformation. Use al_use_transform on an identity
		   transformation to return to the default.
		*/
		void identity_transform();
		/*
		    Builds a transformation given some parameters. This call is
		   equivalent to calling the transformations in this order: make
		   identity, rotate, scale, translate. This method is faster, however,
		   than actually calling those functions.
		*/
		void build_transform(float xTranslation, float yTranslation,
		                     float xScale, float yScale, float rotation);
		/*
		    Places camera at "position", looks toward direction of point "look",
		   and orients itself using "up" to detemine which way should be up.
		*/
		void build_camera_transform(float position_x, float position_y,
		                            float position_z, float lookDir_x,
		                            float look_y, float look_z, float up_x,
		                            float up_y, float up_z);
		/*
		    Apply a translation to a transformation.
		*/
		void translate_transform(float horizontal, float vertical);
		/*
		    Apply a rotation to a transformation.
		*/
		void rotate_transform(float angle);
		/*
		    Apply a scale to a transformation.
		*/
		void scale_transform(float xScale, float yScale);
		// Use this Transform to transform to transform 2D coordinates.
		Coordinates transform_coordinates(float x, float y);
		// Use this Transform to transform to transform 3D coordinates.
		Coordinates3D transform_coordinates_3d(float x, float y, float z);
		// Use this Transform to transform to transform 4D coordinates.
		Coordinates4D transform_coordinates_4d(float x, float y, float z,
		                                       float w);

		/*
		    Transform x, y, z as homogeneous coordinates. This is the same as
		   using al_transform_coordinates_4d with the w coordinate set to 1,
		   then dividing x, y, z by the resulting w.
		*/
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
		void translate_transform_3d(float x, float y, float z);
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
		/*
		    Apply a horizontal shear to the transform.
		*/
		void horizontal_shear_transform(float rotation);
		/*
		    Apply a vertical shear to the transform.
		*/
		void vertical_shear_transform(float rotation);
	};
} // namespace AllegroWrappers

#endif