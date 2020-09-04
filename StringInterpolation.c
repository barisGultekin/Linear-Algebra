#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <complex.h>

float real;
float img;
float pi=4*atan(1.0);

float convertcartesian1(char input[], float *PR , float *PI)
{
 
	int i,j,m=0;
	int count;
	char polstr[52]={0};
	
	
	for(i=0; i<50; i++)
	{
		if(input[i]=='e' && input[i+1]=='x' && input[i+2]=='p'&& input[i+3]=='(')
		{
			j=i+3;
			count=0;
			while(input[j+1]!=')')
			{
				j++;
				if(input[i+4]>='0' && input[i+4]<='9' && count==0)
				{
					polstr[m]='+';
					m++;
					count=1;
					
				}
				if(input[i+4]=='p' && count==0)
				{
					polstr[m]='+';
					m++;
					count=1;
				}
				polstr[m]=input[j];
				m++;
			}
		}
	}

/*	puts(polstr);*/
	i=0;
	int coef[50]={1};
	j=0;
 while(input[i]!='\0')
	{
		if(input[i]=='e')
		{
			if(input[i-1]>='0' && input[i-1]<='9' && input[i-2]>='0'&& input[i-2]<='9' && input[i-3]=='-')
			{
				
				coef[j]=-1*(10*(input[i-2]-'0')+input[i-1]-'0');
				j++;
				i++;
			}
			if(input[i-1]>='0' && input[i-1]<='9' && input[i-2]>='0'&&input[i-2]<='9')
			{
				coef[j]=10*(input[i-2]-'0')+input[i-1]-'0';
				j++;
				i++;
			}
			
			if(input[i-1]>='0' && input[i-1]<='9' && input[i-2]=='-')
			{
				coef[j]=-1*(input[i-1]-'0');
				j++;
			}
			if(input[i-1]>'0' && input[i-1]<='9' && input[i-2]!='-')
			{
				coef[j]=(input[i-1]-'0');
				j++;
			}
			if(input[i-1]=='-')
			{
				coef[j]=-1;
				j++;
			}
			if(input[i-1]=='+')
			{
				coef[j]=1;
				j++;
			}
			if(input[i-1]==NULL)
			{
				coef[j]=1;
				j++;
			}
		}
		i++;
	}


	int len;
	float real=0.0;
	float img=0.0;
	len=strlen(polstr);
	int X;
	float Y=0.0;
	i=0;
	j=0;
	
	
	
	while(polstr[i]!='0')
	{
		
		if(polstr[i]=='+' && polstr[i+1]=='p' && polstr[i+2]=='i' && polstr[i+3]=='j' )
			{
				
				complex x = cexp(I*pi);
				
				real+=coef[j]*creal(x);
				img+=coef[j]*cimag(x);
				j++;
			}
		if(polstr[i]=='-' && polstr[i+1]=='p' && polstr[i+2]=='i' && polstr[i+3]=='j' )
		{
			complex x = cexp(I*pi);
				
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
			j++;
		}
		if(polstr[i]=='+' && polstr[i+2]=='p' && polstr[i+3]=='i' && polstr[i+4]=='j' )
		{
			X=polstr[i+1]-'0';
			
			complex x = cexp(I*pi*X);
				
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
			j++;
		}
			if(polstr[i]=='-' && polstr[i+2]=='p' && polstr[i+3]=='i' && polstr[i+4]=='j' )
		{
			X=polstr[i+1]-'0';
			
			complex x = cexp(I*pi*X);
				
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
			j++;
		}
		if(polstr[i]=='+' && polstr[i+2]=='j')
		{
			X=polstr[i+1]-'0';
			complex x = cexp(I*X);
		/*	printf("**");*/
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
		
			j++;
		}
		if(polstr[i]=='-' && polstr[i+2]=='j')
		{
			X=polstr[i+1]-'0';
			complex x = cexp(I*X);
			
			
			real+=coef[j]*creal(x);
			img-=coef[j]*cimag(x);//
			j++;
		}
		
		if(polstr[i]=='+' && polstr[i+2]=='.' && polstr[i+4]=='p')
		{
			Y=(polstr[i+1]-'0')+(0.1*(polstr[i+3]-'0'));
			/*printf("%f\n",Y);*/
			complex x = cexp(I*Y*pi);
			
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
			j++;
		}
		if(polstr[i]=='-' && polstr[i+2]=='.' && polstr[i+4]=='p')
		{
			Y=-1.00*(polstr[i+1]-'0')+(0.1*(polstr[i+3]-'0'));
			/*printf("%f\n",Y);*/
			complex x = cexp(I*Y*pi);
			
			real-=coef[j]*creal(x);
			img-=coef[j]*cimag(x);
			j++;
		}
			if(polstr[i]=='+' && polstr[i+2]=='.' && polstr[i+4]=='j')
		{
			Y=(polstr[i+1]-'0')+(0.1*(polstr[i+3]-'0'));
			/*printf("%f\n",Y);*/
			complex x = cexp(I*Y);
			
			real+=coef[j]*creal(x);
			img+=coef[j]*cimag(x);
			j++;
		}
			if(polstr[i]=='-' && polstr[i+2]=='.' && polstr[i+4]=='j')
		{
			Y=-1.00*(polstr[i+1]-'0')+(0.1*(polstr[i+3]-'0'));
			/*printf("%f\n",Y);*/
			complex x = cexp(I*Y);
			
			real+=coef[j]*creal(x);
			img-=coef[j]*cimag(x);
			j++;
		}
		
		
		
		i++;
	}
	
/**/
	*PR=real;
    *PI=img;
	/*printf("%f \t %fi\n",*PR,*PI);*/
	real=0.0;
	img=0.0;
 
}
//=================================================================================================================================

