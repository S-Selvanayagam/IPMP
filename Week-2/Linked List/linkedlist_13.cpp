// reverse in groups of k in a linked list
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(!head || k==1) return head;
        struct node *prev = NULL;
        struct node *curr = head;
        struct node *nhead = NULL;
        struct node *tail = NULL;  
        while(curr)
        {
            int count = k;
            struct node *prev1 = NULL;
            struct node *curr1 = curr;
            
            while(curr1 && count >0)
            {
                struct node *next = curr1->next;
                curr1->next = prev1;
                prev1 = curr1;
                curr1 = next;
                count --;
            }
            
            if(!nhead)
            {
                nhead = prev1;
            }
            if(tail)
            {
                tail->next = prev1;  
            }
            tail = curr;
            curr = curr1;
        }
        return nhead;
        
    }
};

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}
