#include<iostream>
using namespace std;
#define size 100
class Hash_Entry
{
    long int no;
    string name;
    friend class Telephone;
    public:
    Hash_Entry()
    {
        no =0;
        name ="";
    }
    Hash_Entry(int x,string y)
    {
        no=x;
        name=y;
    }
};
class Telephone
{
    Hash_Entry table[size];
    public:

    int Hash_Function(long int key);
    void withoutReplacementInsert(long int key,string name);
    void withReplacementInsert(long int key,string name);
    void search(int key);
    void display()
    {
        for(int i=0;i<100;i++)
        {
            if(table[i].no!=0)
            {
                cout<<"Index-"<<i<<","<<"Name-"<<table[i].name<<","<<"Number-"<<table[i].no<<endl;
            }
        }
    }
};

int Telephone::Hash_Function(long int key)
{
    return (key%100);
}
void Telephone::withoutReplacementInsert(long int key,string name)
{
    int index=Hash_Function(key);

    if(table[index].no==0)
    {
       table[index].no=key;

        table[index].name=name;
    }
    else
    {
        int i=index;
        while(i<=100 && table[i].no!=0)
        {
            i++;
        }
        table[i].no=key;
        table[i].name=name;
    }
}
void Telephone::withReplacementInsert(long int key,string name)
{
    int index=Hash_Function(key);
   // int i=index;
    if(table[index].no==0)
    {
        table[index].no=key;
        table[index].name=name;
    }
    else
    {

            int v=table[index].no;
            string name1=table[index].name;
            table[index].no=key;
            table[index].name=name;

            while(index<=100 && table[index].no!=0)
            {
                index++;
            }
            if(index<=100)
            {
                table[index].no=v;
                table[index].name=name1;
            }
            else
            {
                int j=0;
                while(j<index && table[j].no!=0)
                {
                    j++;
                }
                if(j<index)
                {
                    table[j].no=v;
                    table[j].name=name1;
                }
                else
                {
                    cout<<"Hash Table Is Full"<<endl;
                }
            }

    }

}

void Telephone::search(int key)
{
    int value = Hash_Function(key);
int index = value;
int count = 0;
if(table[value].no == key)
    {
count++;
cout<<"Value Found! \n"<<"no Of Comparisons-"<<count<<endl;
cout<<table[value].name<<"->"<<table[value].no<<endl;
}
else
    {
while(value<=size)
        {
count++;
if(table[value].no==key)
            {
break;
}
value++;
}
if(value<=size && table[value].no==key)
        {
cout<<"Value Found! \n"<<"no Of Comparisons-"<<count<<endl;
cout<<table[value].name<<"->"<<table[value].no<<endl;
}
else
        {
int i = 0;
while(i<index && table[i].no!=key)
            {
count++;
i++;
}
if(table[i].no==key)
            {
cout<<"Value Found! \n"<<"no Of Comparisons-"<<count<<endl;
cout<<table[i].name<<"->"<<table[i].no<<endl;
}
else
            {
cout<<"Value Is Not Present!"<<endl;
}
}
}
}

int main()
{
    Telephone t;
    z:
    cout<<"Main Menu-\n1.Create Hash table"
    "\n2.Display Hash Table"
    "\n3.Search Hash Table"
    "\n4.Delete Entry"
    "\n5.Update Entry"<<endl;
    cout<<"Enter Your Choice-";
    int a;
    cin>>a;
    if(a==1)
    {
        cout<<"Enter Total Number Of Entries-";
        int n;
        cin>>n;
        cout<<"1.Insert Without Replacement\n2.Insert With Replacement"<<endl;
        cout<<"Enter Your Choice-";
        int c;
        cin>>c;
        while(n!=0)
        {
            string Name;
            long int K;
            cout<<"Enter Name-";
            cin>>Name;
            cout<<"Enter Number-";
            cin>>K;
            if(c==1)
            {
                t.withoutReplacementInsert(K,Name);
            }
            else if(c==2)
            {
                t.withReplacementInsert(K,Name);
            }
            n--;
        }
        cout<<"Do You Want To Continue?(Y/N)-";
        string r;
        cin>>r;
        if(r=="Y" || r=="y")
        {
         goto z;
        }
    }
    else if(a==2)
    {
        t.display();
        cout<<"Do You Want To Continue?(Y/N)-";
        string r;
        cin>>r;
        if(r=="Y" || r=="y")
        {
         goto z;
        }
    }
    else if(a==3)
    {
        cout<<"Enter Number To Be Searched-";
        long int g;
        cin>>g;
        t.search(g);
        cout<<"Do You Want To Continue?(Y/N)-";
        string r;
        cin>>r;
        if(r=="Y" || r=="y")
        {
         goto z;
        }
    }
    else if(a==4)
    {
    long int n;
    cout<<"Enter the phone number to be deleted-";
    cin>>n;
//    t.Delete(n);
    cout<<"Do You Want To Continue?(Y/N)-";
    string r;
    cin>>r;
    if(r=="Y" || r=="y")
    {
    goto z;
    }

    }
    else if(a==5)
        {
        long int n,n1;
        cout<<"Enter the phone number to be updated-";
        cin>>n;
        cout<<"Enter new phone number-";
        cin>>n1;
;
        cout<<"Do You Want To Continue?(Y/N)-";
        string r;
        cin>>r;
        if(r=="Y" || r=="y")
        {
        goto z;
        }

        }
       return 0;
}




