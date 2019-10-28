/*****************************
 *
 * Federico Panichi
 *
 * federico.panichi@studio.unibo.it
 *
 *
 * GUI for Restricted 3-body problem.
 *
 *  -- Heliocentric coordinate reference
 *  -- Second order symplectic integrator (Yoshida 1990)
 *  -- Simple wrap to GNUPLOT
 *
 * TODO:
 *
 *      a) Implement a dynamical selection of ICs
 *
 *      b) Ask where to save plots/*.dat files
 *
 *
 ******************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // THIS MUST BE CHANGED EVERYTIME
    QPixmap pix("/home/fede/Qt5.7.0/Examples/C++_examples/example_C++_8/fig_1a.png");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EnergyCalc_clicked()
{
    //
    // energy integral
    //
    double Jac0, r10, r20, tau, ptau,c0,s0 ;
    double x,y,px,py,r1,r2,Ener;
    double MU,xcor0,ycor0,vxcor0,vycor0; // variable on input from program
    double OME = 1.0;

    Jac0 = 3.07 ;
    xcor0 =  0.55 ;
    ycor0 = 0.0  ;
    vxcor0 = 0.0 ;

    MU    =  ui->mu_value->text().toDouble();
    xcor0 =  ui->x_value->text().toDouble();
    ycor0 =  ui->y_value->text().toDouble();
    vxcor0 = ui->px_value->text().toDouble();

    r10 = sqrt( pow ( ( xcor0 + MU ), 2) + ycor0*ycor0 ) ;
    r20 = sqrt( pow ( ( xcor0 - 1.0 + MU ), 2) + ycor0*ycor0 )  ;

    vycor0 = sqrt(2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor0*xcor0 + ycor0*ycor0 - Jac0 - vxcor0*vxcor0)  ;

// reference system: from rotating (anti-clockwise) to fixed

    tau = 0.0 ; ptau = 1.0  ;
    c0 = cos(OME*tau) ;
    s0 = sin(OME*tau) ;

    x =   c0 * xcor0 - s0 * ycor0 ;
    y =   s0 * xcor0 + c0 * ycor0 ;
    px = -s0 * xcor0 - c0 * ycor0 + c0 * vxcor0 - vycor0 * s0 ;
    py =  c0 * xcor0 - s0 * ycor0 + s0 * vxcor0 + c0 * vycor0 ;

    r1 = sqrt( pow( (x + MU * c0) , 2) + pow( (y + MU * s0), 2) ) ;
    r2 = sqrt( pow( (x - (1.0 - MU ) * c0), 2) + pow ( y - s0 *(1.0 - MU) , 2)  );

    Ener = 0.50 * (px*px + py*py) + ptau - ( 1.0 - MU ) / r1 - MU / r2 ;

    ui->Energy_value->setText(QString::number(Ener));

}


/*
 * START THE INTEGRATION FUNCTION
 *
 */

