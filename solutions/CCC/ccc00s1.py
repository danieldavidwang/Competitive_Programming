money = int(input())
first = int(input())
second = int(input())
third = int(input())
use = 0

while (money >= 1):
    first += 1
    money -= 1
    use += 1
    if (first == 35):
      money += 30
      first -= 35
    if money == 0: break
    second += 1
    money -= 1
    use += 1
    if (second == 100):
      money += 60
      second -= 100
    if (money == 0): break
    third += 1
    money -= 1
    use += 1
    if (third == 10):
      money += 9
      third -= 10
    if money == 0: break

print ("Martha plays", use, "times before going broke.")