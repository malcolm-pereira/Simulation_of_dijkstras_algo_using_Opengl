#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<process.h>
#include<conio.h>
#define IN 99
#define n 7
int dist[n][n],flag=0,a,b;
char finalpath[n];
void display_nodes();
void display_intro();
void drawnode1();
void drawnode2();
void drawnode3();
void drawnode4();
void drawnode5();
void drawnode6();
void drawline12();
void drawline23();
void drawline34();
void drawline45();
void drawline56();
void drawline61();
void drawline26();
void drawline35();
void init(int w,int h)
{
float aspect=(float)w/h;
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w>=h)
{
    glOrtho(-100*aspect,800*aspect,-100,800,100,-800);
}
else
{
    glOrtho(-100,800,-100/aspect,800/aspect,100,-800);
}
glMatrixMode(GL_MODELVIEW);
glFlush();
}

void drawString(float x, float y, float z, char * string)
{
    char * c;
    glRasterPos3f(x, y, z);
    for (c = string; * c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, * c);
    }
}
void drawString1(float x, float y, float z, char * string) {
    char * c;
    glRasterPos3f(x, y, z);
    for (c = string; * c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, * c);
    }
}
void delay1() {
    int bx, ax;
    bx = 100;
    label1: ax = 20000;
    label2: ax--;
    if (ax != 0) {
        goto label2;
    }
    bx--;
    if (bx != 0) {
        goto label1;
    }
}
void delay()
{
    int bx, ax;
    bx = 100;
    label1: ax = 2000;
    label2: ax--;
    if (ax != 0) {
        goto label2;
    }
    bx--;
    if (bx != 0) {
        goto label1;
    }
}

void distanceMatrix()
{
    int i, j;
    for (i=1;i<n;i++)
        {
        for (j=1;j<n;j++)
        {
            dist[i][j]=IN;
        }
        }
    dist[1][2] = dist[2][1]=10;
    dist[1][6] = dist[6][1]=5;
    dist[2][3] = dist[3][2]=1;
    dist[2][6] = dist[6][2]=3;
    dist[3][4] = dist[4][3]=6;
    dist[3][5] = dist[5][3]=2;
    dist[4][5] = dist[5][4]=9;
    dist[5][6] = dist[6][5]=7;
}
void display_cost(int cost)
{
    glColor3f(1.0,0.0,0.0);
    drawString(1100,550,0,"Shortest distance is :");
    glFlush();
    char buffer[10]={'\0'};
    sprintf(buffer,"%d",cost);
    int len =strlen(buffer);
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(1200,520);
    for(int i=0;i<len;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buffer[i]);
    }
    glColor3f(1.0,0.0,0.0);
    glFlush();
     glColor3f(1.0,0.0,0.0);
    drawString(1100,500,0,"Press Enter to EXIT:");
    glFlush();
}
void display_path(char c[])
{
    int i;
    for(i=0;i!='\o';i++)
    {
        if(c[i]=='B')
        {
          glColor3f(0.0,1.0,0.0);
          drawnode1();
          if(c[i+1]=='C')
          {
             glColor3f(0.0,1.0,0.0);
             drawnode2();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline12();
          }
          else
          if(c[i+1]=='G')
            {
             glColor3f(0.0,1.0,0.0);
             drawnode6();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline61();
             }
          }
        if(c[i]=='C')
        {
             glColor3f(0.0,1.0,0.0);
             drawnode2();
             if(c[i+1]=='B')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode1();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline12();
             }
             else
             if(c[i+1]=='G')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode6();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline26();
             }
             else
             if(c[i+1]=='D')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode3();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline23();
             }
        }
        if(c[i]=='D')
        {
             glColor3f(0.0,1.0,0.0);
             drawnode3();
             if(c[i+1]=='C')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode2();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline23();
             }
             else
             if(c[i+1]=='F')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode5();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline35();
             }
             else
             if(c[i+1]=='E')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode4();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline34();
             }
        }
        if(c[i]=='E')
        {
            glColor3f(0.0,1.0,0.0);
             drawnode4();
             if(c[i+1]=='D')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode3();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline34();
             }
             else
             if(c[i+1]=='F')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode5();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline45();
             }
        }
        if(c[i]=='F')
        {
             glColor3f(0.0,1.0,0.0);
             drawnode5();
             if(c[i+1]=='D')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode3();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline35();
             }
             else
             if(c[i+1]=='E')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode4();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline45();
             }
             else
             if(c[i+1]=='G')
             {
             glColor3f(0.0,1.0,0.0);
             drawnode6();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline56();
             }
        }
        if(c[i]=='G')
        {
            glColor3f(0.0,1.0,0.0);
            drawnode6();
            if(c[i+1]=='C')
            {
             glColor3f(0.0,1.0,0.0);
             drawnode2();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline26();
            }
            else
            if(c[i+1]=='F')
            {
             glColor3f(0.0,1.0,0.0);
             drawnode5();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline56();
            }
            else
            if(c[i+1]=='B')
            {
             glColor3f(0.0,1.0,0.0);
             drawnode1();
             glColor3f(0.0,1.0,0.0);
             glLineWidth(5);
             drawline61();
            }
        }
    }
}

