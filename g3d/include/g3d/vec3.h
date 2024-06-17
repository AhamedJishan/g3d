#pragma once

#include <iostream>
#include <assert.h>

namespace g3d
{
	// A 3-dimensional vector (x, y, z).
	class vec3
	{
	public:
		union
		{
			struct
			{
				float x, y, z;					// Elements of vec3
			};

			float raw[3];						// Float array of x, y, z elements
		};
		

		/*
		* @brief Constructs a Vec3 object with the specified coordinates.
		* @param X: The x element of the vector. Default is 0.0f.
		* @param Y: The y element of the vector. Default is 0.0f.
		* @param Z: The z element of the vector. Default is 0.0f.
		* @details This constructor initializes a Vec3 object with the given coordinates.
		*/
		vec3(float X = 0.0f, float Y = 0.0f, float Z = 0.0f)
			: x(X), y(Y), z(Z) {}

		// @brief Magnitude of the vector.
		// @returns 'magnitude', calculated by sqrt(x*x + y*y + z*z).
		float magnitude() const;

		/**
		* @brief Square of magnitude.
		* Use this when actual magnitude isn't required.
		* Faster than 'magnitude()'.
		* @returns Square of 'magnitude', calculated by (x*x + y*y + z*z).
		*/
		float sqrMagnitude() const;

		// @brief Normalizes the given vector.
		void normalize();

		/**
		* @brief Returns a normalized version of the vector.
		* @returns Normalized vec3, calculated by x = x/m, y = y/m, z = z/m. ('m' = magnitude of the vector)
		*/
		vec3 normalized() const;

		/**
		* @brief Computes the dot product of this vec3 with another vec3.
		* @param other: The other vec3 object.
		* @return The dot product of this vec3(x1, y1, z1) and the other vec3(x2, y2, z2).
		* Calculated as: dot = x1*x2 + y1*y2 + z1*z2
		*/
		float dot(const vec3& other) const;

		/**
		* @brief Computes the dot product of vec3 A with another vec3 B.
		* @param A: The first vec3 object.
		* @param B: The second vec3 object.
		* @return The dot product of 'A' and 'B'.
		* Calculated as: dot = A.x * B.x + A.y * B.y + A.z * B.z
		*/
		static float dot(const vec3& A, const vec3& B)
		{
			return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
		}

		/**
		* @brief Computes the cross product of this vec3 with another vec3.
		* @param other The other vec3 object.
		* @return The cross product of this vec3 'A' and the other vec3 'B'.
		*
		* Calculated as:
		*  cross = { (A.y * B.z - A.z * B.y),
		*            (A.z * B.x - A.x * B.z),
		*            (A.x * B.y - A.y * B.x) }
		*/
		vec3 cross(const vec3& other) const;

		/**
		* @brief Computes the cross product of this vec3 with another vec3.
		* @param A: The first vec3 object.
		* @param B: The second vec3 object.
		* @return The cross product of A and B.
		*
		* Calculated as:
		*  cross = { (A.y * B.z - A.z * B.y),
		*            (A.z * B.x - A.x * B.z),
		*            (A.x * B.y - A.y * B.x) }
		*/
		static vec3 cross(const vec3& A, const vec3& B)
		{
			return vec3((A.y * B.z - A.z * B.y),
						(A.z * B.x - A.x * B.z),
						(A.x * B.y - A.y * B.x));
		}

		/**
		* @brief Finds the angle between two vectors in radians.
		* @param A: The first vec3 object.
		* @param B: The second vec3 object.
		* @return The angle between A and B, in radians.
		* 
		* Calculated as: Angle = arccos( (A•B) / (|A| * |B|) )
		*/
		static float angleBetween(const vec3& A, const vec3& B)
		{
			return acos( dot(A, B) / (A.magnitude() * B.magnitude()) );
		}


		// Arithemetical operator overloads
		inline vec3 vec3::operator+(const vec3& other) const { return vec3(x + other.x, y + other.y, z + other.z); }
		inline vec3 vec3::operator-(const vec3& other) const { return vec3(x - other.x, y - other.y, z - other.z); }
		inline vec3 vec3::operator*(const float scalar) const
		{
			if (scalar == 0) return vec3(x, y);
			return vec3(x * scalar, y * scalar, z * scalar);
		}
		inline vec3 vec3::operator/(const float scalar) const
		{
			if (scalar == 0) return vec3(x, y);
			return vec3(x / scalar, y / scalar, z / scalar);
		}
		// Logical operator overload
		inline bool vec3::operator == (const vec3& other) const { return (x == other.x) && (y == other.y) && (z == other.z); }
		inline bool vec3::operator != (const vec3& other) const { return !(*this == other); }
		inline bool vec3::operator <  (const vec3& other) const { return (sqrMagnitude() < other.sqrMagnitude()); }
		inline bool vec3::operator <= (const vec3& other) const { return (sqrMagnitude() <= other.sqrMagnitude()); }
		inline bool vec3::operator >  (const vec3& other) const { return (sqrMagnitude() > other.sqrMagnitude()); }
		inline bool vec3::operator >= (const vec3& other) const { return (sqrMagnitude() >= other.sqrMagnitude()); }

		friend std::ostream& operator<<(std::ostream& os, const vec3& vec);
	};
}