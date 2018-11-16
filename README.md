# Memory Management Paging Algorithms

### Goal of this programming assignment
Exercise four paging replacement algorithms and evaluate the effectiveness of each algorithm which affects the performance of memory management. 

### Goal of this programming assignment
Write a C or C++ program that simulates the operation of 4 page replacement algorithms used in a virtual memory management system:
1. FIFO (First-in-First-out) algorithm
2. Least Recently Used (LRU) algorithm  
3. Most  Frequently Used (MFU) algorithm
4. Optimal algorithm 

We will simulate each algorithm on the input data sets and report the performance of each.

#### Specification
In this lab assignment, we will be calculating the page fault rate of the each different page replacement algorithms for the given page reference string for one processonly. Our program should accept three arguments, which are the number of page frames of the physical memory, the names of an input file, and an output file. The input file contains the page reference string in the order of page request, and the output file stores the display events and the analysis results. We will run each algorithm four times, the first time with 128 page frames, the second time with 256 page frames, the third time with 512 page frames, and the 4th time with 1024 frames.

Sample usage is   *prompt> memsim frame_size input.dat output.dat*     where
1. frame_size: no. of page frames in the primary memory
2. input.dat: refers to the input file and
3. output.dat:  the name of the output file.

##### Input details
###### Number of Frames
It is a single number that indicates the number of frames in the primary memory. So a number 128 will indicate that there are 128 frames of primary memory for this process. *Our program will be tested with four different size of primary memory: 128, 256, 512 and 1024 frames.*

######  Input File
The file contains the memory page request sequence string for only one process. The each line represents a page number which is being accessed by the process. Assume a process can have up to 4096 pages, and the pages being numbered from 0-4095. This implies that no number in the reference stream will fall outside that range. There will be exactly 10,000 references in the page reference string. In other word, the input file has 10,000 lines.

###### Output Details
The output file should print out the page fault rates for each of the four page replacement algorithms specified above based on the input page reference string at intervals of 2000 pages. Sample output format is shown below. For example, the column under 8000 lists the page fault rates for the first 8000 page references for all algorithms. Note that these are just sample values.

  
