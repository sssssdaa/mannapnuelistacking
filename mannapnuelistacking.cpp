
#include<iostream>
using namespace std;

class stack
{
  public:
      stack() {top = 0;}
      int push(int value)
      {
           if (top+1<=maxsize)  {
                top++;
                S[top]=value;
                return 1;}
        return 0;}
        int pop(int *old);
        int whathight() {return top;}
        int isempty() { return (top<1);}
        private :
        int top;
        int S[100];
        int maxsize=100;
};


/*
  fact : N* ----> N*

  x-1, x>=12;
  F(F(x+2)), x<12;
*/
int n;
stack somestack;

int main()
{
cout<<"n=";cin>>n;
somestack.push((n+2)-3);
int direction=1;
int oldval1,oldval2;
while (somestack.whathight()>=1) {
    cout<<endl<<somestack.whathight();
    if (direction==1)
            {
            somestack.pop(&oldval1);
            somestack.push(oldval1);
            somestack.push(oldval1-1);
                                        if (oldval1==0) direction=0;}
                                        else
                                        {
                                            somestack.pop(&oldval1);
                                            somestack.push(oldval1+2);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);
                                            somestack.pop(&oldval1-1);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);

                                        }

                                        /*


                                        f (8) = f ( f (10) ) = f ( f ( f (12) ) ) = f ( f (11) ) = f ( f ( f (13) ) ) =

        = f ( f (12) ) = f (11) = f ( f (13) ) = f (12) = 11.-








                                        */



    /*              F(F(13)) = F(F(13-1+2) = F(F(14)) = F(13) = 12
                                                       else {
                                                                somestack.pop(&oldval1);
                                                                if (somestack.pop(&oldval2))
                                                                    {somestack.push(oldval1+oldval2);}
                                                               }

                                                    */
                                                     }
cout<<" Compute = "<<oldval1;
return 0;}

int stack::pop(int *old)
{if  (isempty()) { return 0;}
 *old=S[top];top--;
 return 1;}
