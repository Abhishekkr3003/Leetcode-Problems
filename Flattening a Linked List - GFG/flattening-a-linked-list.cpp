// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
pair<Node*, Node*> findMin(Node *root){
    int minVal=root->data;
    Node *cur=root, *ptr=root->next;
    Node *curPrev=NULL;
    Node *prev=root;
    
    while(ptr){
        if(ptr->data<minVal){
            minVal=ptr->data;
            cur=ptr;
            curPrev=prev;
        }
        prev=ptr;
        ptr=ptr->next;
    }
    return {curPrev,cur};
}

Node *flatten(Node *root)
{
    
   
//   Node *ptr=root, *prev=NULL;
   Node *head=NULL, *tail=NULL;
   
//   cout<<root->data<<endl;
   
   while(root){
    //   cout<<root->data<<endl;
       pair<Node*,Node*>chain=findMin(root);
       Node *curMin=chain.second;
       Node *prevMin=chain.first;
       Node *nxtMin=curMin->next;
       
       if(!head) head=tail=curMin;
       else {
           tail->bottom=curMin;
           tail=tail->bottom;
       }
       if(curMin==root){
           if(root->bottom){
               root->bottom->next=root->next;
               root=root->bottom;
           }else{
               root=root->next;
           }
       }else{
           if(curMin->bottom){
               prevMin->next=curMin->bottom;
               curMin->bottom->next=curMin->next;
           }else{
               prevMin->next=nxtMin;
           }
       }
       curMin->next=NULL;
       curMin->bottom=NULL;
   }
   return head;
}

