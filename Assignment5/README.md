# Assignment 5 – Random Number Generation

## Aim
To generate random numbers using a local system and compare execution time with Google Colab.

## Tools Used
- C Programming (GCC)
- Python (NumPy - Google Colab)
- Ubuntu


## Files Included
- random_local.c
- data_local.txt
- README.md


## Local Execution

Compile:
gcc random_local.c -o local

Run:
./local


## Google Colab Execution

Colab Notebook Link:  
https://colab.research.google.com/drive/1NwfYWFKq_B4H8v6TJJKArzu8OU-PGOTq?usp=sharing


## Execution Time Comparison

| Environment     | Input Size | Execution Time (seconds) |
|----------------|-----------|--------------------------|
| Local (CPU)    | 1000000   |        0.116680       |
| Google Colab   | 1000000   |        0.017458              |


## Observation
Execution time differs based on system performance. Cloud platforms may provide faster execution due to optimized resources.


## Conclusion
Random numbers were generated successfully on both local and cloud environments, and execution time comparison was performed.
