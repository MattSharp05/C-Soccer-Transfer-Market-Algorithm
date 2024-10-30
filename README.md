# Football Team Manager Simulator

This repository contains the final project for my Data Structures class, written in C++. The project simulates the experience of managing a football team during a transfer season, allowing users to build a team within a fixed budget by selecting and organizing players based on attributes like price, rating, and position. The project highlights data structure fundamentals, particularly the use of doubly linked lists, and custom sorting algorithms for enhanced user interactivity and strategic gameplay.

- [Video Demonstration](https://youtu.be/ppFJAGDFALk)

## I. Overview
The project allows users to experience the strategic decision-making of a football team manager, with functionality to add, remove, and sort players from a roster managed by a doubly linked list. Users can sort players by various attributes, facilitating a custom team-building experience. This approach introduces fundamental concepts in data structures, like linked lists, and algorithmic sorting, all applied in a realistic simulation environment.

## II. Details of Implementation
- **Data Structure**: The core data structure is a doubly linked list, implemented in the `FootballDList` class. This enables efficient dynamic updates to the player roster by supporting quick insertions, deletions, and sorting from both ends of the list.
- **Sorting Algorithms**: Custom insertion sort algorithms are used for sorting by cost and rating, and a targeted sorting function brings players of a specified position to the top of the list for easy management.
- **Sorting Functions**: 
  - `sortPlayersByCost` – Sorts players by transfer cost in descending order.
  - `sortPlayersByRating` – Sorts players by player rating in descending order.
  - `prioritizePosition` – Moves players of a chosen position to the front for prioritized viewing.

## III. Challenges
The project posed several challenges:
- **Sorting Algorithm Implementation**: Ensuring players could be sorted by cost, rating, and position effectively required developing targeted sorting mechanisms tailored to the doubly linked list.
- **Input Validation**: Preventing user errors and managing accurate position tracking required robust input validation.
- **UI/UX Design**: Crafting an intuitive and visually appealing interface that balanced complexity and usability presented design challenges, addressed through multiple feedback rounds and iterations.

## IV. Contributions
This project was a team effort, with contributions from each team member:
- **Matthew**: Implemented the doubly linked list class and player management methods.
- **Blake**: Developed sorting algorithms and ensured error robustness.
- **Rima**: Proposed the project idea, designed the program, and coordinated the presentation.

Together, the team worked outside of class to integrate their work cohesively, creating a functional and interactive simulation of a football team manager.

---

Explore the codebase for detailed documentation of each feature and function.