void MainWindow::on_orbit_integration_clicked()
{
    //
    // Orbital integration
    //
    double Jac0, r10, r20,c0,s0 ;
    double x,y, tau, ptau,px,py,r1,r2;
    double MU,xcor0,ycor0,vxcor0, vycor0; // variable on input from program
    double OME = 1.0;
    //
    double Ener,Ener0,errh;
    double dt, c, s, fx,fy,ftau;
    double xnew, ynew, taunew, pxnew, pynew, ptaunew;
    double fxnew, fynew, ftaunew;
    int n_step, n_period, k_max, k ;

    // initialize some variables
    Jac0 = 0.0 ;
    xcor0 =  0.0 ;
    ycor0 = 0.0  ;
    vxcor0 = 0.0 ;

    Jac0  =  ui->jacobi_value->text().toDouble();
    MU    =  ui->mu_value->text().toDouble();
    xcor0 =  ui->x_value->text().toDouble();
    ycor0 =  ui->y_value->text().toDouble();
    vxcor0 = ui->px_value->text().toDouble();

    r10 = sqrt( pow ( ( xcor0 + MU ), 2) + ycor0*ycor0 ) ;
    r20 = sqrt( pow ( ( xcor0 - 1.0 + MU ), 2) + ycor0*ycor0 )  ;

    vycor0 = sqrt(2.0*(1.0-MU)/r10 + (2.0*MU)/r20 + xcor0*xcor0 + ycor0*ycor0 - Jac0 - vxcor0*vxcor0)  ;

// reference system: from rotating (anti-clockwise) to fixed

    tau = 0.0 ; ptau = 1.0  ;
    c0 = cos(OME*tau) ;
    s0 = sin(OME*tau) ;

    x =   c0 * xcor0 - s0 * ycor0 ;
    y =   s0 * xcor0 + c0 * ycor0 ;
    px = -s0 * xcor0 - c0 * ycor0 + c0 * vxcor0 - vycor0 * s0 ;
    py =  c0 * xcor0 - s0 * ycor0 + s0 * vxcor0 + c0 * vycor0 ;

// first time calculate the energy

    r1 = sqrt( pow( (x + MU * c0) , 2) + pow( (y + MU * s0), 2) ) ;
    r2 = sqrt( pow( (x - (1.0 - MU ) * c0), 2) + pow ( y - s0 *(1.0 - MU) , 2)  );

    Ener0 = 0.50 * (px*px + py*py) + ptau - ( 1.0 - MU ) / r1 - MU / r2 ;

    /* Open file to write: THIS MUST BE CHANGED EVERYTIME  */
    QString outputFilename = "/home/fede/Qt5.7.0/Examples/C++_examples/example_C++_3_my_code/output/Results_integration.txt";
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);

// define variables for integration

    n_step = ui->step_value->text().toInt() ;
    n_period = ui->period_value->text().toInt() ;
    k_max = n_period*n_step ;
    dt = 1.0/n_step ; // step size

    outStream << "# Value of energy"  << Ener0 << "\n";
    outStream << "# number of periods"  << n_period << "\n";
    outStream << "# number of steps"  << n_period << "\n";

    //!!!!!!!!!!!!!!!
    //! forward integration
    //!!!!!!!!!!!!!!!

    for (k=0; k<=k_max; k++ ){

    // FIRST calling sequence of F
          c = cos(OME*tau) ;
          s = sin(OME*tau) ;

          r1 = sqrt( pow ( (x+MU*c), 2) + pow ((y+MU*s), 2) ) ;
          r2 = sqrt( pow ( (x-(1.0-MU)*c), 2) + pow ( (y-s*(1.0-MU)), 2)) ;

          fx = -((1.0-MU)*(x+MU*c))/pow (r1, 3) - (MU*(x-c*(1.0-MU)))/pow (r2, 3) ;
          fy = -((1.0-MU)*(y+MU*s))/pow (r1, 3) - (MU*(y-s*(1.0-MU)))/pow (r2, 3) ;

          ftau =-((1.0-MU)*OME*MU*(-s*(x+MU*c)+c*(y+MU*s)))/pow (r1, 3) ;

          ftau = ftau - ( MU*(1.0-MU)*OME*(s*(x-(1.0-MU)*c)-c*(y-(1.0-MU)*s)))/pow (r2, 3) ;
    // FIRST finish the calling sequence of F

          xnew = x + px*dt + 0.5*fx*(dt*dt) ;
          ynew = y + py*dt + 0.5*fy*(dt*dt) ;
          taunew = tau + dt ;

    // SECOND calling sequence of F
          c = cos(OME*taunew) ;
          s = sin(OME*taunew);

          r1 = sqrt( pow( (xnew+MU*c), 2) + pow ( (ynew+MU*s), 2) ) ;
          r2 = sqrt( pow( (xnew-(1.0-MU)*c), 2) + pow( (ynew-s*(1.0-MU)), 2) )  ;

          fxnew = -((1.0-MU)*(xnew+MU*c))/pow(r1,3) - (MU*(xnew-c*(1.0-MU)))/pow(r2,3) ;
          fynew = -((1.0-MU)*(ynew+MU*s))/pow(r1,3) - (MU*(ynew-s*(1.0-MU)))/pow(r2,3) ;

          ftaunew =-((1.0-MU)*OME*MU*(-s*(xnew+MU*c)+c*(ynew+MU*s)))/pow(r1,3);

          ftaunew = ftaunew - ( MU*(1.0-MU)*OME*(s*(xnew-(1.0-MU)*c)-c*(ynew-(1.0-MU)*s)))/pow(r2,3) ;
    // SECOND finish the calling sequence of F

          pxnew = px + 0.50*dt*(fx+fxnew) ;
          pynew = py + 0.50*dt*(fy+fynew) ;
          ptaunew = ptau + 0.50*dt*(ftau+ftaunew) ;

    // REDECLARE VARIABLES
          x = xnew ;
          y = ynew ;
          tau = taunew ;
          px = pxnew ;
          py = pynew ;
          ptau = ptaunew ;
    // calculate the energy conservation
          r1 = sqrt( pow( (x + MU * c) , 2) + pow( (y + MU * s), 2) ) ;
          r2 = sqrt( pow( (x - (1.0 - MU ) * c), 2) + pow ( y - s *(1.0 - MU) , 2)  );

          Ener = 0.50 * (px*px + py*py) + ptau - ( 1.0 - MU ) / r1 - MU / r2 ;

          errh = abs(Ener-Ener0)/Ener0 ; //??

          /* Write the line to the file */
          outStream << dt*k << " "<< x << " " << y << "\n";


    }

    /* Close the file */
    outputFile.close();

