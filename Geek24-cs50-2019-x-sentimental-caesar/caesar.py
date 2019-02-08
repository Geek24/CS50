# Author: Chris Edwards, 2017
# Beverly, MA
# PSet 6: Sentimental
from cs50 import sys
from cs50 import get_string

def main():
    cipher = 0
    if len(sys.argv) != 2:
        print("Error! Command line arguments incorrect.")
        exit(1)

    key = int(sys.argv[1])

    print(f"plaintext:")
    plaintext = get_string()
    print(f"ciphertext: ", end="")
    i = 0
    #loop as long as each iteration is < or = length of code to cipher
    while i < len(plaintext):
        cipher = plaintext[i]
        if plaintext[i].islower():
            print(chr(((ord(cipher) - 97 + key) % 26) + 97), end="")
        elif plaintext[i].isupper():
            print(chr(((ord(cipher) - 65 + key) % 26) + 65), end="")
        else:
            if cipher:
                print(plaintext[i], end="")
        i = i + 1
    print("\n")


if __name__ == "__main__":
    main()