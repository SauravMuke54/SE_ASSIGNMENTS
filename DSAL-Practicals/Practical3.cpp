#include <iostream>
using namespace std;

class Node
{

public:

        Node *left, *right;
        int data;
        int rflag, lflag;
    Node()
    {
        left = NULL;
        right = NULL;
        rflag = lflag =0;
    }
    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
        rflag = lflag = 0;
    }

};

class Threaded_Binary_Tree
{
public:
    Node *root, *head;
    Threaded_Binary_Tree()
    {
        root = NULL;
        head = new Node(500);
        head->right = head->left = head;
    }
    void insert(int d);
    void inorder();
    void preorder();

    Node *inorderSuccessor(Node *ptr)
    {
        if (ptr->rflag == 1)
            return ptr->right;
        ptr = ptr->right;
        while (ptr->lflag == 0)
            ptr = ptr->left;
        return ptr;
    }
    Node *inorderPredesessor(Node *ptr)
    {
        if (ptr->lflag == 1)
            return ptr->left;
        ptr = ptr->left;
        while (ptr->rflag== 0)
            ptr = ptr->right;
        return ptr;
    }

    void delete_Node(int x)
    {
        if (head->left == NULL)
        {
            cout << "Tree is Empty!!" << endl;
            return;
        }
        Node *temp = head->left;
        Node *parent = head;

        while (temp != head)
        {
        int found=0;
            if (temp->data == x)
            {
                found = 1;
                break;
            }
            else if (temp->data > x)
            {
                if (temp->lflag == 1)
                {
                    cout << "Element not found!!" << endl;
                    return;
                }
                parent = temp;
                temp = temp->left;
            }
            else if (temp->data < x)
            {
                if (temp->rflag == 1)
                {
                    cout << "Element not found!!" << endl;
                    return;
                }
                parent = temp;
                temp = temp->right;
            }
        }

        if (temp->lflag == 0 && temp->rflag == 0)
        {
            Node *successor = temp->right;
            Node *parent_successor = temp;
            Node *child = NULL;

            while (successor->lflag != 1)
            {
                parent_successor = successor;
                successor = successor->left;
            }
            temp->data = successor->data;
            if (successor->lflag == 1 && successor->rflag == 1)
            {
                if (parent_successor == temp)
                {
                    parent_successor->right = successor->right;
                    parent_successor->rflag = 1;
                    delete successor;
                    cout << "Node deleted!!" << endl;
                    return;
                }
                parent_successor->left = successor->left;
                parent_successor->lflag = 1;
            }
            else
            {
                parent_successor->left = successor->right;
                child = successor->right;
                child->left = successor->left;
            }
            delete successor;
            cout << "Node deleted!!" << endl;
            return;
        }

        else if (temp->lflag == 0 || temp->rflag == 0)
        {
            Node *child = NULL;

            if (temp->lflag == 0)
            {
                child = temp->left;
            }
            else
            {
                child = temp->right;
            }
            if (temp == root)
            {
                head->left = child;
                root = child;
            }

            else if (parent->left == temp)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }

            Node *s = inorderSuccessor(temp);
            Node *p =inorderPredesessor(temp);

            if (temp->lflag == 0)
            {
                p->right = s;
            }

            else
            {
                s->left = p;
            }
            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }
        else
        {

            if (temp == root)
            {
                head->left = NULL;
                root = NULL;
            }

            else if (parent->left == temp)
            {
                parent->lflag = 1;
                parent->left = temp->left;
            }

            else
            {
                parent->rflag = 1;
                parent->right = temp->right;
            }
            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }
    }


};

void Threaded_Binary_Tree::insert(int d)
{
    if (root == NULL)
    {
root = new Node(d);
        root->left = root->right = head;
        root->lflag = root->rflag = 1;
        head->left = root;
        head->lflag = 1;
        cout << "\n sucessfully inserted" << endl;
    }
    else
    {
        Node *current = root;
        while (current != NULL)
        {
            if (current->data > d)
            {
                Node *p = new Node(d);
                if (current->lflag == 1)
                {
                    p->left = current->left;
                    current->left = p;
                    p->lflag = 1;
                    current->lflag = 0;
                    p->right = current;
                    p->rflag = 1;
                    cout << "\n sucessfully inserted" << endl;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }

            if (current->data < d)
            {
                Node *p = new Node(d);
                if (current->rflag == 1)
                {
                    p->right = current->right;
                    current->right = p;
                    p->rflag = 1;
                    current->rflag = 0;
                    p->left = current;
                    p->lflag = 1;
                    cout << "\n sucessfully inserted" << endl;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
}

void Threaded_Binary_Tree::inorder()
{
    Node *p = root;
    while (p->lflag == 0)
        p = p->left;
    while (p != head)
    {
        cout << p->data << "  ";
        if (p->rflag == 0)
        {
            p = p->right;
            while (p->lflag == 0)
                p = p->left;
        }
        else
            p = p->right;
    }
}
void Threaded_Binary_Tree::preorder()
{
    Node *temp = root;
    while (temp != head)
    {
        while (temp->lflag == 0)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rflag == 1)
        {
            temp = temp->right;
            if (temp == head)
                return;
        }
        temp = temp->right;
    }
}






int main()
{
    Threaded_Binary_Tree t;
    int ch;
    while (true)
    {
        cout << "\n<<-----MENU----->>" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal " << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. delete data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "\nEnter number of Nodes:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int data;
                cout << "\nEnter data: ";
                cin >> data;
                t.insert(data);
            }
            break;
        }
        case 2:
        {
        cout<<endl<<endl;
            cout << "*****Inorder Traversal*****" << endl;
            t.inorder();
            break;
        }
        case 3:
        {
        cout<<endl<<endl;
            cout << "*****Preorder Traversal***** " << endl;
            t.preorder();
            break;
        }
        case 4:
                {
                int d;
                    cout << "*****delete node***** " << endl;
                    cout<<"enter data you want to delete:  "<<endl;
                    cin>>d;
                    t.delete_Node(d);
                    break;
                }

        case 5:
            exit(1);
            break;
        default:
            cout << "enter correct choice!" << endl;
        }
    }
    return 0;
}


