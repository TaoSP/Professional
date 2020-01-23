/******************************************************************************
 * main.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-01-22 Create
 * Description: 双向循环链表，实现音乐播放列表
******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Node
{
    char *name;
    Node *prev;
    Node *next;
}Node, *DList;

DList creatDList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if(nullptr == head) // nullptr: g++ -std=c11 / -std=c++11 main.cpp
        return nullptr;
    
    head->name = nullptr; // unused
    head->next = head->prev = head;
    return head;
}

int appendNode(DList list, const char *data)
{
    Node *p = list;
    while(p->next != list)
    {
        p = p->next;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    if(nullptr == node)
    {
        cout << "malloc error" << endl;
        return false;
    }
    //node->name = new char[strlen(data) + 1];
    node->name = (char *)malloc(strlen(data) + 1);
    node->next = node->prev = nullptr;

    strcpy(node->name, data);
    p->next = node;
    node->prev = p;
    node->next = list;
    list->prev = node;

    //cout << "append OK, " << p->next->name << endl;
    return true;
}

int deleteNode(DList list, const char *data)
{
    Node *p = list;
    while(p->next != list)
    {
        p = p->next;
        if(!strcmp(p->name, data))
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p->name);
            free(p);
            return true;
        }
    }

    cout << "deleteNode error" << endl;
    return false;
}

int showAllNode(DList list)
{
    Node *p = list;
    int i = 0;

    while(p->next != list)
    {
        p = p->next;
        cout << ++i << ": " << p->name << endl;
    }

    return true;
}

int getDListLength(DList list)
{
    Node *p = list;
    int i = 0;

    while(p->next != list)
    {
        i++;
        p = p->next;
    }

    return i;
}

int showNode(DList list, int pos) // -1, 1, 2,...
{
    Node *p = list;
    int negative = 0;
    int index = abs(pos);

    if(pos < 0)
    {
        negative = 1;
    }
    
    if(index > getDListLength(list)
        || index == 0)
    {
        cout << "pos error" << endl;
        return false;
    }

    while(index-- > 0)
    {
        if(negative)
            p = p->prev;
        else
            p = p->next;
    }

    cout << "DList: " << pos << ", " << p->name << endl;
    return true;
}

int main()
{
    const char music[][32] = 
    {   "hello", "world", "huang", "tao", "2020",
        "today", "linux", "yesyes" };
    
    cout << "Demo: doubly linked list ..." << endl;

    DList musicList = nullptr;
    musicList = creatDList();
    if(nullptr == musicList)
    {
        cout << "creat error" << endl;
        return false;
    }

    for(int i = 0; i < 8; i++)
    {
        appendNode(musicList, music[i]);
    }

    deleteNode(musicList, "linux");
    showAllNode(musicList);
    //cout << getDListLength(musicList) << endl;

    char c;
    int pos = 0;
    while(1)
    {
        c = getchar();
        if('a' == c)
        {
            --pos;
            showNode(musicList, pos);
        }
        else if('d' == c)
        {
            ++pos;
            showNode(musicList, pos);
        }
        else if('q' == c)
        {
            break;
        }

    }

    return 0;
}
