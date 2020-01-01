#ifndef ALLEGRO_WRAPPERS_COORDINATES
#define ALLEGRO_WRAPPERS_COORDINATES

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

#endif
}