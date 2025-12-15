#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   // 用于键盘输入 (_kbhit, _getch)
#include <windows.h> // 用于延时 (Sleep)
#include <time.h>

// 定义游戏区域大小
#define WIDTH 20
#define HEIGHT 20

// 对应简历点：使用 Struct 定义游戏对象
typedef struct {
    int x, y;
} GameObject;

// 对应简历点：State Management (状态管理)
// 我们把整个游戏的状态打包在这个结构体里
typedef struct {
    GameObject player;
    GameObject enemy;
    GameObject bullet;
    int isBulletActive;
    int score;
    int gameOver;
} GameState;

// 函数声明：全部使用指针传递 (Pass by Pointer)
void initGame(GameState *state);
void draw(GameState *state);
void input(GameState *state);
void logic(GameState *state);

int main() {
    // 对应简历点：Game Loop (游戏循环)
    GameState state;
    initGame(&state); // 传入指针

    while (!state.gameOver) {
        draw(&state);   // 渲染
        input(&state);  // 输入
        logic(&state);  // 逻辑（包含碰撞检测）
        Sleep(100);     // 控制游戏速度 (100ms)
    }

    printf("\nGame Over! Final Score: %d\n", state.score);
    system("pause");
    return 0;
}

// 初始化游戏状态
void initGame(GameState *state) {
    state->player.x = WIDTH / 2;
    state->player.y = HEIGHT - 2;
    state->enemy.x = rand() % WIDTH;
    state->enemy.y = 0;
    state->isBulletActive = 0; // 子弹初始不激活
    state->score = 0;
    state->gameOver = 0;
}

// 渲染画面
void draw(GameState *state) {
    system("cls"); // 清屏 (Windows命令)
    
    // 打印上边界
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("#"); // 左边界
        for (int x = 0; x < WIDTH; x++) {
            if (x == state->player.x && y == state->player.y)
                printf("^"); // 玩家飞机
            else if (x == state->enemy.x && y == state->enemy.y)
                printf("V"); // 敌机
            else if (state->isBulletActive && x == state->bullet.x && y == state->bullet.y)
                printf("|"); // 子弹
            else
                printf(" "); // 空白
        }
        printf("#\n"); // 右边界
    }

    // 打印下边界
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Score: %d  (Controls: A=Left, D=Right, Space=Shoot)\n", state->score);
}

// 处理输入
void input(GameState *state) {
    if (_kbhit()) { // 如果有按键按下
        char key = _getch();
        switch (key) {
            case 'a': 
                if (state->player.x > 0) state->player.x--; 
                break;
            case 'd': 
                if (state->player.x < WIDTH - 1) state->player.x++; 
                break;
            case ' ': // 发射子弹
                if (!state->isBulletActive) {
                    state->isBulletActive = 1;
                    state->bullet.x = state->player.x;
                    state->bullet.y = state->player.y - 1;
                }
                break;
            case 'q':
                state->gameOver = 1;
                break;
        }
    }
}

// 游戏逻辑与碰撞检测
void logic(GameState *state) {
    // 1. 子弹移动
    if (state->isBulletActive) {
        state->bullet.y--;
        if (state->bullet.y < 0) {
            state->isBulletActive = 0; // 子弹飞出屏幕，重置
        }
    }

    // 2. 敌机移动
    // 为了演示简单，敌机偶尔移动一下，或者每次循环都往下掉
    // 这里放慢敌机速度：简单通过随机数模拟
    if (rand() % 2 == 0) { 
        state->enemy.y++;
    }
    
    // 敌机超出边界，重置回顶部
    if (state->enemy.y >= HEIGHT) {
        state->enemy.x = rand() % WIDTH;
        state->enemy.y = 0;
    }

    // 对应简历点：Collision Detection logic (碰撞检测)
    // 判定：子弹坐标 == 敌机坐标
    if (state->isBulletActive && 
        state->bullet.x == state->enemy.x && 
        state->bullet.y == state->enemy.y) {
            state->score += 10;      // 加分
            state->enemy.x = rand() % WIDTH; // 敌机重生
            state->enemy.y = 0;
            state->isBulletActive = 0; // 子弹消失
    }

    // 判定：敌机撞到玩家 -> 游戏结束
    if (state->player.x == state->enemy.x && 
        state->player.y == state->enemy.y) {
        state->gameOver = 1;
    }
}