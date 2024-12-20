# LANParty Simulation ~ PROJECT 1: ALGORITHM DESIGN

## Setup ~ COMPLETE
The setup for the project has been completed as follows:

- Created the project folder containing the necessary input/output files and test scripts.  
- Added a `Makefile` to simplify the compilation process and ensure compatibility with the checker.  

## TASK 1 ~ COMPLETE
- Parsed the input file (`date/d.in`) to create a singly linked list of participating teams.  
- Each team was represented as a struct containing the following:
  - Team name
  - Number of players
  - Dynamically allocated array of player structs, containing player names and scores.  
- Teams were inserted at the beginning of the list for O(1) complexity.  
- Modularized the implementation using headers for lists, teams, and players, facilitating code reusability.  

## TASK 2 ~ COMPLETE
- Calculated the number of teams required to meet the next power of 2 constraint.
- Added a `teamPoints` component to the team struct, which was used to identify and remove the weakest teams.  
- Iteratively eliminated teams until the required number of teams was reached.  

## TASK 3 ~ COMPLETE
- Implemented a queue-based simulation of matches:
  - Used a match queue, where each match contained two teams.
  - Winners and losers of each match were stored in separate stacks.  
- After each round:
  - Cleared the losers' stack.
  - Transferred winners from the winners' stack back to the match queue.  
- Preserved the last eight teams in a separate list for the next tasks.  

## TASK 4 ~ COMPLETE
- Constructed a Binary Search Tree (BST) from the final eight teams, inserting them in such a way that the tree facilitated ranking in descending order.  
- Displayed the top 8 teams in descending order using reverse inorder traversal.  

## TASK 5 ~ COMPLETE
- Converted the BST to an AVL tree, ensuring it was balanced:
  - Implemented rotations (left, right, left-right, right-left) to maintain the height-balance property.  
  - Used the AVL tree to display nodes on level 2, as required.  

## Additional Information
- Memory for dynamically allocated structures (lists, stacks, queues, trees) was freed after usage.  
- Included additional utility scripts (`checker.sh`) for automated testing.  
- Modularized the program by placing general-purpose functions in `functions.c` and `functions.h`.  

---

## How to Run

1. **Clone the Repository**  
   Clone the project repository to your local machine:
   ```bash
   git clone https://github.com/Horicuz/LANParty-Simulation_Homework.git
   ```

2. **Navigate to the Project Directory**  
   Change the directory to the project folder:
   ```bash
   cd LANParty-Simulation_Homework
   ```

3. **Setup the Project**  
   Ensure the project folder contains the input files, output files, and the checker script. Verify the presence of the `Makefile`.

4. **Compile the Code**  
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```

5. **Run the Checker**  
   Execute the checker script with the appropriate input file:
   ```bash
   ./checker.sh date/d.in out/output_file
   ```
   Replace `output_file` with the desired output file name.

6. **Inspect Results**  
   - Results, such as the final rankings, will be saved in the output directory or displayed in the terminal, depending on the implementation.
   - Outputs can be cross-verified using the checker script.

7. **Clean Up**  
   To remove compiled files and binaries, use:
   ```bash
   make clean
   ```

8. **Additional Notes for Beginners**  
   - Install `gcc` and `make` on your system before proceeding.
   - If you encounter permission issues with `checker.sh`, grant execute permissions:
     ```bash
     chmod +x checker.sh
     ```
   - Maintain the directory structure specified in the repository to avoid file path errors.

---

### Notes
- Input files must be formatted as described in the problem requirements.
- Adjust implementations in `functions.c` and queue operations to handle edge cases as needed.
