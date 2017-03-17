# fillit
arrange a list of Tetriminos in the smallest possible square

course projects at 42 US

• The program takes a file as parameter which contains a list of Tetriminos and arrange them to create the smallest square possible.

• Goal: find this smallest square in the minimal amount of time

Notes: • Tetriminos may be not valid.

• Check valid tetriminos without listing all valid shapes: (1) Choose 2 blocks from 4 => 6 combinations (2) Check 6 combinations. If two blocks in a combination are adjacent, counter++ (3) If counter >= 3 (more specifically 3 or 4) => valid tetriminos
