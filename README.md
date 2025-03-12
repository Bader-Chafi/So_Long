# **So Long - A 2D Maze Adventure Game**

## 🎮 **Project Overview**

Welcome to **So Long**, a captivating 2D maze game built with **MLX**, a lightweight graphical library. In this game, you step into the shoes of a brave adventurer, exploring a grid-based maze, collecting treasures, and trying to make your way to the elusive exit. But beware – the maze is filled with traps, and only the sharpest will make it out. 

The **So Long** project is a part of the **42 curriculum** and is designed to sharpen your programming skills in **C**, focusing on graphics rendering, user interaction, and real-time game logic.

---

## 💡 **Concept and Gameplay**

In **So Long**, the player navigates a maze represented by a 2D grid. Your mission? Collect all the candies and find your way to the exit. Sounds simple, right? Well, there are obstacles, traps, and a few surprises that will challenge your every move.

- **Objective**: 
  - **Collect all candies**: `C`
  - **Reach the exit**: `E`
- **Move the player**: The player is represented by a `P` on the map and can move up, down, left, or right.
- **Avoid obstacles**: The walls are represented by `1`. They block your path.
  
---

## 🧩 **Core Features**

### **1. Map Parsing and Validation**

The game is powered by a `.ber` file that contains the maze layout. Your first challenge is to load the map file and make sure it's well-formed. The map must:
- Be **rectangular**: No jagged edges!
- Contain exactly:
  - **One player (`P`)**
  - **One exit (`E`)**
  - **At least one candy (`C`)**
- Have **valid characters**: Only `1` (wall), `0` (empty space), `P` (player), `E` (exit), and `C` (candy) are allowed. No surprises!

---

### **2. Real-Time Player Movement**

Control your character with the arrow keys:
- **Arrow Up**: Move up
- **Arrow Down**: Move down
- **Arrow Left**: Move left
- **Arrow Right**: Move right

But there’s a twist! The player can’t just move anywhere. They’re constrained by walls (`1`). And to make things more exciting, every time you step on a candy (`C`), it gets collected, and your candy count increases. Once all candies are collected, the exit is unlocked!

---

### **3. Graphics Rendering**

Everything in **So Long** is rendered using **MLX**, where each game element (player, wall, exit, candy) is represented by an image. Imagine it like a pixelated board game, but in real time. 

- **Player**: `P`
- **Walls**: `1`
- **Exit**: `E`
- **Candy**: `C`

The game window is dynamically updated as the player moves, showing both the current state of the maze and any changes like candy collection.

---

### **4. Winning the Game**

The ultimate goal is simple: once all candies are collected, the player must find the exit (`E`). But don’t think it’s all smooth sailing – you’ll have to navigate the maze carefully, avoiding walls and strategically moving to collect every candy. 

Once you’ve collected every candy and reached the exit, the game displays a message: 

**“You win!”**

---

## 🛠️ **How to Run the Game**

To get started with **So Long**, follow these easy steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Bader-Chafi/So_Long.git
   cd so_long
   ```

2. **Build the project**:
   ```bash
   make
   ```

3. **Run the game**:
   After compiling, simply execute the game by providing a valid `.ber` map file:
   ```bash
   ./so_long maps/your_map.ber
   ```

   Enjoy the adventure and navigate your way through the maze!

---

## 🧩 **Project Breakdown**

The **So Long** project is split into several crucial components. Here’s a breakdown of how it works under the hood:

### **1. Map Parsing and Validation**

The game begins by loading the map from a `.ber` file. Once the file is loaded:
- **Validate the map**: Check if it’s rectangular, contains a player, an exit, and candies.
- **Store the map**: The map is stored in a 2D array, which is later used to draw the maze and control player movement.

### **2. Real-Time Movement & Event Handling**

The player’s position is updated in real time based on keyboard inputs. The movement is validated to ensure:
- The player doesn’t go through walls or out of bounds.
- Candies are collected when the player steps on them.

### **3. Rendering the Map**

Each game element (walls, player, exit, candies) is represented as an image and displayed using the MLX library. The map is dynamically rendered every time the player moves.

### **4. Winning Condition**

The game checks if all candies are collected and the player reaches the exit. If true, a victory message is displayed. Otherwise, the player continues exploring.

---

## 🧠 **Key Challenges**

- **Map validation**: Ensuring the map is correctly formatted and checking edge cases such as missing player or exit.
- **Memory management**: Properly allocating memory for the map and ensuring all resources are freed when the game ends.
- **Graphical updates**: Managing real-time rendering and ensuring smooth player movement.

---

## 💡 **Project Folder Structure**

Here’s a look at how the project is organized:

```plaintext
so_long/
│
├── src/                  # Source files
│   ├── main.c            # Entry point and main game logic
│   ├── map.c             # Map parsing and validation
│   ├── player.c          # Player movement and input handling
│   ├── graphics.c        # Game rendering logic
│   └── error.c           # Error handling functions
│
├── includes/             # Header files
│   └── so_long.h         # Main header with function prototypes
│
├── XPM/                  # Image files for rendering game elements
│   └── player.xpm
│   └── wall.xpm
│   └── exit.xpm
│   └── candy.xpm
│
├── Makefile              # Makefile for compiling the project
├── README.md             # The README file you’re reading right now
└── map.ber               # Example map file
```

---

## 🏆 **Conclusion**

**So Long** is an engaging and interactive project that challenges your understanding of **C programming**, **memory management**, and **event-driven programming**. By completing this project, you'll gain hands-on experience with **graphics rendering**, **game mechanics**, and **input handling** — all while crafting a fun and functional game.

So, gear up and start your adventure through the maze! 🚀

--- 

**Good luck, and may the best adventurer win!** 🎮

