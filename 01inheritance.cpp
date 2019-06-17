#include <iostream>
using namespace std;

//人类
class Human {
public:
	Human(const string& name, int age):
		m_name(name), m_age(age) {}
	void eat(const string& food) const{
		cout << "我在吃" << food << endl;
	}
	void sleep(int time) const {
		cout << "我睡了" << time << "小时" << endl;
	}
protected: //保护类型成员可以在类的内部和子类中访问
	string m_name;
	int m_age;	
};

//学生类，集成人类
class Student:public Human {
public:
	Student(const string& name, int age, int no):
		Human(name,age), m_no(no) {}
	void who(void) const{
		cout << "我叫" << m_name << ", 今年" << 
			m_age << "随， 学号是" << m_no << endl;
	}
	void learn(const string& course) const {
		cout << "我在学"<< course << endl;
	}	
private:
	int m_no;
};

//教师类，集成人类
class Teacher:public Human {
public:
	Teacher(const string& name, int age,
			double salary):Human(name, age),
				m_salary(salary) {}
	void who(void) const {
		cout << "我叫" << m_name << ",今年，" << 
			m_age << "随， 每个月的薪水为：" << 
			m_salary << endl;
	}
	void teach(const string& course) {
		cout << "我叫" << course << endl;
	}
private:
	double m_salary;
};

int main(void) {
	Student s("悟空", 30, 10011);
	s.who();
	s.eat("水果");
	s.sleep(8);
	s.learn("念经");
	
	Teacher t("三藏", 35, 800.5);
	t.who();
	t.eat("面条");
	t.sleep(6);
	t.teach("佛法");

	return 0;
}
