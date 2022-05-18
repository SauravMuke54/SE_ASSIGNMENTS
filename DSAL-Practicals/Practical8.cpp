/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class QNode
{
    int data;
    QNode* link;
    public:
    QNode()
    {
        data=-1;
        link=NULL;
    }
    QNode(int x)
    {
        data=x;
        link=NULL;
    }
    friend class Queue;
};


class Queue
{
    QNode *front;
    QNode *rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    bool isempty()
    {
        if(front==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int x)
    {
        QNode *temp=new QNode(x);
        if(isempty())
        {
            rear=temp;
            front=temp;
        }
        else
        {
            rear->link=temp;
            rear=temp;
        }
    }

    int wfront() // @suppress("No return")
    {
        if(!isempty())
        {
            return front->data;
        }
        return 0;
    }

    void dequeue()
    {
        if(!isempty())
        {
            QNode *temp=front;
            front=front->link;
            delete temp;
        }

    }
};

class Node
{
    int vertex;
    Node* next;
    public:
    Node()
    {
        vertex=-1;
        next=NULL;
    }
    Node(int x)
    {
        vertex=x;
        next=NULL;
    }
    friend class Graph;
};

class Graph
{
    int no_vertex;
    int no_edges;
    Node ** header;
    bool *visited;
    public:

    Graph()
    {
        no_vertex=0;
        no_edges=0;
        header=NULL;
        visited=NULL;
    }

    Graph(int x,int y)
    {
        no_vertex=x;
        no_edges=y;
        header=new Node*[x];
        visited=new bool[x];
        for(int i=0; i<x;i++)
        {
            header[i]=NULL;
            visited[i]=false;
        }
    }

    void accept_graph()
    {
        int s,d;
        for(int i=0;i<no_edges;i++)
        {
            cout<<"Enter the source vertex : ";
            cin>>s;
            cout<<"Enter the destination vertex : ";
            cin>>d;
            add_edge(s,d);
        }
    }

    void add_edge(int s,int d)
    {
        Node *dest=new Node(d);

        if(header[s]==NULL)
        {
            header[s]=dest;
        }

        else
        {
            Node *temp=header[s];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=dest;
        }
    }

    void display()
    {

        for(int i=0;i<no_vertex;i++)
        {
            cout<<i<<" -> ";
            Node *temp=header[i];
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    cout<<temp->vertex<<endl;
                    temp=temp->next;
                }
                else
                {
                    cout<<temp->vertex<<" , ";
                    temp=temp->next;
                }
            }
        }
    }

    void topo_sort()
    {
        Queue q;
        int ind;
        int indegree[no_vertex];
        for(int i=0;i<no_vertex;i++)
        {
            indegree[i]=0;
        }
        for(int i=0;i<no_vertex;i++)
        {
            Node *temp=header[i];
            while(temp!=NULL)
            {
                indegree[temp->vertex]++;
                temp=temp->next;
            }

        }
        for(int i=0;i<no_vertex;i++)
        {
            cout<<"Indegree of "<<i<<" is "<<indegree[i]<<endl;
        }
        for(int i=0;i<no_vertex;i++)
        {
            ind=indegree[i];
            if(ind==0)
            {
                q.enqueue(i);
            }
        }
        cout<<"Topological sort : "<<endl;
        while(!q.isempty())
        {
            int k=q.wfront();
            q.dequeue();
            indegree[k]=-1;
            cout<<k<<"  ";
            Node *temp=header[k];
            while(temp!=NULL)
            {
                indegree[temp->vertex]--;
                temp=temp->next;
            }
            for(int i=0;i<no_vertex;i++)
            {
                ind=indegree[i];
                if(ind==0)
                {
                    q.enqueue(i);
                }
            }
        }
    }
};
int main()
{
int ch;
int x,y;
cout<<"Enter the number of vertices : ";
cin>>x;
cout<<"Enter the number of edges : ";
cin>>y;
Graph g1(x,y);
while(true)
{
cout<<"1.Create\n2.Display\n3.Topological Sort\n4.Exit\n";
cout<<"Enter your choice : ";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
    g1.accept_graph();
    break;
case 2:
    g1.display();
    break;
case 3:
    g1.topo_sort();
    break;
case 4:
    cout<<"Program Ended!";
    exit(1);
    break;
default:
    cout<<"Invalid choice!"<<endl;
}
}
return 0;
}



