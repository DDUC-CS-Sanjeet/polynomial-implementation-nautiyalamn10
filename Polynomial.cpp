#include<iostream>
using namespace std;

class Polynomial
{
	int array[100];
	int power;
	
	 // Variables to store information about polynomial
	 public:
	 	
	 	Polynomial()
	 	{
	 		power=1;
		}
		Polynomial(int deg)
		{
			// Behavior of constructor with arguments
			cout<<"Enter the degree of polynomial "<<deg<<" : ";
			cin>>power;
			power++;	
		}
		~Polynomial()
        {
             // Behavior of destructor
        }
         //  Overload copy constructor, +, - and = operators
        Polynomial operator +(Polynomial z)
		{
			Polynomial p;
			p.power=this->power>=z.power? this->power:z.power;
			for(int i=0;i<p.power;i++)
			{
				if(i>=this->power)
				  this->array[i]=0;
				if(i>=z.power)
				  z.array[i]=0;
				  p.array[i]=z.array[i]+this->array[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial z)
		{
			Polynomial p;
			p.power=this->power>=z.power? this->power:z.power;
			for(int i=0;i<p.power;i++)
			{
				if(i>=this->power)
				  this-> array[i]=0;
				if (i>=z.power)
				  z.array[i]=0;
				  p.array[i]=this->array[i]-z.array[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial z)
		{
			Polynomial p;
			this->power=z.power;
			for(int i=0;i<this->power;i++)
			  this->array[i]=z.array[i];
	    }
	    void storePolynomial()
        {
                //  Code to enter and store polynomial	
            cout<<"\nEnter the cofficient in ascending order of powers "<<endl;
			for(int i=0;i<power;i++)
			cin>>array[i];
 	    }
 	    void display()
        {
            //  Code to print the polynomial in readable format
            cout<<endl;
            for(int i=0;i<power;i++)
            {
            	cout<<array[i]<<"X^"<<i;
            	if(i<power-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{int degFirst=1, degSecond=2;
  // Ask user to input the values of degFirst and degSecond
  
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"Your first polynomial is = ";
  firstPolynomial.display();
  cout<<endl;
  cout<<"Your second polynomial is = ";
  
  secondPolynomial.display();
  cout<<endl;
cout<<"Your third polynomial is = ";
  
  thirdPolynomial.display();
cout<<endl;
cout<<"Your fourth polynomial is = ";
    fourthPolynomial.display();
    return 0;

}
