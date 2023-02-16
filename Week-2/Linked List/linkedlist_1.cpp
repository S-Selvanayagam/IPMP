// GFG get Nth From Last
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


int length(Node *head)
{
    int len=0;
    Node *temp = head;
    if(head == NULL ) return 0;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

int getNthFromLast(Node *head, int n)
{
    int len =length(head);
    if (n>len) return -1;
    if(head == NULL ) return 0;
    int x = len - n + 1;
    for(int i=1; i<x;i++)
    {
        head = head->next;
    }
    return head->data;
}

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}



