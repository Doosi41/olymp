n = int(input())

ans_6, ans_8 = 0, 0

total = n*3

small , large = 6 ,8

if total < 15 or total == 18:
    ans_6 = (total-1) // small+1
else:
    ans_8 = (total-1) // large+1

print(ans_6, ans_8)