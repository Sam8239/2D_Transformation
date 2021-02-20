#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
int main()
{
    int sx,sy,xt,yt,r;
    int gm;
    int gd=DETECT;
    int n,i,choice=0;
    int x[10],y[10],nx[10],ny[10];
    float t,u,v;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    line(320,0,320,480);
    line(0,240,640,240);
    printf("Enter Number of Vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("\nPlease Enter Coordinate for Point %d: ",i+1);
    scanf("%d %d", &x[i],&y[i]);
    }
    for(i=0;i<n-1;i++){
        line(320+x[i],240-y[i],320+x[i+1],240-y[i+1]);
	    delay(1000);
    }
    line(320+x[i],240-y[i],320+x[0],240-y[0]);
    printf("\nMENU:\n1. Translation\n2. Rotation\n3. Scaling\n4. Exit\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    do{
    switch(choice)
    {
        case 1:
                printf("\nEnter the Translation Factor: ");
                scanf("%d %d",&xt,&yt);
                for(i=0;i<n;i++){
                    nx[i]=x[i]+xt;
                    ny[i]=y[i]+yt;
                }
                for(i=0;i<n-1;i++){
                    line(320+nx[i],240-ny[i],320+nx[i+1],240-ny[i+1]);
                    delay(1000);
                }
                line(320+nx[i],240-ny[i],320+nx[0],240-ny[0]);
                break;
        case 2:
                printf("\nEnter the Angle Of Rotation: ");
                scanf("%d",&r);
                t=3.14*r/180;
                for(i=0;i<n;i++){
                    u=x[i];
                    v=y[i];
                    nx[i]=floor(u*cos(t)-v*sin(t));
                    ny[i]=floor(v*cos(t)+u*sin(t));
                }
                for(i=0;i<n-1;i++){
                    line(320+nx[i],240-ny[i],320+nx[i+1],240-ny[i+1]);
                    delay(1000);
                }
                line(320+nx[i],240-ny[i],320+nx[0],240-ny[0]);
                break;

        case 3:
                printf("\nEnter The Scaling Factor: ");
                scanf("%d %d",&sx,&sy);
                for(i=0;i<n;i++){
                    nx[i]=x[i]*sx;
                    ny[i]=y[i]*sy;
                }
                for(i=0;i<n-1;i++){
                    line(320+nx[i],240-ny[i],320+nx[i+1],240-ny[i+1]);
                    delay(1000);
                }
                line(320+nx[i],240-ny[i],320+nx[0],240-ny[0]);
                break;

        case 4:
                break;
        default:
                printf("\nEnter a Correct Choice: ");
    }
    printf("\nEnter Your Choice Again: ");
    scanf("%d",&choice);
    }while(choice!=4);
    getch();
    closegraph();
    return 0;
}