// end integration

     if (!ui->radioButton_2->isChecked() && !ui->radioButton->isChecked()){
         // which window I want to show
         QMessageBox::information(this,tr("Selection problem!"),tr("Please, select one output option!"));
         ui->finish_run_label->setText("Error.");
     } else {
         // write a fancy finishing integration comment
         ui->finish_run_label->setText("Finished.");
     }

// check if you want to show the orbit or not
  if( ui->radioButton_2->isChecked())
  {

   // try to draw the orbit

    const string dat_filename = "/home/fede/Qt5.7.0/Examples/C++_examples/example_C++_3_my_code/output/Results_integration.txt"; // input file
    const string dat_filename2 = "/home/fede/Qt5.7.0/Examples/C++_examples/example_C++_3_my_code/output/star.dat"; // input file
    const string exe = "gnuplot";

    const string cmd_filename = "test.txt";
    const string pic_filename = "4pl_stableXY.eps";

    {
      std::ofstream f(cmd_filename.c_str());

      f <<
        "set border 31 back linetype -1 linewidth 2.000 \n"
        "set term post color portrait enhanced \"Helvetica\" 20 \n"
        "set output '" << pic_filename <<"'\n"
        "set size square\n"
        "set yrange [-1:1.] ; set xrange [-1:1.]\n"
        "set xlabel \"{/=20 x-coordinate}\" \n"
        "set ylabel \"{/=20 y-coordinate}\" \n"
        "LABEL = \"Asteroid\" \n"
        "set label 2 at 0.75,-0.1 LABEL tc rgb \"black\" center front font \"Helvetica,16\" \n"
        "LABEL = \"Sun\" \n"
        "set label 3 at -0.2,0.0 LABEL tc rgb \"black\" center front font \"Helvetica,16\" \n"
        "t0 = 0.0 \n"
        "plot \"" << dat_filename<< "\" u ($0<10000 ? $2:1/0):3 w p pt 7 ps 0.4 not , \""
         << dat_filename<< "\" u ($0== t0 ? $2:1/0):3 w p pt 7 ps 1.5 lc rgb 'black' not, \""
         << dat_filename<< "\" u ($0== t0 ? $2:1/0):3 w p pt 7 ps 1.2 lc rgb 'green' not, \""
         << dat_filename2 << "\" w p pt 7 ps 2.5 lc rgb 'black' not, \""
         << dat_filename2<< "\" w p pt 7 ps 2.0 lc rgb 'orange' not \n";

    }

    const string cmd = exe + " " + cmd_filename;

    system(cmd.c_str());

    QLabel label;
    label.setPixmap(QPixmap(pic_filename.c_str()));
    label.show();


    system("gv *.eps");
  }

}
