/*
As remainder must always be +ve, we need to implement a function to handle modulo of -ve numbers. 
*/

inline int positiveModulo(long long a, int b) {
    
    return (a%b+b)%b;                           //always returns only positive remainder
    
}

int Solution::pow(int x, int n, int d) {
    
    if(x==0)
        return 0;                               //any power of 0 is always 0
    else if(n==0)
        return 1;                               //any no. with power 0 is always 1
    else if(n==1)
        return positiveModulo(x,d);
        
    long long temp=pow(x,n/2,d);
    temp=positiveModulo(temp*temp,d);
    
    if(n%2==0)
        return temp;                            //if n is even, n=(n/2)+(n/2)
    else
        return positiveModulo(temp*x,d);        //if n is odd, n=(n/2)+(n/2)+1
    
}
