# 🌊 Flood Fill

## What is Flood Fill?
Imagine you have a map — like a grid of squares. Some squares are walls, some are open space, maybe some are water or other stuff.

Flood fill is a way to figure out which squares you can reach starting from a certain point.

## 🔍 How Does It Work? The Concept
**1. Start somewhere:**
Pick a square on the map where you want to begin (like the player’s position).

**2. Mark it as visited:** 
Imagine you put a flag on this square saying, "I can get here."

**3. Look around:**
Check the neighboring squares (up, down, left, right). For each neighbor:
If it’s a wall or an obstacle, ignore it.
If it’s open, go there next.

**4. Repeat:**
From each new square you can reach, look around again at their neighbors and mark all reachable open squares.
Keep going until no new squares can be visited: When there are no more new open squares to visit, you’ve found all reachable places from the starting point.

**5. Stop when done**
When you can’t move anywhere new, you’ve found all connected reachable areas.

## 🎮 Why Use Flood Fill in so_long?
In your game, flood fill can help you:
- Check if all collectibles and the exit are reachable from the player’s starting position.
- Make sure the map is solvable before the game starts.

## 🎨 Real-Life Analogy
Think of flood fill like spilling paint on a floor:
- You pour paint on one tile.
- The paint spreads to all adjacent tiles it can flow to.
- Tiles blocked by walls or obstacles stay clean.
- By the end, the paint covers all tiles that are connected and reachable from where you poured it.

## 📚 Summary
- Flood fill explores the map from a starting point.
- It visits every open tile connected to that point.
- It helps you know if certain spots are accessible.
- Great for validating game maps or filling areas.
