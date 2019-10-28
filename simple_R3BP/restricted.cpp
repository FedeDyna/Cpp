#include<iostream>
#include<cmath>

using namespace std;

const double duepi = 2*M_PI;
const double MU = 0.000954 ;
const double OME = 1.0 ;
const int    n_step = 20000 ;
const int    n_period = 3 ;


double* F( double X, double Y,double Tau )
{       
    double*punt = new double[3];
    double  c = cos(OME*Tau);
    double  s = sin(OME*Tau);
	 
    double sq = (Y+MU*s);
    
    double      r1 = sqrt(pow((X+MU*c),2)+sq*sq);
    double      r2 = sqrt(pow((X-(1.0-MU)*c),2)+pow((Y-s*(1.0-MU)),2));
	 
    double      Fx = -((1.0-MU)*(X+MU*c))/pow(r1,3) - (MU*(X-c*(1.0-MU)))/pow(r2,3);
    double      Fy = -((1.0-MU)*(Y+MU*s))/pow(r1,3) - (MU*(Y-s*(1.0-MU)))/pow(r2,3);
    double      Ftau =-((1.0-MU)*OME*MU*(-s*(X+MU*c)+c*(Y+MU*s)))/pow(r1,3);
                Ftau -=  (MU*(1.0-MU)*OME*(s*(X-(1.0-MU)*c)-c*(Y-(1.0-MU)*s)))/pow(r2,3);
                punt[0]=Fx;
                punt[1]=Fy;
                punt[2]=Ftau;
	      return punt;
}



int main(void)
{

double t_per = duepi/OME ;
double tempo_finale = n_period*t_per;

double Jac0 =3.07;

double tau0 = 0.0 ;
double ptau0 = 1.0 ;      

double c0 = cos(OME*tau0) ;
double s0 = sin(OME*tau0) ;
      
double xcor0 = 0.55 ;
double ycor0 = 0.0;
      
double r10 = sqrt(pow((xcor0+MU),2)+ycor0*ycor0) ;
double r20 = sqrt(pow((xcor0-1.0+MU),2)+ycor0*ycor0) ;
 
double vxcor0 = 0.0 ;
double vycor0 = 0.929168 ;
      
double vycor2 = sqrt(2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor0*xcor0 + ycor0*ycor0 - Jac0 - vxcor0*vxcor0);

double Jac3 = 2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor0*xcor0 + ycor0*ycor0 - vycor2*vycor2 - vxcor0*vxcor0 ;
double Jac4 = 2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor0*xcor0 + ycor0*ycor0 - vycor0*vycor0 - vxcor0*vxcor0 ;

//     cout << Jac3 <<' '<< Jac4 <<' '<< vycor0 <<' '<< vycor2 << endl;

double     x0 = c0*xcor0 - s0*ycor0 ;
double     y0 = s0*xcor0 + c0*ycor0 ;
double     px0 = -s0*xcor0 - c0*ycor0 + c0*vycor0 - vycor0*s0 ;
double     py0 = c0*xcor0 - s0*ycor0 + s0*vxcor0 + c0*vycor0 ;
  
double      X = x0 ;
double      Y = y0 ;
double      Tau = tau0 ;
double      px = px0 ;
double      py = py0 ;
double      ptau = ptau0 ;
double      n_step_r8 = n_step ;
double      k_max = n_period*n_step ;
double      dt = tempo_finale/k_max ;
int      k = 0 ;
double      t = 0.0 ;
double xnew, ynew, taunew, pxnew,pynew,ptaunew;
double xcor1, ycor1, vxcor1, vycor1,Jac5,r11,r21;



  //  for(k=0;k<k_max;k++)
  // {
           t = k*dt;
    double* Fvet = F(X,Y,Tau);
    cout << t <<' '<< X <<' '<< Y <<' '<< px <<' '<< py << endl;
    cout << Fvet[0] <<' '<< Fvet[1] <<' '<< Fvet[2] << endl;
     xnew = X + px*dt + 0.5*Fvet[0]*(dt*dt); // QUESTO RISULTATO DOVREBBE ESSERE 0,549999838 invece
     // è 0,550291906 perchè dt*dt è troppo basso, dt= 0.000314159
          // !!! Ma se fosse più grande da non essere arrotondato a zero avrei altri errori
     ynew = Y + py*dt + 0.5*Fvet[1]*(dt*dt) ;
     taunew = Tau + dt;
    cout << dt <<' '<< xnew <<' '<< ynew <<' '<< taunew << endl; 
    cout << 0.5*Fvet[0]*(dt*dt) <<' '<< 0.5*Fvet[1]*(dt*dt) << endl;
    double* Fvetnew = F(xnew,ynew,taunew);


     pxnew = px + 0.5*dt*(Fvet[0]+Fvetnew[0]);
     pynew = py + 0.5*dt*(Fvet[1]+Fvetnew[1]);
     ptaunew = ptau + 0.5*dt*(Fvet[2]+Fvetnew[2]);
	 
     X = xnew;
     Y = ynew;
     Tau = taunew;
     px = pxnew;
     py = pynew;
     ptau = ptaunew;
     xcor1 = X*cos(t)+Y*sin(t);
	 ycor1 = -X*sin(t)+Y*cos(t);
	 vxcor1 = px*cos(t)+py*sin(t)-X*sin(t)+Y*cos(t);
	 vycor1 = -px*sin(t)+py*cos(t)-X*cos(t)-Y*sin(t);
     //cout << t <<' '<< X <<' '<< Y <<' '<< px <<' '<< py << endl;
     r11 = sqrt(pow((xcor1+MU),2)+ycor1*ycor1) ;
     r21 = sqrt(pow((xcor1-1.0+MU),2)+ycor1*ycor1) ;
     Jac5 = 2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor1*xcor1 + ycor1*ycor1 - vycor1*vycor1 - vxcor1*vxcor1 ;
    cout << xcor0 <<' '<< ycor0 <<' '<< vycor0 <<' '<< vycor0 <<' '<< Jac0 << endl;
    cout << xcor1 <<' '<< ycor1 <<' '<< vxcor1 <<' '<< vycor1 <<' '<< Jac5 << endl;
  //   }
    return 0;
}
