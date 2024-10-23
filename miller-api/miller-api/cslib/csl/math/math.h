#pragma once

#ifdef EXPORTING_TYPES

namespace csl::math {
	class Vector2 {
	public:
		float x; float y;
	};

	class alignas(16) Vector3 {
	public:
		float x; float y; float z;
	};

	class alignas(16) Vector4 {
	public:
		float x; float y; float z; float w;
	};

	class alignas(16) Quaternion  {
	public:
		float x; float y; float z; float w;
		void SetRotationBetweenVectors(const Vector4& a, const Vector4& b, const Vector4& fallback);
		static Vector4 RotateVector(const Quaternion& quaternion, const Vector4& vector);
	};

	class alignas(16) Matrix44 {
	public:
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	};

	class alignas(16) Matrix34 {
	public:
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	};

	class Position {
	public:
		float x; float y; float z;
	};

	class Rotation {
	public:
		float x; float y; float z; float w;
	};
}

#else

#ifndef NO_EIGEN_MATH

#include <Eigen/Eigen>
// #include <unsupported/Eigen/AlignedVector3>

#define RANGERS_SDK_PACK(...) __VA_ARGS__
#define RANGERS_SDK_NEWTYPE_WITH_ATTRS(ClassName, BaseClass, ConstructorName, Attrs) \
	class Attrs ClassName : public BaseClass { \
	public: \
		using BaseClass::ConstructorName; \
    \
		inline ClassName(const BaseClass& other) : BaseClass{ other } {} \
		inline ClassName(BaseClass& other) : BaseClass{ std::move(other) } {} \
	}
#define RANGERS_SDK_NEWTYPE(ClassName, BaseClass, ConstructorName) RANGERS_SDK_NEWTYPE_WITH_ATTRS(ClassName, BaseClass, ConstructorName,)
#define RANGERS_SDK_NEWTYPE_ALIGNED(ClassName, BaseClass, ConstructorName, Alignment) RANGERS_SDK_NEWTYPE_WITH_ATTRS(ClassName, BaseClass, ConstructorName, alignas(Alignment))

namespace csl::math {
	RANGERS_SDK_NEWTYPE(Vector2, Eigen::Vector2f, Matrix);
	// RANGERS_SDK_NEWTYPE(Vector3, Eigen::AlignedVector3<float>, AlignedVector3);
	RANGERS_SDK_NEWTYPE_ALIGNED(Vector3, Eigen::Vector3f, Matrix, 16);
	RANGERS_SDK_NEWTYPE(Vector4, Eigen::Vector4f, Matrix);
	RANGERS_SDK_NEWTYPE(Quaternion, Eigen::Quaternionf, Quaternion);
	RANGERS_SDK_NEWTYPE(Matrix34, Eigen::Affine3f, Transform);
	RANGERS_SDK_NEWTYPE(Matrix44, Eigen::Projective3f, Transform);
	RANGERS_SDK_NEWTYPE(Position, Eigen::Vector3f, Matrix);
	RANGERS_SDK_NEWTYPE(Rotation, RANGERS_SDK_PACK(Eigen::Quaternion<float, Eigen::DontAlign>), Quaternion);
}

inline bool operator==(const csl::math::Matrix44& one, const csl::math::Matrix44& other) {
	return one.matrix() == other.matrix();
}

inline bool operator!=(const csl::math::Matrix44& one, const csl::math::Matrix44& other) {
	return !(one == other);
}

inline bool operator==(const csl::math::Matrix34& one, const csl::math::Matrix34& other) {
	return one.matrix() == other.matrix();
}

inline bool operator!=(const csl::math::Matrix34& one, const csl::math::Matrix34& other) {
	return !(one == other);
}

#endif

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
			// min = min.cwiseMin(point);
			// max = max.cwiseMax(point);
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
	float Vector3Distance(const Vector3& x, const Vector3& y);
	float Vector3DistanceSq(const Vector3& x, const Vector3& y);
	float Vector3DistanceNormalized(const Vector3& x, const Vector3& y);
	float Vector3Dot(const Vector3& x, const Vector3& y);
	Vector3 Vector3NormalBetween(const Vector3& x, const Vector3& y);

	Matrix34 CreateViewMatrix(const Vector3& position, const Vector3& up, const Vector3& target);
	Matrix44 CreateOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
	Matrix44 CreatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);

	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);
	Matrix34 Matrix34Rotation(const Quaternion& rotation);

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
