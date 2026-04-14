#pragma once
#ifdef EXPORTING_TYPES
namespace csl::math {
	class Vector2 { public: float x; float y; };
	class alignas(16) Vector3 { public: float x; float y; float z; };
	class alignas(16) Vector4 { public: float x; float y; float z; float w; };
	class alignas(16) Quaternion { public: float x; float y; float z; float w; };
	class alignas(16) Matrix44 { public: Vector4 t; Vector4 u; Vector4 v; Vector4 w; };
	class alignas(16) Matrix34 { public: Vector4 t; Vector4 u; Vector4 v; Vector4 w; };
	class Position { public: float x; float y; float z; };
	class Rotation { public: float x; float y; float z; float w; };
}
#else
#include <ucsl/math.h>

namespace csl::math {
	UCSL_NEWTYPE_SIMPLE(Vector2, ucsl::math::Vector2);
	UCSL_NEWTYPE_SIMPLE(Vector3, ucsl::math::Vector3);
	UCSL_NEWTYPE_SIMPLE(Vector4, ucsl::math::Vector4);
	UCSL_NEWTYPE_SIMPLE(Quaternion, ucsl::math::Quaternion);
	UCSL_NEWTYPE_SIMPLE(Matrix44, ucsl::math::Matrix44);
	UCSL_NEWTYPE_SIMPLE(Matrix34, ucsl::math::Matrix34);
	UCSL_NEWTYPE_SIMPLE(Position, ucsl::math::Position);
	UCSL_NEWTYPE_SIMPLE(Rotation, ucsl::math::Rotation);
}
#endif

static_assert(alignof(csl::math::Vector2) == 4);
static_assert(alignof(csl::math::Vector3) == 16);
static_assert(alignof(csl::math::Vector4) == 16);
static_assert(alignof(csl::math::Quaternion) == 16);
static_assert(alignof(csl::math::Matrix34) == 16);
static_assert(alignof(csl::math::Matrix44) == 16);
static_assert(alignof(csl::math::Position) == 4);
static_assert(alignof(csl::math::Rotation) == 4);

namespace csl::math {
	class Transform
	{
	public:
		Vector3 position{ 0.0f, 0.0f, 0.0f };
		Quaternion rotation{ 0.0f, 0.0f, 0.0f, 1.0f };
		Vector3 scale{ 0.0f, 0.0f, 0.0f };

		inline bool operator==(const Transform& other) const {
			return position == other.position && rotation == other.rotation && scale == other.scale;
		}

		inline bool operator!=(const Transform& other) const {
			return !operator==(other);
		}
	};

	class Plane {
	public:
		Vector3 point;
		Vector3 normal;

		static Plane FromPointNormal(const Vector3& point, const Vector3& normal);
		Vector3 ProjectOnNormal(const Vector3& point, float* signedDistance) const;
	};
}

namespace csl::geom {
	class Aabb
	{
	public:
		math::Vector3 min{ 0.0f, 0.0f, 0.0f };
		math::Vector3 max{ 0.0f, 0.0f, 0.0f };

		static Aabb Transform(const math::Matrix34& matrix, const Aabb& aabb);
		math::Vector3 Center() const;
		bool Intersect(const Aabb& aabb) const;
		math::Vector3 Extent() const;
		float DistanceSq(const math::Vector3& point, math::Vector3* distanceByAxis) const;

		inline void AddPoint(const csl::math::Vector3& point) {
			min = min.cwiseMin(point);
			max = max.cwiseMax(point);
		}
	};

	class Obb
	{
	public:
		math::Vector3 min{};
		math::Vector3 extentX{};
		math::Vector3 extentY{};
		math::Vector3 extentZ{};

		void Set(const math::Vector3& position, const math::Vector3& halfExtents, const math::Quaternion& rotation);
		float DistanceSq(const math::Vector3& point, math::Vector3* distanceByAxis) const;
	};
	
	class Segment3
	{
	public:
		math::Vector3 start{};
		math::Vector3 end{};
	};

	class Sphere
	{
	public:
		math::Vector3 position{};
		float radius;
	};

	class Cylinder
	{
	public:
		Segment3 segment;
		float radius;

		void Set(float radius, float halfHeight, const math::Vector3& center, const math::Quaternion& rotation);
		float DistanceSq(const math::Vector3& point, float* scaledHeightFromBase) const;
	};
	
