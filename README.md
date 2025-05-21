# Project: Emergency Room - Patient Priority Queue

## Problem Description
This project simulates an emergency room system in a hospital using the Max Heap data structure. Each patient has a priority level based on their medical condition, and patients are treated according to their priority.

## Project Features
- Insert patients in random order.
- Automatically sort patients based on priority.
- Always treat the patient with the highest priority first.

## Solution Steps
1. Design a `Patient` object that contains the name, condition, and priority.
2. Create a MaxHeap data structure.
3. Implement insertion and extraction functions.
4. Display the list of patients before and after processing.

## Example 
****************** Input ******************

Name: Randa, Priority: 100, Arrival Time: 10

Name: Reem, Priority: 95, Arrival Time: 7  

Name: Saad, Priority: 90, Arrival Time: 2   

Name: Mohamed, Priority: 80, Arrival Time: 1

Name: Alex, Priority: 90, Arrival Time: 5  

Name: Zyad, Priority: 70, Arrival Time: 3 

Name: Mazen, Priority: 75, Arrival Time: 6 

Name: Farah, Priority: 80, Arrival Time: 8 

Name: Ibrahim, Priority: 70, Arrival Time: 9

Name: Ahmed, Priority: 85, Arrival Time: 4


****************** Output ******************

Name: Randa, Priority: 100, Arrival Time: 10

Name: Reem, Priority: 95, Arrival Time: 7

Name: Saad, Priority: 90, Arrival Time: 2

Name: Alex, Priority: 90, Arrival Time: 5

Name: Ahmed, Priority: 85, Arrival Time: 4

Name: Mohamed, Priority: 80, Arrival Time: 1

Name: Farah, Priority: 80, Arrival Time: 8

Name: Mazen, Priority: 75, Arrival Time: 6

Name: Zyad, Priority: 70, Arrival Time: 3

Name: Ibrahim, Priority: 70, Arrival Time: 9
