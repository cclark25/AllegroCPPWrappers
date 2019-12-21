#include "Transform.h"
namespace AllegroWrappers {
	Transform::Transform() {
		this->data = new foreign_data();
		this->data->reference_count = 1;
		this->data->transform = new ALLEGRO_TRANSFORM();
		this->identity_transform();
	}

	Transform::Transform(Transform &source) {
		this->data = source.data;
		this->data->reference_count++;
	}

	Transform Transform::copy_transform() {
		Transform t;
		al_copy_transform(t.data->transform, this->data->transform);
		return t;
	}

	Transform::~Transform() {
		data->reference_count--;
		if (data->reference_count == 0) {
			delete data->transform;
			delete data;
		}
	}

	void Transform::invert_transform() {
		al_invert_transform(this->data->transform);
	}

	void Transform::transpose_transform() {
		al_transpose_transform(this->data->transform);
	}

	bool Transform::check_inverse(float tolerance) {
		return al_check_inverse(this->data->transform, tolerance);
	}

	void Transform::identity_transform() {
		al_identity_transform(this->data->transform);
	}

	void Transform::build_transform(float xTranslation, float yTranslation,
	                                float xScale, float yScale,
	                                float rotation) {
		al_build_transform(this->data->transform, xTranslation, yTranslation,
		                   xScale, yScale, rotation);
	}

	void Transform::build_camera_transform(float position_x, float position_y,
	                                       float position_z, float lookDir_x,
	                                       float look_y, float look_z,
	                                       float up_x, float up_y, float up_z) {
		al_build_camera_transform(this->data->transform, position_x, position_y,
		                          position_z, lookDir_x, look_y, look_z, up_x,
		                          up_y, up_z);
	}

	void Transform::translate_transform(float horizontal, float vertical) {
		al_translate_transform(this->data->transform, horizontal, vertical);
	}

	void Transform::rotate_transform(float angle) {
		al_rotate_transform(this->data->transform, angle);
	}

	void Transform::scale_transform(float xScale, float yScale) {
		al_scale_transform(this->data->transform, xScale, yScale);
	}

	Coordinates Transform::transform_coordinates(float x, float y) {
		Coordinates result = {x, y};
		al_transform_coordinates(this->data->transform, &result.x, &result.y);
		return result;
	}
	Coordinates3D Transform::transform_coordinates_3d(float x, float y,
	                                                  float z) {
		Coordinates3D result = {x, y, z};
		al_transform_coordinates_3d(this->data->transform, &result.x, &result.y,
		                            &result.z);
		return result;
	}
	Coordinates4D Transform::transform_coordinates_4d(float x, float y, float z,
	                                                  float w) {
		Coordinates4D result = {x, y, z, w};
		al_transform_coordinates_4d(this->data->transform, &result.x, &result.y,
		                            &result.z, &result.w);
		return result;
	}

	Coordinates3D
	Transform::_transform_coordinates_3d_projective(float x, float y, float z) {

		Coordinates3D result = {x, y, z};
		al_transform_coordinates_3d_projective(this->data->transform, &result.x,
		                                       &result.y, &result.z);
		return result;
	}

	void Transform::compose_transform(Transform transformation) {
		al_compose_transform(this->data->transform,
		                     transformation.data->transform);
	}

	void Transform::orthographic_transform(float left, float top, float right,
	                                       float bottom, float near,
	                                       float far) {
		al_orthographic_transform(this->data->transform, left, top, right,
		                          bottom, near, far);
	}

	void Transform::perspective_transform(float left, float top, float right,
	                                      float bottom, float near, float far) {
		al_perspective_transform(this->data->transform, left, top, right,
		                         bottom, near, far);
	}

	void Transform::translate_transform_3d(float x, float y, float z) {
		al_translate_transform_3d(this->data->transform, x, y, z);
	}

	void Transform::scale_transform_3d(float xScale, float yScale,
	                                   float zScale) {
		al_scale_transform_3d(this->data->transform, xScale, yScale, zScale);
	}
	void Transform::rotate_transform_3d(float x, float y, float z,
	                                    float angle) {
		al_rotate_transform_3d(this->data->transform, x, y, z, angle);
	}
	void Transform::horizontal_shear_transform(float rotation) {
		al_horizontal_shear_transform(this->data->transform, rotation);
	}
	void Transform::vertical_shear_transform(float rotation) {
		al_vertical_shear_transform(this->data->transform, rotation);
	}

} // namespace AllegroWrappers