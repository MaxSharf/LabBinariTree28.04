#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct Elem
{
    string eng_word;
    string ua_word;
    //---------------------------------
    Elem* left, * right, * parent;
};

class Tree
{
    //корень
    Elem* root;
public:
    Tree();
    ~Tree();
    //печать от указанного узла
    void Print(Elem* Node);
    //поиск от указанного узла
    //min от указанного узла
    Elem* Min(Elem* Node);
    //max от указанного узла
    Elem* Max(Elem* Node);
    //следующий для указанного узла
    Elem* Next(Elem* Node);
    //предыдущий для указанного узла
    Elem* Previous(Elem* Node);
    //вставка узла
    void Insert(Elem* z);
    //удаление ветки для указанного узла,
    //0 - удаление всего дерева
    void Del(Elem* z = 0);
    //получить корень
    Elem* GetRoot();
};
Tree::Tree()
{
    root = NULL;
}
Tree::~Tree()
{
    Del();
}

void Tree::Print(Elem* Node)
{
    if (Node != 0)
    {
        Print(Node->left);
        cout << Node->eng_word << Node->ua_word << endl;
        Print(Node->right);
    }
}
Elem* Tree::Min(Elem* Node)
{
    //Поиск самого "левого" узла
    if (Node != 0)
        while (Node->left != 0)
            Node = Node->left;
    return Node;
}
Elem* Tree::Max(Elem* Node)
{
    //Поиск самого "правого" узла
    if (Node != 0)
        while (Node->right != 0)
            Node = Node->right;
    return Node;
}
Elem* Tree::Next(Elem* Node)
{
    Elem* y = 0;
    if (Node != 0)
    {
        //если есть правый потомок
        if (Node->right != 0)
            return Min(Node->right);
        //родитель узла
        y = Node->parent;
        //если Node не корень и Node справа
        while (y != 0 && Node == y->right)
        {
            //Движемся вверх
            Node = y;
            y = y->parent;
        }
    }
    return y;
}
Elem* Tree::Previous(Elem* Node)
{
    Elem* y = 0;
    if (Node != 0)
    {
        //если есть левый потомок
        if (Node->left != 0)
            return Max(Node->left);
        //родитель узла
        y = Node->parent;
        //если Node не корень и Node слева
        while (y != 0 && Node == y->left)
        {
            //Движемся вверх
            Node = y;
            y = y->parent;
        }
    }
    return y;
}
Elem* Tree::GetRoot()
{
    return root;
}
void Tree::Insert(Elem* z)
{
    //потомков нет
    z->left = NULL;
    z->right = NULL;
    Elem* y = NULL;
    Elem* Node = root;
    //поиск места
    while (Node != 0)
    {
        //будущий родитель
        y = Node;
        if (strcmp(z->eng_word, Node->eng_word) < 0)
            Node = Node->left;
        else
            Node = Node->right;
    }
    //заполняем родителя
    z->parent = y;
    if (y == 0) //элемент первый (единственный)
        root = z;
    //чей ключ больше?
    else if (strcmp(z->eng_word, y->eng_word) < 0)
        y->left = z;
    else
        y->right = z;
}
void Tree::Del(Elem* z)
{
    //удаление куста
    if (z != 0)
    {
        Elem* Node, * y;
        //не 2 ребенка
        if (z->left == 0 || z->right == 0)
            y = z;
        else
            y = Next(z);
        if (y->left != 0)
            Node = y->left;
        else
            Node = y->right;
        if (Node != 0)
            Node->parent = y->parent;
        //Удаляется корневой узел?
        if (y->parent == 0)
            root = Node;
        else if (y == y->parent->left)
            //слева от родителя?
            y->parent->left = Node;
        else
            //справа от родителя?
            y->parent->right = Node;
        if (y != z)
        {
            //Копирование данных узла
            strcpy(z->eng_word, y->eng_word);
            strcpy(z->ua_word, y->ua_word);
        }
        delete y;
    }
    else //удаление всего дерева
        while (root != 0)
            Del(root);
}

//void Add() {
//
//    cout<<
//
//
//}
void Edit() {

}



void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);




    _getch();

}

