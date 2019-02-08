# Author: Chris Edwards, 2017
# Beverly, MA
# PSet 6: Sentimental
from cs50 import get_float
from math import floor


c = 0
while c <= 0:
    print(f"How much change is owed?\n")
    c = get_float()


# counting the coins
# converted into cents:
cents = round(c*100)
print(f"Cents: {cents}")

quarters = 0
dimes = 0
nickels = 0
remainter = 0

# quarters
quarters = cents // 25
print(f"Quarters: {quarters}")
remainder = cents - (quarters * 25)

#dimes
dimes = remainder // 10
print(f"Dimes: {dimes}")
float(remainder)
fdimes = remainder % 10

#nickels
final = fdimes
print(f"final: {final}")
nickels = final // 5

#pennies
pennies = final - (5 * nickels)

#final coin count
total = quarters + dimes + nickels + pennies
print(f"Final: {total}")
