#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <raylib.h>

#include "render/Render.hpp"

static void RenderEntity(const Entity& entity);

static Vector2 WorldToScreen(double worldX, double worldY);


const int windowWidth = 800;
const int windowHeight = 450;

const double scale_multiplier = 1.1;
const double speed = 5.0;

double camera_x;
double camera_y;

double scale = 1;

std::string data;

bool RenderWorld(World* world)
{
    if(IsKeyDown(KEY_D)) camera_x += speed;
    if(IsKeyDown(KEY_A)) camera_x -= speed;
    if(IsKeyDown(KEY_W)) camera_y -= speed;
    if(IsKeyDown(KEY_S)) camera_y += speed;
    if(IsKeyDown(KEY_E)) scale *= scale_multiplier;
    if(IsKeyDown(KEY_Q)) scale /= scale_multiplier;

    if(IsKeyPressed(KEY_SPACE))
    {
        if (!IsWindowFullscreen())
        {
            int monitor = GetCurrentMonitor();
            int monitorWidth = GetMonitorWidth(monitor);
            int monitorHeight = GetMonitorHeight(monitor);

            SetWindowSize(monitorWidth, monitorHeight);
            ToggleFullscreen();
        }
        else
        {
            ToggleFullscreen();

            SetWindowSize(windowWidth, windowHeight);
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();
        const Entity* clicked = nullptr;

        for (const auto& entity : world->GetEntities())
        {
            Vector2 pos = WorldToScreen(entity.X(), entity.Y());
            bool hit = false;

            switch (entity.GetType())
            {
                case ENT_Asteroid:
                {
                    float radius = 50.0f * (float)scale;
                    float dx = mouse.x - pos.x;
                    float dy = mouse.y - pos.y;
                    hit = (dx * dx + dy * dy) <= (radius * radius);
                    break;
                }
                case ENT_Factory:
                case ENT_Storage:
                {
                    float w = 50.0f * (float)scale;
                    float h = 25.0f * (float)scale;
                    hit = (mouse.x >= pos.x && mouse.x <= pos.x + w &&
                           mouse.y >= pos.y && mouse.y <= pos.y + h);
                    break;
                }
                case ENT_MiningShip:
                case ENT_DeliveryShip:
                {
                    float radius = 10.0f * (float)scale;
                    float dx = mouse.x - pos.x;
                    float dy = mouse.y - pos.y;
                    hit = (dx * dx + dy * dy) <= (radius * radius);
                    break;
                }
                default:
                    break;
            }

            if (hit)
            {
                clicked = &entity;
                break;
            }
        }

        if (clicked)
        {
            std::vector<std::string> new_data = clicked->GetData();
            if(!new_data.empty()) data = new_data[0];
            // TODO
        }
        else
        {
            data = "";
        }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    for(const auto& entity : world->GetEntities())
    {
        RenderEntity(entity);
    }

    DrawText(data.c_str(), 20, 20, 20, WHITE);

            // // Отрезок (Линия)
            // DrawLine(50, 100, 250, 100, RED);
            // DrawLineEx((Vector2){50, 120}, (Vector2){250, 120}, 5.0f, MAROON);

            // // Прямоугольники
            // DrawRectangle(50, 170, 200, 100, BLUE);          // Залитый
            // DrawRectangleLines(300, 170, 200, 100, ORANGE);    // Только контур

            // // Круги
            // DrawCircle(620, 220, 50, GREEN);                  // Залитый
            // DrawCircleLines(620, 220, 60, DARKGREEN);         // Контур вокруг него

            // // Треугольник (вершины передаются в порядке против часовой стрелки)
            // Vector2 v1 = { 150, 320 };
            // Vector2 v2 = { 50, 400 };
            // Vector2 v3 = { 250, 400 };
            // DrawTriangle(v1, v2, v3, PURPLE);

            // // Полигон (правильный многоугольник, например, шестиугольник)
            // // Центр x, Центр y, количество сторон, радиус, поворот, цвет
            // DrawPoly((Vector2){400, 360}, 6, 50.0f, 0.0f, GOLD);

        EndDrawing();

        return WindowShouldClose();
}

void RenderStart()
{
    InitWindow(windowWidth, windowHeight, "Mining");
    SetTargetFPS(60);
}

void RenderEnd()
{
    CloseWindow();
}

static void RenderEntity(const Entity& entity)
{
    Vector2 pos = WorldToScreen(entity.X(), entity.Y());

    switch(entity.GetType())
    {
        case ENT_Asteroid:
            DrawCircle((int)pos.x, (int)pos.y, 50.0f * (float)scale, GRAY);
            break;
        case ENT_Factory:
            DrawRectangle((int)pos.x, (int)pos.y, (int)(50 * scale), (int)(25 * scale), BLUE);
            break;
        case ENT_Storage:
            DrawRectangle((int)pos.x, (int)pos.y, (int)(50 * scale), (int)(25 * scale), YELLOW);
            break;
        case ENT_DeliveryShip:
            DrawCircle((int)pos.x, (int)pos.y, 10.0f * (float)scale, RED);
            break;
        case ENT_MiningShip:
            DrawPoly(pos, 3, 10.0f, 0.0f, PURPLE);
            break;
    }
}

static Vector2 WorldToScreen(double worldX, double worldY)
{
    const float screenW = (float)GetScreenWidth();
    const float screenH = (float)GetScreenHeight();
    return 
    {
        (float)((worldX - camera_x) * scale + screenW * 0.5),
        (float)((worldY - camera_y) * scale + screenH * 0.5)
    };
}