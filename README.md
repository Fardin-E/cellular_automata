# cellular_automata
This project is a Cellular Automata Visualizer written in C++ using the Raylib library. Cellular automata (CA) are mathematical models composed of a grid of cells that evolve through discrete steps according to a set of rules. This visualizer allows users to explore and simulate various CA types, including Conway's Game of Life, Rule 30, and others, in real-time.

## Clone the repository
```
git clone https://github.com/Fardin-E/cellular_automata.git
cd cellular_automata
```
## Build the project using cmake
```
cmake . -B build
```
## Change the ruleset
- in the source code, inside the checkNeighbor() function change the variable rule to any value from 1 - 256. for more details. Visit [https://mathworld.wolfram.com/ElementaryCellularAutomaton.html]

- ![image](https://github.com/user-attachments/assets/0f4aee37-98f8-4898-9eaf-8c4570bbee35)