	class Line3;
	class Ray3;
}

namespace csl::math {
	Vector3 Vector3Cross(const Vector3& x, const Vector3& y);
	Vector3 Vector3NormalBetween(const Vector3& x, const Vector3& y);
	Vector3 Vector3Rotate(const Quaternion& rotation, const Vector3& vec);
	Vector3 Vector3MulAdd(const Vector3 x, const Vector3 y, float scale);
	Vector3 Vector3Sub(const Vector3& lhs, const Vector3& rhs);
	Vector3 Vector3Scale(const Vector3& vec, float scalar);
	float Vector3Distance(const Vector3& x, const Vector3& y);
	float Vector3DistanceSq(const Vector3& x, const Vector3& y);
	float Vector3DistanceNormalized(const Vector3& x, const Vector3& y);
	float Vector3Dot(const Vector3& x, const Vector3& y);
	float Vector3Length(const Vector3& x);
	float Vector3LengthSq(const Vector3& x);
	bool Vector3DistanceLessThan(const Vector3& x, const Vector3& y, float threshold);
	void Vector3Normalize(const Vector3& vec, Vector3* result);
	bool Vector3NearZero(const Vector3& vec);
	
	Quaternion QuaternionRotationBetweenNormals(const Vector3& from, const Vector3& to);
	Quaternion QuaternionRotationBetweenNormalsAxis(const Vector3& from, const Vector3& to, const Vector3& axis);
	Quaternion QuaternionRotationAxis(const Vector3& position, const Vector3& lookAt, const Vector3& axis);
	void QuaternionToEulerAngleZXY(const Quaternion& quat, Vector3* result);

	bool QuaternionsCloserThan(const Quaternion& quat1, const Quaternion& quat2, float distance);

	Matrix34 Matrix34Transpose(const Matrix34& mat);
	Matrix34 Matrix34Inverse(const Matrix34& mat, Vector3* maybeDeterminant);
	bool Matrix34Inverse(const Matrix34& mat, Matrix34* result);
	Matrix34 Matrix34LookAt(const Vector3& position, const Vector3& up, const Vector3& target);
	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	Matrix34 Matrix34Rotation(const Quaternion& rotation);
	Matrix34 Matrix34Scaling(float scale);
	Matrix34 Matrix34Scaling(float x, float y, float z);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);
	void Matrix34Rotate(const Matrix34& mat, const Quaternion& rotation, Matrix34* result);
	void Matrix34RotateX(const Matrix34& mat, float angle, Matrix34* result);
	void Matrix34RotateY(const Matrix34& mat, float angle, Matrix34* result);
	void Matrix34RotateZ(const Matrix34& mat, float angle, Matrix34* result);
	void Matrix34RotationRollPitchYaw(Matrix34* mat, const Vector3& rotation);
	void Matrix34ToEulerAngleZXY(const Matrix34& mat, Vector3* result);

	Matrix44 Matrix44Convert(const Matrix34& mat);
	Matrix44 Matrix44Perspective(float fov, float aspectRatio, float nearClip, float farClip);
	Matrix44 Matrix44Orthogonal(float top, float bottom, float left, float right, float nearClip, float farClip);
	Matrix44 Matrix44Scaling(float scale);
	Matrix44 Matrix44Scaling(float x, float y, float z);
	Matrix44 Matrix44Multiply(const Matrix44& x, const Matrix44& y);

	bool Intersection(const geom::Line3& line, const Plane& plane, Vector3* intersectionPoint, float* unkParam);
	bool Intersection(const geom::Ray3& line, const geom::Aabb& aabb, float* unkParam);
	bool Intersection(const geom::Ray3& line, const Plane& plane, Vector3* intersectionPoint, float* unkParam);
	bool Intersection(const geom::Segment3& line, const Plane& plane, Vector3* intersectionPoint, float* unkParam);
	bool Intersection(const geom::Sphere& sphere, const geom::Aabb& aabb);
	bool Intersection(const geom::Sphere& sphere, const geom::Obb& obb);
	bool Intersection(const Vector3& point, const geom::Aabb& aabb);
	bool Intersection(const Vector3& point, const geom::Obb& obb);
	bool Intersection(const Vector3& point, const geom::Sphere& sphere);
	bool Intersection(const Vector3& point, const geom::Cylinder& sphere);
}
