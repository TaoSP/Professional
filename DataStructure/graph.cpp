/******************************************************************************
 * graph.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-05 Create
 * Description: 图，遍历
******************************************************************************/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define MAX_VERTEX    6

// 图的邻接矩阵表示
char vexs[MAX_VERTEX] = {'a', 'b', 'c', 'd', 'e', 'f'};
int arcs[MAX_VERTEX][MAX_VERTEX] = 
{
    {0, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0}
};
int visited[MAX_VERTEX];

void BFS(int start)
{
    if(start < 0 || start >= MAX_VERTEX)
        return;
    
    cout << vexs[start] << endl;
    visited[start] = true;
    queue<int> que;
    que.push(start);
    while (!que.empty())
    {
        int index = que.front(); que.pop();
        for(int i = 0; i < MAX_VERTEX; i++)
        {
            if(!visited[i] && arcs[index][i])
            {
                cout << vexs[i] << endl;
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

void DFS(int start)
{
    if(start < 0 || start >= MAX_VERTEX)
        return;
    
    cout << vexs[start] << endl;
    visited[start] = true;
    for(int i = 0; i < MAX_VERTEX; i++)
    {
        if(!visited[i] && arcs[start][i])
            DFS(i);
    }
}

void DFSNonRecursive(int start)
{
    if(start < 0 || start >= MAX_VERTEX)
        return;
    
    cout << vexs[start] << endl;
    visited[start] = true;

    int i;
    stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int index = st.top();
        for(i = 0; i < MAX_VERTEX; i++)
        {
            if(!visited[i] && arcs[index][i])
            {
                cout << vexs[i] << endl;
                visited[i] = true;
                st.push(i);
                break; // 继续深度遍历
            }
        }
        if(i == MAX_VERTEX)
            st.pop(); // 回溯到上一层
    }
}

int main()
{
    for(int i = 0; i < MAX_VERTEX; i++)
        visited[i] = false;
    
    //for(int i = 0; i < MAX_VERTEX; i++) // 防止顶点间不联通
    //BFS(1);
    //DFS(0);
    DFSNonRecursive(0);

    return 0;
}
