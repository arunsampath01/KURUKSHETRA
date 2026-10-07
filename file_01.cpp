#include <iostream>
#include <raylib.h>
using namespace std;

int screen_width; //1920
int screen_height; //1080

void grid(){
    int x=0,y=0;
    for(x=0;x<=screen_width;x+=10){
        DrawLine(x,0,x,screen_height,GRAY);
    }
    for(y=0;y<=screen_height;y+=10){
        DrawLine(0,y,screen_width,y,GRAY);
    }

}

class BALL{
    public:
    float x,y;
    float radius;
    float speed_x,speed_y;

    void draw(){
        DrawCircle(x,y,radius,WHITE);
    }

    void update(){
        if(IsKeyDown(KEY_UP)) y = y - speed_y;
        if(IsKeyDown(KEY_DOWN)) y = y + speed_y;
        if(IsKeyDown(KEY_RIGHT)) x = x + speed_x;
        if(IsKeyDown(KEY_LEFT)) x = x - speed_x;   
    }

};

class PADDLE{
    public:
    float x,y;
    float height, width;
    float speed_x,speed_y;

    void draw(){
        DrawRectangle(x,y,width,height,WHITE);
    }


    void update_p2_pos(){
        x = x - speed_x;
        if(x<=870){
            speed_x = speed_x * (-1);
        }
        if(x>=930){
            speed_x = speed_x * (-1);
        }
    }
};



int main(){

    InitWindow(screen_width,screen_height,"KURUKSHETRA");
    SetTargetFPS(120);
    screen_height = GetScreenHeight();
    screen_width = GetScreenWidth();

   
    
    
    BALL ball;
    ball.x = GetScreenWidth()/2;
    ball.y = GetScreenHeight()/2;
    ball.radius = 10;
    ball.speed_x = 1;
    ball.speed_y = 1;

    PADDLE p1,p2,p3,p4;

    //p1_b1 - LEFT PADDLE
    
    p1.x = screen_width/2 - 50;
    p1.y = screen_height/2 - 30;
    p1.height = 60;
    p1.width = 20;


    //p2_b1 - TOP PADDLE
    p2.x = screen_width/2 - 30;
    p2.y = screen_height/2 - 50;
    p2.height = 20;
    p2.width = 60;

    p2.speed_x = 1;
    
    
    //p3_b1 - RIGHT PADDLE
    p3.x = screen_width/2 + 30;
    p3.y = screen_height/2 - 30;
    p3.width = 20;
    p3.height = 60;
    

    //p4_b1 - BOTTOM PADDLE
    p4.x = screen_width/2 - 30;
    p4.y = screen_height/2 + 30;
    p4.height = 20;
    p4.width = 60;

    
    


    
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        grid();
        
        ball.draw();
        ball.update();
        
       
        p2.update_p2_pos();

        Rectangle paddle_2 ={p2.x,p2.y,p2.width,p2.height};
        Vector2 ball_pos = {ball.x,ball.y};
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        p1.draw();
        p2.draw();
        p3.draw();
        p4.draw();
        
        EndDrawing();
    }
    


    return 0;
}
