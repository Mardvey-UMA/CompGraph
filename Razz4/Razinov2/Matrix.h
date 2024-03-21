#pragma once
class vec2 {
public:
	float x, y;
	vec2() {}
	vec2(float a, float b) : x(a), y(b) {}
};
class vec3 {
public:
	float x, y, z;
	vec3() {}
	vec3(float a, float b, float c) : x(a), y(b), z(c) {}
	vec3(vec2 v, float c) : vec3(v.x, v.y, c) {}
	vec3& operator*=(const vec3& v) {
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}
	const vec3 operator*(const vec3& v) {
		return vec3(*this) *= v;
	}
	float& operator[](int i) {
		return ((float*)this)[i];
	}
};
float dot(vec3 v1, vec3 v2) {
	vec3 tmp = v1 * v2;
	return tmp.x + tmp.y + tmp.z;
}
vec2 normalize(vec3 v) {
	return vec2(v.x / v.z, v.y / v.z);
}
class mat3 {
public:
	vec3 row1, row2, row3;
	mat3() {}
	mat3(vec3 r1, vec3 r2, vec3 r3) : row1(r1), row2(r2), row3(r3) {}
	mat3(float a) {
		row1 = vec3(a, 0.f, 0.f);
		row2 = vec3(0.f, a, 0.f);
		row3 = vec3(0.f, 0.f, a);
	}
	vec3& operator[](int i) {
		return ((vec3*)this)[i];
	}
	mat3 transpose() {
		mat3 tmp(*this);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				(*this)[i][j] = tmp[j][i];
		return *this;
	}
	const vec3 operator* (const vec3& v) {
		vec3* res = new(vec3);
		for (int i = 0; i < 3; i++) {
			(*res)[i] = dot((*this)[i], v);
		}
		return *res;
	}
	mat3& operator*= (const mat3& m) {
		mat3 A(*this), B(m);
		B.transpose();
		for (int i = 0; i < 3; i++)
			(*this)[i] = A * B[i];
		return (*this).transpose();
	}
	const mat3 operator* (const mat3& m) {
		return mat3(*this) *= m;
	}
};