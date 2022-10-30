#pragma once
class CloudPoint
{
private:
	float x;
	float y;
	float z;
	int R;
	int G;
	int B;

public:
	CloudPoint(float x, float y, float z, int R, int G, int B);

	float getX();
	float getY();
	float getZ();
	int getR();
	int getG();
	int getB();
};

