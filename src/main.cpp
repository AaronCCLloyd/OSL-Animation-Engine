#include <raylib.h>
#include <cstdlib>

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Welcome to Nø̈reng");
    ToggleFullscreen();

    Camera camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    Vector2 cubeScreenPosition = {0.0f, 0.0f};

    DisableCursor();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        cubeScreenPosition = GetWorldToScreen(
            (Vector3){cubePosition.x, cubePosition.y + 2.5f, cubePosition.z}, camera);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane(cubePosition, (Vector2){2.0f, 2.0f}, DARKGREEN);

        // TODO: Provide the ability to render arbitrary topology for the land in the scene

        EndMode3D();

        DrawText(
            "Enemy: 100 / 100", (int)cubeScreenPosition.x - MeasureText("Enemy: 100/100", 20) / 2,
            (int)cubeScreenPosition.y,
            20,
            BLACK);

        DrawText(
            TextFormat(
                "Cube position in screen space coordinates: [%i, %i]",
                (int)cubeScreenPosition.x,
                (int)cubeScreenPosition.y),
            10, 10, 20, LIME);

        DrawText("Text 2d should be always on top of the cube", 10, 40, 20, GRAY);

        DrawFPS((0.95 * screenWidth), (0.005 * screenWidth));

        EndDrawing();
    }
    CloseWindow();
    return EXIT_SUCCESS;
}