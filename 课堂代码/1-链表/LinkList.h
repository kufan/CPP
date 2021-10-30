#pragma once
// 防止头文件被重复编译 -- 在工程中异常重要

// 设计节点
// 数据域，交给用户去维护!!!
typedef struct LINKNODE {
	struct LINKNODE* next;   // 指针域，用来保存下一个节点的地址
}LinkNode;
// 节点一旦设计好，链表中数据的格式也就确定了


// 设计一个链表的起点
// 其实就是对头节点的封装 -- 单纯的，为了方便管理链表
typedef struct LINKLIST {
	LinkNode head;   // 头节点
	int size;   // 记录链表中节点个数
}LinkList;


// typedef: 1、给指定类型起别名; 2、修饰类型(typedef 后面的，必须是类型)
// 借助设计 函数指针类型 的方式，指定打印函数的格式
typedef void(*PRINTNODE)(LinkNode*);
// void(*PRINTNODE)(LinkNode*) 就是类型，函数指针类型
// void(*PRINTNODE)(LinkNode*) a; 声明了一个叫做 a 的 void(*PRINTNODE)(LinkNode*) 类型的变量
// 此时 a 天生就是指针，且 a 只能指向一个函数(a 中只能保存一个函数的地址)
// a 只能指向 没有返回值，且只能有一个 LinkNode* 类型参数的 函数
// void(*PRINTNODE)(LinkNode*) 可以简写为 PRINTNODE
// PRINTNODE a;



typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
// int(*COMPARENODE)(LinkNode*, LinkNode*) 就是类型
// int(*COMPARENODE)(LinkNode*, LinkNode*) a;
// a 只能指向一个有 int 返回值，且有两个 LinkNode* 类型的参数的  函数
// int(*COMPARENODE)(LinkNode*, LinkNode*) 可以简写为 COMPARENODE


// 初始化链表 -- 创造一个链表
// 其实就是把起点初始化出来
// 开发者控制数据的生命周期
// 将会在堆区，初始化链表，初始化成功后返回该链表的地址
LinkList* Init_LinkList();
// 指针函数 -- 一个返回值是指针的函数


// 插入操作
// 给链表 list 的 pos 位置插入一个 dt 的节点
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);

// 删除操作： 删除链表 list 中第 pos 个节点
int Delete_LinkList(LinkList* list, int pos);

// 返回链表大小
int GetSize_LinkList(LinkList* list);

// 遍历操作: 遍历链表中每个节点中的值
// 节点中的值，是由用户维护的，作为框架开发者，不知道数据是什么类型
// 因此，作为框架开发者，不知道该如何打印数据
// 但是用户知道如何打印数据
// 就需要用户提供一个打印函数，我们反向调用(回调),这个函数就叫做 回调函数
// 不同的人在设计函数的时候，风格和习惯是不一样
// 调用函数的前提是，必须明确这个函数的格式: 有无参数，几个参数，有无返回值，什么返回值
// 所以，作为框架提供者，我们必须要规范这个打印函数的格式
// 借助设计 函数指针类型 的方式，指定打印函数的格式
// 借助 函数指针类型，反向调用用户设计实现的 打印函数即可
int Print_LinkList(LinkList* list, PRINTNODE print);

// 查找函数
// 在链表 list 中查找是否存在节点 dt，如果存在，返回第一次出现 dt 的位置
// 作为框架开发者，不知道数据是什么样的，所以没法做比较
// 必须由用户，实现一个比较函数，我们反向调用作比较
// 通过设计实现  函数指针类型 的方式，执行比较函数的规格
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);


// 销毁链表
int Destory_LinkList(LinkList* list);