int exceptexp(char input[], float *Pr, float *Pi)
{
	
	int i=0,j;
	int len;
	len=strlen(input);
	float img=0.0;
	float real=0.0;
	int value=0;
	
	while(input[i]!='\0')
	{
		if(i==0 && input[i+1]=='j')
		{
			value=input[i]-'0';
		
			img=img+(cimag(I)*value);
		}
		if(i==0 && input[i+1]!='j')
		{
			value=input[i]-'0';
		
			real=real+value;
			
		}
		if(input[i]=='j' && input[i-1]=='+')
		{
			img=img+1;
		}
			if(input[i]=='j' && input[i-1]=='-')
		{
			img=img-1;
		}
		if(input[i]>'0'&& input[i]<='9' && input[i+1]=='j' && input[i-1]=='+')
		{
			value=input[i]-'0';
		
			img=img+(cimag(I)*value);
		}
			if(input[i]>'0'&& input[i]<='9' && input[i+1]=='j' && input[i-1]=='-')
		{
			value=input[i]-'0';
		
			img=img-(cimag(I)*value);
		}
			if(input[i]>'0'&& input[i]<='9' && input[i+1]!='j' && input[i-1]=='+')
		{
			value=input[i]-'0';
		
			real=real+value;
		
		}
			if(input[i]>'0'&& input[i]<='9' && input[i+1]!='j' && input[i-1]=='-')
		{
			value=input[i]-'0';
		
			real=real-value;
		
		}
		i++;
	}
	
	/*	printf("\n%f \t %fi\n",real,img);*/
	*Pi=img;
	*Pr=real;
	
	real=00.00;
	img=0.0;
	}

//=================================================================================================================================

void convertCartesianToPolar(float x, float y)
{
   float r=0.0;
   float theta=0.0;
  
	 /* Calculating r */
	 r = sqrt(x*x + y*y);
	
	 /* Calculating theta in radian */
	 theta = atan(y/x);
	
	 /* Converting theta from degree to radian */
	 theta = 180.0 * theta/ pi;
	
	 printf("Polar coordinate is: r = %0.2f and theta = %0.2f in degree", r, theta);
	 getch(); /* Holds Screen */
   
   
}

//=================================================================================================================================

void printResults(float RE, float IM, float RE1 , float IM2)
{
    int cartesianPolarChoice;
    
    printf("\n1.Cartesian Output\n2.Polar Output\n");
    printf("Choose the output format: ");
    scanf(" %d", &cartesianPolarChoice);
    if(cartesianPolarChoice == 1)
    {
        char resultSign[3];
        if(img>=0)
        {
            resultSign[0] = '+';
        }
        if(img<0)
        {
            resultSign[0] = '-';
            img = img*(-1);
        }
        printf("\nResult: %lf %c %lfj\n", RE1+RE, resultSign[0], IM2+IM);
    }else if(cartesianPolarChoice == 2)
    {
        convertCartesianToPolar(RE1+RE, IM2+IM);
    }
}

//================================================================================================================================
int controller(char input[])
{
	int i;
	int ok=0;

	while(input[i]!='\0')
	{
		if(input[i]=='+' && input[i+1]=='+')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
		if(input[i]=='+' && input[i+1]=='-')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
			if(input[i]=='-' && input[i+1]=='-')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
			if(input[i]=='+' && input[i+1]=='+')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
			if(input[i]=='e' && input[i+1]=='e')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
			if(input[i]=='(' && input[i+1]==')')
		{
			printf("\nERROR!!\n");
			
			ok=1;
			break;
		}
	
		
		i++;
	}
return ok;
}
int main()
{
    int error=0;
	float Real;
	float Imaginary;
	float Real1;
	float Imaginary1;
	char input[100];

    printf("Enter your expression: ");
    gets(input);
   error= controller(input);
   if(error==1)
   {
   	exit(0);
   }
    convertcartesian1(input,&Real,&Imaginary);
   	
  /*  printf("%f \t %f",Real,Imaginary);*/
  
     //*\\--------------------------------CLEAR EXPS-----0----------------------------//*\\
    
 	int i;
	int j;
	
	while(input[i]!='\0')	
	{
		
		if(input[i]=='e' )
		{
			j=i;
			while(input[j]!=')')
				{
					input[j]=' ';
					j++;
				}
			input[i-1]=' ';
			input[j]=' ';
		}
		i++;
	}
	/*puts(input);*/


	exceptexp(input,&Real1,&Imaginary1);
	
 /*  printf("\n%f\t%f i",Real1,Imaginary1);*/
    //\----------------------------------------------------------------------------//
    
	printResults(Real,Imaginary,Real1,Imaginary1);
   
    
}
	

    

