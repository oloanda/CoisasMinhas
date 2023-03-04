#include <stdio.h>
#include "raylib.h"
#include <cmath>
#include <string>

static int screenWidth = 1200;
static int screenHeight = 900;
static int frameCount = 0;



void Asteroid(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    while(t <= 2 * PI)
    {
        float x = powf(cosf(t),3);
        float y = powf(sinf(t), 3);
        
        float tx = cosf(time * 3) * x +  sinf(time * 3) * y;
        float ty = -sinf(time * 3) * x + cosf(time * 3) * y;
        
        tx *= 400;
        ty *= 400;
        
        DrawCircle(tx + x0, ty + y0, 30.0f,GOLD);
        t += 0.01f;
    }
}


void Heart(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    
    while(t <= 2 * PI)
    {
        float x = powf(sinf(t),3);
        float y = cosf(t) - powf(cos(t),4);
        
        float X = 300 * x;
        float Y = 300 * y;
        
        float SX = 250 * x;
        float SY = 250 * y;
        
        float TX = 150 * x;
        float TY = 150 * y;
        
        if((frameCount/100)%2)DrawCircle(X + x0, -Y + y0,20.0f, RED);
        if((frameCount/120)%2)DrawCircle(SX + x0,-SY +y0,20.0f, PINK);
        if((frameCount/140)%2)DrawCircle(TX + x0, -TY + y0,20.0f,PURPLE);
        t += 0.01f;
    }
}


void Flower(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    
    while(t <= 2 * PI)
    {
        float x = cosf(t) * sinf(4 * t);
        float y = sinf(t) * sinf(4 * t);
        
        float tx = cosf(time * 2) * x - sinf(time * 2) * y;
        float ty = sinf(time * 2) * x + cosf(time * 2) * y;
        
        tx *= 400;
        ty *= 400;
        
        DrawCircle(tx + x0, ty + y0, 20.0f,GREEN);
        
        t += 0.01f;
    }
}

void Spiral(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;

    while(t <= 2 * PI)
    {
        float x = t * cosf( 2 * PI * t);
        float y = t * sinf(2 * PI * t);


        float tx = cosf(time * 4) * x - sinf(time * 4) * y;
        float ty = sinf(time * 4) * x + cosf(time * 4) * y;

        tx *= 80;
        ty *= 80;


        DrawCircleV({x0 + tx, y0 + ty}, 20.0f, BLUE);
        t += 0.01f;
    }
}



void Leaf(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    while(t <= 2 * PI)
    {
        float x = cosf(t) * (-8 * sinf(32 * t));
        float y = sinf(t) * (-8 * sinf(32 * t));

        float tx = cosf(time * 4) * x - sinf(time * 4) * y;
        float ty = sinf(time * 4) * x + cosf(time * 4) * y;

        tx *= 80;
        ty *= 80;


        DrawLine(x0, y0,x0 + tx, y0 + ty, RED);

        t += 0.01f;
    }
}

void Goodness(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    while(t <= 2 * PI)
    {
        float x = sinf(7 * PI * t);
        float y = cosf(5 * PI * t);

        float tx = cosf(time * 4) * x - sinf(time * 4) * y;
        float ty = -sinf(time * 4) * x + cosf(time * 4) * y;

        tx *= 500;
        ty *= 500;

        DrawLine(x0, y0,x0 + tx, y0 + ty, WHITE);

        t += 0.01f;
    }
}

void Crazy(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    while(t <= 2 * PI)
    {
        float x = cosf(t) * (1 + (1 / 8)*(cosf(t) + cosf(5 * t)));
        float y = sinf(t) * (1 + (1 / 8)*(cosf(t) + cosf(5 * t))); 


        float tx = 200 * x;
        float ty = 200 * y;


        DrawLine(x0, y0,x0 + tx, y0 + ty, RED);

        t += 0.01f;
    }
}

void Star(float y0, float x0)
{
    float time = GetTime();
    float t = 0.0f;
    while(t <= 2 * PI)
    {
        float x = 2 * cosf(t) + 5 * cosf((2 / 3) *t);
        float y = 2 * sinf(t) - 5 * sinf((2 / 3) * t);

        float tx = 50 * x;
        float ty = 50 * y;


        DrawLine(x0, y0,x0 + tx, y0 + ty, BLUE);

        t += 0.01f;
    }
}


int main(int argc, char** argv)
{
    char buffer1[128];
    char buffer2[128];
    char buffer3[128];
    char buffer4[128];

    FILE* file = fopen("../Assets/Poeme.txt", "r");
    if(file)
    {
        fgets(buffer1, 128, file);
        fgets(buffer2, 128, file);
        fgets(buffer3, 128, file);
        fgets(buffer4, 128, file);
    }
    fclose(file);
    
    InitWindow(screenWidth,screenHeight,"OSVALDO LOANDA - TON FAN");
    InitAudioDevice();

    
    
    while(!WindowShouldClose())
    {
        frameCount++;



                
        ClearBackground(BLACK);
        BeginDrawing();

        Leaf(screenHeight/2.0f,screenWidth / 2.0f);
        Goodness(screenHeight/2.0f,screenWidth / 2.0f);
        Spiral(screenHeight/2.0f,screenWidth / 2.0f);
        Flower(screenHeight/2.0f, screenWidth/2.0f);
        Asteroid(screenHeight/2.0f,screenWidth / 2.0f);
        Heart(screenHeight/4.0f,screenWidth/2.0f);

#if 1
        //if((frameCount / 60) % 2)
        //{
            DrawText(buffer1,(int)screenWidth / 2 - MeasureText(buffer1, 42) / 2, (int)screenHeight / 4,42, WHITE);
            DrawText(buffer2,(int)screenWidth / 2 - MeasureText(buffer2, 42) / 2, (int)screenHeight / 4 + 100,42, WHITE);
            DrawText(buffer3,(int)screenWidth / 2 - MeasureText(buffer3, 36) / 2, (int)screenHeight / 4 + 200,36, WHITE);
            DrawText(buffer4,(int)screenWidth / 2 - MeasureText(buffer4, 42) / 2, (int)screenHeight / 4 + 300,42, WHITE);

        //}
        
#endif

        if((frameCount/50)%2)
        {
            DrawText("OSVALDO",(int)screenWidth - MeasureText("OSVALDO", 50) - 40, (int)screenHeight - 60,50, WHITE);
        }



        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}