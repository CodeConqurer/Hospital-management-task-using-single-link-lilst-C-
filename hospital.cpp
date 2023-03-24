#include<iostream>
using namespace std;
struct patient{
  string name;
  int age;
  int CNIC;
  string medhis;
  string currcond;
};

class node{
   patient p1;
   node*next;

   friend class Hospital;
   node(){
  this->next = NULL;
   }


   node(string name,int age,int CNIC, string medhis,string currcond ){
    this->p1.age=age;
    this->p1.CNIC=CNIC;
     this->p1.currcond=currcond;
      this->p1.medhis=medhis;
       this->p1.name=name;
       }
};
class Hospital{
   node*head;

   public:

   Hospital(){
    this->head=NULL;
   }

   void insert(string name,int age,int CNIC, string medhis,string currcond){
   
    node*newnode=new node(name,age,CNIC,medhis,currcond);

    if(this->head==NULL){
         
       //setting the head pointer
        
        head=newnode;
        newnode->next=NULL;

   }

   else{
    node*temp=head;

    while(temp->next!=NULL){
         temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=NULL;

   }
   
   }

   

   bool remove(string name){

      bool flag=false;

    node*temp=head;
    node*pre=head; 
           if(name==head->p1.name){
            head = head->next;
            flag=true;
            
           }
           else{
           while(temp->next!=NULL){
             if(temp->p1.name==name){
         pre->next = temp->next;
         pre->next = temp->next;
         temp->next=NULL;
         flag=true;
         break;
         }

         else{
          pre=temp;
          temp=temp->next;
         }
         
            
           }

           
           
           
           }



     return flag;
   }

   void show(){
    node*temp=this->head;
    while(temp!=NULL){
        cout<<temp->p1.name<<"\t\t"<<temp->p1.age<<"\t"<<temp->p1.CNIC<<"\t"<<temp->p1.medhis<<"\t\t"<<temp->p1.currcond<<endl;
        temp=temp->next;
    }
    cout<<endl;
   }
    
   bool search(int cnic){

    node*temp=head;
    bool flag=false;

    while(temp->next!=NULL){
      
      if(temp->p1.CNIC==cnic){
      
               flag=true;}
   else{
    temp=temp->next;
   }
   return flag;
   }
   
   
   
   
   return flag;

   }

   bool update(patient newdata, string olddata){

     bool flag=false;

    node*temp=head;
    if(head->p1.name==olddata){
      temp->p1.name=newdata.name;
      flag=true;
    }

    else{
      while(temp->next!=NULL){
        if(temp->p1.name==olddata){
          temp->p1.CNIC=newdata.CNIC;       
          temp->p1.age=newdata.age;
          temp->p1.medhis=newdata.medhis;
          temp->p1.currcond=newdata.currcond;
          temp->p1.name=newdata.name;
          flag=true;
        }
        else{
          temp=temp->next;
        }
      }
    }

       return flag;        }



   int countnode(){
    node*temp=head;
    int count=0;
    while(temp!=0)
{ 
    count++;
    temp=temp->next;

} 

return count;     }



bool updateatnode(int pos,patient p){
  int count=countnode();
   bool flag=false;
  if(pos>count && pos<count){
    flag=false;
    return flag;
  }

  else{
    int count2=01;
        node*temp=head;
        while(count2!=pos){
          temp=temp->next;
          count2++;
        }

        temp->p1.name=p.name;
        temp->p1.age=p.age;
        temp->p1.CNIC=p.CNIC;
        temp->p1.currcond=p.currcond;
        temp->p1.medhis=p.medhis;
        flag=true;
  }


return flag;
  
}

   bool displayspec(int cnic){
    bool flag=false;
    node*temp=head;
    while(temp->next!=NULL){
      if(temp->p1.CNIC==cnic){
      cout<<temp->p1.name<<"\t\t"<<temp->p1.age<<"\t"<<temp->p1.CNIC<<"\t"<<temp->p1.currcond<<"\t"<<temp->p1.medhis<<endl;
      flag=true;
      break;
      
      }
      
      else{
        temp=temp->next;
      }
    }

    
    return flag;
}};
int main()
{

    Hospital h1;
    h1.insert("John",19,1,"injured","under Observation");
    h1.insert("Harry",19,2,"injured","under Observation");
    h1.insert("Leo",19,3,"injured","under Observation");
    h1.insert("David",19,4,"injured","under Observation");
    cout<<"Name\t\tAge\tCNIC\t Conition\tCurrent Condition"<<endl<<endl;

        h1.show();
    
   if(h1.remove("John")==false){
    cout<<"---- John Not Found------"<<endl<<endl;
   }
   else{
    cout<<"Displaying record after removing John is: "<<endl<<endl;
    cout<<"Name\t\tAge\tCNIC\t Conition\tCurrent Condition"<<endl<<endl;
        h1.show();
}


    
   patient p1;
   p1.age=19;
   p1.CNIC=03;
   p1.medhis="Normal";
   p1.currcond="Normal";
   p1.name="Selena";

   if(h1.search(1)==false){
    cout<<"-----Record for Patient with CNIC 001 not found---------"<<endl;
   }

   else{

    cout<<"Displaying record of with CNIC 001 : "<<endl<<endl;
cout<<"Name\t\tAge\tCNIC\t Conition\tCurrent Condition"<<endl<<endl;
    h1.displayspec(1);
   }

   cout<<endl<<endl;

    


 if(h1.update(p1,"Harry")==true){
   cout<<"Displaying data after replacing John with Selena:  "<<endl;

    h1.show();}
    else{
      cout<<"------John Not Found-------"<<endl;
    }
    

    cout<<"Total Number of nodes: "<<h1.countnode()<<endl;
   
    if(h1.updateatnode(2,p1)==false){
      cout<<"---------Invali Node-----------"<<endl;
    }

    else{
      cout<<"---------Displaying updated data of 2nd node: ---------------"<<endl;
      cout<<"Name\t\tAge\tCNIC\t Conition\tCurrent Condition"<<endl<<endl;
       h1.show();
    }
return 0;
}