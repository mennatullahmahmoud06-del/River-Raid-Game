# 🛩️ River Raid (C++ OOP Arcade Game)

A modern C++ recreation of the classic 1982 Atari game *River Raid*, built from scratch using the CMU Graphics Library. This project heavily emphasizes **Object-Oriented Programming (OOP)** principles, including polymorphism, inheritance, encapsulation, and dynamic memory management.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/Object_Oriented-Architecture-success?style=for-the-badge)
![CMU Graphics](https://img.shields.io/badge/CMU_Graphics_Lib-blueviolet?style=for-the-badge)

---

## 🎮 Gameplay Features
- **Dynamic Difficulty:** Enemy spawn rates and movement speeds scale dynamically based on the player's current score.
- **Fuel Management:** The player must continuously collect fuel tanks to prevent crashing. Fuel drains over time, adding strategic depth.
- **Save/Load System:** Full game state persistence. Players can save their progress (plane position, score, active enemies, bullets) to a text file and load it later.
- **Collision Detection:** Custom bounding-box collision algorithms for bullets, enemies, fuel, and the player.
- **Interactive UI:** A custom toolbar and status bar rendering system displaying live score, speed, lives, and fuel levels.

---

## 🏗️ Object-Oriented Architecture

This project was designed with a strict OOP methodology to ensure modularity, scalability, and clean code. 

### 1. Inheritance & Polymorphism
The game entities are structured using a robust class hierarchy. All drawable elements inherit from base classes, allowing the game loop to manage them generically.

- **`Drawable` / `GameObject` (Base Classes):** Define core properties (position, dimensions, colors) and virtual methods like `draw()`, `move()`, and `collisionAction()`.
- **`Enemy` (Abstract Base Class):** Inherits from `GameObject`. Defines the interface for all hostile entities.
  - **`Jets`**: Fast-moving aerial enemies.
  - **`Tanker`**: Slow, high-value ground targets.
  - **`helicopter`**: Erratic movement patterns.
  - **`Bridge`**: Static structural targets.
- **`Plane` & `Bullet` & `Fuel`:** Specialized derived classes for the player, projectiles, and collectibles.

*Polymorphism in action:* The `Game` class stores all enemies in a `std::vector<Enemy*>`. By overriding the virtual `move()` and `draw()` methods, the game loop can update all different enemy types with a single, clean loop without knowing their specific concrete types.

### 2. Encapsulation
Game state is heavily encapsulated. The `Game` class acts as the central controller. Variables like `score`, `fuelGauge`, `gameSpeed`, and entity vectors (`bullets`, `enemies`, `fuels`) are kept private/protected. External classes interact with these states strictly through controlled public getter/setter methods (e.g., `getscore()`, `UpdateScore()`, `addBullet()`, `setIsMoving()`).

### 3. Memory Management & RAII
Because entities are spawned and destroyed continuously, memory management was a critical focus:
- Dynamic allocation (`new`) is used for spawning enemies, bullets, and fuel.
- The `Game` destructor (`~Game()`) ensures all heap memory is properly deallocated to prevent memory leaks.
- Entities that move off-screen or are destroyed are safely removed from vectors using `std::find` and `erase`, followed by `delete` to free memory immediately.

---

## 🧠 Core Systems (Code Highlights)

### Dynamic Enemy Spawner
The game scales difficulty automatically without hardcoding levels. It modifies spawn cooldowns and maximum speeds based on player points.
```cpp
void Game::generate_enemys(int level) {
    // Difficulty scales with score
    spawnTimer = 3.0f - (points * 0.002f);
    if (spawnTimer < 0.5f) spawnTimer = 0.5f;

    float currentSpeed = enemySpeed + (points * 0.005f);
    if (currentSpeed > 8.0f) currentSpeed = 8.0f;

    // Polymorphic enemy generation
    int type = rand() % 4;
    switch (type) {
        case 0: pE = new Jets(this, pos, 100, 50, RED, BLACK); break;
        case 1: pE = new Tanker(this, pos, 80, 60, BLUE, WHITE); break;
        // ...
    }
    pE->setSpeed(currentSpeed);
    enemies.push_back(pE);
}
```

### Serialization (Save/Load)
Custom file I/O logic parses game state into a structured text format.
```cpp
void Game::saveGame(string filename) {
    fstream outFile("IO files\\" + filename + ".txt", ios::out);
    outFile << "PLANE " << planePos.x << " " << planePos.y << endl;
    outFile << "SCORE " << score << endl;
    outFile << "BULLETS " << bullets.size() << endl;
    // ... iterates through vectors to save entity states
}
```

---

## 🚀 How to Compile and Run

### Prerequisites
- Windows OS (Required for the CMU Graphics Library)
- Visual Studio (2019 or 2022 recommended)
- The `CMUgraphicsLib` folder must be included in the project directory.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/mennatullahmahmoud06-del/River-Raid-Game.git
   ```
2. Open `graphics_prj.sln` in Visual Studio.
3. Ensure the configuration is set to **x86** or **Win32** (depending on your VS setup).
4. Build the solution (`Ctrl + Shift + B`).
5. Run the executable or start without debugging (`Ctrl + F5`).

---

## 🎮 Controls
- **Move:** Arrow Keys (Left/Right/Up/Down)
- **Shoot:** Spacebar
- **Pause/Resume:** Use the in-game Toolbar buttons
- **Save/Load:** Use the Toolbar icons to write/read game state.

---
*Developed by [Mennatullah Mahmoud](https://github.com/mennatullahmahmoud06-del) as a university project demonstrating advanced C++ and Object-Oriented Design.*
```
