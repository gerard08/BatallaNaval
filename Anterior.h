#pragma once

class Anterior {
public:
	Anterior() { m_x = 0; m_y = 0; m_tocat = false; };
	void setX(int x) { m_x = x; };
	void setY(int y) { m_y = y; };
	void setTocat(int tocat) { m_tocat = tocat; };
	int getX() { return m_x; };
	int getY() { return m_y; };
	bool getTocat() { return m_tocat; };
private:
	int m_x;
	int m_y;
	bool m_tocat;
};