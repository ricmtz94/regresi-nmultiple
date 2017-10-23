#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodos()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::metodos(){

    QString temp,temp1,temp2,temp3,temp4;         //Temporary use text strings

    double X1=ui->x1->value();   //Retrieves the values ​​in column X1
    double X2=ui->x2->value();   //
    double X3=ui->x3->value();   //
    double X4=ui->x4->value();   //
    double X5=ui->x5->value();   //
    double X6=ui->x6->value();   //

    double X1_2=ui->x1_2->value();   //Retrieves the values ​​in column X2
    double X2_2=ui->x2_2->value();   //
    double X3_2=ui->x3_2->value();   //
    double X4_2=ui->x4_2->value();   //
    double X5_2=ui->x5_2->value();   //
    double X6_2=ui->x6_2->value();   //


    double Y1=ui->y1->value();   //Retrieves the values ​​in column Y
    double Y2=ui->y2->value();   //
    double Y3=ui->y3->value();   //
    double Y4=ui->y4->value();   //
    double Y5=ui->y5->value();   //
    double Y6=ui->y6->value();   //

    double A[6]={X1,X2,X3,X4,X5,X6}; //Saves the values ​​of X1 in the array.
    double C[6]={X1_2,X2_2,X3_2,X4_2,X5_2,X6_2}; //Saves the values ​​of X2 in the array.
    double B[6]={Y1,Y2,Y3,Y4,Y5,Y6};  //Saves the values ​​of Y in the array.

    int i=1;      // use variables
    double b=0;   //
    double CUADRADOX2=0;//
    double prod=0;//
    double prodx2=0;//
    double f1=0;//
    double d=0;   //
    double m=0;   //
    double cu=0;  //
    double n=6;    //
    double y1=0,y2=0,y3=0,y4=0,y11=0,y22=0,y33=0,y44=0,y222=0,y333=0,y444=0,a2=0,ac=0;
    double au=0;
    double Sr=0,St=0,yn=0,r=0;
    for(i=0;i<n;i++){   //Counter for use of fixtures.
        b=b+A[i];//sum of X1
        f1=f1+C[i];//  sum of X2
        cu=cu+(A[i]*A[i]);//sum of squares of X1
        prod=prod+(A[i]*C[i]);   // SUM OF PRODUCTS X2 and X1
        CUADRADOX2=CUADRADOX2+(C[i]*C[i]); //SQUARE OF X2
        d=d+B[i]; //sum of Y1
        m=m+(A[i]*B[i]); // PRODUCT X1 and Y1
        prodx2=prodx2+(C[i]*B[i]);//Sum of product x2 and y1
    }
    y1=b-(b/n)*n;         //Method of elimination gauseana
    y2=cu-(b/n)*b;                     //
    y3=prod-(b/n)*f1;                  //
    y4=m-(b/n)*d;                      //

    y11=f1-(f1/n)*n;                   //
    y22=prod-(f1/n)*b;                 //
    y33=CUADRADOX2-(f1/n)*f1;          //
    y44=prodx2-(f1/n)*d;               //

    y222=prod-(prod/cu)*cu;            //
    y333=y33-(y22/y2)*y3;              //
    y444=y44-(y22/y2)*y4;              //

    a2=y444/y333;                      //
    au=(y44-y33*a2)/(y22);             //
    ac=(d-b*au-f1*a2)/(n);             //
    yn=d/n;                            //

    for(i=0;i<n;i++){                  //Calculation of St and Sr
    Sr=Sr+(B[i]-ac-au*A[i]-a2*C[i])*(B[i]-ac-au*A[i]-a2*C[i]);
    St=St+(B[i]-yn)*(B[i]-yn);
    }
    r=sqrt((St-Sr)/(St));               //Calculation of r value


    temp.append("\ny=").append(temp1.setNum(ac)).append("+").append(temp2.setNum(au)).append("x1 ").append(temp3.setNum(a2).append("x2\nr=").append(temp4.setNum(r)));
     ui->text->setText(temp); //print;
       }
void MainWindow::borrar(){
    ui->x1->setValue(0.0);  //The spinbox is deleted
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);  //The spinbox is deleted
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);

    ui->x1_2->setValue(0.0);  //The spinbox is deleted
    ui->x2_2->setValue(0.0);
    ui->x3_2->setValue(0.0);
    ui->x4_2->setValue(0.0);  //The spinbox is deleted
    ui->x5_2->setValue(0.0);
    ui->x6_2->setValue(0.0);

    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);  //The spinbox is deleted
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);

    ui->text->clear();
}

