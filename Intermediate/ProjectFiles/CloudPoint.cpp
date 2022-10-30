#include "CloudPoint.h"


CloudPoint::CloudPoint(float x, float y, float z, int R, int G, int B) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->R = R;
	this->G = G;
	this->B = B;
}

float CloudPoint::getX() {
	return x;
}

float CloudPoint::getY() {
	return y;
}

float CloudPoint::getZ() {
	return z;
}

int CloudPoint::getR() {
	return R;
}

int CloudPoint::getG() {
	return G;
}

int CloudPoint::getB() {
	return B;
}