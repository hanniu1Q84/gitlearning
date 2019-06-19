#include <iostream>
using namespace std;

class Shape {
public:
	Shape(int x, int y):m_x(x), m_y(y) {}
	virtual void draw(void) {
		cout << "绘制图形" << m_x << ',' << m_y << endl;
	}
protected:
	int m_x;
	int m_y;
};

class Rect:public Shape{
public:
	Rect(int x, int y, int w, int h):
		Shape(x,y), m_w(w), m_h(h) {}
	void draw(void) {
		cout << "绘制矩形：" << m_x << ',' << m_y <<
			',' << m_w << ',' << m_h << endl;
	}
private:
	int m_w;
	int m_h;
};

class Circle:public Shape {
public:
	Circle(int x, int y, int r):Shape(x,y), m_r(r) {}
	void draw(void) {
		cout << "绘制圆形：" << m_x << ',' << m_y <<
			',' << m_r << endl;
	}
private:
	int m_r;
};

void render(Shape* shapes[]) {
	for(int i = 0; shapes[i]; i++) {
		shapes[i]->draw();
	}
}	

int main(void) {
	Shape* shapes[1024] = { NULL };
	shapes[0] = new Rect(2, 3, 5, 6);
	shapes[1] = new Rect(4, 5, 10, 11);
	shapes[2] = new Circle(6, 8, 8);
	shapes[3] = new Circle(15, 16, 20);
	shapes[4] = new Rect(10, 12, 20, 30);
	render(shapes);
		
	return 0;
}
