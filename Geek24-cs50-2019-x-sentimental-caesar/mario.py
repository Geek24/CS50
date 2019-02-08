# Author: Chris Edwards, 2017
# Beverly, MA
# PSet 6: Sentimental
from cs50 import get_int

def main():
    height = -1

    while True:
        print(f"Height:")
        height = get_int()
        if height <= 23 and height > 0:
            break

    for i in range(height):
        for k in range(height - i - 1):
            print(" ", end = "")
        for k in range(i+1):
            print("#", end = "")
        print("")

if __name__ == "__main__":
    main()