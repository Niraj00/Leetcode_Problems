#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;

class Heap
{
public:
    vector<int> getvector(int n)
    {   vector<int> operation;
        int a;
        cout<<"Enter elements: "<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            operation.push_back(a);

        }
        return operation;

    }

    int getleftchild(vector<int> &operation, int parent)
    {
      int leftchildindex=(parent*2)+1;
      if(leftchildindex<operation.size())
      {
          return leftchildindex;
      }
      else return -1;

    }

    int getrightchild(vector<int> &operation, int parent)
    {
      int rightchildindex=(parent*2)+2;
      if(rightchildindex<operation.size())
        return rightchildindex;

      else return -1;

    }

    int getparent(int child)
    {
         return (child-1)/2;

    }
    void doinsert(vector<int> &operation)
    {   cout<<"insert your element at the end;"<<endl;
        int a;
        cin>>a;
        operation.push_back(a);
        doprecolateup(operation, operation.size()-1);
    }

    void doprecolateup(vector<int> &operation, int pos)
    {

        int parentindex=getparent(pos);
        if(operation[parentindex]<operation[pos])
        {
            swap(operation[parentindex], operation[pos]);
            doprecolateup(operation, parentindex);
        }
    }

    void dodelete(vector<int> &operation)
    {
        operation[0]=operation[operation.size()-1];
        operation.pop_back();

        doprecolatedown(operation, 0);
    }

    void doprecolatedown(vector<int> &operation, int pos)
    {
        int leftchildindex=getleftchild(operation, pos);
        int rightchildindex=getrightchild(operation, pos);
        int maxindex=pos;

        if(leftchildindex!=-1 && operation[leftchildindex]>operation[maxindex])
            maxindex=leftchildindex;

        if(rightchildindex!=-1 && operation[rightchildindex]>operation[maxindex])
            maxindex=rightchildindex;

        if(pos!=maxindex)
        {
            swap(operation[pos], operation[maxindex]);
            doprecolatedown(operation, maxindex);
        }


    }

    void show(vector<int> &operation)
    {
        cout<<"showing vector: "<<endl;
        for(int i=0; i<operation.size(); i++)
        {
            cout<<operation[i]<<" " ;
        }
        cout<<endl;
    }
};

int main()
{
    Heap object;
    vector<int> operation;

    cout<<"Enter size of vector: "<<endl;
    int n;
    cin>>n;

    operation=object.getvector(n);
    object.show(operation);

    object.doinsert(operation);
    object.show(operation);

    object.dodelete(operation);
    object.show(operation);

}
