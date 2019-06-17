 #include <iostream>
 #include <iomanip>
 using namespace std;

 class M33 {
 public:
         M33(void) {
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 m_a[i][j] = 0;
         }
         M33(int a[][3]) {
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 m_a[i][j] = a[i][j];
         }

         friend ostream& operator<<(ostream& os,
                         const M33& m) {
                 for(int i = 0; i < 3; i++){
                         for(int j = 0; j < 3; j++)
                    //设置yukuan
                         os << setw(4) << m.m_a[i][j] ;
                 os << endl;
                 }
                 return os;
         }
         // + - *:返回优质，操作数可以是作之也可以是优质
         const M33 operator+(const M33& m) const {
                 int a[3][3] = {0};
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 a[i][j] = m_a[i][j] +
                                         m.m_a[i][j];
                 return a;
         }
         const M33 operator-(const M33& m) const {
                 int a[3][3] = {0};
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 a[i][j] = m_a[i][j] -
                                         m.m_a[i][j];
                 return a;
         }
         const M33 operator*(const M33& m) const {
                 int a[3][3] = {0};
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 for(int k = 0; k<3;k++)
                                 a[i][j] += m_a[i][k] *
                                         m.m_a[k][j];
                 return a;
         }

         // += -= *= :返回作之，作操作数必须是作之，有操作数
         // 可以时作之，也可以是优质

         M33& operator+=(const M33& m) {
                 return *this = *this + m;
         }
         M33& operator-=(const M33& m) {
                 return *this = *this - m;
         }
         M33& operator*=(const M33& m) {
                 return *this = *this * m;
         }
         // 取负-，表达式优质，操作负可以是作之也可以是优质
         const M33 operator-(void) const {
                 return M33() - *this;
         }
         //前++ --：返回作之，操作数作之
         M33& operator++(void) {
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 ++m_a[i][j];
                 return *this;
         }
         M33& operator--(void) {
                 for(int i = 0; i < 3; i++)
                         for(int j = 0; j < 3; j++)
                                 --m_a[i][j];
                 return *this;
         }
         // 后++ --：返回优质，操作数是作之
         const M33 operator++(int) {
                 M33 old = *this;
                 ++(*this);
                 return old;
        }
         const M33 operator--(int) {
                 M33 old = *this;
                 --(*this);
                return old;
         }
         int* operator[](int i) {
                return m_a[i];
         }
         const int* operator[](int i)const {
                 return const_cast<M33&>(*this)[i];
         }
 private:
         int m_a[3][3];
};

int main(void) {
        int a1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int a2[3][3] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        M33 m1(a1);
        M33 m2(a2);
        cout << m1 << endl;
        cout << m2 << endl;
        cout << "m1 + m2: " << endl;
        cout << m1 + m2 << endl;
        cout << "m1 - m2: " << endl;
        cout << m1 - m2 << endl;
        cout << "m1 * m2: " << endl;
        cout << m1 * m2 << endl;
        cout << "m1 += m2" << endl;
        cout << (m1 += m2) << endl;
        cout << "m1 -= m2" << endl;
        cout << (m1 -= m2) << endl;
        cout << "m1 *= m2" << endl;
        cout << (m1 *= m2) << endl;
        cout << "-m1: " << endl;
        cout << -m1 << endl;
        cout << "++m2" << endl;
        cout << ++m2 << endl;
        cout << m2 << endl;
        cout << "--m2" << endl;
        cout << --m2 << endl;
        cout << m2 << endl;
        cout << "m2++" << endl;
        cout << m2++ << endl;
        cout << m2 << endl;
        cout << "m2--" << endl;
        cout << m2-- << endl;
        cout << m2 << endl;

       	cout << "[]" << endl;
        for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3;j++)
                         m2[i][j] += 10;
        const M33& cm2 = m2;
        for(int i = 0; i < 3; i++){
                 for(int j = 0; j < 3;j++)
                         cout << setw(4) << cm2[i][j];
                cout << endl;
         }

         return 0;
}
