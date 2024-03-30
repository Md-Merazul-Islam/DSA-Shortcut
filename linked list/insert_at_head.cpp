#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *next_value;
    Node(int value)
    {
        this->value = value;
        this->next_value = NULL;
    }
};

void insert_at_head(Node*&head,int v)
{
    Node* newnode = new Node(v);
    newnode->next_value= head;
    head=newnode;
    cout<<"Inserted at new head"<<endl;
}


int main()
{
    Node *head = NULL;
    while (true)
    {
        cout << "Option 1 : Insert at tail " << endl;
        cout << "Option 2 : Print Linked list " << endl;
        cout << "Option 3 : Insert any position " << endl;
        cout << "Option 4 : Insert at head " << endl;
        cout << "Option 5 : terminate " << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Please enter the value :"<<endl;
            int v;
            cin >> v;
            insert_at_position(head, v);
        }

        else if (op==2)
        {

            priting_linked_list(head);
        }
        else if (op==3)
        {
            
            int pos,v;
            cout<<"Enter the position: "<<endl;
            cin>>pos;
            cout<<"Enter the value : "<<endl;
            cin>>v;
            if ( pos ==0)
            {
                insert_at_head(head,v);
            }
            else{

            insert_pos_value(head,pos,v);
            }
        }
        else if ( op==4)
        {
            int v;
            cout<<"Enter the value : "<<endl;
            cin>>v;
            insert_at_head(head,v);
        }
        else if (op==5)
        {
            cout<<"program finish";
            break;
        }
    }
    return 0;
}
