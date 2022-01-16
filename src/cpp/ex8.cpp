#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "../headers/ex8.h"
using namespace std;
namespace ex8
{
    class Node
    {
        public:
            char c; //��ʾ�ַ�
            int frequency; //��ʾ���ַ����ֵĴ�����Ƶ��
            Node *left;
            Node *right;

            Node(char _c, int f, Node *l = NULL, Node *r = NULL)
                :c(_c), frequency(f), left(l), right(r) { }

            bool operator<(const Node &node)
            const   //����<���㷨�������ڼ������ȶ��е�ʱ�������δ�����λ��
            {
                return frequency > node.frequency;
            }
    };

    void initNode(priority_queue<Node> &q, int nodeNum,int n)
    {
        unsigned seed;
        srand(seed);
        char c;
        int frequency;
        for (int i = 0; i < nodeNum; i++)
        {
            char c=97+i;
            frequency=rand() % n +0;
            Node node(c, frequency);
            q.push(node);
        }
    }

    void showNode(priority_queue<Node> q)
    {
        while (!q.empty())
        {
            Node node = q.top();
            q.pop();
//            cout << node.c << ", " << node.frequency << endl;
        }
    }

//�����������
    void huffmanTree(priority_queue<Node> &q)
    {
        while (q.size() != 1)
        {
            Node *left = new Node(q.top());
            q.pop();
            Node *right = new Node(q.top());
            q.pop();

            Node node('R', left->frequency + right->frequency, left, right);
            q.push(node);
        }
    }

// ��ӡ����������
    void huffmanCode(Node *root, string &prefix, map<char, string> &result)
    {
        string m_prefix = prefix;
        if (root->left == NULL)
        {
            return;
        }
        prefix += "0";
        if (root->left->left == NULL)
        {
            result[root->left->c] = prefix;
        }
        else
        {
            huffmanCode(root->left, prefix, result);
        }
        prefix = m_prefix;
        prefix += "1";
        if (root->right->right == NULL)
        {
            result[root->right->c] = prefix;
        }
        else
        {
            huffmanCode(root->right, prefix, result);
        }
    }
    int fex8()
    {
    	int n=1000;
    	int cn=3;
        for(; true;)
        {
            priority_queue<Node> q;
            int nodeNum;

            initNode(q,cn ,n);
            showNode(q);

            clock_t a=clock();
            for(int i=0; i<1000; i++)
            {
                //�����������
                huffmanTree(q);
                //�������������
                Node root = q.top();
                string prefix = "";
                map<char, string> result;
                huffmanCode(&root, prefix, result);
            }
            clock_t b=clock();
            cout<<b-a<<endl;
            
            cn+=1;
        }
        return 0;
    }
}

