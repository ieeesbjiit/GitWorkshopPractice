#!/usr/bin/env python3

"""
Binary Search Algorithm to search an element from an array of integers.

Author: Abhiram B.S.N. (abhirambsn: GitHub)
Language: Python
"""

def binary_search(arr, element):
    low = 0
    high = len(arr)-1
    mid = 0

    while (low <= high):
        mid = (high +low) // 2

        if (arr[mid] < element):
            low = mid + 1
        elif (arr[mid] > element):
            high = mid - 1
        else:
            return mid
    return -1


def main():
    arr = eval(input("Enter Array:"))
    if type(arr) == type([1]):
        arr.sort()
        element = int(input("Enter Element:"))
        ele_index = binary_search(arr, element)
        if element < 0:
            print("Not Found")
        else:
            print("Element Found at index {}".format(ele_index))
    else:
        print("Please enter a list")


if __name__ == '__main__':
    main()
