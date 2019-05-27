#pragma once
class Llista
{
public:
	int getX() { return m_x; };
	int getY() { return m_y; };
	void setX(int x) { m_x = x; };
	void setY(int y) { m_y = y; };
private:
	int m_x;
	int m_y;
};
