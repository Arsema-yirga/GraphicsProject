#include <windows.h>
#include <GL/freeglut.h>
#include <cmath>
#define PI 3.14159265358979323846

const float FLAG_X = 50;
const float FLAG_Y = 100;
const float FLAG_W = 500;
const float FLAG_H = 300;
const int STRIPS = 160;
const float WAVE_AMP = 12.0f;
const float WAVE_FREQ = 2.5f;

float wavePhase = 0.0f;
float flagOffsetY = 0.0f;

float rotationAngle = 0.0f;
float scaleValue = 1.0f;
float scaleDir = 1.0f;
float floatOffset = 0.0f;
float waveY(float x) {
    float t = (x - FLAG_X) / FLAG_W;
    return WAVE_AMP * sinf(wavePhase + t * 2.0f * PI * WAVE_FREQ);
}


void drawStrip(float lx, float rx) {
    float ly = waveY(lx);
    float ry = waveY(rx);

    float topL = FLAG_Y + FLAG_H + ly;
    float topR = FLAG_Y + FLAG_H + ry;

    float botL = FLAG_Y + ly;
    float botR = FLAG_Y + ry;

    float tL = (lx - FLAG_X) / FLAG_W;
    float tR = (rx - FLAG_X) / FLAG_W;

    float blueDiagL = FLAG_Y + tL * FLAG_H + ly;
    float blueDiagR = FLAG_Y + tR * FLAG_H + ry;

    glColor3f(0.0f, 0.18f, 0.55f);
    glBegin(GL_QUADS);
    glVertex2f(lx, botL);
    glVertex2f(rx, botR);
    glVertex2f(rx, blueDiagR);
    glVertex2f(lx, blueDiagL);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(lx, blueDiagL);
    glVertex2f(rx, blueDiagR);
    glVertex2f(rx, topR);
    glVertex2f(lx, topL);
    glEnd();

    const float YELLOW_T = 0.40f;

    float yellowDiagL = FLAG_Y + (1.0f - YELLOW_T) * FLAG_H + tL * FLAG_H + ly;
    float yellowDiagR = FLAG_Y + (1.0f - YELLOW_T) * FLAG_H + tR * FLAG_H + ry;

    if (yellowDiagL > topL) yellowDiagL = topL;
    if (yellowDiagR > topR) yellowDiagR = topR;

    if (tL < YELLOW_T) {
        float drawR = (tR > YELLOW_T) ? topR : yellowDiagR;

        glColor3f(1.0f, 0.84f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(lx, yellowDiagL);
        glVertex2f(rx, drawR);
        glVertex2f(rx, topR);
        glVertex2f(lx, topL);
    }
}
void drawFlagCircle(float cx, float cy, float r) {
    glColor3f(0, 0, 0);
    glLineWidth(7);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float a = i * PI / 180.0f;
        float x = cx + r * cos(a);
        float y = cy + r * sin(a);
        glVertex2f(x, y + waveY(x));
    }
    glEnd();
}

void drawSmallTriangles(int cx, int cy, int b) {
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);

    glVertex2f(cx, cy + b + 15 + waveY(cx));
    glVertex2f(cx - 8, cy + b + 5 + waveY(cx - 8));
    glVertex2f(cx + 8, cy + b + 5 + waveY(cx + 8));

    glVertex2f(cx, cy - b - 15 + waveY(cx));
    glVertex2f(cx - 8, cy - b - 5 + waveY(cx - 8));
    glVertex2f(cx + 8, cy - b - 5 + waveY(cx + 8));

    glVertex2f(cx + b + 15, cy + waveY(cx + b + 15));
    glVertex2f(cx + b + 5, cy - 8 + waveY(cx + b + 5));
    glVertex2f(cx + b + 5, cy + 8 + waveY(cx + b + 5));

    glVertex2f(cx - b - 15, cy + waveY(cx - b - 15));
    glVertex2f(cx - b - 5, cy - 8 + waveY(cx - b - 5));
    glVertex2f(cx - b - 5, cy + 8 + waveY(cx - b - 5));

    glEnd();
}

void drawStar() {
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);

    glVertex2f(180, 315 + waveY(180));
    glVertex2f(220, 245 + waveY(220));
    glVertex2f(140, 245 + waveY(140));

    glVertex2f(180, 225 + waveY(180));
    glVertex2f(220, 295 + waveY(220));
    glVertex2f(140, 295 + waveY(140));

    glEnd();
}