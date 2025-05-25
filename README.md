# Word Melt Puzzle Using Breadth-First Search (BFS)

This project uses BFS to find the shortest path in a given word melt puzzle. A word melt puzzle has a start word, goal word, and a dictionary of valid words. We begin at the start word, changing the word one character at a time by changing, inserting, and/or deleting a letter. While changing the word, only valid words from the dictionary (not including the word being changed) that result from changes are used to traverse from the start word to the goal word. 


The order of word transformations is changing a letter, inserting a letter, and removing a letter.
An example of all iterations on the word "and" is shown below:  

<pre>
(read the first row left to right, then the second row, etc.):
Change each letter:
bnd, cnd, dnd, end, fnd, gnd, hnd, ind, jnd, knd, lnd, mnd, nnd, ond, pnd,
qnd, rnd, snd, tnd, und, vnd, wnd, xnd, ynd, znd, aad, abd, acd, add, aed,
afd, agd, ahd, aid, ajd, akd, ald, amd, aod, apd, aqd, ard, asd, atd, aud,
avd, awd, axd, ayd, azd, ana, anb, anc, ane, anf, ang, anh, ani, anj, ank,
anl, anm, ann, ano, anp, anq, anr, ans, ant, anu, anv, anw, anx, any, anz,

Insert Letter:
aand, band, cand, dand, eand, fand, gand, hand, iand, jand, kand, land,
mand, nand, oand, pand, qand, rand, sand, tand, uand, vand, wand, xand,
yand, zand, aand, abnd, acnd, adnd, aend, afnd, agnd, ahnd, aind, ajnd,
aknd, alnd, amnd, annd, aond, apnd, aqnd, arnd, asnd, atnd, aund, avnd,
awnd, axnd, aynd, aznd, anad, anbd, ancd, andd, aned, anfd, angd, anhd,    
anid, anjd, ankd, anld, anmd, annd, anod, anpd, anqd, anrd, ansd, antd,
anud, anvd, anwd, anxd, anyd, anzd, anda, andb, andc, andd, ande, andf,
andg, andh, andi, andj, andk, andl, andm, andn, ando, andp, andq, andr,
ands, andt, andu, andv, andw, andx, andy, andz,

Delete Letter:
nd, ad, an
</pre>

Notice that the word "and" does not appear in this list.

## Relation to DFS Maze Solver
This project uses the [DFS Maze Solver](https://github.com/joel-sarmiento/dfs-maze-solver) as reference.

## Program Input Format
Number of words in dictionary  
word  
word  
.  
.  
.  
start word  
goal word  

## Program Output
If there is a solution, the shortest path from the start word to goal word is output. Otherwise, "no solution" is output.

## Test Results
Input 1:  
![Screenshot 2025-05-24 at 8 36 31 PM](https://github.com/user-attachments/assets/ed32b5b7-1452-4101-92af-4a95a04d73e6)

Output 1:  
![Screenshot 2025-05-24 at 8 35 38 PM](https://github.com/user-attachments/assets/c413dc5b-ae41-477a-aa93-b7ed1f9b5e06)

Input 2:  
![Screenshot 2025-05-24 at 8 37 22 PM](https://github.com/user-attachments/assets/78a13e28-9c9d-49c9-adac-80962f1ffaaf)

Output 2:  
![Screenshot 2025-05-24 at 8 38 16 PM](https://github.com/user-attachments/assets/d037b0f0-23b9-4fbb-85f2-0e247669b408)

Input 3:  
![Screenshot 2025-05-24 at 8 40 25 PM](https://github.com/user-attachments/assets/a2782149-6a06-457f-acc9-a8c102cbdc97)

Output 3:  
![Screenshot 2025-05-24 at 8 41 03 PM](https://github.com/user-attachments/assets/141d3977-5d2a-46db-bb50-61e9c31b14bf)




