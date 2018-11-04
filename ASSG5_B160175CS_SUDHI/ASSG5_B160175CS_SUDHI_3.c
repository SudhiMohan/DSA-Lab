#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int n,heapsize=-1,dest,distance[10000],vstd[10000],heap[10000];
struct vertex
{
	int data,weight;
	struct vertex *next;
};

struct table{
    struct vertex *list;
}adjacencylist[10000];

void min_heapify(int i);
int extract_min();
int parent(int x);
void dijkstra(int start);
void heap_insert(int i);
void insert_edge(int i,int x);
void relax(struct vertex *ptr, int u);
void print();

int main()
{
int i,j;int y,z;
int t,d;char x,c;
  scanf("%d",&n);
  scanf("%c",&c);
for( i=0;i<n;i++)
 {
     vstd[i]=0;
 }
for(j=0;j<n;j++)
   {
      adjacencylist[j].list=NULL;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            y=c-'0';
            while(1)
            {
                scanf("%c",&x);
                if(x=='\n' || x==' ' ) break;
                z=x-'0';
                y=y*10 +z;
                
            }
        }
       
        struct vertex *newnode=malloc(sizeof(struct vertex));
        newnode->data=y;
        newnode->weight=0;
        newnode->next=NULL;
        if(adjacencylist[j].list==NULL)
        {
            adjacencylist[j].list=newnode;
        }
        else
        {
            struct vertex *temp=adjacencylist[j].list;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
        if(x=='\n') break;
        
    }
  }
  
  for(j=0;j<n;j++)
   {
       struct vertex*temp=adjacencylist[j].list;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            y=c-'0';
            while(1)
            {
                scanf("%c",&x);
                if(x=='\n' || x==' ' ) break;
                z=x-'0';
                y=y*10 +z;
                
            }
        }
        temp->weight=y;
        temp=temp->next;
        if(x=='\n') break;
        
    }
  }
  char ch[4];
  while(1)
  {
  scanf("%s",ch);
  if(!strcmp(ch,"apsp"))
  {
      scanf("%d",&t);
      dijkstra(t);
      for(i=0;i<n;i++)
         {
           if(distance[i]==10001)
            printf("INF ");
           else
            printf("%d ",distance[i]);
          }
      printf("\n");
      for(i=0;i<n;i++)
      vstd[i]=0;
  }
  else if(!strcmp(ch,"sssp"))
  {
       scanf("%d%d",&t,&d);
       dijkstra(t);
     if(distance[d]==10001)
     printf("UNREACHABLE\n");
     else
      printf("%d\n",distance[d]);
      for(i=0;i<n;i++)
      vstd[i]=0;
  }
  else if(!strcmp(ch,"stop"))
  exit(0);
  }
  return 0;
}


void insert_edge(int i,int x)
{
	struct vertex *ptr=(struct vertex*)malloc(sizeof(struct vertex));
	ptr->data=x;
	ptr->weight=0;
	ptr->next=NULL;

	if(adjacencylist[i].list==NULL)
	{	adjacencylist[i].list=ptr;
		return;
	}
	struct vertex *temp=adjacencylist[i].list,*prev=NULL;
	
	while(temp!=NULL)
	{	prev=temp;
		temp=temp->next;
	}
	
	prev->next=ptr;
}


void heap_insert(int i)
{
	heapsize++;
	heap[heapsize]=i;
	i=heapsize;
	while(i>0 && distance[heap[parent(i)]]>distance[heap[i]])
	{       
		int swap=heap[parent(i)];
	        heap[parent(i)]=heap[i];
	        heap[i]=swap;
	        i=parent(i);

	}
}




void min_heapify(int i)
{
	int l=2*i+1,r=2*i+2;
	int smallest;

	if(l<=heapsize && distance[heap[l]] < distance[heap[i]])
		smallest=l;
	else smallest=i;

	if(r<=heapsize && distance[heap[r]] < distance[heap[smallest]] )
		smallest=r;

	if(smallest!=i)
	{
		int temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		min_heapify(smallest);
	}


}



int extract_min()
{	
	int temp=heap[0];
	heap[0]=heap[heapsize];
	heapsize--;
	min_heapify(0);
	return temp;
}

int parent(int x)
{
	if(x%2==0)
		return (x-2)/2;
	return (x-1)/2;
}
void dijkstra(int start)
{
	int i;
	for(i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		vstd[i]=0;	
	}

	distance[start]=0;

	heap_insert(start);

	while(heapsize!=-1)
	{
		int u=extract_min();

		vstd[u]=1;
		struct vertex *ptr=adjacencylist[u].list;
		//relax(ptr,u);
		while(ptr!=NULL)
		{

			if(vstd[ptr->data]==0)
			 {      
			 	int t=distance[u]+ptr->weight;
				if(t < distance[ptr->data])
            				distance[ptr->data]=t;
             			heap_insert(ptr->data);

         		 }	
		
			ptr=ptr->next;	
		}

	
	}

}
void relax(struct vertex *ptr,int u)
{
	
		while(ptr!=NULL)
		{//printf("%d\n",ptr->data);
			if(vstd[ptr->data]==0)
			 {      
			 	int t=distance[u]+ptr->weight;
				if(t < distance[ptr->data])
            				distance[ptr->data]=t;
             			heap_insert(ptr->data);

         		 }			
			ptr=ptr->next;	
		}

}

void print()
{
	int i=0;
	while(i<n)
	{
		struct vertex *ptr=adjacencylist[i].list;
		
		while(ptr!=NULL)
		{
			printf("%d %d  %d\n",i,ptr->data,ptr->weight);
			ptr=ptr->next;
		}printf("\n");
		i++;
	//printf("%d %d\n",i,n);

	}
	return;
}
