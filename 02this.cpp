#include <iostream>
using namespace std;

class User {
public:
	/*User(const string& name, int age):
		m_name(name), m_age(age) {
		cout << "构造函数：" << this << endl;
		}*/
	// 当参数变量名和成员变量名一样，必须用this区分
	User(const string& m_name, int m_age) {
		this->m_name = m_name;
		this->m_age = m_age;
		cout << "构造函数：" << this << endl;
		}
	void print(void) {
		cout << m_name << ',' << m_age << endl;
	}
	/*print 被编译后，代码类似：
	 * void print(User* this){ 
	 *	cout << this-<m_name << ',' << this->m_age << endl;
	 * }
	 */
private:
	string m_name;
	int m_age;
};

int main(void) {
	User user1("张飞", 28);
	cout << "user1:" << &user1 << endl;
	User user2("赵云", 25);
	cout << "user2:" << &user2 << endl;
	user1.print(); //user1.print(&user1)
	user2.print(); //user2.print(&user2)

	return 0;
}
