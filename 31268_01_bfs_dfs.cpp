#include <iostream>
using namespace std;
#define MAX 10
class Queue
{
	int *arr;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue(int size = MAX);
	~Queue();
	void dequeue();
	void enqueue(int x);
	int peek();
 	int size();
 	bool isEmpty();
 	bool isFull();
};
Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}
Queue::~Queue()
{
	delete[] arr;
}
void Queue::dequeue(){
	if (isEmpty())
	{
		cout << "Underflow\n";
		return;
	}
	front = (front + 1) % capacity;
	count--;
}
void Queue::enqueue(int item)
{
	if (isFull())
	{
		cout << "Overflow\n";
		return;
	}
	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}
int Queue::peek()
{
	if (isEmpty())
	{
		cout << "Underflow\n";
		return -1;
	}
	return arr[front];
}
int Queue::size()
{
	return count;
}
bool Queue::isEmpty()
{
	return (size() == 0);
}
bool Queue::isFull()
{
	return (size() == capacity);
}
class Node{
	int vertex;
	Node* next;
	public:
	Node(int d){
		vertex=d;
		next=NULL;
	}
friend class Graph;
};

class Graph{
	int v,e;
	Node **adjlist;
public:
	Graph(int v,int e){
		this->v=v;
		this->e=e;
		adjlist=new Node *[v];
		for(int i=0;i<v;i++){
			adjlist[i]=NULL;
		}
	}
	void insert();
	void display();
	void dfs(int,int[]);
	void bfs(int);
};
void Graph::insert(){
	int s,d;
	cout<<"Enter source vertex: ";
	cin>>s;
	cout<<"Enter destination vertex: ";
	cin>>d;
	Node *temp=new Node(d);
	if(adjlist[s]==NULL){
		adjlist[s]=temp;
	}
	else
	{
		Node *t=adjlist[s];
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=temp;
	}
	Node *tmp=new Node(s);
	if(adjlist[d]==NULL)
	{
		adjlist[d]=tmp;
	}
	else
	{
		Node *t=adjlist[d];
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=tmp;
	}
}
void Graph::display(){
	for(int i=0;i<v;i++){
		cout<<endl<<i<<" ==>";
		Node *t=adjlist[i];
		while(t!=NULL)
		{
			cout<<t->vertex<<" ";
			t=t->next;
		}
	}
}
void Graph::dfs(int start, int visited[]){
	visited[start] = 1;
	cout << start << " ";
	Node *tmpptr=adjlist[start];
	while(tmpptr!=NULL)
	{
		if (visited[tmpptr->vertex] == 0)
		{
			dfs(tmpptr->vertex,visited);
		}
		tmpptr=tmpptr->next;
	}
}
void Graph::bfs(int start){
	int visited[v]={0};
	Queue q;
	q.enqueue(start);
	visited[start] = 1;
	while (!q.isEmpty())
	{
		int vertx = q.peek();
		q.dequeue();
		cout << vertx << " ";
		for (Node *tmpptr = adjlist[vertx]; tmpptr !=NULL; tmpptr = tmpptr->next)
		{
			if (visited[tmpptr->vertex] == 0)
			{
				q.enqueue(tmpptr->vertex);
				visited[tmpptr->vertex] = 1;
			}
		}
	}
}
int main() {
	int tv,te,s,choice;
	cout<<"\nEnter total no of vertices: ";cin>>tv;
	cout<<"Enter total no of edges: ";
	cin>>te;
	int visited[tv]={0};
	Graph g(tv,te);
	while(1)
	{
		cout<<endl; cout<<"\n------------MENU------------\n";
		cout<<"1.Create Graph\n";
		cout<<"2.Display \n";
		cout<<"3.DFS\n";
		cout<<"4.BFS\n";
		cout<<"5.Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice){
		case 1:
			for(int i=0;i<te;i++){
				g.insert();
			}
			break;
		case 2:
			g.display();
			break;
		case 3:
			cout<<"\nEnter start vertex: ";
			cin>>s;
			g.dfs(s, visited);
			break;
		case 4:
			cout<<"\nEnter start vertex: ";
			cin>>s;
			g.bfs(s);
			break;
		case 5:
			exit(0);
		default:
			cout<<"\nEnter correct choice: ";
		}
	}
	return 0;
}


// Enter total no of vertices: 5
// Enter total no of edges: 5


// ------------MENU------------
// 1.Create Graph
// 2.Display 
// 3.DFS
// 4.BFS
// 5.Exit
// Enter choice: 1
// Enter source vertex: 0
// Enter destination vertex: 1
// Enter source vertex: 0
// Enter destination vertex: 3
// Enter source vertex: 0
// Enter destination vertex: 4
// Enter source vertex: 1
// Enter destination vertex: 2
// Enter source vertex: 2
// Enter destination vertex: 3


// ------------MENU------------
// 1.Create Graph
// 2.Display 
// 3.DFS
// 4.BFS
// 5.Exit
// Enter choice: 2

// 0 ==>1 3 4 
// 1 ==>0 2 
// 2 ==>1 3 
// 3 ==>0 2 
// 4 ==>0 

// ------------MENU------------
// 1.Create Graph
// 2.Display 
// 3.DFS
// 4.BFS
// 5.Exit
// Enter choice: 3

// Enter start vertex: 0
// 0 1 2 3 4 

// ------------MENU------------
// 1.Create Graph
// 2.Display 
// 3.DFS
// 4.BFS
// 5.Exit
// Enter choice: 4

// Enter start vertex: 0
// 0 1 3 4 2 

// ------------MENU------------
// 1.Create Graph
// 2.Display 
// 3.DFS
// 4.BFS
// 5.Exit
// Enter choice: 5