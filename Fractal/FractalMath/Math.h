#ifndef _FMATH_H
#define _FMATH_H

#ifndef _VECTOR_H
#include "Vector.h"
#endif // !_VECTOR_H

#include <cmath>

namespace fractal {
	namespace fmath {
		#ifndef F_PI
		#define F_PI 3.14159265358979323846f
		#endif

		#ifndef DEGREES_TO_RADIANS
		#define DEGREES_TO_RADIANS (F_PI / 180.0f)
		#endif	

		inline float toRadians(float degrees) {
			return degrees * DEGREES_TO_RADIANS;
		}

		//change this to a vec4 and use the right overloaded functions
		struct Sphere : public Vector3 {
			float r;
			Sphere(float s = 0.0f) { x = s; y = s; z = s; r = s; }

			Sphere(float x, float y, float z, float r) {
				this->x = x; this->y = y; this->z = z; this->r = r;
			}

			inline Sphere(const Sphere& v) {
				x = v.x;  y = v.y;  z = v.z; r = v.r;
			}
		};

		//change this implementation to a vec4 and use the proper overloaded functions
		struct Plane : public Vector3 {
			float d;

			/// Here's a set of constructors
			inline Plane(float s = 0.0f) {
				x = s;
				y = s;
				z = s;
				d = s;
			}

			inline Plane(float x, float y, float z, float d) {
				Vector3 normalized(x, y, z);
				normalized.normalize();
				this->x = normalized.x;
				this->y = normalized.y;
				this->z = normalized.z;
				this->d = d;
			}

			inline Plane(const Plane& v) {
				x = v.x;
				y = v.y;
				z = v.z;
				d = v.d;
			}

			inline Plane(const Vector3& normal, const Point3& point) {
				Vector3 normalized = normal;
				normalized.normalize();
				this->x = normalized.x;
				this->y = normalized.y;
				this->z = normalized.z;
				this->d = -(normal.x * point.x + normal.y * point.y + normal.z * point.z);
			}

			inline Plane(const Vector3& normal, float d) {
				Vector3 normalized = normal;
				normalized.normalize();
				this->x = normalized.x;
				this->y = normalized.y;
				this->z = normalized.z;
				this->d = d;
			}

			/**
			Construct a normalized plane using 3 points.
			This constructor creates two vectors from the points passed as argument:
			<code>v1 = p1 - p0;</code> and <code>v2 = p2 - p0;</code>.
			Then, the normal of the plane is calculated by the cross product between <code>v1</code> and <code>v2</code>.
			*/
			inline Plane(const Point3& p0, const Point3& p1, const Point3& p2) {
				Vector3 a = p1 - p0;
				Vector3 b = p2 - p0;

				//make a cross product
				Vector3 n = Vector3(a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x);

				n.normalize();

				//normalized plane
				load(n.x, n.y, n.z, -n.dot(p2));
			}

			/**
			Construct a normalized plane using 2 <code>Vector3</code> and a point.
			The normal of the plane is calculated by the cross product between <code>v1</code> and <code>v2</code>.
			*/
			inline Plane(const Vector3& a, const Vector3& b, const Point3& p) {

				//make a cross product
				Vector3 n = Vector3(a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x);
				n.normalize();

				//normalized plane
				load(n.x, n.y, n.z, -n.dot(p));
			}

			inline void load(float x, float y, float z, float d) {
				this->x = x;
				this->y = y;
				this->z = z;
				this->d = d;
			}
		};
	}
}



#endif // !_FMATH_H
