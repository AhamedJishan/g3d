#pragma once

class vector
{
public:
	virtual vector operator+(vector& other) const = 0;
	
protected:
	vector() {};
};


class vec2 : public vector
{
public:
	float x, y;
private:
};