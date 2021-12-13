#include <iostream>

using namespace std;

/*
构造函数：
	1、仅仅是针对 类/结构体 而言的一个概念
	2、构造函数的名字，必须要跟  类名/结构体 名一致
	3、构造函数不需要 返回值
		函数名的前面，不能出现 返回值类型
		函数体内部不能出现 return 语句 
	4、构造函数不能手动调用
		当满足条件的时候，由编译器自动调用
	5、构造函数的分类
		默认构造函数
		自定义构造函数
	6、默认构造函数
		凡是没有参数的构造函数，就是默认构造函数
		任何一个类/结构体 中都有默认构造函数 
		当某个类/结构体中没有自定义构造函数时
			默认构造函数可以省略不写
			当满足条件的时候，编译器会自动添加并调用默认构造函数
	7、自定义构造函数
		凡是有参数的构造函数，就是自定义构造函数
		自定义构造函数的参数，根据项目需求决定
	8、主要作用
		主要用来在 构造对象的时候，初始化对象

析构函数 
 
*/

struct Stu {
	// 成员变量 
	string name;
	int    age;
	float  sc;
	
	// 默认构造函数	
	Stu() {
		cout << "默认构造函数被调用" << endl;
	}
	
	Stu(string na, int ag, float s) {
		name = na;
		age  = ag;
		sc   = s;
		cout << "自定义构造函数被调用" << endl;
	}
	
	Stu(string na, int ag) {
		name = na;
		age = ag;
	}
	
	// 成员函数
	void show() {
		cout << "name = " << name << ", age = " << age << ", sc= " << sc << endl;
	} 
}; 


void test() {
	Stu s;  // 声明变量，构造对象(调用默认构造函数构造对象) 
	s.show();	
	
	Stu sss("Li4", 15); 
	
	Stu ss("zhang3", 14, 99.99);
	ss.show();
	

}

int main() {
	
	test();
	
	return 0;
}
