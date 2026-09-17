#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <raylib.h>

#include "world/World.hpp"


int main() 
{
 
    World* world = new World();
    world->Start();

    InitWindow(800, 600, "My First raylib Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        world->Update();
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
            DrawText("Базовые примитивы в raylib:", 20, 20, 20, DARKGRAY);

            // Отрезок (Линия)
            DrawLine(50, 100, 250, 100, RED);
            DrawLineEx((Vector2){50, 120}, (Vector2){250, 120}, 5.0f, MAROON);

            // Прямоугольники
            DrawRectangle(50, 170, 200, 100, BLUE);          // Залитый
            DrawRectangleLines(300, 170, 200, 100, ORANGE);    // Только контур

            // Круги
            DrawCircle(620, 220, 50, GREEN);                  // Залитый
            DrawCircleLines(620, 220, 60, DARKGREEN);         // Контур вокруг него

            // Треугольник (вершины передаются в порядке против часовой стрелки)
            Vector2 v1 = { 150, 320 };
            Vector2 v2 = { 50, 400 };
            Vector2 v3 = { 250, 400 };
            DrawTriangle(v1, v2, v3, PURPLE);

            // Полигон (правильный многоугольник, например, шестиугольник)
            // Центр x, Центр y, количество сторон, радиус, поворот, цвет
            DrawPoly((Vector2){400, 360}, 6, 50.0f, 0.0f, GOLD);

        EndDrawing();
    }

    CloseWindow();

    delete world;

    return 0;
}