void dijsktra(int cost[][n],int source,int target)
{
   int dist1[n],prev[n],selected[n]={0},i,m,min,start,d,j;
    char path[n];
    for(i=1;i<n;i++)
    {
        dist1[i] = IN;
        prev[i] = -1;
    }
    printf("%d\t%d",source,target);
    start = source;
    selected[start]=1;
    dist1[start] = 0;
    while(selected[target]==0)
    {
        min = IN;
        m = 0;
        for(i=1;i<n;i++)
        {
            d = dist1[start] +cost[start][i];
            if(d< dist1[i]&&selected[i]==0)
            {
                dist1[i] = d;
                prev[i] = start;
            }
            if(min>dist1[i] && selected[i]==0)
            {
                min = dist1[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    printf("%s", path);
    printf("\n%d",dist1[target]);
    display_path(path);
    display_cost(dist1[target]);
}
void display_first_message()
{
    glColor3f(0.0,0.0,1.0);
    drawString(1100,550,0,"Press Enter to RUN");
    glFlush();
}

void insert_weight()
{
    glColor3f(0.0,0.0,1.0);
    drawString(230, 550, 0, "10");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(500, 660, 0, "1");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(750, 550, 0, "6");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(750, 330, 0, "9");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(500, 230, 0, "7");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(250, 320, 0, "5");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(660, 450, 0, "2");
    glFlush();
    glColor3f(0.0,0.0,1.0);
    drawString(360, 450, 0, "3");
    glFlush();
    if(flag==0)
    display_first_message();
}
void drawline12()
{
     glBegin(GL_LINES);
    glVertex2f(200,500);
    glVertex2f(300,600);
    glEnd();
}
void drawline23()
{
    glBegin(GL_LINES);
    glVertex2f(400,650);
    glVertex2f(600,650);
    glEnd();
}
void drawline34()
{
    glBegin(GL_LINES);
    glVertex2f(700,600);
    glVertex2f(800,500);
    glEnd();
}
void drawline45()
{
     glBegin(GL_LINES);
    glVertex2f(800,400);
    glVertex2f(700,300);
    glEnd();
}
void drawline56()
{
     glBegin(GL_LINES);
    glVertex2f(600,250);
    glVertex2f(400,250);
    glEnd();
}
void drawline61()
{
    glBegin(GL_LINES);
    glVertex2f(200,400);
    glVertex2f(300,300);
    glEnd();
}
void drawline26()
{
     glBegin(GL_LINES);
    glVertex2f(350,600);
    glVertex2f(350,300);
    glEnd();
}
void drawline35()
{
    glBegin(GL_LINES);
    glVertex2f(650,600);
    glVertex2f(650,300);
    glEnd();
}
void display_lines()
{
    glColor3f(1.0,0.0,0.0);
    drawline12();
    glColor3f(1.0,0.0,0.0);
    drawline23();
    glColor3f(1.0,0.0,0.0);
    drawline34();
    glColor3f(1.0,0.0,0.0);
    drawline45();
    glColor3f(1.0,0.0,0.0);
    drawline56();
    glColor3f(1.0,0.0,0.0);
    drawline61();
    glColor3f(1.0,0.0,0.0);
    drawline26();
    glColor3f(1.0,0.0,0.0);
    drawline35();
    insert_weight();
}
void drawnode1()
{
    glBegin(GL_POLYGON);
    glVertex2f(100,400);
    glVertex2f(200,400);
    glVertex2f(200,500);
    glVertex2f(100,500);
    glEnd();
    glFlush();
    glColor3f(1.0,1.0,0.0);
    drawString(150, 450, 0, "1");
    glFlush();
}
void drawnode2()
{
    glBegin(GL_POLYGON);
    glVertex2f(300,600);
    glVertex2f(400,600);
    glVertex2f(400,700);
    glVertex2f(300,700);
    glEnd();
    glFlush();
    glColor3f(10,1.0,0.0);
    drawString(350, 650, 0, "2");
    glFlush();
}
void drawnode3()
{
     glBegin(GL_POLYGON);
    glVertex2f(600,600);
    glVertex2f(700,600);
    glVertex2f(700,700);
    glVertex2f(600,700);
    glEnd();
    glFlush();
    glColor3f(1.0,1.0,0.0);
    drawString(650, 650, 0, "3");
    glFlush();
}
void drawnode4()
{
     glBegin(GL_POLYGON);
    glVertex2f(800,400);
    glVertex2f(900,400);
    glVertex2f(900,500);
    glVertex2f(800,500);
    glEnd();
    glFlush();
    glColor3f(1.0,1.0,0.0);
    drawString(850, 450, 0, "4");
    glFlush();
}
void drawnode5()
{
    glBegin(GL_POLYGON);
    glVertex2f(600,200);
    glVertex2f(700,200);
    glVertex2f(700,300);
    glVertex2f(600,300);
    glEnd();
    glFlush();
    glColor3f(1.0,1.0,0.0);
    drawString(650, 250, 0, "5");
    glFlush();
}
void drawnode6()
{
    glBegin(GL_POLYGON);
    glVertex2f(300,200);
    glVertex2f(400,200);
    glVertex2f(400,300);
    glVertex2f(300,300);
    glEnd();
    glFlush();
    glColor3f(1.0,1.0,0.0);
    drawString(350, 250, 0, "6");
    glFlush();
}
void display_nodes()
{
    glColor3f(1.0,0.0,0.0);
    drawnode1();
    glColor3f(1.0,0.0,0.0);
    drawnode2();
    glColor3f(1.0,0.0,0.0);
    drawnode3();
    glColor3f(1.0,0.0,0.0);
    drawnode4();
    glColor3f(1.0,0.0,0.0);
    drawnode5();
    glColor3f(1.0,0.0,0.0);
    drawnode6();
    display_lines();
}
void display2()
{
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 display_nodes();
 //glutSwapBuffers();
 glFlush();
}
void display()
{
 distanceMatrix();
 display_intro();
 glFlush();
}

void mykeyboard(unsigned char key,int x,int y)
{
    int i;
    if ((key == 13) && flag == 0)
    {
        flag = 1;
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        display2();
        glColor3f(0.0, 0.0, 1.0);
        drawString(1050,550,0, " Enter the number for Source Node");
        drawString(1100,530,0, " 1, 2, 3, 4, 5, 6");
        glFlush();
    }
    else
    if((key==13)&& flag!=0)
    {
        exit(0);
    }
    else
    if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'||key=='6')
     {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        display2();
        if (flag == 1)
        {
            flag = 2;
            drawString(1030,550,0, " Enter the number for Destination Node");
            drawString(1100,530,0, " 1, 2, 3, 4, 5, 6");
            if (key == '1')
            {
                a = 1;
            }
            else
            if (key == '2')
            {
                a = 2;
            }
            else
            if (key == '3')
             {
                a = 3;
            }
            else
            if (key == '4')
             {
                a = 4;
            }
            else
            if (key=='5')
            {
                a=5;
            }
            else
            {
                a = 6;
            }

        }
         else
            if (flag == 2)
            {
            if (key == '1')
             {
                b = 1;
            }
         else
            if (key == '2')
            {
                b = 2;
            }
         else
            if (key == '3')
             {
                b = 3;
            }
         else
            if (key == '4')
             {
                b = 4;
            }
         else
             if(key=='5')
         {
             b=5;
         }
         else
            if(key=='6')
            {
                b = 6;
            }
           dijsktra(dist,a,b);
        }
        else
            {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glFlush();
            glClearColor(1.0, 1.0, 1.0, 1.0);
            glFlush();
            glColor3f(0.0, 0.0, 1.0);
            drawString(100, 400, 0, " Invalid Key Pressed ");
            glFlush();
            for (i = 0; i <= 500; i++)
            {
                delay();
            }
            for (i = 0; i <= 500; i++)
            {
                delay();
            }
            exit(0);
        }
        glFlush();
    }
    else
        {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glFlush();
        glColor3f(0.0, 0.0, 1.0);
        drawString(100, 400, 0, " Invalid Key Pressed ");
        glFlush();
        for (i = 0; i <= 500; i++)
         {
            delay();
        }
        for (i = 0; i <= 500; i++)
         {
            delay();
        }
        exit(0);
    }
}
void display_intro()
{
    int i,j;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawString1(125, 400, 0, " SIMULATION OF DIJKSTRA'S ALGORITHM");
    glFlush();
      for (i = 0; i < 565; i = i + 25)
        {
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(125 + i, 390, 0);
        glVertex3f(150 + i, 390, 0);
        glEnd();
        for (j = 0; j<=100; j++) {
            delay();
        }
        glFlush();
    }
    glColor3f(1.0, 0.0, 0.0);
    drawString(140, 220, 0, " By:");
    drawString(220, 200, 0, " Malcolm Pereira");
    glFlush();
    for (i = 0; i <= 100; i++) {
        delay1();
    }
    display2();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitWindowSize(1000,1000);
glutCreateWindow("Dijkstra's algorithm");
glutFullScreen();
glutInitDisplayMode(GLUT_DOUBLE);
glutReshapeFunc(init);
glutDisplayFunc(display);
glutKeyboardFunc(mykeyboard);
glutMainLoop();
return 0;
}
