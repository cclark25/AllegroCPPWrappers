#include "Transform.h"
namespace AllegroWrappers {
	Transform::Transform() {
		this->data = new foreign_data();
		this->data->reference_count = 1;
		this->data->transform = new ALLEGRO_TRANSFORM();
	}
	Transform::Transform(Transform &source) {}

	Transform Transform::copy_transform() { Transform t(); }
	void Transform::invert_transform() {}
	void Transform::transpose_transform() {}
	bool Transform::check_inverse(float tolerance) {}
	void Transform::identity_transform() {}
	void Transform::build_transform(float xTranslation, float yTranslation,
	                                float xScale, float yScale,
	                                float rotation) {}
	void Transform::build_camera_transform(float position_x, float position_y,
	                                       float position_z, float lookDir_x,
	                                       float look_y, float look_z,
	                                       float up_x, float up_y, float up_z) {
	}
	void Transform::translate_transform(float horizontal, float vertical) {}
	void Transform::rotate_transform(float angle) {}
	void Transform::scale_transform(float xScale, float yScale) {}
	Coordinates Transform::transform_coordinates(float x, float y) {}
	Coordinates3D Transform::transform_coordinates_3d(float x, float y,
	                                                  float z) {}
	Coordinates4D Transform::transform_coordinates_4d(float x, float y, float z,
	                                                  float w) {}
	Coordinates3D Transform::_transform_coordinates_3d_projective(float x,
	                                                              float y,
	                                                              float z) {}
	void Transform::compose_transform(Transform transformation) {}
	void Transform::orthographic_transform(float left, float top, float right,
	                                       float bottom, float near,
	                                       float far) {}
	void Transform::perspective_transform(float left, float top, float right,
	                                      float bottom, float near, float far) {
	}
	void Transform::translate_transform_3d(float x, float y) {}
	void Transform::scale_transform_3d(float xScale, float yScale,
	                                   float zScale) {}
	void Transform::rotate_transform_3d(float x, float y, float z,
	                                    float angle) {}
	void Transform::horizontal_shear_transform(float rotation) {}

} // namespace AllegroWrappers